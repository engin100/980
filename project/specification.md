---
layout: spec
latex: true
---

# Project Specification
The goal of this semester's project is to:

### 1. Build
Build a (model) rocket that will ascend to approximately 1,000 ft altitude carrying a (roughly) 3 oz, with a specified length, width, and height.  The nose cone or body tube may need to be modified to allow the sensor board and battery to be safely enclosed with no motion during the flight.  The nose cone or body may need to be further modified to allow the team to see the LEDs on the sensor board - the LEDs should be visible after the sensor board is enclosed in the nose cone or body. The rocket must survive and operate properly in all phases of the flight (thrust, drift, descent).

<div class="primer-spec-callout warning" markdown="1">
Teams of 5 and 4 cannot build the "Green Eggs" rocket for launch. They must choose between either the Vapor or the High-Flier XL.
</div>

### 2. CAD
Provide a complete CAD drawing of your chosen rocket, complete with dimensions.  The CAD must include all aspects of the rocket, including: nose cone, sensor payload in the nose cone, body tube, parachute and connection points, motor housing, motor, motor holder, and fins. Additionally, the CAD model must include descent phase also, with parachute deployed.

### 3. Sensors
Build a sensor board that measures the rocket's acceleration and altitude during both ascent and descent. [More information on sensor board documentation](/project/sensor-board).

**Measurements**
- **Acceleration:** must capture the different phases of the flight robustly enough that velocity and altitude can be determined from it.
- **Altitude:** pressure readings must be translated to altitude robustly enough that velocity and acceleration can be determined from it.
- **Extra BME680 sensor:** all teams must record pressure and temperature with the BME680, and could also choose one or more additional BME680 measurement: humidity or VOC/gases.

**Calibration**
- All sensors must be calibrated.
- Record **raw** sensor values (e.g. ADC readings) to the SD card, not calibrated ones.
- Apply your calibration curves to the data *after* the launch. Electronics are finicky, so a curve measured a few days earlier may not hold on launch day. With raw data, you can fit a new curve and apply it directly instead of first converting your calibrated values back to raw.

**Power and storage**
- The board must survive the flight running on a 9V battery.
- All data must be written to a microSD card *as it is being taken*, in an easy-to-read format (such as a CSV file).
- The board should keep taking data until it is turned off.

**Countdown timer**

The board must wait before it starts taking data, so the user has time to turn it on, pack it securely into the nose cone, put the nose cone back on the rocket, place the rocket on the launch pad, and prep it for launch. The board should indicate:
1. That it is counting down.
2. A warning when it is about to start taking data.
3. When it is actually taking data.

### 4. Simulation
Build a simulation package that describes the different phases of the flight (thrust, drift, descent) robustly.  This simulation package must:

1. Calculate the changing accelerations given the (vertical) forces that are acting on the rocket at the time.

2. Take into account the changing mass of the rocket.

3. Take into account the changing area of the rocket.

4. Calculate the velocity of the rocket as a function of time.

5. Calculate the altitude of the rocket as a function of time.

The coding language can be Google Spreadsheets, Excel, Python, Matlab, or C++. Additionally, the simulation should accurately capture the thrust profile of the specific rocket engine used and should accurately capture the deployment of the parachute over the course of the time specified through experimentation (drop tests???).

### 5. Data Analysis
Conduct data analysis by comparing and contrasting the different methods of calculating acceleration, velocity, and position for the flight and simulation data.  This comparison must be included in the poster and final reports, as described on the [Project page](/project/project#poster-presentation).
