---
layout: spec
latex: true
---

# Pendulum Test Tips
The pendulum test can be one of the more difficult tests to get meaningful data from and properly analyze, so this page contains some tips and tricks to help your team to be successful.

## Setup And Collecting Data
Before collecting any data, make sure your board is setup and mounted well.
- Make sure the code running on your board is collecting acceleration data at least 100 times per second (100Hz). More is better, but any less than this and your data won't make much sense.
- However you mount your board and battery to the string, make sure it's not off balance. The two holes on the PCB are there for you to put the string through as an easy way to mount the board.
- Once your board is hanging by itself with the battery mounted, make sure it's not spinning. The more stable it appears to hang, the better. Try pulling the board back roughly 10&deg; - 20&deg; and letting it swing. Does it spin in the air or is it stable?

Now start the data collection and let it swing at around 10&deg; - 20&deg;. Collect data from at least 2 periods of oscillation, then stop the collection, and repeat. It's hard to know if the data from a particular attempt will be good, so collect a couple attempts before moving on to analysis. Also, before doing any analysis, make sure to clip your data to when the oscillations start and end, shift your time so that $t = 0$ occurs when the oscillations start, and convert your time to seconds.

## Analysis
### The Physics
There are two main forces acting on the board as it swings: gravity and the tension from the string. Remember from lab 5 that the accelerometer does not measure acceleration from gravity, so your accelerometer data will only represent the acceleration from the tension in the string. Also notice that since the board rotates as it swings, the force from tension always acts along the long direction of the board, so the data you're interested in only comes from one axis (it should be obvious which axis it is from the data). Now, if you try to solve for your angle or velocity from only the tension in the string, you will find that it's impossible (I encourage you to try). The missing piece of information is something about the system (the board) at a known point. There are a couple options here, you can find the acceleration at the maximum angle or the acceleration at the minimum angle. The equations later in the page use the acceleration at the minimum angle (the bottom of the swing) - this corresponds to the maximum acceleration.

### Fitting The Data
The first step in the analysis is to find a good fit to your data. Use whichever software you are most comfortable with, I recommend using Matlab or Python since this is a little too complicated for Excel or Google Sheets. Matlab can be difficult to use if you've never used it before so ask an IA if you need help. Fit your data to that of a damped oscillation: 

$$a(t) = A + Ce^{-\gamma t} \cos(\omega t + \phi)$$

where $$\omega$$ is the frequency of oscillation in radians per unit time and $$A + Ce^{-\gamma t}$$ is how the maximum acceleration varies in time.

### Oscillation Frequency
Compare the $$\omega$$ from your fit to the theoretical frequency or period of a pendulum. Make sure that you convert your $$\omega$$ to match whatever theoretical value you calculate, e.g. convert to oscillations per second if you're comparing to the frequency or convert to seconds if you're comparing to the theoretical period. Note that $$\omega$$ is twice the actually frequency of your pendulum since the period of the acceleration is from the minimum at one side of the swing, to the maximum at the bottom, to the minimum again at the top of the other side of the swing, whereas the period of a pendulum is a swing from one side to the other, and then a swing back. Also, when the calculating the theoretical frequency/period, remember that the length in this case is the distance from the top of the pendulum to the center of mass of the board. An easy way to find the center of mass of your board is to figure out where the board balances on a thin object (like a ruler on its side).

### Angle And Velocity
Skipping the derivation, the angle is related to the acceleration by this equation:

$$1+\frac{a(t)-a_m(t)}{3g}=\cos(\theta(t))$$

where $$a_m(t)$$ is how the maximum acceleration varies with time (remember you found this earlier from finding a fit to your data), $$a(t)$$ is acceleration in m/s/s, and $$\theta(t)$$ is the positive angle from the vertical in radians.

Try flipping every other cycle to be negative to get a nice sine/cosine curve of your angle. _Hint: Use the sign of_ $$\cos(\omega t + \phi)$$ _from your fit with half the frequency and an adjusted phase shift._

Velocity is left for you to figure out :), good luck!