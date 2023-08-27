---
layout: spec
latex: true
---

# Lab 1: Arduino 101

## Contents

- [Lab 1: Arduino 101](#lab-1-arduino-101)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Introduction](#introduction)
  - [Procedure](#procedure)
    - [1: The Breadboard](#1-the-breadboard)
    - [2: LED Blink](#2-led-blink)
    - [3: Voltage Divider](#3-voltage-divider)
  - [Post-Lab Questions](#post-lab-questions)
  - [Submission](#submission)

## Materials

For this lab, you will need:

- [ ] 1 Arduino Nano
- [ ] 1 Breadboard
- [ ] 1 Programming Cable (and adapters if necessary)
- [ ] 9 LEDs
- [ ] 3 1k$$\Omega$$ resistors
- [ ] 3 2k$$\Omega$$ resistors
- [ ] 3 7.5k$$\Omega$$ resistors
- [ ] 3 10k$$\Omega$$ resistors
- [ ] A computer with the Arduino IDE [installed](/tutorials#arduino-ide-install) and [setup](/tutorials#arduino-library).

## Introduction

Welcome to ENGR100-950! Over the course of the next semester, you will be designing and building your own circuit board, complete with measurement instruments to gather information on all sorts of atmospheric data. To get to that point, we will spend the first couple labs learning about various components and eventually how to combine them into a cohesive system.

In lecture, you've had a crash course on the ins and outs of micro-controllers. Now, you'll be working with your own **Arduino Nano** micro-controller so you can begin to learn how to use it. The Nano will be the brain of your payload; it is very well-suited to these sorts of applications, as you will see.

![Arduino Nano pinout](https://docs.arduino.cc/static/aea75b21cea87290ef2ed4e783b336ef/A000005-pinout.png)

The **IO pins** on the Nano each serve different purposes. Above, and in [resources](/resources#arduino-nano-pinout), is a helpful diagram detailing the types of pins on the board.

*[IO]: Input/Output

In general, the digital pins are on one side (D2 - D13), and the analog pins are on the other (A0 - A7). Digital pins only read and write binary values - HIGH (5V) or LOW (0V). Analog pins can also write these binary values. However, analog pins can read more than just binary values. They read a range of analog values from 0V - 5V. An analog pin reads the voltage that it "sees" on the circuit or sensor you connect it to.

Finally, it's worth noting the GND pin. Voltage values are read with respect to some constant reference. They are relative, not absolute. This reference is usually called 'Ground.' There should ALWAYS be a ground connection on every circuit you make, whether you are using a micro-controller or not. This is essential when dealing with electricity, to make sure that things don't spark or get fried because they draw too much power.

To illustrate, consider the simple LED circuit shown below, where a 5V supply powers a bulb, which is attached to GND. The two circuits shown are actually equivalent representations of the same thing. In the circuit on the left, the 5-volt battery raises the top half of the loop 5 volts higher than the bottom half. The bottom half of the loop is held at zero volts, since it is grounded. Current flows clockwise from the positive (top) to the negative (bottom) terminals of the battery.

In the circuit on the right, the top node is held at 5V by some unseen source, and the bottom is held at 0V because it is grounded. The current flows down, into the grounded node. This representation works great if you want to analyze a fragment from a larger circuit.

![Grounding circuit schematic example](../media/ground-example.png){: .invert-colors-in-dark-mode }

## Procedure

### 1: The Breadboard

### 2: LED Blink

### 3: Voltage Divider

## Post-Lab Questions

## Submission

