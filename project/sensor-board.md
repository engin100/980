---
layout: spec
latex: true
---

# Sensor Board Documentation

Because you are going to be using the sensor board that the staff designed for your project, we thought it would be best to also give you some documentation on the board, including key directions for LEDs and your software. 

## Sensor Pin Connections

This table outlines how everything is connected on the circuit board. **Take note of what sensor is connected to which Arduino pin as it may be different from what is currently in your code, and may require updates.**

|Sensor/Component Pin | Arduino Pin |
|:-----------|:-------------:|
|Data logging on/off|D2 |
|Buzzer |D3|
|LED1 (D1) | D4|
|LED2 (D2) | D5|
|LED3 (D3) | D6|
|LED4 (D4) | D7|
|LED5 (D5) | D8|
|LED6 (D6) | D9|
|SD - CS| D10|
|SD - MOSI| D11|
|SD - MISO| D12|
|SD - SCK| D13|
|Pressure Sensor| A0|
|Accel - X| A1|
|Accel - Y| A2|
|Accel - Z| A3|
|Extra Sensor| A5|
|Battery Voltage Div. Measurement| A6|
|TMP36| A7|

## Standard Operation
When fully assembled, the rocket board records various sensor measurements and drives six LEDs. The device draws power from a battery, connected to the JST connector (PN: B2B-PH-K-S). Power is controlled by the attached switch (SW1). 

When the device is powered on via that switch, it's in a "ready" mode. In order to actually _begin_ data collection, you must connect pin D2 to ground briefly. That tells the Arduino that it's time for launch. You'll find holes for D2 and GND labelled SW2. How should you do this? It's up to your team! You can solder a button onto wires going to the board, make a spot to put a small jumper wire, whatever you want (within reason, of course). The only requirement is that you must be able to start recording data while the board is packed away inside the rocket. Ensuring that no wires are loosely hanging off your rocket during launch isn't a requirement, but this could tangle your parachute or cause other issues. (Tape will be your friend here)

Just like in lab, the data will be saved to an SD card. Nothing special there. 

## Hardware Things

### Assembly Tips
Now that you can see how everything goes together, let's look at a few important details to remember:

1. Put a piece of electrical tape over the solder joints that go below the SD card module so that nothing short circuits on the SD card module.
2. Solder female headers in for the pressure sensor and accelerometer.
3. For each of the 6 LEDs, the hole with the **square border** is for the negative pin, which is the shorter of the pins on the LED. 
4. Although the pressure sensor is marked P1 on the top layer, we reccomend putting the sensor on the bottom layer. Again, look at Fig. 1 to see which pin is #1 (the marked pin on the pressure sensor)
5. Looking at the buzzer, you should notice a + and - directly above the footprint. This corrosponds with the symbol on the buzzer. 
6. Solder the SD card reader and Arduino directly to the board, and then use headers for the pressure sensor and accelerometer. 

![Rocket Board Layout](/media/Rocket%20Board%20Markup.jpg)

_Figure 1: Rocket Board Diagram_

Everything else should be labeled in such a way that you can deduce the orientation of the component. 

### Technical Drawing
In Fig. 2, you'll find the technical drawing of the board. Note that the three mounting holes are 2mm in diameter. That will be important when figuring out how to secure the board in your rocket!

![Rocket Board Drawing](/media/rocketboarddrawing.png)

## Things your team needs to do:
1. Assemble the board!
2. Figure out how you'll mount it within your rocket
3. Figure out how you'd like to 

As always, don't hesitate to reach out to Prof. Ruf or the IAs (Jack will probably give you the best answer, he designed the board) if you need help, or have any questions!