---
layout: spec
title: Launch Day Logistics
---

# Launch Day Logistics

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


.meteogram-panel-label {
  font-size: 0.75rem;
  fill: #57606a;
}

.meteogram-temp-line {
  stroke: #cf222e;
  stroke-width: 3;
}

.meteogram-windchill-line {
  stroke: #0969da;
  stroke-width: 2.5;
}

.meteogram-wind-line {
  stroke: #1a7f37;
  stroke-width: 2.5;
}

.meteogram-gust-line {
  stroke: #9a6700;
  stroke-width: 2.5;
  stroke-dasharray: 6 4;
}

.meteogram-humidity-line {
  stroke: #0a3069;
  stroke-width: 2.2;
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

.meteogram-y-axis-label {
  font-size: 0.7rem;
  fill: #57606a;
  text-anchor: end;
  dominant-baseline: middle;
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

.legend-swatch.windchill {
  background: #0969da;
}

.legend-swatch.wind {
  background: #1a7f37;
}

.legend-swatch.gust {
  background: #9a6700;
}

.legend-swatch.precip {
  background: #1f6feb;
}

.legend-swatch.humidity {
  background: #0a3069;
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
<!-- Switch the class to `no-go` if we scrub and the banner will turn red. -->

## Lab Access Windows (Nov 13-14)

- **Thursday, Nov 13:** The lab is open now and stays open until 7:30 p.m. Use this time to finish fabrication and assembly.
- **Friday, Nov 14 (3:30–5:30 p.m.):** Final office hours for fabrication/assembly. Put rechargeable batteries on the charger during this window. If you rely on disposable batteries, you will receive a fresh one before launch, but you must check one out from the IAs on Saturday.

## Saturday Morning Timeline

- The lab opens at **10:00 a.m.** on Saturday. Use this slot to gather materials, run quick pre-launch checks, and insert a clean microSD card.
- Do **not** attempt major code or hardware changes Saturday morning, and avoid any testing that could damage your payload—there will not be time to recover from issues.

## Launch Kit Pickup

- Each team will receive a launch kit on Friday containing an engine, igniters, plugs, and recovery wadding.
- Place your team parts box (clear tackle box) inside the purple cabinets on Friday so staff can load the launch materials.
- Every team starts Saturday with one engine. After the first round of launches we will redistribute any remaining engines to teams that need a second attempt.

## What to Bring to Mitchell Field West

Bring the essentials so you can debug on site after your first flight:

- Laptop computer
- microSD card reader
- Cable adapters and your programming cable

## Launch Schedule & Location

- Plan to arrive at the lab between **10:00 a.m. and 11:30 a.m.** on Saturday. Launches begin around **12:00 p.m.** at **Mitchell Field West (softball fields).**
- We will monitor weather closely and send a Canvas + Slack Go/No-Go announcement by **9:30 a.m.** Saturday.

## Weather Outlook

Stay informed with the live NOAA meteogram for Ann Arbor. The chart below always locks onto the 48-hour Saturday/Sunday window so you can compare temperature, wind, gusts, humidity, and precipitation potential at a glance.

<div class="forecast-frame">
  <div class="meteogram-card">
    <div class="meteogram-body" data-noaa-meteogram data-lat="42.29" data-lon="-83.73">
      <p class="meteogram-loading">Pulling live data from NOAA…</p>
    </div>
  </div>
</div>

<p class="caption">Source: <a href="https://forecast.weather.gov/MapClick.php?lon=-83.7238&lat=42.286" target="_blank" rel="noopener">NOAA / NWS Detroit-Pontiac</a></p>

<script defer src="{{ '/assets/js/noaa-meteogram.js' | relative_url }}"></script>
