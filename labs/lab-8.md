---
layout: spec
latex: true
---

# Lab 8: Terminal Velocity and Drop Tests

## Contents

- [Lab 8: Terminal Velocity & Drop Tests](#lab-8-terminal-velocity-and-drop-tests)
  - [Contents](#contents)
  - [Materials](#materials)
  - [Introduction](#introduction)
  - [Procedure](#procedure)
    - [Setup](#setup)
    - [Parachute Trials](#parachute-trials)
    - [Computations](#computations)
  - [Submission](#submission)

## Materials

- [ ] Scale (kg)
- [ ] Measuring tape / ruler
- [ ] 1 Parachute (all groups will use the same size)
- [ ] 4-5 Figurines
- [ ] Stopwatch, camera, or other timing method
- [ ] **Optional:** A fitness watch to track the large number of stairs you're going to climb...

## Introduction

Galileo Galilei, a 16th century astronomer, philosopher, mathematician, and central figure in the Scientific Revolution of the 17th Century, once wrote that, in the absence of resistance caused by air, a hammer and a feather would fall at the same rate. His claim was verified centuries later on the moon by the crew of Apollo 15, which is also known as the all-UMich Apollo astronaut crew. You can watch the demonstration in the video [Hammer vs Feather - Physics on the moon](https://youtu.be/KDp1tiUsZw8?feature=shared).

This phenomena is not random, and is instead due to drag forces. While we know that the acceleration due to gravity is constant for all objects, we also know that not all objects fall at the same rate, even if it seems they should. This is because of drag force, which is related to properties of the object as well as the cross-sectional area of the object. Terminal velocity is the maximum speed an object can reach while in free-fall. Historically, we have used this to our advantage with the use of parachutes to lead to safe fall speeds for things like payloads, or even humans.

[![The Drag Equation](https://www1.grc.nasa.gov/wp-content/uploads/drageq-1-scaled.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/drag-equation/)

- The density mentioned is the density of the fluid the object is moving through. In the case of free-fall, it's air's density. The reference area is the cross-sectional area of the object with regard to its movement; in the graphic above, it's the area as you look at the plane from the front, like this:

[![Reference Area](https://www1.grc.nasa.gov/wp-content/uploads/sized.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/size-effects-on-drag/)

In the case of an object attached to a parachute, we can consider the object as a projectile with no thrust that starts from a y-position of greater than 0. We also need to incorporate drag force into our standard projectile equations to help us determine when the object will reach its terminal velocity.

Terminal velocity is when the drag force is equal to the weight of the object, as noted below:

[![Terminal Velocity](https://www1.grc.nasa.gov/wp-content/uploads/termv.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/termvel/)

- For Cd, you should look up typical values for parachutes and play around with it. There will be variations, so find which coefficients get you closest to your experimental values!

- For mass and cross-sectional area, you will measure both of these as part of your experimental setup. Since parachutes have the cross-sectional area of a circle, you can calculate the area using standard circle equations. Keep in mind that when you measure the circle's diameter on a flat surface, it is not the same as when it is falling and looks more like a hemisphere! Keep this in mind when doing your calculations.

  - Think about the difference between a half-circumference of a sphere and the radius of the sphere. Drawing this in 2D may help.

- The density of air is typically 1.29 kg/m^3.

## Procedure

### Setup

1. Measure the parachute's area and record the value in the spreadsheet given below.

2. Measure the mass of the payload you are carrying for each iteration. (1, 2, 4-5 figurines).

3. Measure the mass of the parachute with one figurine attached (as given).

### Parachute Trials

<div class="primer-spec-callout info" markdown="1">
Note: The distance from the floor to the ceiling of the second floor is: 10' 6".
Imagine you are on the ground. If you walk up one set of stairs the ceiling above your head is this height^.
</div>

We are going to measure the terminal velocity of your parachute with three different mass configurations, and create plots of terminal velocity vs mass. We have created a [spreadsheet](https://docs.google.com/spreadsheets/d/1g0C3GjiIXb2twbJVo77Gfwd3KZr_5--W4aGh4ZKWDxo/edit?usp=sharing) for you to record your values in. The sheet is laid out as a 1x3 matrix: one parachute area paired with the three payload masses you will test.

- Go to the Robotics building across the street. If you have three team members present, designate one as the person transporting the system back up the stairs between trials, one as the dropper, and one as the recorder. Additional members can work on the Altium lab or aid in the drop tests.

- Prepare your parachute by flattening it out a little such that it isn't crumpled.

- Drop the parachute and have the partner on the ground take a video of the parachute as it falls.

  - You can look frame-by-frame to pull timestamps and record the number of seconds until the object reaches the top of the second floor and then the ground.

  - **Note:** The top of the second floor refers to the height of the ceiling above someone walking on the second floor.

- Repeat this with 2 and 4-5 figurines attached to the parachute, recording the total masses and time differences for all trials in your spreadsheet.

### Computations

- With all of your trials completed and recorded in your spreadsheet, calculate the terminal velocity of each trial in the provided column. HINT: The height of the top of the second floor, the time it takes to reach the second floor, and the time it takes to reach the ground are particularly helpful in this calculation.

- Produce two graphs with the following:

  - Plot the three experimental trials on the same graph. The y-axis will be terminal velocity and the x-axis will be mass. Be sure to label your axes clearly and include the measured parachute area in the graph title or caption.

  - Repeat this same plot again but with the theoretically determined terminal velocities for the same masses.

## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] Screenshots of the two plots made above.

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>

#### Separately:

- [ ] Upload your memo as a PDF to the **Memo 2** assignment on Canvas. This memo is a completely separate submission from the PDF you turn in for this lab. Take a look at the [memo guidelines](https://980.engr100.org/labs/memo-guidelines) page for this lab for help.


