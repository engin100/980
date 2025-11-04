---
layout: spec
latex: true
---

# Project Guidelines

## Contents

- [Project Specification](#project-specification)
- [Preliminary Design Review](#preliminary-design-review)
- [Go / No-Go Testing](#go--no-go-testing)
- [Poster Presentation](#poster-presentation)
- [Final Report](#final-report)

## Project Specification
The goal of this semester's project is to:

### 1. Build
Build a (model) rocket that will ascend to approximately 1,000 ft altitude carrying a (roughly) 3 oz payload in the nose cone, with a specified length, width, and height.  The selection criteria and choice of the model rockets is provided in [this document](https://980.engr100.org/labs/rocket-selection).  The nose cone or body tube may need to be modified to allow the sensor board and battery to be safely enclosed with no motion during the flight.  The nose cone or body may need to be further modified to allow the team to see the LEDs on the sensor board - the LEDs must be visible after the sensor board is enclosed in the nose cone or body. The rocket must survive and operate properly in all phases of the flight (thrust, drift, descent).

<div class="primer-spec-callout warning" markdown="1">
Teams of 5 cannot build the "Green Eggs" rocket for launch. They must choose between either the Vapor or the High-Flier XL. Teams of 4 can choose between either of those rockets, in addition to the Green Eggs variation. The PDR may be presented on a different rocket other than these options, however the final build will be restricted to those three. Take a look at the [rocket selection guidelines](/labs/rocket-selection) for help with this topic. (The spreadsheet has been updated, so it may be worth taking a second look).
</div>

### 2. CAD
Provide a complete CAD drawing of your chosen rocket, complete with dimensions.  The CAD must include all aspects of the rocket, including: nose cone, sensor payload in the nose cone, body tube, parachute and connection points, motor housing, motor, motor holder, and fins. Additionally, the CAD model must include descent phase also, with parachute deployed.

### 3. Sensors
Build a sensor board that will measure the rocket's acceleration and altitude during both the ascent and descent phase of the launch.  The acceleration must capture the different phases of the flight with enough robustness that the velocity and altitude can be determined.  The pressure sensor readings must be translated to altitude with enough robustness that the velocity and acceleration can be determined.  The sensor board needs to survive the flight using a 9V battery and store all of the data on a microSD card.  The sensor board needs to have a timer so that the user can turn the sensor board on, pack it into the nose cone in a way that it will survive the flight, put the nose cone back on to the rocket, put the rocket onto the launch pad, and prep the rocket for launch, all before the sensor board STARTS taking data.  The sensor board should provide some indication that it is counting down and should provide the user with warnings when it is just about ready to start taking data, and then when it is actually taking data.  The board should continue to take data until turned off.  All data should be recorded on the SD card as it is being taken.  It should be stored in a format that is easy for the user to read (such as a csv file).  All sensors must be calibrated. Additionally, you'll choose one extra sensor on the BME680 to use to record data. All teams must record pressure with the BME680, but you may also choose to measure humidity, VOC/gases, or temperature. [More information on sensor board documentation](/project/sensor-board).

### 4. Simulation
Build a simulation package that describes the different phases of the flight (thrust, drift, descent) robustly.  This simulation package must:

1. Calculate the changing accelerations given the (vertical) forces that are acting on the rocket at the time.

2. Take into account the changing mass of the rocket.

3. Take into account the changing area of the rocket.

4. Calculate the velocity of the rocket as a function of time.

5. Calculate the altitude of the rocket as a function of time.

The coding language can be Google Spreadsheets, Excel, Python, Matlab, or C++. Additionally, the simulation should accurately capture the thrust profile of the specific rocket engine used and should accurately capture the deployment of the parachute over the course of the time specified through experimentation (drop tests???).

### 5. Data Analysis
Conduct data analysis by comparing and contrasting the different methods of calculating acceleration, velocity, and position for the flight and simulation data.  This comparison must be included in the poster and final reports, as described below.

## Preliminary Design Review
All teams must collectively present a preliminary design review, which must include:

### 1. Team information
Team number, name, members with a logo

### 2. Area of focused refinement/analysis
Choose an area (Build, CAD, Sensors, or Simulation) in which your team will focus the project design around and provide **MORE** detailed analysis in the project reports.

<div class="primer-spec-callout info" markdown="1">
**Note:** All teams must complete all requirements listed within the project sub-sections (Build, CAD, Sensors, or Simulation)
</div>

### 3. Level 1 Requirements for the project
See above!

### 4. System-level block diagram
This is very much like your schematic, but simplified and with connections (5V, 3.3V, analog, digital)
<div class="primer-spec-callout info" markdown="1">
**Note:** This doesn't need to show every connection, such as ground wires, but rather should give an overview of the important connections between components.
</div>

### 5. Sensor board physical specifications
Any important specifications about the sensor board. For more details go to the [sensor board spec](/project/sensor-board) page.

### 6. Chosen rocket
Show images and preliminary measurements of the chosen rocket.
<div class="primer-spec-callout info" markdown="1">
**Note:** Again, it isn't required that you build the rocket that you present on in the PDR. You may find out the rocket you selected won't work well for the final build, or it may not be an allowed rocket! That's part of why we are giving these presentations.
</div>

### 7. Mass budget spreadsheet
<div class="primer-spec-callout info" markdown="1">
**Note:** If you do not have any concrete numbers for the weight of some components, search it up online or simply ask an IA if you can weight that component during Lab or OH! **Make sure to watch out for sig figs.**
</div>

### 8. Extra BME680 sensor 
Explain the chosen extra BME680 sensor, its characteristics, and how you can implement it into your rocket to **gather meaningful data**.
<div class="primer-spec-callout info" markdown="1">
**Note:** You do not need to know specifically how to implement the extra sensor into your rocket yet; however, we do want to see that you have considered a way to implement it. You may find out that your sensor implementation for the final build may not work! That's part of why we are giving these presentations.
</div>

### 9. Simulation Results
Explain your simulation design strategy. Show any initial simulation results if available; otherwise, the simulation design strategy will suffice.

### 10. Design
Explain how your design was shaped by the requirements.

### 11. Testing strategies
Explain your testing strategies. 

<div class="primer-spec-callout info" markdown="1">
**Note:** Look at the testing strategies laid out in the [Go / No-Go Testing Section](#go--no-go-testing)! This will help guide your response to this requirement, but you will also need to come up with tests for your extra sensor!
</div>

### 12. Test results
Explain any test results that you have up until this point. 

<div class="primer-spec-callout info" markdown="1">
**Note:** Obviously we are still early in the build process, so you may not have any obvious test results. You could talk about the drop tests for design testing, rather than final product testing.
</div>

### 13. Team Format
Which team member will be responsible for which aspect of the project, including a back-up member.

### 14. What questions do you have for us?
You can ask us any questions that you have. The PDR is a **two-way deal**: we ask you guys questions about your design, and you can ask us questions as well! 
<div class="primer-spec-callout danger" markdown="1">
Be mindful of the time limit!
</div>

## Go / No-Go Testing

Test all critical aspects of the system (rocket and sensor board), showing that both operate as required. Specifically, tests include:

### 1. Bench Test
Validate that the system works while sitting on the workbench and that all sensors are calibrated. 
- Data plots must indicate passing of this test
- Video should show the LEDs indicating when the sensor package is waiting for the time delay and when it is taking data
- Video should also highlight the buzzer going off at an appropriate time

### 2. Pendulum Test
Attach the sensor board (with battery) to different lengths of strings. Take data while the sensor board swings back and forth. [Tips for the pendulum test.](/project/pendulum)
- Show that the measured 3D acceleration can be used to determine the angle and velocity of the sensor board as it swings
- Show that the period of the pendulum is as expected from an analytical solution

<div class="primer-spec-callout info" markdown="1">
**Note:** If your team is focusing on **simulation**, you should have a simulation of the pendulum that shows that you are getting consistent results between the measurements and the simulations.
</div>

<div class="primer-spec-callout danger" markdown="1">
You should have a sample rate of at least 5 Hz when you are sampling all of the sensors (except the accelerometer) as usual. When performing any tests with the accelerometer specifically (such as this pendulum test) you should have a sample rate of at least 100 Hz. In order to do this, you may need to lower the BME680's gas sensor heating time to allow for faster sampling.
</div>

### 3. Spike Test
Verify that each sensor that you are **utilizing** can detect and respond to a large change in a **small amount of time** (“spike”) in its measured variable. You will need to use some creativity to design and execute your own methods to produce a clear “spike” for each sensor. To create a “spike”:
1. Begin by collecting a few seconds of stable baseline data
2. Perform the chosen action to make the “spike”
3. Let the system return to equilibrium

The goal is to observe how each sensor reacts to large, fast variations and confirm its responsiveness. For each sensor, you must create plots that clearly show a “spike” and explain what you did to get this “spike”.

<div class="primer-spec-callout info" markdown="1">
**Note:** The humidity sensor should be the only one that cannot create a **spike**. Still, we should see a significant change, but not over a short period like the other sensors. It will look more like a hill. **If you chose the humidity sensor, you must explain why the humidity sensor behaves like this in the Go/No-Go Presentation.**
</div>

<div class="primer-spec-callout danger" markdown="1">
You should have a sample rate of at least 5 Hz when you are sampling all of the sensors (except the accelerometer) as usual. When performing any tests with the accelerometer specifically you should have a sample rate of at least 100 Hz. In order to do this, you may need to lower the BME680's gas sensor heating time to allow for faster sampling.
</div>

### 4. Elevator Test
Find a building that is at least 8 stories tall and ride an elevator from the bottom floor to at least the 8th floor. The sensor package must be taking data during the elevator ride and should be placed on the floor so that it is measuring the acceleration of the elevator. There should be at least two stops on the way to the 8th floor, so the stopping and starting can be noted and correlated with the pressure data.
- The pressure must be converted to altitude
- The acceleration should be integrated to be converted to velocity and the velocity integrated to be converted to altitude
- The altitude derived from pressure must be differentiated to convert it to velocity and the velocity differentiated to convert it to acceleration
- Plots need to show the results of this test

### 5. Simulation Test
Show that your rocket with the sensor board incorporated will reach at least 500 ft and will not exceed 1200 ft with one of the recommended motors. The exact motor that your group would like will be specified with this test. Plots will prove that this test passed.

<div class="primer-spec-callout danger" markdown="1">
All tests need to be presented at the Go/No-Go meeting. Each team must pass all tests before being OKed for launch.
</div>

## Poster Presentation

All team members must collectively design, create, and present a poster.  The poster should be persuasive, convincing those who look at it that their project was successful. Teams should be able to highlight the aspects of their project (images, CAD drawings, physical rocket, simulation results, flight results) that convinces their audience (other class members, teaching staff, deans, etc.) that their project was a success.  The size and characteristics of the poster are provided in discussion.

## Final Report

All team members must collectively write a final report.  The final report should be persuasive, convincing those who read it that the team has designed the best software, best rocket, and/or best sensor package. The team should use as much evidence as they can (i.e., testing results and flight data / comparisons) to help convince the audience.  The final report should be written as a memo, and directed towards the teaching staff, who are (hypothetically) forming a new rocket company and are looking the best products they can to maximize their profitability.  Because all new companies need to hire raw talent, the final report should highlight which team members contributed in which areas.

We specifically are not providing minimum / maximum page counts or requirement on sections.  We are looking to see if your team makes a convincing argument that is backed up by data. 


