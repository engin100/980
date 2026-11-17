---
layout: spec
latex: true
---

# Programming Tips

Short reminders and useful information for the Arduino code in this class. 

## Contents

- [Programming Tips](#programming-tips)
  - [Contents](#contents)
  - [Timing Your Loop Without delay()](#timing-your-loop-without-delay)
  - [Why Sample Fast?](#why-sample-fast)
  - [The BME680](#the-bme680)
  - [Analog Sensors](#analog-sensors)
  - [MicroSD Card Logging](#microsd-card-logging)
  - [SPI Wiring](#spi-wiring)
  - [Serial Monitor](#serial-monitor)
  - [Putting It All Together](#putting-it-all-together)
  - [Debugging Checklist](#debugging-checklist)

<div class="primer-spec-callout info" markdown="1">
**TLDR**

1. **Use `delay()` very frugally in flight code.** Use a [`millis()` timer](#timing-your-loop-without-delay) when possible instead.
2. **Log the accelerometer at 100 Hz or faster.** [Here's why.](#why-sample-fast)
3. **Never wait on the BME680.** Use [`beginReading()` / `endReading()`](#using-async-functions), not `performReading()`.
4. **Do your math with floats.** Write `5.0 / 1023.0`, not `5 / 1023`.
</div>

## Timing Your Loop Without `delay()`

So far, most of our starter code has ended `loop()` with a `delay()`. While this has worked for our labs, `delay()` freezes the whole Arduino: nothing gets read or logged while it waits. It also doesn't actually set your sample rate. Your real loop time is the delay **plus** however long it takes to read your sensors and write to the microSD card, so `delay(10)` does **not** give you 100 Hz.

Instead, we can use `millis()`, which returns the number of milliseconds since the Arduino turned on, to check if enough time has passed before taking the next sample:

```cpp
const unsigned long SAMPLE_MS = 10;   // 10 ms between samples = 100 Hz
unsigned long lastSample = 0;

void loop() {
  unsigned long now = millis();
  if (now - lastSample >= SAMPLE_MS) {
    lastSample = now;
    // read sensors + write one line to the microSD card
  }
  // other jobs (like checking the BME680) go here, outside the if
}
```

<div class="primer-spec-callout info" markdown="1">
**Note:** Always store times in an `unsigned long`. An `int` can only hold about 32 seconds worth of milliseconds before it overflows!
</div>

A few more things to keep in mind:

- Write the check as `now - lastSample >= SAMPLE_MS`
- If you need more than one rate, use one timer per job, like sampling every 10 ms and checking the battery every 1000 ms.
- To see what rate you are *actually* getting, log `millis()` as the first column of your CSV and look at the gaps between rows.

## Why Sample Fast?

Your rocket's motor only burns for about 1-2 seconds, and that is the most important part of the flight! The Lab 4 starter code logs at about 2 Hz, which would give you only about 3 data points during the entire burn.

There is also a rule called the **Nyquist rate**: to capture a signal, you need to sample at least twice as fast as the highest frequency in that signal. The ADXL335 module filters its outputs at about 50 Hz, so we want to log at **100 Hz or faster**. This is also the requirement for your [Go/No-Go](/project/go-no-go) tests.

Sampling fast matters even more once you integrate your acceleration data to get velocity and altitude, since the error grows as the time between samples gets larger.

The BME680 does not need to keep up with the accelerometer. Pressure changes much more slowly than acceleration, so log the accelerometer every sample and just repeat the most recent BME680 values until a new reading comes in.

## The BME680

All of the BME680 functions used below come from Adafruit's library. You can find what each one does in the [Adafruit BME680 library documentation](https://adafruit.github.io/Adafruit_BME680/html/class_adafruit___b_m_e680.html#a2e6a61b5441c51bf5e44c3af3ee3fec8).

### `performReading()` Freezes Your Code

The BME680-Example code uses `performReading()`, which does not return until the measurement is completely finished. With the example's settings, each call freezes the Arduino for **about a third of a second**. This happens for two reasons:

1. The **gas heater** (320 °C for 150 ms) runs *after* the temperature, pressure, and humidity measurements.
2. The library waits **twice** the remaining time, just to be safe.

This means your *whole loop*, including the accelerometer, can only run at about 3 Hz.

### Using Async Functions

To fix this, we can use the BME680's **async** functions. An async function lets the Arduino start a task and keep doing other things while that task finishes, instead of waiting around for it.

```cpp
// in loop(), outside your sample timer
bme.beginReading();
if (bme.remainingReadingMillis() == 0) {
  bme.endReading();
  temperature = bme.temperature;
  pressure    = bme.pressure;
}
```

In words, this code:

1. Starts a reading with `beginReading()`. If a reading is already running, it does nothing.
2. Checks if the reading is done by checking if `remainingReadingMillis()` equals 0.
3. If it is done, `endReading()` grabs the results, which we save into our own variables.
4. If it is not done, the code just moves on, so the loop can keep reading the accelerometer and other stuff.

### The Gas Heater

If your team doesn't need gas data, turning the heater off makes the BME680 much faster.

<div class="primer-spec-callout warning" markdown="1">
**Watch out:** `setGasHeater(0, 0)` turns the heater off, but the library still waits the old 150 ms anyway! To actually speed things up, shrink the heater time first:

```cpp
bme.setGasHeater(320, 1);   // set the heater time the library waits for to 1 ms...
bme.setGasHeater(0, 0);     // ...then switch the heater off
```
</div>

| Setup | Approximate BME680 Rate |
|---|---|
| `performReading()`, heater on | about 3 Hz |
| Async, heater on | about 6 Hz |
| Async, heater off (the trick above) | 50+ Hz |

These rates assume 1x oversampling, like in the BME680-Example code. Higher oversampling (the library's default if you don't set it) is less noisy, but slower.

### Other BME680 Tips

- `bme.pressure` is in **Pa**, not hPa. Divide by `100.0` (not `100`!) to get hPa.
- Avoid `readAltitude()`. It needs today's sea-level pressure, and it runs *another* blocking reading. 
- Keep the IIR filter small (0-3). A large filter smooths the data, but makes it lag behind, which smears out apogee. You can always smooth your data afterwards in your spreadsheet.
- If `bme.begin()` fails, double-check that the CS pin in your code matches your wiring, and that SDI goes to pin 11 and SDO goes to pin 12. These get swapped a lot!

## Analog Sensors

The TMP36, the voltage divider, and the ADXL335 are all read with `analogRead()`, so they all share the same common mistakes. For a refresher on how this works, see [How Analog to Digital Converters (ADCs) Work](/labs/lab-3#how-analog-to-digital-converters-adcs-work) in Lab 3.

<div class="primer-spec-callout danger" markdown="1">
**Integer math truncates!** `analogRead(A1) * 5 / 1023` can only ever be 0, 1, 2, 3, 4, or 5. Instead, write `analogRead(A1) * (5.0 / 1023.0)`.
</div>


## MicroSD Card Logging

- Filenames must be in **8.3 format**: at most 8 characters, a dot, then at most 3 characters. `FLIGHT.CSV` works, but `flightdata.csv` will fail and `SD.open()` will return false.
- Some writes randomly take 10-100+ ms while the card erases a block. This is normal, and is one more reason to log `millis()` on every line.