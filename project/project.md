---
layout: spec
latex: true
---

# Project Guidelines

## Contents


## Project Specification

The goal of this semester's project is to:

1. Build a (model) rocket that will ascend to approximately 1,000 ft altitude carrying a (roughly) 3 oz payload in the nose cone, with a specified length, width, and height.  The selection criteria and choice of the model rockets is provided in [this document](https://980.engr100.org/labs/rocket-selection).  The nose cone or body tube may need to be modified to allow the sensor board and battery to be safely enclosed with no motion during the flight.  The nose cone or body may need to be further modified to allow the team to see the LEDs on the sensor board - the LEDs must be visible after the sensor board is enclosed in the nose cone or body. The rocket must survive and operate properly in all phases of the flight (thrust, drift, descent).

2. Provide a complete CAD drawing of your chosen rocket, complete with dimensions.  The CAD must include all aspects of the rocket, including: nose cone, sensor payload in the nose cone, body tube, parachute and connection points, motor housing, motor, motor holder, and fins.

3. Build a sensor board that will measure the rocket's acceleration and altitude during both the ascent and descent phase of the launch.  The acceleration must capture the different phases of the flight with enough robustness that the velocity and altitude can be determined.  The pressure sensor readings must be translated to altitude with enough robustness that the velocity and acceleration can be determined.  The sensor board needs to survive the flight using a 9V battery and store all of the data on a microSD card.  The sensor board needs to have a timer so that the user can turn the sensor board on, pack it into the nose cone in a way that it will survive the flight, put the nose cone back on to the rocket, put the rocket onto the launch pad, and prep the rocket for launch, all before the sensor board STARTS taking data.  The sensor board should provide some indication that it is counting down and should provide the user with warnings when it is just about ready to start taking data, and then when it is actually taking data.  The board should continue to take data until turned off.  All data should be recorded on the SD card as it is being taken.  It should be stored in a format that is easy for the user to read (such as a csv file).  All sensors must be calibrated.

4. Build a simulation package that describes the different phases of the flight (thrust, drift, descent) robustly.  This simulation package must:
A. Calculate the changing accelerations given the (vertical) forces that are acting on the rocket at the time.
B. Take into account the changing mass of the rocket.
C. Take into account the changing area of the rocket.
D. Calculate the velocity of the rocket as a function of time.
E. Calculate the altitude of the rocket as a function of time.
The coding language can be Google Spreadsheets, Excel, Python, Matlab, or C++.

5. Conduct data analysis by comparing and contrasting the different methods of calculating acceleration, velocity, and position for the flight and simulation data.  This comparison must be included in the poster and final reports, as described below.

## Preliminary Design Review

All teams must collectively present a preliminary design review, which must include:

1. Team number, name, members with a logo

2. Focus area for the project

3. Level 1 Requirements for the project

4. System-level block diagram - Very much like your schematic, but simplified and with connections (5V, 3.3V, analog, digital)

5. Sensor board physical specifications.

6. Chosen rocket with images and preliminary measurements.

7. A mass budget spreadsheet!

8. Your extra sensor (if you have one) and its characteristics

9. Initial simulation results if you have any.  Otherwise, the simulation design strategy.

10. How your design was shaped by the requirements.

11. Testing strategies that you have come up with.

12. Any test results that you have at this point.

13. Which team member will be responsible for which aspect of the project, including a back-up member.

## Go / No-Go Testing

Test all aspects of the system (rocket and sensor board), showing that both operate as expected.  Specifically, tests include:

1. Bench test - validate that the system works while sitting on the workbench and that all sensors are calibrated.  Data plots must indicate passing of this test.  Video should show the LEDs indicating when the sensor package is waiting for the time delay and when it is taking data.

2. Pendulum test - attach the sensor board (with battery) to different lengths of strings.  Take data while the sensor board swings back and forth.  Show that the measured 3D acceleration can be used in a way to provide the angle and velocity of the sensor board as it swings.  Show that the period of the pendulum is as expected from an analytic solution.  If your team is focusing on simulations, you should have a simulation of the pendulum that shows that you are getting consistent results between the measurements and the simulations.

3. Parachute test - While the sensor board is running and installed into your rocket, open the rocket and remove the parachute, but do not unfold it.  Drop it from a 4th floor (EECS or Robotics) so that the parachute has time to open and fully deploy.  You may want to practice this on something besides your rocket, so that you know that it will work (i.e., attatch your parachute to a mass that is comparable to your rocket and practice folding and dropping the system). You also may want to do a couple of tests with no sensor board on your rocket, so that the system has less weight and the terminal velocity is lower, so if there is terminal failure your rocket won't be destroyed. You have to show video of the final complete drop and the acceleration results during the test.

4. Drop test - This will be the scariest test.  Drop your fully assembled rocket with sensor package installed and running from 2 meters height, with the nose cone pointed towards the ground.  Do this over a grassy area, so that the rocket does not impact a super hard surface.  You have to show video of this being done and the acceleration results during the test.

5. Elevator test - You must find a building that is at least 10 stories and ride an elevator from the bottom floor to at least the 10th floor. The sensor package must be taking data during the elevator ride and should be placed on the floor so that it is measuring the acceleration of the elevator.  There should be at least two stops on the way to the 10th floor, so the stopping and starting can be noted and correlated with the pressure data.  The pressure must be converted to altitude.  The acceleration should be integrated to be converted into velocity and altitude.  The pressure / altitude must be differentiated to convert it to velocity and acceleration.  Plots need to show the results of this test.

6. Simulation test - Show that your rocket with the sensor board incorporated will reach at least 500 ft and will not exceed 1200 ft with one of the recommended motors.  The exact motor that your group would like will be specified with this test.  Plots will prove that this test passed.

All tests need to be presented at the Go/No-Go meeting.  Each team must pass all tests before being OKed for launch.

## Poster Presentation

All team members must collectively design, create, and present a poster.  The poster should be persuasive, convincing those who look at it that their project was successful. Teams should be able to highlight the aspects of their project (images, CAD drawings, physical rocket, simulation results, flight results) that convinces their audience (other class members, teaching staff, deans, etc.) that their project was a success.  The size and characteristics of the poster are provided in discussion.

## Final Report

All team members must collectively write a final report.  The final report should be persuasive, convincing those who read it that the team has designed the best software, best rocket, and/or best sensor package. The team should use as much evidence as they can (i.e., testing results and flight data / comparisons) to help convince the audience.  The final report should be written as a memo, and directed towards the teaching staff, who are (hypothetically) forming a new rocket company and are looking the best products they can to maximize their profitability.  Because all new companies need to hire raw talent, the final report should highlight which team members contributed in which areas.

We specifically are not providing minimum / maximum page counts or requirement on sections.  We are looking to see if your team makes a convincing argument that is backed up by data. 


