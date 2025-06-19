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
  modified 27 Aug 2023
  by Eric Andrechek

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/


// Change this variable to the pin you plug your LED circuit into:
#define LED_PIN 5
// set these to the next pins in your circuit. Make sure that the physical order of the LEDs
// on your board are in the order they are labelled here.

#define LED_PIN_2 5
#define LED_PIN_3 5
#define LED_PIN_4 5
#define LED_PIN_5 5
#define LED_PIN_6 5

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN_2, HIGH);
  delay(100);
  digitalWrite(LED_PIN_3, HIGH);
  digitalWrite(LED_PIN, LOW);
  delay(100);
  digitalWrite(LED_PIN_4, HIGH);
  digitalWrite(LED_PIN_2, LOW);
  delay(100);
  digitalWrite(LED_PIN_5, HIGH);
  digitalWrite(LED_PIN_3, LOW);
  delay(100);
  digitalWrite(LED_PIN_6, HIGH);
  digitalWrite(LED_PIN_4, LOW);
  delay(100);
  digitalWrite(LED_PIN_5, LOW);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(LED_PIN_5, HIGH);
  delay(100);
  digitalWrite(LED_PIN_4, HIGH);
  digitalWrite(LED_PIN_6, LOW);
  delay(100);
  digitalWrite(LED_PIN_3, HIGH);
  digitalWrite(LED_PIN_5, LOW);
  delay(100);
  digitalWrite(LED_PIN_2, HIGH);
  digitalWrite(LED_PIN_4, LOW);
  delay(100);
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_PIN_3, LOW);
  delay(100);
  digitalWrite(LED_PIN_2, LOW);
  delay(100);
}
