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
    - [The BME680](#bme680-4-in-1-digital-sensor)
    - [Accelerometer](#accelerometer)
  - [Procedure](#procedure)
    - [1. Setup](#1-setup)
    - [2. Calibrating The Accelerometer](#2-calibrating-the-accelerometer)
    - [3. Connecting The BME680](#3-connecting-the-bme680)
    - [4. Modifying The Code](#4-modifying-the-code)
    - [5. Collecting Data](#5-collecting-data)
    - [6. Analyzing the Data in Google Sheets (or Excel)](#6-analyzing-the-data-in-google-sheets-or-excel)
  - [Wrap-Up and Conclusion](#wrap-up-and-conclusion)
  - [Submission](#submission)

## Materials

- [ ] 1 Arduino Nano Every
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
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
- [ ] 1 BME680 Digital Sensor
- [ ] A Computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).

## Introduction

By the end of this lab, you will have re-built your circuit from lab 4, and added a 4-in-1 digital sensor, as well as made calibration curves for your accelerometer.

Most of the time involved in this lab will be re-wiring what you have previously built, adapting your code to support the new digital sensor, as well as working on calibrating your accelerometer.

What this means for you is that we are slowly going to start making our instructions increasingly vague. By this point you should know how to wire up an analog sensor to your Arduino and how to find and run starter code.

### BME680 4-in-1 Digital Sensor

The BME680 is a digital sensor that measures temperature, humidity, pressure, and VOC gases. VOC stands for Volitile Organic Compound, think organic solvents like alcohols and paint stripper. The pressure data from this sensor can be used to calculate your altitude since atmospheric pressure decreases with altitude.

You will be using this sensor for all sensing besides acceleration from this lab onwards so it will be important to get familiar with it.

This is a digital sensor, which means that instead of connecting it to an analog pin on your Arduino and reading the raw voltage, it will connect in an almost identical way to the SD logger from lab 4. This also means that you will not need to calibrate this sensor, since you will be reading a direct measurement from it and not voltage.

### Accelerometer

In this lab you will continue to use the accelerometer, this time calibrating it and collecting data in Gs (or m/s^2).

## Procedure

### 1. Setup

As mentioned in the introduction, this lab is not going to give you nearly as detailed of instructions as previous labs have. Use your resources and refer to previous labs or references as needed if you are stuck on something!

To start, we are going to re-wire the same setup that you had last lab. You should end up with a voltage divider and an accelerometer connected to your Arduino, which is powered via a 9V battery.

<div class="primer-spec-callout danger" markdown="1">
Remember that the accelerometer sensor takes 3.3V input, not 5V. Plugging it into 5V can break the sensor or cause other bad and unintended things to happen!
</div>

Then plug your Arduino onto your breadboard and hook it up to your computer. These next 2 steps will have you doing calibrations on your accelerometer, meaning we will be reading analog values over Serial. Was there a lab (maybe lab 3...) where we had start code to do exactly this that you could repurpose?

<div class="primer-spec-callout info" markdown="1">
Note: Later in this lab we will ask for a picture of your finished circuit. Part of the requirements for this circuit are that one side of your breadboard's power rail is for 5V, one is for 3.3V, and both sides should have common ground. Additionally it is required that all power is routed with red jumper cables, all ground with black, and all data with other colors.
</div>

### 2. Calibrating The Accelerometer

To calibrate your accelerometer, you will have to go through the same procedure that you did in lab 3, for all 3 axes of the accelerometer. This means that for each axis, you will need at least 2 known values of acceleration that you can subject the sensor to while reading the voltage.

In order to find 2 known values of acceleration, we must understand what exactly is it that the accelerometer measures. The name "accelerometer" is kind of misleading in this case, since it doesn't actually measure total acceleration. Internally, the sensor has a tiny object (usually silicon) that is connected to the rest of the sensor via a spring-like connection. This connection has electrical properties that change based on the tension that the connection experiences. This is a simplified explanation, but the actual sensors don't differ too much. 

If a force is applied to the outside of the sensor, the tension in the connection increases to keep the small internal object accelerating at the same rate as the sensor. This means that the sensor can only detect acceleration from forces that are applied **only** to the outside of the package, since if a force was applied equally to the internal object, the tension in the connection would not have to increase to keep the object accelerating with the rest of the sensor. Usually this isn't a problem, since most forces we're concerned with are fall into this category, however, there is one major force that doesn't: gravity. Recall from physics that gravity acts in a way that makes all objects accelerate at the same rate (9.8 m/s^2). This is the exact type of force that accelerometers cannot measure, since the internal connection does not have to apply any force to the internal object to keep it accelerating with the sensor - in the absence of external forces, everything accelerates at 9.8 m/s^2.

Now let's try to figure out what the accelerometer would measure in 2 different situations: in free-fall, and sitting stationary on a lab table. Start by drawing a free-body diagram for each situation, and then remove the gravitational force. The acceleration from the remaining forces is what the sensor would measure. In the situation of free-fall, since gravity is the only force (in the absence of air resistance), the acclerometer measures nothing. In the situation of the sensor sitting stationary, the normal force opposes gravity and is exactly equal to the force from gravity. The accelerometer will only measure the acceleration from the normal force, and since the normal force is equal to gravity in this case, it will measure 9.8 m/s^2, or 1 G, upwards. You will use this fact to calibrate the accelerometer.

Reminder to pay attention to the 3-axis figure printed on the sensor module. When the sensor is flat on the table, the Z-axis should be vertical, and the others will be parallel to the table/ground.

In this orientation, the Z-axis is straight up, and from our previous findings should measure 1G. X and Y are both perpendicular to the force of gravity and would be recording 0Gs. If you turn your board upside down, the Z axis should read -1G. Rotate your sensor around as needed so that each axis has at least two data-points where it is (anti-)parallel to the force of gravity.

With this calibration process completed, each axis will have a calibration value of 1G and -1G. Record these values in your spreadsheet again, and calculate the calibration curve for each axis.

Include your data table for all 3 axes, and your spreadsheet for the calibration of all 3 axes in your lab submission.

### 3. Connecting The BME680

As noted above, the BME680 connects to the Arduino using the same pins as the SD logger. This is ok to do since they both use a protocol called SPI. This is a very common protocol used to connect different digital chips together. SPI uses 3 pins to transfer data, and 1 pin to select which chip to communicate with, called chip select (CS for short). This chip select pin tells the device (the SD logger or BME680) to either pay attention to the 3 data pins, or ignore them. Both the SD logger and the BME680 will connect the 3 data pins to the same 3 pins on the Arduino, however the chip select pin for the BME680 will not connect to the same pin as the chip select pin on the SD logger, it will instead connect to a different digital pin on the Arduino. The goal is for the Arduino to be able to "select" which chip it wants to communicate using the chip select pins.

In the real world of electrical and computer engineering, there most likely won't always be a tutorial to hold your hand and tell you how to wire up a component. As such, instead of *showing you* exactly how to wire up your BME680, [here are the sensor's technical specs, which include wiring information on **page 12**](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-bme680-humidity-temperature-barometic-pressure-voc-gas.pdf). Remember that while you can connect the CS pin on both the SD logger and the BME680 to any Arduino digital pins, they should not connect to the same pin. 

### 4. Modifying The Code

Modify either your code or the code given for the previous lab to add your new sensor to the csv the Arduino outputs. You will need to modify the pins defined at the top of the file, and will need to add some column titles to the header string defined above the `setup()` function as well. You will also need to modify the code in `loop()` to include the sensor values in the string added each iteration. The new data from the BME680 will be in the physical units of the corresponding type of measurement (e.g. C for temperature), and not voltage or raw value like your analog data. Make sure this is reflected in the new column titles of your header string.

Since the BME680 can be somewhat complicated to interface with, an example has been provided in the Arduino library for this class. Note that this example only covers basic communication with the BME680, so you will need to use this program as an example of what to add to either your code or the code given for the previous lab.

### 5. Collecting Data

With everything plugged into the 9V and running, unplug the Arduino from your computer. Walk around with your Arduino and try to think about things you can do to wildly influence the sensor values (without breaking your circuit!). More interesting changes will be more visible and easier to see in your final plots. (Question - will walking up 4 flights of stairs cause the pressure sensor to change?)

Now, before you jump ahead and start to dissemble your board, take a picture of it in its final working state! You will be submitting this!

### 6. Analyzing the Data in Google Sheets (or Excel)

In your spreadsheet, upload the csv file that your Arduino created. Similar to the previous lab, you will need to add some new columns to calculate values.

In addition to the columns your Arduino recorded, you will need a battery (in V) column, acceleration in X direction (Gs), acceleration in Y direction (Gs), acceleration in Z direction (Gs), and max acceleration (highest G-Force reading from any direction at each point in time) (Gs).

Graph temperature and pressure on the same graph compared to time. Since the Y-axis of this graph will have 2 different units, you may need to make sure your graph has a second Y-axis on the other side. Both graphs need to be labelled in a legend. Follow tech comm best practices when making the graph.

Graph all (4) acceleration values on the same graph compared to time. All of the values are in Gs, so only one Y-axis is needed. Be sure to label each line with a legend, and follow tech comm best practices.

## Wrap-Up and Conclusion

Congratulations! You have made it through the bread-boarding portion of this class! We hope that you enjoyed your time with Arduinos and learned a thing or two.

Moving forward, you are going to learn how to make 3D CAD (computer aided design) models and how to use Altium to build our Arduino breadboard circuits on a printed circuit board that can be soldered directly onto.

All of this will give you the final skills you need for your teams to work together and assemble a package that you will build to launch on a model rocket!

## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] A screenshot of your calibration spreadsheet(s) and data for the accelerometer. This should be 3 total calibration curves (1 from each axis of the accelerometer).
- [ ] Your plot comparing temperature and pressure to time.
- [ ] Your plot comparing max acceleration and acceleration on each axis to time.
- [ ] A picture of your final breadboard with all the sensors connected and all of the power rail and wire color requirements satisfied.

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>

