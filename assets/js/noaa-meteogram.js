(function () {
  const SELECTOR = '[data-noaa-meteogram]';
  const SVG_NS = 'http://www.w3.org/2000/svg';
  const HOURS_TO_SHOW = 48;

  function init() {
    const widgets = document.querySelectorAll(SELECTOR);
    if (!widgets.length) {
      return;
    }
    widgets.forEach((widget) => {
      const lat = parseFloat(widget.dataset.lat);
      const lon = parseFloat(widget.dataset.lon);
      if (Number.isNaN(lat) || Number.isNaN(lon)) {
        widget.innerHTML = '<p class="meteogram-error">Unable to load NOAA data for this location.</p>';
        return;
      }
      loadForecast(widget, lat, lon);
    });
  }

  async function loadForecast(container, lat, lon) {
    setStatus(container, 'Loading live data from NOAA…');
    try {
      const forecast = await fetchForecast(lat, lon);
      container.innerHTML = '';
      container.appendChild(buildSummary(forecast));
      container.appendChild(buildChart(forecast));
      container.appendChild(buildUpdatedStamp(forecast));
    } catch (error) {
      console.error('NOAA meteogram failed', error);
      container.innerHTML = '<p class="meteogram-error">NOAA data is temporarily unavailable. Try refreshing in a minute.</p>';
    }
  }

  function setStatus(container, text) {
    container.innerHTML = `<p class="meteogram-loading">${text}</p>`;
  }

  async function fetchForecast(lat, lon) {
    const pointResponse = await fetch(`https://api.weather.gov/points/${lat},${lon}`);
    if (!pointResponse.ok) {
      throw new Error('Unable to locate grid point.');
    }
    const pointData = await pointResponse.json();
    const hourlyUrl = pointData.properties.forecastHourly;
    if (!hourlyUrl) {
      throw new Error('Hourly forecast not available.');
    }
    const hourlyResponse = await fetch(hourlyUrl);
    if (!hourlyResponse.ok) {
      throw new Error('Unable to download hourly forecast.');
    }
    const hourlyData = await hourlyResponse.json();
    const periods = (hourlyData.properties.periods || []).slice(0, HOURS_TO_SHOW);
    if (!periods.length) {
      throw new Error('Forecast did not include hourly periods.');
    }
    return {
      city: pointData.properties.relativeLocation?.properties?.city || 'Ann Arbor',
      state: pointData.properties.relativeLocation?.properties?.state || 'MI',
      periods,
      updated: hourlyData.properties.updated
    };
  }

  function buildSummary(forecast) {
    const temps = forecast.periods.map((p) => p.temperature);
    const winds = forecast.periods.map((p) => parseWind(p.windSpeed));
    const precip = forecast.periods.map((p) => p.probabilityOfPrecipitation?.value ?? 0);
    const summary = document.createElement('div');
    summary.className = 'meteogram-summary';
    summary.appendChild(summaryItem('48h High', `${Math.round(Math.max(...temps))}°F`));
    summary.appendChild(summaryItem('48h Low', `${Math.round(Math.min(...temps))}°F`));
    summary.appendChild(summaryItem('Peak Wind', `${Math.round(Math.max(...winds))} mph`));
    summary.appendChild(summaryItem('Max Precip Chance', `${Math.round(Math.max(...precip))}%`));
    return summary;
  }

  function summaryItem(label, value) {
    const card = document.createElement('div');
    card.className = 'meteogram-summary-item';
    const labelEl = document.createElement('span');
    labelEl.textContent = label;
    const valueEl = document.createElement('strong');
    valueEl.textContent = value;
    card.appendChild(labelEl);
    card.appendChild(valueEl);
    return card;
  }

  function buildChart(forecast) {
    const wrapper = document.createElement('div');
    wrapper.className = 'meteogram-chart-wrapper';
    const svg = createSvgElement('svg', {
      viewBox: '0 0 720 320',
      class: 'meteogram-chart'
    });

    const margin = { top: 18, right: 24, bottom: 48, left: 48 };
    const tempAreaHeight = 200;
    const precipAreaHeight = 90;
    const axisGap = 14;
    const innerWidth = 720 - margin.left - margin.right;
    const periods = forecast.periods;
    const steps = Math.max(periods.length - 1, 1);
    const xStep = innerWidth / steps;
    const temps = periods.map((p) => p.temperature);
    const tempMin = Math.min(...temps) - 3;
    const tempMax = Math.max(...temps) + 3;
    const tempRange = Math.max(tempMax - tempMin, 1);
    const precipValues = periods.map((p) => p.probabilityOfPrecipitation?.value ?? 0);

    // temperature grid lines
    [0.25, 0.5, 0.75].forEach((fraction) => {
      const y = margin.top + tempAreaHeight * fraction;
      const line = createSvgElement('line', {
        x1: margin.left,
        y1: y,
        x2: 720 - margin.right,
        y2: y,
        class: 'meteogram-grid-line'
      });
      svg.appendChild(line);
    });

    const tempPath = createSvgElement('path', {
      class: 'meteogram-temp-line',
      fill: 'none'
    });
    const points = periods
      .map((period, index) => {
        const x = margin.left + index * xStep;
        const y = margin.top + tempAreaHeight - ((period.temperature - tempMin) / tempRange) * tempAreaHeight;
        return `${index === 0 ? 'M' : 'L'}${x},${y}`;
      })
      .join(' ');
    tempPath.setAttribute('d', points);
    svg.appendChild(tempPath);

    // precipitation bars
    const precipBase = margin.top + tempAreaHeight + axisGap;
    periods.forEach((period, index) => {
      const probability = precipValues[index] / 100;
      const barHeight = probability * precipAreaHeight;
      const rect = createSvgElement('rect', {
        x: margin.left + index * xStep - Math.max(xStep - 4, 2) / 2,
        y: precipBase + (precipAreaHeight - barHeight),
        width: Math.max(xStep - 4, 2),
        height: barHeight,
        class: 'meteogram-precip-bar'
      });
      svg.appendChild(rect);
    });

    // axis labels
    periods.forEach((period, index) => {
      if (index % 6 !== 0 && index !== periods.length - 1) {
        return;
      }
      const label = createSvgElement('text', {
        x: margin.left + index * xStep,
        y: 320 - 16,
        class: 'meteogram-axis-label'
      });
      label.textContent = formatHourLabel(period.startTime);
      svg.appendChild(label);
    });

    const legend = document.createElement('div');
    legend.className = 'meteogram-legend';
    legend.innerHTML = `
      <span><span class="legend-swatch temp"></span>Temperature (°F)</span>
      <span><span class="legend-swatch precip"></span>Precipitation chance (%)</span>
    `;

    wrapper.appendChild(svg);
    wrapper.appendChild(legend);
    return wrapper;
  }

  function buildUpdatedStamp(forecast) {
    const stamp = document.createElement('p');
    stamp.className = 'meteogram-updated';
    const updated = forecast.updated ? new Date(forecast.updated) : new Date();
    stamp.textContent = `Updated ${formatTimestamp(updated)} • ${forecast.city}, ${forecast.state}`;
    return stamp;
  }

  function parseWind(value) {
    if (!value) {
      return 0;
    }
    const matches = value.match(/(\d+)/g);
    if (!matches) {
      return 0;
    }
    const numbers = matches.map((n) => Number(n));
    const sum = numbers.reduce((acc, current) => acc + current, 0);
    return sum / numbers.length;
  }

  function formatHourLabel(value) {
    const date = new Date(value);
    return date.toLocaleString('en-US', {
      weekday: 'short',
      hour: 'numeric'
    });
  }

  function formatTimestamp(date) {
    return date.toLocaleString('en-US', {
      weekday: 'short',
      hour: 'numeric',
      minute: '2-digit',
      timeZoneName: 'short'
    });
  }

  function createSvgElement(tag, attributes) {
    const element = document.createElementNS(SVG_NS, tag);
    Object.entries(attributes || {}).forEach(([key, value]) => {
      element.setAttribute(key, value);
    });
    return element;
  }

  document.addEventListener('DOMContentLoaded', init);
})();
