// LIBRARY IMPORTS
// ----------------------------------------------------------------------------
// Do not touch unless your custom sensor needs an additional library

#include <SPI.h>
#include <SD.h>

// ----------------------------------------------------------------------------



// PIN DEFINITIONS
// ----------------------------------------------------------------------------
// Note: the pins each thing is connected to may have changed. You will need to
// reference the schematic for the rocket board here:
// https://980.engr100.org/project/sensor-board.html

// put pin definitions here

// ----------------------------------------------------------------------------



// CSV FILE HEADER
// ----------------------------------------------------------------------------
// This is the string that goes at the top of your csv file. It is the column 
// headers for your spreadsheet. You can/should it to match your analog sensors

const String header = "Time (ms),TMP36 (Raw),Voltage (Raw)";

// ----------------------------------------------------------------------------



// HELPER FUNCTIONS
// ----------------------------------------------------------------------------
// Functions to call to make setup() and loop() simpler.

// --------------------------Tone function (built-in)--------------------------
// Play a 1000Hz tone on the buzzer for 2000ms:
// tone(buzzerPin, 1000, 2000);
// Play a 440Hz (A4) tone on the buzzer:
// tone(buzzerPin, 440);
// This plays until either a new tone is passed
// or until notone is called:
// noTone(buzzerPin);

// ----------------------------------------------------------------------------


void setup() {
  // set buzzer to output
  pinMode(buzzerPin, OUTPUT);

  // set other pinModes as required

  // setup SD Card module

  // write SD Card header
}

void loop() {
  // read sensor inputs

  // write to sd card

  // flush sd card file outputs

  // do LED and buzzer things

  // For LED: you have 6 different LEDs at your disposal. You must at a minimum
  // 1. Communicate power status of board (ie on/off)
  // 2. Communicate when a countdown has been initiated and roughly how long
  //    until data recording begins
  // 3. Communicate when data recording is in progress

  // For Buzzer: 
  // - In general, mirroring LED requirements 2&3 may help you know
  //  the status of your rocket even if you can't see the LEDs
  // - You MUST have your buzzer making loud and frequent noises after landing
  //  following the launch to add in locating your rocket payload
  // - You will need to utilize some of your sensor data to know when the
  //  rocket has landed. What sensor(s) you use to determine this is 100% up to
  //  you. For example, if you had an altitude sensor you could check your
  //  altitude in every loop and see if it was similar to the altitude when
  //  launch occurred and turn on the buzzer then. You will need to test this
  //  thoroughly before launch day as it is how we will find hiding rockets.
  // - Points may be deducted if your rocket is especially annoying and buzzing
  //  frequently during the launch preparation and countdown period in front of
  //  the teaching staff
}
