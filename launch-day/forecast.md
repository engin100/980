---
layout: spec
title: Weather Forecast
---

# Weather Forecast

<style>
.launch-status {
  padding: 1rem;
  border-radius: 10px;
  text-align: center;
  font-weight: 600;
  font-size: 1.1rem;
  border: 2px solid transparent;
  margin-bottom: 1.5rem;
}
.launch-status.go {
  background-color: #e6f4ea;
  border-color: #2d7a36;
  color: #1e5c27;
}
.launch-status.no-go {
  background-color: #fdecea;
  border-color: #c62828;
  color: #7a0c0c;
}
.launch-status small {
  display: block;
  font-weight: normal;
  margin-top: 0.4rem;
}
.forecast-frame {
  margin-top: 1.5rem;
}

.meteogram-card {
  border: 1px solid #d0d7de;
  border-radius: 12px;
  padding: 1.25rem;
  background: #fff;
  box-shadow: 0 10px 25px rgba(15, 23, 42, 0.1);
}

.meteogram-body {
  min-height: 260px;
}

.meteogram-summary {
  display: flex;
  flex-wrap: wrap;
  gap: 0.75rem;
  margin-bottom: 1rem;
}

.meteogram-summary-item {
  flex: 1 1 150px;
  border-radius: 8px;
  padding: 0.75rem 1rem;
  background: #f6f8fa;
}

.meteogram-summary-item span {
  display: block;
  font-size: 0.75rem;
  text-transform: uppercase;
  letter-spacing: 0.04em;
  color: #57606a;
  margin-bottom: 0.25rem;
}

.meteogram-summary-item strong {
  font-size: 1.4rem;
  color: #101828;
}

.meteogram-chart-wrapper {
  width: 100%;
}

.meteogram-chart {
  width: 100%;
  height: auto;
  display: block;
}

.meteogram-grid-line {
  stroke: #d0d7de;
  stroke-dasharray: 4 4;
  stroke-width: 1;
}

.meteogram-temp-line {
  stroke: #cf222e;
  stroke-width: 3;
}

.meteogram-precip-bar {
  fill: #1f6feb;
  opacity: 0.65;
}

.meteogram-axis-label {
  font-size: 0.7rem;
  fill: #57606a;
  text-anchor: middle;
}

.meteogram-loading,
.meteogram-error {
  text-align: center;
  padding: 2rem 0;
  color: #57606a;
  font-weight: 500;
}

.meteogram-legend {
  display: flex;
  gap: 1.25rem;
  flex-wrap: wrap;
  margin-top: 0.75rem;
  font-size: 0.85rem;
  color: #57606a;
}

.meteogram-legend span {
  display: flex;
  align-items: center;
  gap: 0.35rem;
}

.legend-swatch {
  width: 14px;
  height: 14px;
  border-radius: 999px;
  display: inline-block;
}

.legend-swatch.temp {
  background: #cf222e;
}

.legend-swatch.precip {
  background: #1f6feb;
}

.meteogram-updated {
  margin-top: 0.75rem;
  font-size: 0.85rem;
  color: #57606a;
}
</style>

<div class="launch-status go">
  We are a GO for launch!
</div>
<!-- Update this banner to `no-go` if weather calls for a scrub. -->

Stay on top of the latest National Weather Service model for Mitchell Field West. The plot below updates automatically from NOAA so you can track temperature, wind, sky cover, and precipitation in the 48-hour window around launch.

<div class="forecast-frame">
  <div class="meteogram-card">
    <div class="meteogram-body" data-noaa-meteogram data-lat="42.29" data-lon="-83.73">
      <p class="meteogram-loading">Pulling live data from NOAA…</p>
    </div>
  </div>
</div>

<p class="caption">Source: <a href="https://forecast.weather.gov/MapClick.php?lon=-83.7238&lat=42.286" target="_blank" rel="noopener">NOAA / NWS Detroit-Pontiac</a></p>

<script defer src="{{ '/assets/js/noaa-meteogram.js' | relative_url }}"></script>
