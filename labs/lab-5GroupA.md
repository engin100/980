---
layout: spec
latex: true
---

# Lab 5: Group A Portion

Adding the BME680 to your Lab 4 circuit and calibrating the accelerometer.

<div class="primer-spec-callout danger" markdown="1">
Starting with this lab, we will **no longer** plug the 9V battery straight into the Arduino's Vin pin. Instead, the battery will power a voltage regulator circuit (built by Group B), and that circuit's 5V output will power the Arduino through its 5V pin. Until your power circuit is done, power your Arduino over USB from your computer.
</div>

## Contents

- [Lab 5: Group A Portion](#lab-5-group-a-portion)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Procedure](#procedure)
    - [1. Setup](#1-setup)
    - [2. Calibrating The Accelerometer](#2-calibrating-the-accelerometer)
    - [3. Connecting The BME680](#3-connecting-the-bme680)
    - [4. Modifying The Code](#4-modifying-the-code)

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

## Procedure

### 1. Setup

As mentioned in the introduction, this lab is not going to give you nearly as detailed of instructions as previous labs have. Use your resources and refer to previous labs or references as needed if you are stuck on something!

To start, grab your assembled circuit from Lab 4. You should have a voltage divider, an accelerometer, and a MicroSD Card Adapter Module connected to your Arduino, which is powered via a 9V battery. If anything came loose, re-wire it before moving on.

Next, unplug your 9V battery and remove the jumper going into the Arduino's Vin pin. Nothing should be plugged into Vin from now on.

<div class="primer-spec-callout danger" markdown="1">
Remember that the accelerometer sensor takes 3.3V input, not 5V. Plugging it into 5V can break the sensor or cause other bad and unintended things to happen!
</div>

Then hook your Arduino up to your computer. These next 2 steps will have you doing calibrations on your accelerometer, meaning we will be reading analog values over Serial. Was there a lab (maybe lab 3...) where we had start code to do exactly this that you could repurpose?

<div class="primer-spec-callout info" markdown="1">
**Note:** Later in this lab we will ask for a picture of your finished circuit. Part of the requirements for this circuit are that one side of your breadboard's power rail is for 5V, one is for 3.3V, and both sides should have common ground. Additionally it is required that all power is routed with red jumper cables, all ground with black, and all data with other colors.
</div>

### 2. Calibrating The Accelerometer

To calibrate your accelerometer, you will have to go through the same procedure that you did in lab 3, for all 3 axes of the accelerometer. This means that for each axis, you will need at least 2 known values of acceleration that you can subject the sensor to while reading the voltage.

In order to find 2 known values of acceleration, we must understand what exactly is it that the accelerometer measures. The name "accelerometer" is kind of misleading in this case, since it doesn't actually measure total acceleration. Internally, the sensor has a tiny object (usually silicon) that is connected to the rest of the sensor via a spring-like connection. This connection has electrical properties that change based on the tension that the connection experiences. This is a simplified explanation, but the actual sensors don't differ too much. 

If a force is applied to the outside of the sensor, the tension in the connection increases to keep the small internal object accelerating at the same rate as the sensor. This means that the sensor can only detect acceleration from forces that are applied **only** to the outside of the package, since if a force was applied equally to the internal object, the tension in the connection would not have to increase to keep the object accelerating with the rest of the sensor. Usually this isn't a problem, since most forces we're concerned with are fall into this category, however, there is one major force that doesn't: gravity. Recall from physics that gravity acts in a way that makes all objects accelerate at the same rate ($$9.8\,\frac{m}{s^2}$$). This is the exact type of force that accelerometers cannot measure, since the internal connection does not have to apply any force to the internal object to keep it accelerating with the sensor - in the absence of external forces, everything accelerates at $$9.8\,\frac{m}{s^2}$$.

Now let's try to figure out what the accelerometer would measure in 2 different situations: in free-fall, and sitting stationary on a lab table. Start by drawing a free-body diagram for each situation, and then remove the gravitational force. The acceleration from the remaining forces is what the sensor would measure. In the situation of free-fall, since gravity is the only force (in the absence of air resistance), the acclerometer measures nothing. In the situation of the sensor sitting stationary, the normal force opposes gravity and is exactly equal to the force from gravity. The accelerometer will only measure the acceleration from the normal force, and since the normal force is equal to gravity in this case, it will measure $$9.8\,\frac{m}{s^2}$$, or 1 G, upwards. You will use this fact to calibrate the accelerometer.

Reminder to pay attention to the 3-axis figure printed on the sensor module. When the sensor is flat on the table, the Z-axis should be vertical, and the others will be parallel to the table/ground.

In this orientation, the Z-axis is straight up, and from our previous findings should measure 1G. X and Y are both perpendicular to the force of gravity and would be recording 0Gs. If you turn your board upside down, the Z axis should read -1G. Rotate your sensor around as needed so that each axis has at least two data-points where it is (anti-)parallel to the force of gravity.

With this calibration process completed, each axis will have a calibration value of 1G and -1G. Record these values in your spreadsheet again, and calculate the calibration curve for each axis.

Include your data table for all 3 axes, and your spreadsheet for the calibration of all 3 axes in your lab submission.

### 3. Connecting The BME680

As noted above, the BME680 connects to the Arduino using the same SPI pins as the MicroSD Card Adapter Module. As you learned in Lab 4, both devices share the 3 SPI data pins (11, 12, and 13), but each one needs its **own** chip select (CS) pin so the Arduino can choose which device it is talking to.

Wire the BME680 the same way you did in [Lab 3](/labs/lab-3). If you need a refresher, [the sensor's technical guide has wiring information on **page 12**](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-bme680-humidity-temperature-barometic-pressure-voc-gas.pdf).
<div class="primer-spec-callout danger" markdown="1">
The MicroSD Card Adapter Module and the BME680 should **NOT** connect their CS pins to the same Arduino pin. The MicroSD module uses pin 10, so if you used pin 10 for the BME680's CS in Lab 3, move it to a different digital pin and update `BMEchipSelect` in your code to match.
</div>

### 4. Modifying The Code

Modify either your code or the code given for the previous lab to add your new sensor to the csv the Arduino outputs. You will need to modify the pins defined at the top of the file, and will need to add some column titles to the header string defined above the `setup()` function as well. You will also need to modify the code in `loop()` to include the sensor values in the string added each iteration. The new data from the BME680 will be in the physical units of the corresponding type of measurement (e.g. C for temperature), and not voltage or raw value like your analog data. Check what unit each sensor reads, and make sure it is reflected in the new column titles of your header string.

You already added the BME680 to your Lab 3 code, so use that code (or the BME680-Example sketch in the course library) as a guide for what to add to either your code or the code given for the previous lab.

Upload your code and check the Serial Monitor to make sure the BME680 is reporting sensible values before moving on. If it isn't, double-check your wiring and CS pin.

<div class="primer-spec-callout warning" markdown="1">
When Group B is ready to move on, disconnect all power from both boards. Then take both of your breadboards and move the analog jumpers running from Group B's Arduino (battery, 5V line, and 3.3V line) into free analog pins on your Arduino, so that everything is wired into one microcontroller (you need not physically move the components, but rather just their jumpers, leaving two breadboards side by side. They can lock together!). Then connect a jumper from the 5V rail of Group A to the 5V rail of Group B (do this for the 3.3V rail and the GND rails as well). Note that the numbering of the analog pins does NOT matter. As one last final check, Group B's original Arduino should have nothing plugged into it, so you can remove any jumpers remaining connecting it to power or GND, and nothing should be plugged into your Arduino's Vin pin. The 9V battery now connects only to Group B's power board. Once this is done, follow the link below to jump back into the normal lab manual together.
</div>

- [Groups A & B Lab Manual - Finishing Steps](/labs/lab-5#8-consolidation)
