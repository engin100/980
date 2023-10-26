---
layout: spec
latex: true
---

# Sensor Board Documentation

Because you are going to be using the sensor board that the staff designed for your project, we thought it would be best to also give you some documentation on the board, including key directions for LEDs and your software. 

## Schematic

This schematic outlines how everything is traced out on the board. Take note of what sensor is connected to which Arduino pin as it may be different from what is currently in your code. 
![Rocket Board Schematic](/media/rocketBoardSch.jpg)

_Figure 1: Sensor Board Schematic_

Note the different connection colors: magenta for analog, dark blue for SPI/SD card, light blue for +9V, and green for the LEDs (and ground... forgot to change that one)

## Board Specific Things

Now that you can see how everything goes together, let's look at a few important details to remember:

1. For the battery connector, BT1, the positive terminal goes in the square outlined pin, while the negative terminal goes in the circular outlined pin (with the white silkscreen square around it)
2. For the 6 LEDs, the negative pin of the LED goes in the square outlined pin, or the bottom row if you have the switch at the bottom like in Figure 2.
3. Although the pressure sensor is marked P1 on the top layer, we reccomend putting the sensor on the bottom layer. Again, look at Fig. 2 to see which pin is #1 (the marked pin on the pressure sensor)
4. Looking at the buzzer, you should notice a + and - directly above the footprint. This corrosponds with a + on the buzzer. 
5. Solder the Arduino and SD card reader directly to the board, and then use headers for the pressure sensor and accelerometer.

![Rocket Board Layout](/media/Rocket%20Board%20Markup.jpg)

_Figure 2: Rocket Board Diagram_

Everything else should be labeled in such a way that you can deduce the orientation of the component. As always, don't hesitate to reach out to Prof. Ridley or the IAs (Jack will probably give you the best answer, he designed the board) if you need help!