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

<div class="primer-spec-callout danger" markdown="1">
All tests need to be presented at the Go/No-Go meeting. Each team must pass all tests before being OKed for launch.
</div>
