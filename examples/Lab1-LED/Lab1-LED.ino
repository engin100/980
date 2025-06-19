/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
  modified 25 Aug 2024
  by Benjamen Miller
*/

// ######################### BEGIN EDITING HERE (1/1) #########################

// Change this variable to be the digital pin number your LED circuit is plugged into
#define LED_PIN_0 ???

// ########################## END EDITING HERE (1/1) ##########################

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize digital pin LED_PIN_0 as an output.
  pinMode(LED_PIN_0, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN_0, HIGH);  // turn the built-in LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);  // turn the circuit LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second (1000 milliseconds)
  digitalWrite(LED_PIN_0, LOW);   // turn the built-in LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);   // turn the circuit LED off by making the voltage LOW
  delay(1000);                      // wait for a second (1000 milliseconds)
}
