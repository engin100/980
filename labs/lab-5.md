---
layout: spec
latex: true
---

# Lab 5: Acceleration & Pressure

## Contents

- [Lab 5: Acceleration & Pressure](#lab-5-acceleration--pressure)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Introduction](#introduction)
    - [Pressure Sensor](#pressure-sensor)
    - [Accelerometer](#accelerometer)
  - [Procedure](#procedure)
    - [1. Setup](#1-setup)
    - [2. Pressure Sensor](#2-pressure-sensor)
    - [3. Accelerometer](#3-accelerometer)
    - [4. Putting It All Together](#4-putting-it-all-together)
    - [5. Collecting Data](#5-collecting-data)
    - [6. Analyzing the Data in Google Sheets (or Excel)](#6-analyzing-the-data-in-google-sheets-or-excel)
  - [Wrap-Up and Conclusion](#wrap-up-and-conclusion)
  - [Submission](#submission)

## Materials

- [ ] 1 Arduino Nano Every
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] 1 TMP36 Temperature Sensor
- [ ] 1 MicroSD Card
- [ ] 1 Data Logger
- [ ] 1 MicroSD Card - USB Adapter
- [ ] 2 1k$$\Omega$$ resistors
- [ ] 5-ish Black Jumper Wires
- [ ] 5-ish Red Jumper Wires
- [ ] 10-ish Other Colored Jumper Wires
- [ ] 1 9V Battery
- [ ] 1 9V Battery Connector
- [ ] 1 ADXL335 3-Axis Accelerometer
- [ ] 1 MPX4115A Pressure Sensor
- [ ] A Computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).

<div class="primer-spec-callout danger" markdown="1">
This is your first team lab! You can (and should) all work together to complete it and have one student submit the assignment on behalf of the team.
</div>

## Introduction

By the end of this lab, you will have re-built your circuit from lab 4, and added an accelerometer and pressure sensor, as well as made calibration curves for each of the sensors.

Most of the time involved in this lab will be re-wiring what you have previously built, as well as working on calibrating your accelerometer and pressure sensors.

What this means for you is that we are slowly going to start making our instructions increasingly vague. By this point you should know how to wire up an analog sensor to your Arduino and how to find and run starter code.

### Pressure Sensor

Our pressure sensor for this lab is what we will eventually be using to launch on our rocket. With some math and equations we will talk about in lecture, it is possible for us to estimate altitude based on pressure data, which will be useful for our rocket launch.

### Accelerometer

For this lab, we are using a 3-axis accelerometer. This sensor is capable of measuring acceleration in Gs on the x, y, and z planes.

1 G is considered normal acceleration that we feel on Earth as exerted by gravity. It is equivalent to a magnitude of 9.8m/s<sup>2</sup>.

## Procedure

### 1. Setup

As mentioned in the introduction, this lab is not going to give you nearly as detailed of instructions as previous labs have. Use your resources and refer to previous labs or references as needed if you are stuck on something!

To start, we are going to wire in a pressure sensor and calibrate it, and then an acceleration sensor and calibrate it. See the next 2 steps for more details about wiring each component.

Plug your Arduino onto your breadboard and hook it up to your computer. These next 2 steps will have you doing calibrations on analog sensors, meaning we will be reading analog values over Serial. Was there a lab (maybe lab 3...) where we had start code to do exactly this that you could repurpose?

<div class="primer-spec-callout info" markdown="1">
Note: Later in this lab we will ask for a picture of your finished circuit. Part of the requirements for this circuit are that one side of your breadboard's power rail is for 5V, one is for 3.3V, and both sides should have common ground. Additionally it is required that all power is routed with red jumper cables, all ground with black, and all data with other colors.
</div>

### 2. Pressure Sensor

In the real world of electrical and computer engineering, there most likely won't always be a tutorial to hold your hand and tell you how to wire up a component. As such, instead of *showing you* exactly how to wire up your pressure sensor, [here are the sensor's technical specs, which include wiring information on **page 9**](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/1001/MPX4115A.pdf).

Our sensor uses style 1 as listed in the docs. You should only need to connect three pins (Vout, Vin (5V), and GND). Since this is an analog sensor, connect Vout to an analog input pin on the Arduino, and run your code to get values you can use to calibrate the sensor.

Up until now we have been taking two very different measurements (like for the TMP36 temperature sensor) of both a room temperature reading and a very cold reading (like in the cold chamber) in order to build a calibration curve. Unfortunately, for the pressure sensor, it is hard for us to find two wildly different pressures. As such, we are letting you assume that at 0V the pressure is 0. You will need to measure another point and calculate the calibration curve for this sensor accordingly (for example, what does your weather app say the pressure is right now?). To be more precise about the 0 pressure being a 0V measurement, the spec sheet may provide more info, if you are interested.

Copy your Google Sheet (or Excel file), record these calibration values and calculate your calibration curve.

### 3. Accelerometer

The accelerometer is relatively straightforward to wire compared to the pressure sensor. All of the pinouts are clearly labelled on the sensor. You will wire GND to GND, X, Y, and Z each to its own analog pin on the Arduino, and **VCC to the 3V3 pin on the Arduino**.

<div class="primer-spec-callout danger" markdown="1">
This accelerometer sensor takes 3.3V input, not 5V like everything else we have used so far. Plugging it into 5V can break the sensor or cause other bad and unintended things to happen!
</div>

To read the number of Gs coming in on each axis, we will simply read the analog input for each axis pin. X, Y, and Z all should have their own analog pins to read off of. Make the necessary changes in your code so that you can read from these pins.

When calibrating this sensor, we will use our understanding of what 1 G is to our advantage. You will need to pay careful attention to the small 3-axis figure printed on the sensor module. When the sensor is flat on the table, the Z-axis should be vertical, and the others will be parallel to the table/ground.

In this orientation, the Z-axis is straight up and down and is therefore experiencing -1G. X and Y are both perpendicular to the force of gravity and would be recording 0Gs. If you turn your board upside down, the Z axis should read +1G. Rotate your sensor around as needed so that each axis has at least two data-points where it is (anti-)parallel to the force of gravity.

With this calibration process completed, each axis will have a calibration value of -1G and 1G. Record these values in your spreadsheet again, and calculate the calibration curve for each axis.

### 4. Putting It All Together

With your calibration curves calculated for both new sensors, we will now begin putting everything together. You can refer to the procedure in the previous lab should you need help.

Again, note that as described earlier, there are organizational and color requirements for breadboard wiring this lab. This makes it easier for other people to quickly look at and understand, and will make things more organized when moving into Altium later.

To re-iterate these requirements, you need a 5V power rail on one side of the breadboard, a 3.3V power rail on the other side, and 2 GND rails on either side. Additionally, all the GND connections should use black wires, all the 5V and 3.3V should use red wires (it is also ok if 5V uses red and 3.3V uses say orange), and all data wires (like analog in and SD card connections) using another color not used by any of the power circuitry.

The end result will be a temperature sensor, pressure sensor, accelerometer, and voltage divider all wired to an Arduino which stores data onto a microSD card and receives power via a 9V battery.

Modify the code given for the previous lab to add your new sensors to the csv the Arduino outputs. You will need to modify the pins defined at the top of the file, and will need to add some column titles to the header string defined above the `setup()` function as well. You will also need to modify the code in `loop()` to include the sensor values in the string added each iteration.

### 5. Collecting Data

With everything plugged into the 9V and running, unplug the Arduino from your computer. Walk around with your Arduino and try to think about things you can do to wildly influence the sensor values (without breaking your circuit!). More interesting changes will be more visible and easier to see in your final plots. (Question - will walking up 4 flights of stairs cause the pressure sensor to change?)

Now, before you jump ahead and start to dissemble your board, take a picture of it in its final working state! You will be submitting this!

### 6. Analyzing the Data in Google Sheets (or Excel)

In your spreadsheet, upload the csv file that your Arduino created. Similar to the previous lab, you will need to add some new columns to calculate values.

In addition to the columns your Arduino recorded, you will need a temperature (in C) column, a battery (in V) column, a pressure (hPa, mmHg, etc up to you), acceleration in X direction (Gs), acceleration in Y direction (Gs), acceleration in Z direction (Gs), and max acceleration (highest G-Force reading from any direction at each point in time) (Gs).

Graph temperature and pressure on the same graph compared to time. Since the Y-axis of this graph will have 2 different units, you may need to make sure your graph has a second Y-axis on the other side. Both graphs need to be labelled in a legend. Follow tech comm best practices when making the graph.

Graph all (4) acceleration values on the same graph compared to time. All of the values are in Gs, so only one Y-axis is needed. Be sure to label each line with a legend, and follow tech comm best practices.

## Wrap-Up and Conclusion

Congratulations! You have made it through the bread-boarding portion of this class! We hope that you enjoyed your time with Arduinos and learned a thing or two.

Moving forward, you are going to learn how to make 3D CAD (computer aided design) models and how to use Altium to build our Arduino breadboard circuits on a printed circuit board that can be soldered directly onto.

All of this will give you the final skills you need for your teams to work together and assemble a package that you will build to launch on a model rocket!

## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] A screenshot of your calibration curves and data for both new sensors added. This should be 4 total calibration curves (1 from each axis of the accelerometer).
- [ ] Your plot comparing temperature and pressure to time.
- [ ] Your plot comparing max acceleration and acceleration on each axis to time.
- [ ] A picture of your final breadboard with all the sensors connected and all of the power rail and wire color requirements satisfied.

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>

