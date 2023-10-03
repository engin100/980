---
layout: spec
latex: true
---

# Lab 8: Terminal Velocity and Drop Tests

## Contents

- [Lab 8: Terminal Velocity & Drop Tests](#lab-8-terminal-velocity-and-drop-tests)
  - [Contents](#contents)
  - [Resources](#resources)
  - [Introduction](#introduction)
  - [Procedure](#procedure)
    - [Setup](#setup)
    - [Parachute Trials](#parachute-trials)
    - [Streamer Trials](#streamer-trials)
    - [Computations](#computations)
  - [Submission](#submission)

## Resources

<div class="primer-spec-callout danger" markdown="1">
Although you have been given teams, this lab is done in partners and submitted individually. Break into groups of two (your partner may be in your assigned team, but this is not required) and gather data together. You should both submit separate PDFs.
</div>

- [ ] Scale (kg)
- [ ] Measuring tape (at least 45")
- [ ] 1 - Parachute
- [ ] 1 -  45" Strip of Streamer (3" Wide Caution Tape)
- [ ] 3 - Binder Clips
- [ ] Stopwatch, camera, or other timing method
- [ ] **Optional:** A fitness watch to track the large number of stairs you're going to climb...

## Introduction

Galileo Galilei, a 16th century astronomer, philosopher, mathematician, and central figure in the Scientific Revolution of the 17th Century, once wrote that, in the absence of resistance caused by air, a hammer and a feather would fall at the same rate. His claim was verified centuries later on the moon by the crew of Apollo 15, which is also known as the all-UMich Apollo astronaut crew. You can watch the demonstration in the video [Hammer vs Feather - Physics on the moon](https://youtu.be/KDp1tiUsZw8?feature=shared).

This phenomena is not random, and is instead due to drag forces. While we know that the acceleration due to gravity is constant for all object, we also know that not all objects fall at the same rate, even if it seems they should. This is because of drag force, which is related to properties of the object as well as the cross-sectional area of the object. Terminal velocity is the maximum speed an object can reach while in free-fall. Historically, we have used this to our advantage with the use of parachutes to lead to safe fall speeds for things like payloads, or even humans.

[![The Drag Equation](https://www1.grc.nasa.gov/wp-content/uploads/drageq-1-scaled.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/drag-equation/)

- The density mentioned is the density of the fluid the object is moving through. In the case of free-fall, it's air's density. The reference area is the cross-sectional area of the object with regard to its movement; in the graphic above, it's the area as you look at the plane from the front, like this:

[![Reference Area](https://www1.grc.nasa.gov/wp-content/uploads/sized.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/size-effects-on-drag/)

In the case of an object attached to a parachute, we can consider the object as a projectile with no thrust and starts from a y-position of greater than 0. We also need to incorporate drag force into our standard projectile equations to help us determine when the object will reach its terminal velocity. We have provided a [starter spreadsheet](https://docs.google.com/spreadsheets/d/1i1tA8Tf3p17-aFP-UT3sTd0ahJDdGCRagowuNc-9yh4/edit?usp=sharing) that integrates these concepts of drag and terminal velocity.

Terminal velocity is when the drag force is equal to the weight of the object, as noted below:

[![Terminal Velocity](https://www1.grc.nasa.gov/wp-content/uploads/termv.jpg)](https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/termvel/)

- For Cd, you should look up typical values for parachutes and play around with it. There will be variations, so find which coefficients get you closest to your experimental values!

- For mass and cross-sectional area, you will measure both of these as part of your experimental setup. Since parachutes have the cross-sectional area of a circle, you can calculate the area using standard circle equations. Keep in mind that when you measure the circle's diameter on a flat surface, it is not the same as when it is falling and looks more like a hemisphere! Keep this in mind when doing your calculations.

  - Think about the difference between a half-circumference of a sphere and the radius of the sphere. Drawing this in 2D may help.

- The density of air is typically 1.29 $ \frac{kg}{m^3} $.

## Procedure

### Setup

1. Measure your parachute's diameter and calculate its area. Store this value in the spreadsheet.

2. Record your parachute's mass (with the army guy) and record this value in the spreadsheet.

3. Measure ***ONE*** binder clip and record this mass in your spreadsheet.

4. Measure the mass of your 45" roll of streamer tape and record this value in the spreadsheet.

<div class="primer-spec-callout warning" markdown="1">
For consistency, measure the mass of one binder clip and for each iteration with a different total mass, make sure to use the same kind and size of binder clip. Then you can simply multiply the number of clips and add the mass of the parachute for each iteration to find the total mass rather than re-weighing the entire system for every trial.
</div>

### Parachute Trials

To start, we are going to measure the terminal velocity of your parachute setup with two separate mass configurations, and create a similar plot to your sensor calibration curves. We have created a [spreadsheet](https://docs.google.com/spreadsheets/d/1AUMeqXp-Q7AxpnpcWtZtmy4o5fRdKY107KgAZXwz7kc/edit?usp=sharing) for you to record your values in.

- Go to the robotics building across the street. Send one partner to the top floor and the other should remain on the ground floor.

- Prepare your parachute by attaching a single binder clip to the army guy.

- Drop the parachute and have the partner on the ground take a video of the parachute as it falls.

  - You can look frame-by-frame to pull timestamps and record the number of seconds until the object reaches the top of the second floor and then the ground.

  - **Note:** The top of the second floor refers to the height of the ceiling above someone walking on floor two.

- Repeat this with all three binder clips attached to the parachute, recording the total masses and timestamps for both trials in your spreadsheet.

### Streamer Trials

Next, we are going to perform similar trials using streamers. The concept of streamers is similar... but different... from parachutes. The object of streamers is to make a strip of material (often mylar in model rocketry) flap around in the wind and expose as much of its surface area to the air it's travelling through. Parachutes have a property of "catching" the air and allowing it to spill over its edges creating drag while also maintaining a steady attitude. Streamers, on the other hand, create enough drag to keep the object falling in a constant orientation, but don't provide nearly as much drag. We will observe this in the following procedure.

- Remaining on the top floor of the robotics building, unroll your caution tape so you have 45" exposed. Clip one binder clip to the bottom and perform the drop test as before.

  - Mark these values in your spreadsheet, noting the mass of the system, and the timestamps as before.

- Repeat this two more times with the same mass, but changing the length of your exposed streamer to 30" and 15" by rolling it up and clipping it together.

- Repeat these three trials again but with all three of your binder clips attached to the streamer to express the difference that mass can make in your terminal velocities.

  - Again, record all of these values in your spreadsheet, taking note of mass and timestamps.

### Computations

- With all of your trials completed and recorded in your spreadsheet, calculate the terminal velocity of each trial in the provided column. HINT: The height of the top of the second floor, the time it takes to reach the second floor, and the time it takes to reach the ground are particularly helpful in this calculation.

- Plot three graphs showing the folliwing:

  - Parachute trials denoting terminal velocities vs your varying mass.

  - Streamer trials denoting terminal velocities vs your varying length of streamer for your **first** weight (one binder clip)

  - Streamer trials denoting terminal velocities vs your varying length of streamer for your **second** weight (three binder clips)

### Post-Lab Questions

1. Why do we have you record the time it takes our objects to travel from the second floor to the ground? Why wouldn't you want to record time from the initial height?

2. Plot your experimentally determined terminal velocities along with the theoretical terminal velocity calculated in the spreadsheet and the analytically calculated terminal velocities from your terminal velocity equation for your varying parameter. (Hint: create a small table of these projected values as you vary your parameter. You will have three different lines on the plot!)

3. Is the terminal velocity with a parachute proportional to mass? How about for streamers?

4. With your answers to these questions in mind, for a rocket of 6 oz mass, what mode of drag is best? Consider factors such as time spent in the air, and speed with which the rocket will impact the ground!

## Submission

<div class="primer-spec-callout danger" markdown="1">
Although you have been given teams, this lab is done in partners and submitted individually. You and your partner should both submit separate PDFs.
</div>

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] Screenshots of your three plots: parachute trials, streamer trials with one mass, and streamer trials with the other mass.
- [ ] The answers to the post-lab questions.

To put said content into a PDF, it is suggested you create a new Google Doc ([docs.new](https://docs.new)) and paste your images and write any text in the document. Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE OR SPREADSHEET FILES.**

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>

#### Separately:

- [ ] Upload your memo as a PDF to the **Memo 2** assignment on Canvas. This memo is a completely separate submission from the PDF you turn in for this lab. Take a look at the [memo guidelines](https://980.engr100.org/labs/memo-guidelines) page for this lab for help.
