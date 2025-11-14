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
.forecast-frame img {
  max-width: 100%;
  border: 1px solid #ccc;
  border-radius: 6px;
}
</style>

<div class="launch-status go">
  We are a GO for launch!
  <small>Update this banner to <code>no-go</code> if weather calls for a scrub.</small>
</div>

Stay on top of the latest National Weather Service model for Mitchell Field West. The plot below updates automatically from NOAA so you can track temperature, wind, sky cover, and precipitation in the 48-hour window around launch.

<div class="forecast-frame">
  <img
    src="https://forecast.weather.gov/meteograms/Plotter.php?lat=42.286&lon=-83.7238&w0=temperature&w1=dewpoint&w2=windchill&w3=surfacewind&w4=sky&w5=pop&w6=rh&w7=rain&unit=0&tz=EST&start=1&duration=48"
    alt="NWS Graphical Forecast for Ann Arbor">
</div>

<p class="caption">Source: <a href="https://forecast.weather.gov/MapClick.php?lon=-83.7238&lat=42.286" target="_blank" rel="noopener">NOAA / NWS Detroit-Pontiac</a></p>
