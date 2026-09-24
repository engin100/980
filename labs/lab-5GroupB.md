---
layout: spec
latex: true
---

# Lab 5: Group B Portion

Building and testing the 5V and 3.3V LDO power board, and powering an Arduino from it.

<div class="primer-spec-callout danger" markdown="1">
Starting with this lab, we will **no longer** plug the 9V battery straight into the Arduino's Vin pin. Instead, the battery will power the voltage regulator circuit you build below, and that circuit's 5V output will power the Arduino through its 5V pin.
</div>

## Contents

- [Lab 5: Group B Portion](#lab-5-group-b-portion)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Safety](#safety)
    - [Electrostatic Discharge](#electrostatic-discharge)
  - [Procedure](#procedure)
    - [1. Testing the LDOs](#1-testing-the-ldos)
    - [2. Power Supply](#2-power-supply)
    - [3. Battery Power](#3-battery-power)

## Materials

- [ ] 1 Arduino Nano
- [ ] 1 Breadboard
- [ ] 5.0V LDO
- [ ] 3.3V LDO
- [ ] 22 micro-Farad Capacitor
- [ ] Resistors for voltage divider circuit
- [ ] 9V Battery
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] A computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library)
- [ ] ENGR100-950 Arduino Library
- [ ] Completed sensor board from Lab 3
- [ ] ENGR 100 950 KiCAD [libary](https://drive.google.com/drive/folders/1rgl_aX9MQJvx8G1FlQenvKY04iy5qNv3?usp=share_link)

## Safety

This lab involves working with a power supply which can provide higher voltages/currents than the Arduinos! Read the following sections carefully to maintain your safety and the safety of the components we are using.

<div class="primer-spec-callout danger" markdown="1">
It is very easy to accidentally short batteries when wires are connected to them. When not using the 9V battery, make sure that they have wire ends that are taped/secured, so the battery can not be shorted!
</div>

### Electrostatic Discharge

In this lab we will start taking precautions when dealing with electronics as there is possibly of ESDs damaging components. When you eventually start soldering your PCB’s, you will be dealing with much smaller components and will thus absolutely need to take ESD precautions. For the subteam that will be working with the power portion of the lab: whoever is touching and interacting with the circuit will be needing to wear an ESD bracelet at all times.

An ESD bracelet provides your body contact through a conductive element to ground, therefore allowing any static discharge accumulated on your body to be discharged to ground. The blue ESD mats serve a similar purpose, and when using the smaller board to do the power lab please do so on the blue mat.

## Procedure

### 1. Testing the LDOs

Make the circuit below on an (initially) empty breadboard. The power connection is coming from a 9V battery.

![Power Circuit](/media/power-circuit.jpg)

<div class="primer-spec-callout info" markdown="1">
NOTE 1: We have a variety of through-hole LDOs.  They may not match exactly what is specified in the diagram above.  **Google search for the LDOs that you have and verify their voltages and pin out configurations.  It is up to you to get these right!**
</div>

<div class="primer-spec-callout info" markdown="1">
NOTE 2: **The longer lead of the capacitor is the positive end.** This means you should connect the longer lead to the side with a non-zero (non-ground) voltage, and the shorter lead to the ground line.
</div>

<div class="primer-spec-callout info" markdown="1">
NOTE 3: Your system and your battery eventually need to share a common ground for you to get correct voltage measurements. **Electrically connect all GND pins together to the battery’s negative terminal.**
</div>

<div class="primer-spec-callout info" markdown="1">
NOTE 4: **We are now going to disconnect power whenever we rewire components on our breadboard!**
</div>

Use a multimeter to measure the actual outputs of the 5V and 3.3V LDO lines. If the 5V line is not exactly 5V, it can cause errors on the conversions of the sensor data from voltage into actual ”geophysical” units (C, %, g, etc.) You may want to use the reading from the 5V LDO in your calibration calculations.

**Have a staff member check your circuit before you proceed.**

A staff member will work with you on replacing the battery with a power supply.

### 2. Power Supply

The figure below shows a lab **power supply.** This is a device we frequently use in labs to power circuits: sometimes to avoid using the USB cable and a computer for power, and sometimes when we need a higher voltage than can be provided by the Arduino. There are multiple channels on the power supply, to allow for powering more than one device or produce more than one voltage at the same time.

![Power Supply](/media/power-supply.png)

You will be using the power supply on your workbenches today to power portions on your circuit. Please do **NOT** connect the power supply to the board until looked at by one of the instructors. The power supply has been current-limited at 500 mA and can cause some serious damage if used improperly. Please call the instructor to have them examine the breadboard before connecting to power. Also, do not increase the power supply voltage above 10V.

The wires to the power supply should already be connected (Red = positive and Black = negative). Connect the red wire to the positive rail located at the top of the breadboard, and the black wire to the blue rail located adjacent to it. Do not connect them in holes adjacent to one another; we want to remove any possibility of the two wires accidentally coming in contact and shorting the circuit. **Please do not turn on the power supply until your connections have been verified by an instructor.** Please do not adjust the wires connected to the power supply unless the supply is turned off. You can use this rail to power the components of your circuit as illustrated in Part 1 below.

<div class="primer-spec-callout danger" markdown="1">
Do not turn on the power supply until your connections have been verified by an instructor!
</div>

Slowly reduce the voltage on the power supply (you can use the “Coarse” knob but rotate it slowly). Reduce it to 0V in increments of 1V, using a multimeter to record the voltage on the 5V and the 3.3V lines. **Note the power supply voltage at which the 5V line no longer reads 5V and the voltage at which the 3.3V line no longer reads 3.3V.** There will be some variation, so let's assume that once it is more than .15V away from the value it has sufficiently dropped.

**Turn the power supply off!**

### 3. Battery Power

Disconnect the power supply, and add an Arduino to your power board. Make two voltage divider circuits, one hooked up to the Vin pin of the 5V LDO (i.e., this one will measure (half) the battery voltage) and one hooked up to the Vout pin of the 5V LDO (i.e., this should measure (half) 5V). Attach the output pin of the 3.3V LDO to an analog pin on the Arduino also.  You should now be able to make a program that will measure the battery voltage, the 5V line voltage, and the 3.3V line voltage.

**Remember to use color coding for your power lines and data lines. This will dramatically assist you in the debugging of your system if things don't work.**

<div class="primer-spec-callout danger" markdown="1">
Note that the output lines of the 5V and 3.3V lines are now your main power rails.  The 5V LDO output line should be connected directly to the 5V line on the Arduino and there should be NO connections to the Vin pin on the Arduino.  The 3.3V line does NOT get connected to the 3.3V line on the Arduino!
</div>

Once you have verified that everything is hooked up as it should be, add a 9V, battery to the top rail of your bread-board to power your LDO circuit and power on your Arduino. When you connect your battery, everything should turn on and start reporting data (although you can’t see it, since your computer is not hooked up yet).  Hook up the USB to the Arduino and measure the battery voltage, 5V line voltage, and 3.3V line voltage using a program. **Take a screenshot that shows that you are measuring the proper voltages on the different lines!**

**Take some pictures of this beautiful power board!**

<div class="primer-spec-callout warning" markdown="1">
When Group A is ready to move on, disconnect all power from both boards. Then take both of your breadboards and move the analog jumpers running from your Arduino (battery, 5V line, and 3.3V line) into free analog pins on Group A's Arduino, so that everything is wired into one microcontroller (you need not physically move the components, but rather just their jumpers, leaving two breadboards side by side. They can lock together!). Then connect a jumper from the 5V rail of Group A to the 5V rail of Group B (do this for the 3.3V rail and the GND rails as well). Note that the numbering of the analog pins does NOT matter. As one last final check, Group B's original Arduino should have nothing plugged into it, so you can remove any jumpers remaining connecting it to power or GND, and nothing should be plugged into Group A's Vin pin. The 9V battery now connects only to your power board. Once this is done, follow the link below to jump back into the normal lab manual together.
</div>

- [Groups A & B Lab Manual - Finishing Steps](/labs/lab-5#8-consolidation)
