(function () {
  const SELECTOR = '[data-noaa-meteogram]';
  const SVG_NS = 'http://www.w3.org/2000/svg';
  const HOURS_TO_SHOW = 48;
  const MS_IN_HOUR = 3600000;
  const WEEKEND_START_DAY = 6; // Saturday

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
    const rawPeriods = hourlyData.properties.periods || [];
    const weekendWindow = getWeekendWindow();
    const weekendSelection = extractWeekendForecast(rawPeriods, weekendWindow);
    const periods = weekendSelection.length ? weekendSelection : rawPeriods.slice(0, HOURS_TO_SHOW);
    if (!periods.length) {
      throw new Error('Forecast did not include hourly periods.');
    }
    return {
      city: pointData.properties.relativeLocation?.properties?.city || 'Ann Arbor',
      state: pointData.properties.relativeLocation?.properties?.state || 'MI',
      periods,
      updated: hourlyData.properties.updated,
      window: weekendSelection.length ? weekendWindow : null
    };
  }

  function buildSummary(forecast) {
    const temps = forecast.periods.map((p) => p.temperature);
    const winds = forecast.periods.map((p) => parseWind(p.windSpeed));
    const precip = forecast.periods.map((p) => p.probabilityOfPrecipitation?.value ?? 0);
    const gusts = forecast.periods.map((p) => parseWind(p.windGust));
    const windChills = forecast.periods.map((p) => computeWindChill(p.temperature, parseWind(p.windSpeed)));
    const summary = document.createElement('div');
    summary.className = 'meteogram-summary';
    summary.appendChild(summaryItem('48h High', `${Math.round(Math.max(...temps))}°F`));
    summary.appendChild(summaryItem('48h Low', `${Math.round(Math.min(...temps))}°F`));
    summary.appendChild(summaryItem('Min Wind Chill', `${Math.round(Math.min(...windChills))}°F`));
    summary.appendChild(summaryItem('Peak Wind', `${Math.round(Math.max(...winds))} mph`));
    summary.appendChild(summaryItem('Peak Gust', `${Math.round(Math.max(...gusts))} mph`));
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
    const width = 720;
    const margin = { top: 18, right: 24, bottom: 60, left: 52 };
    const tempAreaHeight = 140;
    const windAreaHeight = 110;
    const precipAreaHeight = 90;
    const axisGap = 24;
    const height = margin.top + tempAreaHeight + windAreaHeight + precipAreaHeight + axisGap * 2 + margin.bottom;
    const innerWidth = width - margin.left - margin.right;
    const svg = createSvgElement('svg', {
      viewBox: `0 0 ${width} ${height}`,
      class: 'meteogram-chart'
    });

    const periods = forecast.periods;
    const steps = Math.max(periods.length - 1, 1);
    const xStep = innerWidth / steps;
    const temps = periods.map((p) => p.temperature);
    const windChills = periods.map((p) => computeWindChill(p.temperature, parseWind(p.windSpeed)));
    const windSpeeds = periods.map((p) => parseWind(p.windSpeed));
    const windGusts = periods.map((p) => parseWind(p.windGust));
    const precipValues = periods.map((p) => p.probabilityOfPrecipitation?.value ?? 0);
    const humidityValues = periods.map((p) => p.relativeHumidity?.value ?? 0);

    const tempValues = [...temps, ...windChills].filter((v) => Number.isFinite(v));
    const tempMin = Math.min(...tempValues) - 3;
    const tempMax = Math.max(...tempValues) + 3;
    const tempRange = Math.max(tempMax - tempMin, 1);
    const windValues = [...windSpeeds, ...windGusts].filter((v) => Number.isFinite(v));
    const windMax = Math.max(10, Math.ceil(Math.max(...windValues, 0) / 5) * 5);

    const tempTop = margin.top;
    const windTop = tempTop + tempAreaHeight + axisGap;
    const precipTop = windTop + windAreaHeight + axisGap;

    addGridLines(svg, margin, width, tempTop, tempAreaHeight);
    addGridLines(svg, margin, width, windTop, windAreaHeight);
    addGridLines(svg, margin, width, precipTop, precipAreaHeight);

    drawPanelLabel(svg, 'Temperature & Wind Chill (°F)', margin.left, tempTop - 4);
    drawPanelLabel(svg, 'Wind Speed & Gusts (mph)', margin.left, windTop - 4);
    drawPanelLabel(svg, 'Precipitation & Humidity (%)', margin.left, precipTop - 4);

    svg.appendChild(
      createLinePath(periods, xStep, margin, (index) => {
        const value = temps[index];
        const y = tempTop + tempAreaHeight - ((value - tempMin) / tempRange) * tempAreaHeight;
        return y;
      }, 'meteogram-temp-line')
    );

    svg.appendChild(
      createLinePath(periods, xStep, margin, (index) => {
        const value = windChills[index];
        const y = tempTop + tempAreaHeight - ((value - tempMin) / tempRange) * tempAreaHeight;
        return y;
      }, 'meteogram-windchill-line')
    );

    svg.appendChild(
      createLinePath(periods, xStep, margin, (index) => {
        const value = windSpeeds[index];
        const y = windTop + windAreaHeight - (value / Math.max(windMax, 1)) * windAreaHeight;
        return y;
      }, 'meteogram-wind-line')
    );

    svg.appendChild(
      createLinePath(periods, xStep, margin, (index) => {
        const value = windGusts[index];
        if (!Number.isFinite(value)) {
          return null;
        }
        const y = windTop + windAreaHeight - (value / Math.max(windMax, 1)) * windAreaHeight;
        return y;
      }, 'meteogram-gust-line')
    );

    const precipBase = precipTop;
    const barWidth = Math.max(xStep - 4, 2);
    periods.forEach((period, index) => {
      const probability = (precipValues[index] ?? 0) / 100;
      const barHeight = probability * precipAreaHeight;
      const rect = createSvgElement('rect', {
        x: margin.left + index * xStep - barWidth / 2,
        y: precipBase + (precipAreaHeight - barHeight),
        width: barWidth,
        height: barHeight,
        class: 'meteogram-precip-bar'
      });
      svg.appendChild(rect);
    });

    svg.appendChild(
      createLinePath(periods, xStep, margin, (index) => {
        const value = humidityValues[index];
        const y = precipTop + precipAreaHeight - (value / 100) * precipAreaHeight;
        return y;
      }, 'meteogram-humidity-line')
    );

    periods.forEach((period, index) => {
      if (index % 6 !== 0 && index !== periods.length - 1) {
        return;
      }
      const label = createSvgElement('text', {
        x: margin.left + index * xStep,
        y: height - 18,
        class: 'meteogram-axis-label'
      });
      label.textContent = formatHourLabel(period.startTime);
      svg.appendChild(label);
    });

    const legend = document.createElement('div');
    legend.className = 'meteogram-legend';
    legend.innerHTML = `
      <span><span class="legend-swatch temp"></span>Temperature</span>
      <span><span class="legend-swatch windchill"></span>Wind Chill</span>
      <span><span class="legend-swatch wind"></span>Sustained Wind</span>
      <span><span class="legend-swatch gust"></span>Wind Gust</span>
      <span><span class="legend-swatch precip"></span>Precipitation Chance</span>
      <span><span class="legend-swatch humidity"></span>Relative Humidity</span>
    `;

    wrapper.appendChild(svg);
    wrapper.appendChild(legend);
    return wrapper;
  }

  function buildUpdatedStamp(forecast) {
    const stamp = document.createElement('p');
    stamp.className = 'meteogram-updated';
    const updated = forecast.updated ? new Date(forecast.updated) : new Date();
    let text = `Updated ${formatTimestamp(updated)} • ${forecast.city}, ${forecast.state}`;
    if (forecast.window) {
      text += ` • Window: ${formatWindowRange(forecast.window)}`;
    }
    stamp.textContent = text;
    return stamp;
  }

  function parseWind(value) {
    if (!value) {
      return 0;
    }
    if (typeof value === 'number') {
      return value;
    }
    const matches = value.match(/(\d+)/g);
    if (!matches) {
      return 0;
    }
    const numbers = matches.map((n) => Number(n));
    const sum = numbers.reduce((acc, current) => acc + current, 0);
    return sum / numbers.length;
  }

  function computeWindChill(tempF, windMph) {
    if (!Number.isFinite(tempF) || !Number.isFinite(windMph)) {
      return tempF;
    }
    if (tempF > 50 || windMph < 3) {
      return tempF;
    }
    const chill =
      35.74 +
      0.6215 * tempF -
      35.75 * Math.pow(windMph, 0.16) +
      0.4275 * tempF * Math.pow(windMph, 0.16);
    return Math.round(chill);
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

  function formatWindowRange(window) {
    const startLabel = new Date(window.start).toLocaleString('en-US', {
      weekday: 'short',
      hour: 'numeric',
      minute: '2-digit'
    });
    const endLabel = new Date(window.end - 60 * 1000).toLocaleString('en-US', {
      weekday: 'short',
      hour: 'numeric',
      minute: '2-digit'
    });
    return `${startLabel} – ${endLabel}`;
  }

  function createSvgElement(tag, attributes) {
    const element = document.createElementNS(SVG_NS, tag);
    Object.entries(attributes || {}).forEach(([key, value]) => {
      element.setAttribute(key, value);
    });
    return element;
  }

  function createLinePath(periods, xStep, margin, yAccessor, className) {
    const path = createSvgElement('path', {
      class: className,
      fill: 'none'
    });
    let d = '';
    let active = false;
    periods.forEach((_, index) => {
      const y = yAccessor(index);
      if (y === null || Number.isNaN(y)) {
        active = false;
        return;
      }
      const x = margin.left + index * xStep;
      if (!active) {
        d += `M${x},${y}`;
        active = true;
      } else {
        d += ` L${x},${y}`;
      }
    });
    path.setAttribute('d', d);
    return path;
  }

  function addGridLines(svg, margin, width, top, height) {
    [0.25, 0.5, 0.75].forEach((fraction) => {
      const y = top + height * fraction;
      const line = createSvgElement('line', {
        x1: margin.left,
        y1: y,
        x2: width - margin.right,
        y2: y,
        class: 'meteogram-grid-line'
      });
      svg.appendChild(line);
    });
  }

  function drawPanelLabel(svg, text, x, y) {
    const label = createSvgElement('text', {
      x,
      y,
      class: 'meteogram-panel-label',
      'text-anchor': 'start'
    });
    label.textContent = text;
    svg.appendChild(label);
  }

  function getWeekendWindow() {
    const now = new Date();
    const start = new Date(now);
    start.setHours(0, 0, 0, 0);
    const day = start.getDay();
    const daysUntilSaturday = (WEEKEND_START_DAY - day + 7) % 7;
    start.setDate(start.getDate() + daysUntilSaturday);
    const end = new Date(start.getTime() + HOURS_TO_SHOW * MS_IN_HOUR);
    return { start: start.getTime(), end: end.getTime() };
  }

  function extractWeekendForecast(periods, windowOverride) {
    if (!periods.length) {
      return [];
    }
    const window = windowOverride || getWeekendWindow();
    const selection = periods.filter((period) => {
      const startTime = new Date(period.startTime).getTime();
      return startTime >= window.start && startTime < window.end;
    });
    return selection.slice(0, HOURS_TO_SHOW);
  }

  document.addEventListener('DOMContentLoaded', init);
})();
