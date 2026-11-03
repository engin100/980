---
layout: spec
latex: true
---

# Pendulum Test Tips
The pendulum test can be one of the more difficult tests to get meaningful data from and properly analyze, so this page contains some tips and tricks to help your team be successful.

## Setup And Collecting Data
Before collecting any data, make sure your board is setup and mounted well.
- Make sure the code running on your board is collecting acceleration data at least 100 times per second (100Hz). More is better, but any less than this and your data won't make much sense.
- However you mount your board and battery to the string, make sure it's not off balance. The two holes on the PCB are there for you to put the string through as an easy way to mount the board.
- Once your board is hanging by itself with the battery mounted, make sure it's not spinning. The more stable it appears to hang, the better. Try pulling the board back roughly 10&deg; - 20&deg; and letting it swing. Does it spin in the air or is it stable?

Now start the data collection and let it swing at around 10&deg; - 20&deg;. Collect data from at least 2 periods of oscillation, then stop the collection, and repeat. It's hard to know if the data from a particular attempt will be good, so collect a couple attempts before moving on to analysis. Record the distance from the attachment point of the string to the center of mass of your board (the pendulum length). Also, before doing any analysis, make sure to crop your data to when the oscillations start and end, shift your time so that $t = 0$ occurs when the oscillations start, and convert your time to seconds.

## Analysis
### The Physics
There are two main forces acting on the board as it swings: gravity and the tension from the string. Remember from lab 5 that the accelerometer does not measure the true acceleration from gravity, so your accelerometer data will only represent the acceleration from the tension in the string. Also notice that since the board rotates as it swings, the force from tension always acts along the same direction of the board, so the data you're interested in only comes from one axis (it should be obvious which axis it is from the data). Now, if you try to solve for your angle or velocity from only the tension in the string, you will find that it's impossible (I encourage you to try). The missing piece of information is something about the system (the board + string) at a known point. There are a couple options here: you can find the acceleration at the maximum angle (the furthest point that the board swings) or the acceleration at the minimum angle (straight down). The equations later in the page use the acceleration at the minimum angle (the bottom of the swing) - this corresponds to the maximum acceleration.

### Fitting The Data
The first step in the analysis is to find a good fit to your data. You are free to use whatever software or tool you would like (or even code something), however note that this is very similar to what you saw in the [second in-class exercise](https://umich.instructure.com/courses/857075/assignments/3253295). A good place to start is to try to fit your data to that of a simple oscillation:

$$a(t) = A\cos(\omega t + \phi)$$

Or possibly a damped oscillation:

$$a(t) = B + Ce^{-bt} \cos(\omega t + \phi)$$

($$\omega$$ is the angular frequency of oscillation in radians per unit time, $$\phi$$ is a constant phase offset to account for differences in data, $$A$$ is the simple oscillation amplitude, and $$Ce^{-bt}$$ models the diminishing amplitude over time due to damping)

The goal of this step is just to extract an oscillation frequency and an equation for how the maximum acceleration varies (or doesn't) with time.

### Oscillation Frequency
Compare the $$\omega$$ from your fit to the theoretical frequency or period of a pendulum (look this up online). Be consistent with units. Note that $$\omega$$ is twice the frequency of your pendulum since the accelerometer cannot distinguish between the back and forth swings, while the definition of the frequency of a pendulum does. Also, when the calculating the theoretical frequency/period, remember that the length in this case is the distance from where you attached the string to a stationary object, to the center of mass of the board. An easy way to find the center of mass of your board is to figure out where the board balances on a thin object (like a ruler on its side).

### Angle And Velocity
The angle is related to your acceleration data by this equation:

$$1+\frac{a(t)-a_m(t)}{3g}=\cos(\theta(t))$$

where $$a_m(t)$$ is the maximum acceleration (remember you found this earlier from finding a fit to your data), which may or may not vary with time depending on if your fit was that of a simple oscillation or a damped oscillation. $$a(t)$$ is acceleration and $$\theta(t)$$ is the positive angle from the vertical.

Try flipping every other cycle to be negative to get a nice sine/cosine curve of your angle. _Hint: Use the sign of_ $$\cos(\omega t + \phi)$$ _from your fit with half the frequency and an adjusted phase shift._

Velocity is left for you to figure out :), good luck!