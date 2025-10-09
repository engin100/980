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

1. Build a (model) rocket that will ascend to approximately 1,000 ft altitude carrying a (roughly) 3 oz payload in the nose cone, with a specified length, width, and height.  The selection criteria and choice of the model rockets is provided in [this document](https://980.engr100.org/labs/rocket-selection).  The nose cone or body tube may need to be modified to allow the sensor board and battery to be safely enclosed with no motion during the flight.  The nose cone or body may need to be further modified to allow the team to see the LEDs on the sensor board - the LEDs must be visible after the sensor board is enclosed in the nose cone or body. The rocket must survive and operate properly in all phases of the flight (thrust, drift, descent).

    - Teams of 5 cannot build the "Green Eggs" rocket for launch. They must choose between either the Vapor or the High-Flier XL. Teams of 4 can choose between either of those rockets, in addition to the Green Eggs variation. The PDR may be presented on a different rocket other than these options, however the final build will be restricted to those three. Take a look at the [rocket selection guidelines](/labs/rocket-selection) for help with this topic. (The spreadsheet has been updated, so it may be worth taking a second look).

2. Provide a complete CAD drawing of your chosen rocket, complete with dimensions.  The CAD must include all aspects of the rocket, including: nose cone, sensor payload in the nose cone, body tube, parachute and connection points, motor housing, motor, motor holder, and fins. Additionally, the CAD model must include descent phase also, with parachute deployed.

3. Build a sensor board that will measure the rocket's acceleration and altitude during both the ascent and descent phase of the launch.  The acceleration must capture the different phases of the flight with enough robustness that the velocity and altitude can be determined.  The pressure sensor readings must be translated to altitude with enough robustness that the velocity and acceleration can be determined.  The sensor board needs to survive the flight using a 9V battery and store all of the data on a microSD card.  The sensor board needs to have a timer so that the user can turn the sensor board on, pack it into the nose cone in a way that it will survive the flight, put the nose cone back on to the rocket, put the rocket onto the launch pad, and prep the rocket for launch, all before the sensor board STARTS taking data.  The sensor board should provide some indication that it is counting down and should provide the user with warnings when it is just about ready to start taking data, and then when it is actually taking data.  The board should continue to take data until turned off.  All data should be recorded on the SD card as it is being taken.  It should be stored in a format that is easy for the user to read (such as a csv file).  All sensors must be calibrated. Additionally, you'll choose one extra sensor on the BME680 to use to record data. All teams must record pressure with the BME680, but you may also choose to measure humidity, VOC/gases, or temperature. [More information on sensor board documentation](https://980.engr100.org/labs/rocket-selection).

4. Build a simulation package that describes the different phases of the flight (thrust, drift, descent) robustly.  This simulation package must:
A. Calculate the changing accelerations given the (vertical) forces that are acting on the rocket at the time.
B. Take into account the changing mass of the rocket.
C. Take into account the changing area of the rocket.
D. Calculate the velocity of the rocket as a function of time.
E. Calculate the altitude of the rocket as a function of time.
The coding language can be Google Spreadsheets, Excel, Python, Matlab, or C++. Additionally, the simulation should accurately capture the thrust profile of the specific rocket engine used and should accurately capture the deployment of the parachute over the course of the time specified through experimentation (drop tests???).

5. Conduct data analysis by comparing and contrasting the different methods of calculating acceleration, velocity, and position for the flight and simulation data.  This comparison must be included in the poster and final reports, as described below.

## Preliminary Design Review

All teams must collectively present a preliminary design review, which must include:

1. Team number, name, members with a logo

2. Area of focused refinement/analysis (CAD, build, sensors, simulation)

    - Note that all teams must complete all requirements listed within the project sub-sections (CAD, rocket structures, extra sensors, thrust modeled simulations) but teams will also pick one of these areas to focus your design around and provide more detailed analysis in the project reports.

3. Level 1 Requirements for the project

    - See above!

4. System-level block diagram - Very much like your schematic, but simplified and with connections (5V, 3.3V, analog, digital)

    - This doesn't need to show every connection, such as ground wires, but rather should give an overview of the important connections between components.

5. Sensor board physical specifications.

6. Chosen rocket with images and preliminary measurements.

    - Again, it isn't required that you build the rocket that you present on in the PDR. You may find out the rocket you selected won't work well for the final build, or it may not be an allowed rocket! That's part of why we are giving these presentations.

7. A mass budget spreadsheet!

8. Your extra BME680 sensor and its characteristics 

9. Initial simulation results if you have any. Otherwise, the simulation design strategy.

10. How your design was shaped by the requirements.

11. Testing strategies that you have come up with.

    - Look at the testing strategies laid out in the Go / No-Go section below! This will help guide your response to this requirement, but you will also need to come up with tests for your extra sensor!

12. Any test results that you may have at this point.

    - Obviously we are still early in the build process, so you may not have any obvious test results. You could talk about the drop tests for design testing, rather than final product testing.

13. Which team member will be responsible for which aspect of the project, including a back-up member.

14. What questions do you have for us?

## Go / No-Go Testing

Test all critical aspects of the system (rocket and sensor board), showing that both operate as required. Specifically, tests include:

1. Bench test - validate that the system works while sitting on the workbench and that all sensors are calibrated. Data plots must indicate passing of this test. Video should show the LEDs indicating when the sensor package is waiting for the time delay and when it is taking data. Video should also highlight the buzzer going off at an appropriate time.

2. Pendulum test - attach the sensor board (with battery) to different lengths of strings. Take data while the sensor board swings back and forth. Show that the measured 3D acceleration can be used to determine the angle and velocity of the sensor board as it swings. Show that the period of the pendulum is as expected from an analytical solution. If your team is focusing on simulations, you should have a simulation of the pendulum that shows that you are getting consistent results between the measurements and the simulations.

3. Parachute test - Attach your parachute to the sensor board plus enough additional mass so the total mass is comparable to your integrated rocket+payload. With the sensor board running, drop the assembly from a 4th floor (EECS or Robotics) so that the parachute has time to open and fully deploy.  Show video of the drop. Show a plot of the acceleration data measured during the drop.

4. Elevator test - Find a building that is at least 8 stories tall and ride an elevator from the bottom floor to at least the 8th floor. The sensor package must be taking data during the elevator ride and should be placed on the floor so that it is measuring the acceleration of the elevator. There should be at least two stops on the way to the 8th floor, so the stopping and starting can be noted and correlated with the pressure data. The pressure must be converted to altitude. The acceleration should be integrated to be converted to velocity and the velocity integrated to be converted to altitude. The altitude derived from pressure must be differentiated to convert it to velocity and the velocity differentiated to convert it to acceleration. Plots need to show the results of this test.

5. Simulation test - Show that your rocket with the sensor board incorporated will reach at least 500 ft and will not exceed 1200 ft with one of the recommended motors. The exact motor that your group would like will be specified with this test. Plots will prove that this test passed.

All tests need to be presented at the Go/No-Go meeting. Each team must pass all tests before being OKed for launch.

## Poster Presentation

All team members must collectively design, create, and present a poster.  The poster should be persuasive, convincing those who look at it that their project was successful. Teams should be able to highlight the aspects of their project (images, CAD drawings, physical rocket, simulation results, flight results) that convinces their audience (other class members, teaching staff, deans, etc.) that their project was a success.  The size and characteristics of the poster are provided in discussion.

## Final Report

All team members must collectively write a final report.  The final report should be persuasive, convincing those who read it that the team has designed the best software, best rocket, and/or best sensor package. The team should use as much evidence as they can (i.e., testing results and flight data / comparisons) to help convince the audience.  The final report should be written as a memo, and directed towards the teaching staff, who are (hypothetically) forming a new rocket company and are looking the best products they can to maximize their profitability.  Because all new companies need to hire raw talent, the final report should highlight which team members contributed in which areas.

We specifically are not providing minimum / maximum page counts or requirement on sections.  We are looking to see if your team makes a convincing argument that is backed up by data. 


