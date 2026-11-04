---
layout: spec
latex: true
---

# Go / No-Go Testing

Test all critical aspects of the system (rocket and sensor board), showing that both operate as required. Specifically, tests include:

### 1. Bench Test
Validate that the system works while sitting on the workbench and that all sensors are calibrated. 
- Data plots must indicate passing of this test
- Video should show the LEDs indicating when the sensor package is waiting for the time delay and when it is taking data
- If your board has a buzzer, the video should also highlight the buzzer going off at an appropriate time

### 2. Pendulum Test
Attach the sensor board (with battery) to different lengths of strings. Take data while the sensor board swings back and forth. [Tips for the pendulum test.](/project/pendulum)
- Show that the measured 3D acceleration can be used to determine the angle and velocity of the sensor board as it swings
- Show that the period of the pendulum is as expected from an analytical solution

<div class="primer-spec-callout info" markdown="1">
**Note:** If your team is focusing on **simulation**, you should have a simulation of the pendulum that shows that you are getting consistent results between the measurements and the simulations.
</div>

<div class="primer-spec-callout danger" markdown="1">
You should have a sample rate of at least 5 Hz when you are sampling all of the sensors (except the accelerometer) as usual. When performing any tests with the accelerometer specifically (such as this pendulum test) you should have a sample rate of at least 100 Hz. In order to do this, you may need to lower the BME680's gas sensor heating time to allow for faster sampling.
</div>

### 3. Spike Test
Verify that each sensor that you are **utilizing** can detect and respond to a large change in a **small amount of time** (“spike”) in its measured variable. You will need to use some creativity to design and execute your own methods to produce a clear “spike” for each sensor. To create a “spike”:
1. Begin by collecting a few seconds of stable baseline data
2. Perform the chosen action to make the “spike”
3. Let the system return to equilibrium

The goal is to observe how each sensor reacts to large, fast variations and confirm its responsiveness. For each sensor, you must create plots that clearly show a “spike” and explain what you did to get this “spike”.

<div class="primer-spec-callout info" markdown="1">
**Note:** The humidity sensor should be the only one that cannot create a **spike**. Still, we should see a significant change, but not over a short period like the other sensors. It will look more like a hill. **If you chose the humidity sensor, you must explain why the humidity sensor behaves like this in the Go/No-Go Presentation.**
</div>

<div class="primer-spec-callout danger" markdown="1">
You should have a sample rate of at least 5 Hz when you are sampling all of the sensors (except the accelerometer) as usual. When performing any tests with the accelerometer specifically you should have a sample rate of at least 100 Hz. In order to do this, you may need to lower the BME680's gas sensor heating time to allow for faster sampling.
</div>

### 4. Elevator Test
Find a building that is at least 8 stories tall and ride an elevator from the bottom floor to at least the 8th floor. The sensor package must be taking data during the elevator ride and should be placed on the floor so that it is measuring the acceleration of the elevator. There should be at least two stops on the way to the 8th floor, so the stopping and starting can be noted and correlated with the pressure data.
- The pressure must be converted to altitude
- The acceleration should be integrated to be converted to velocity and the velocity integrated to be converted to altitude
- The altitude derived from pressure must be differentiated to convert it to velocity and the velocity differentiated to convert it to acceleration
- Plots need to show the results of this test

### 5. Simulation Test
Show that your rocket with the sensor board incorporated will reach at least 500 ft and will not exceed 1200 ft with one of the recommended motors. The exact motor that your group would like will be specified with this test. Plots will prove that this test passed.

### 6. The Final Test
This is a full dress rehearsal of launch day. It is similar to the bench test, but your rocket and payload should be essentially finished. Record **one continuous video** of your team doing exactly what you will do at the launch site, in the same order, from a powered-off payload to a rocket that is ready to go on the pad.

The video must show:
1. **Powering on the payload** and starting data collection, using the same switch, button, or jumper you will use on launch day.
2. **Confirming the payload is working** before it goes in, using the LEDs (or buzzer) to show that it is waiting for the time delay and then taking data.
3. **Inserting the payload** into the nose cone or payload bay and securing it. This should be quick and should not require any tools, tape, or wiring you won't have at the field.
4. **Preparing the recovery system:** packing the parachute with your chosen method (see [Parachute Packing Research](#parachute-packing-research) below) and stowing it and the shock cord in the body tube. Leave room for recovery wadding below them and point out where it will go (see the note below).

   <div class="primer-spec-callout info" markdown="1">
   **Recovery wadding:** You won't receive wadding until launch day, so you don't need it for this video, but your rocket must have room for it. Wadding is flame-resistant paper that protects the parachute from the hot gases of the motor's ejection charge. On launch day:

   - Wadding goes in **first**, pushed down the body tube so it sits right above the motor mount, between the ejection charge and the parachute
   - Crumple each sheet loosely; it should fill the tube from wall to wall without being packed tight, so the ejection charge can still push everything out
   - The shock cord and parachute go in **on top of** the wadding, and the parachute must never touch the motor end directly
   </div>

5. **Fully assembling the rocket** (nose cone on, everything secured) as if you were about to walk it to the pad.
6. **Confirming the payload is still working** once it is sealed inside the rocket: you should be able to see the LEDs or hear the buzzer without taking the rocket apart.

<div class="primer-spec-callout warning" markdown="1">
**Do not install a motor or igniter for this test.** Everything else should be done exactly as it will be on launch day.
</div>

After filming, take the payload out, pull the microSD card, and show the data that was collected during the video:
- Plot every sensor you are using against time for the whole recording
- Point out the moments from the video in the data (e.g. powering on, inserting the payload, handling the rocket)
- Show that your sample rates meet the requirements above and that no data was lost or corrupted

#### Parachute Packing Research
A parachute that doesn't open will destroy your payload, so the way you pack it matters. Before filming, each team must:
- Research **three different methods** of packing a model rocket parachute
- **Briefly** describe each method with a pro and a con (e.g. how reliably it opens, how much space it takes up, how easy it is to tangle, how quickly it can be packed at the field)
- Explain **which method you chose and why** in a sentence or two
- Cite where you found each method

Use your chosen method in the Final Test video and include this research in your Go/No-Go presentation.

<div class="primer-spec-callout info" markdown="1">
**Keep this short.** The goal is just to see that there is more than one way to pack a parachute and that packing it well matters. This should take some time to research, but not hours, and only needs about **one slide** (under a minute) in your Go/No-Go presentation.
</div>

<div class="primer-spec-callout danger" markdown="1">
All tests need to be presented at the Go/No-Go meeting. Each team must pass all tests before being OKed for launch.
</div>
