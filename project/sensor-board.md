---
layout: spec
latex: true
---

## Contents

- [Sensor Board Documenation](#sensor-board-documentation)
    - [Sensor Pin Connections](#sensor-pin-connections)
    - [Board Example](#board-example)
    - [Standard Operation](#standard-operation)
    - [Hardware Remarks](#hardware-remarks)
        - [Assembly Tips](#assembly-tips)
        - [Technical Drawing](#technical-drawing)
    - [Sensor Board Files](#sensor-board-files)
    - [Component Spec Sheets](#component-spec-sheets)
    - [Next Steps](#next-steps)

# Sensor Board Documentation

Because you are going to be using the sensor board that the staff designed for your project, we thought it would be best to also give you some documentation on the board.

## Sensor Pin Connections

Here is the schematic for the rocket boards. Take note of voltages, resistance values, etc. **Take note of what sensor is connected to which Arduino pin as it may be different from what is currently in your code, and may require updates.**

![Rocket Board Schematic](/media/Rev2%20Schematic.png)

## Board Example
<div class="primer-spec-callout danger" markdown="1">
READ THIS VERY CAREFULLY: Make sure that you ADD **headers** to the arduino. Other than this, your PCB board should look identical to the example below. The SD Card can be soldered on directly to the board as seen on the example below.
</div>
![PCB1](/media/pcb1.jpeg)
![PCB2](/media/pcb2.jpeg)
![PCB3](/media/pcb3.jpeg)
![PCB4](/media/pcb4.jpeg)
![PCB5](/media/pcb5.jpeg)

## Standard Operation
When fully assembled, the rocket board records various sensor measurements and drives 5 LEDs. The device draws power from a battery, connected to the JST connector. Power is controlled by the SMD switch. 

When the device is powered on via that switch, it's in a "ready" mode. In order to actually _begin_ data collection, you must pull pin D2 to ground briefly. This tells the Arduino that it's time for launch. You'll find holes for D2 and GND labelled J1. How should you do this? It's up to your team! You can solder a button onto wires going to the board, make a spot to put a small jumper wire, whatever you want (within reason, of course). The only requirement is that you must be able to start recording data while the board is packed away inside the rocket. Ensuring that no wires are loosely hanging off your rocket during launch isn't a requirement, but this could tangle your parachute or cause other issues. (Tape will be your friend here)

Just like in lab, the data will be saved to an SD card. Nothing special there.

## Hardware Remarks

### Assembly Tips
Now that you can see how everything goes together, let's look at a few important details to remember:

1. Solder female headers in for the accelerometer, BME680, and Arduino. If space allows, do this for the SD logger as well (most likely not...).
2. You cannot mix around the LED positions without paying very close attention to the current limiting resistors. If you solder the wrong resistor value to an LED it will do one of two things: be too bright and burn out, or dim and not visible. We highly recommend reading carefully over the locations of the LEDs, and making sure of their positions before soldering anything. We will NOT be replacing LEDs that get burnt out due to mismatched positions.

<div class="primer-spec-callout danger" markdown="1">
READ THIS VERY CAREFULLY: All 5 LEDs have the same footprint, symbol, style, etc. They are made by the same manufacturer, they are even in the same product line with consecutive part numbers. BUT they do not necessarily have the same indications for positive and negative (anode/cathode) sides. For every individual LED you must carefully check the datasheet to confirm its correct orientation, and do not assume it will be the same as the others (because they are not...). The datasheets for every part you are working with is included below in the resources section.
</div>

### Technical Drawing
In the figure below you'll find the schematic of the inner copper layers and edge cuts.

![Rocket Board Inner Copper](/media/inner_copper.png)

## Sensor Board Files

<a href="../sensor-board/Rocket Boards_rev2.step" download>3D STEP File</a>

<a href="../sensor-board/Rocket_Boards_-_Rev2.zip" download>Production .zip</a>

<a href="../sensor-board/Rev2 Schematic.pdf" download>Schematic</a>

<a href="../sensor-board/Rocket Boards_rev2 Drawing v1.pdf" download>Technical Drawing</a>

<a href="../sensor-board/bom.csv" download>Bill of Materials</a>

# Component Spec Sheets

<a href="../components/ABX00033.pdf" download>Arduino Nano</a>

<a href="../components/ADXL335.pdf" download>ADXL335 - Accelerometer</a>

<a href="../components/bme680.pdf" download>BME680</a>

[Link to BME680 Arduino Library Documentation](https://adafruit.github.io/Adafruit_BME680/html/class_adafruit___b_m_e680.html)

<a href="../components/buzzer.pdf" download>Buzzer</a>

<a href="../components/slide-switch.pdf" download>Slide Switch</a>

<a href="../components/SM1206NAC-IL.pdf" download>Amber LED</a>

<a href="../components/SM1206NBWC-IL.pdf" download>Blue LED</a>

<a href="../components/SM1206NHC-IL.pdf" download>Red LED</a>

<a href="../components/SM1206NPGC-IL.pdf" download>Green LED</a>

<a href="../components/SM1206NYC-IL.pdf" download>Yellow LED</a>

[Link to SD Logger Documentation](https://github.com/adafruit/MicroSD-breakout-board)

# Async for BME680
Everytime the BME680 does a reading, it blocks all other inputs from happening. This causes a delay between 300 ms - 500 ms. To fix this we have to use async functions.

An async function is a type of function in programming that allows for asynchronous operations, meaning it can perform tasks without blocking the execution of other code.

The three main functions that you will need to use are `beginReading()`, `endReading()`, and `remainingReadingMillis()`. You can read the documentation of these functions [here](https://adafruit.github.io/Adafruit_BME680/html/class_adafruit___b_m_e680.html#:~:text=member%20variables.%20More...-,uint32_t%C2%A0,has%20started%2C%20%2D1%20or%20Adafruit_BME680%3A%3Areading_not_started.%20Does%20not%20block.%20More...,-Public%20Attributes)

You will have to do something along these lines

```cpp
bme.beginReading();
if(bme.remainingReadingMillis() == 0){
    bme.endReading();
    //print out any sensor values or add to datastring, up to you
    //you can get the specific values you want by doing
    //bme.temperature, bme.pressure, bme.humidity, bme.gas_resistance
}
else{
    //do nothing or whatever you want
}
```

In words, this code:
1. Starts an async function, `beginReading()`.
2. Checks if the async function is done by checking if `remainingReadingMillis()` equals 0.
3. If it is done, we end the reading using `endReading()`, which defines all environment variables (temperature, pressure, humidity, and gas_resistance). Optionally, you would print the values out to the SD logger, store it into the data string, or just set them equal to a variable that you can then use later on. Totally up to you how you approach this!
4. If it is not done, then we do nothing or whatever you want, we just want to be able to move down and read the other sensor values. 

This makes your code non-blocking for the BME680 functions.

# Next Steps
1. Assemble the board!
2. Figure out how you'll mount it within your rocket
3. Figure out how you'd like to collect data using Arduino IDE

<div class="primer-spec-callout danger" markdown="1">
As always, don't hesitate to reach out to the IAs if you need help, or have any questions! If you do **NOT** plan accordingly, this class can get overwhelming. **Office hours and slack are your best friends**
</div>