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
</div>
<!-- Update this banner to `no-go` if weather calls for a scrub. -->

Stay on top of the latest National Weather Service model for Mitchell Field West. The plot below updates automatically from NOAA so you can track temperature, wind, sky cover, and precipitation in the 48-hour window around launch.

<div class="forecast-frame">
  <img
    src="https://forecast.weather.gov/meteograms/Plotter.php?point=42.29,-83.73&zcode=MIZ068&gset=20&g=0&r=0&a=0&pcmd=0&relative=0&wfo=DTX&lat=42.29&lon=-83.73&z=0&tz=EST"
    alt="NOAA meteogram showing temperature, wind, humidity, and precipitation for Ann Arbor">
</div>

<p class="caption">Source: <a href="https://forecast.weather.gov/MapClick.php?lon=-83.7238&lat=42.286" target="_blank" rel="noopener">NOAA / NWS Detroit-Pontiac</a></p>
