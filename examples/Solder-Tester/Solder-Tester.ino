/*
  Solder_Tester

  Created February 14th, 2024
  By: Benjamen Miller, University of Michigan
  NOTE: This code is NOT elegant in any way, shape, or form... it is simply a quick utility script, a quite ugly one!

  Performs test on soldering challenge boards

  - Starts with two cycles of knight-rider pattern using 9 LEDs to determine LED status
  - Onboard LED flashes 0-5 times, indicating the number of voltage readings that are within their proper thresholds (out of 5)
      - Simultaneously uses LEDs 0-4 to indicate which voltages are within a reasonable range, in order (batt, 5v, 2/3 * 5v, 1/3 * 5v, 3.3v)
  - Indicates battery voltage from scale of 0-5v using 1-9 LEDs (through 1/2 * Vin voltage divider)
  - Flashes 5 times to indicate readout from 5v pin, then indicates voltage level of 5v pin (scale from 1-9 LEDs of 0-5 volts)
  - Flashes 2 times to indicate readout from 5v pin through 2/3 * Vin voltage divider
  - Flashes 2 times to indicate readout from 5v pin through 1/3 * Vin voltage divider
  - Flashes 3 times to indicate readout from 3.3v pin (still on scale from 0-5v using 1-9 LED scale)
  - ^^Repeats cycle^^

  This solder challenge code is in the ENGR100-950 Arduino Library
*/


#define LED_PIN_1 2
#define LED_PIN_2 3
#define LED_PIN_3 4
#define LED_PIN_4 5
#define LED_PIN_5 6
#define LED_PIN_6 7
#define LED_PIN_7 8
#define LED_PIN_8 9
#define LED_PIN_9 10

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);

  // initialize digital pin LED_PIN as an output.
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_8, OUTPUT);
  pinMode(LED_PIN_9, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_PIN_1, HIGH);
    delay(100);
    digitalWrite(LED_PIN_2, HIGH);
    delay(100);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_1, LOW);
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
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_5, LOW);
    delay(100);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_6, LOW);
    delay(100);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_PIN_7, LOW);
    delay(100);

    digitalWrite(LED_PIN_8, LOW);
    delay(100);
    
    digitalWrite(LED_PIN_8, HIGH);
    delay(100);

    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_9, LOW);
    delay(100);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_8, LOW);
    delay(100);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_7, LOW);
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
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    delay(100);
    digitalWrite(LED_PIN_2, LOW);
    delay(100);
  }
  digitalWrite(LED_PIN_1, LOW);

  delay(1000);

  int correctVoltages = 0;

  double batteryVal = analogRead(A6);
  double batteryVolts = batteryVal * (5.0 / 1023.0);

  delay(100);
  double fiveVal = analogRead(A1);
  double fiveVolts = fiveVal * (5.0 / 1023.0);

  delay(100);
  double twothreeVal = analogRead(A2);
  double twothreeVolts = twothreeVal * (5.0 / 1023.0);

  delay(100);
  double onethreeVal = analogRead(A3);
  double onethreeVolts = onethreeVal * (5.0 / 1023.0);

  delay(100);
  double threeVal = analogRead(A0);
  double threeVolts = threeVal * (5.0 / 1023.0);

  if(batteryVolts <= 5.0 && batteryVolts >= 3.0) {
    correctVoltages++;
    digitalWrite(LED_PIN_1, HIGH);
  }
  if(fiveVolts <= 7.0 && fiveVolts >= 4.7) {
    correctVoltages++;
    digitalWrite(LED_PIN_2, HIGH);
  }
  if(twothreeVolts <= 4.7 && twothreeVolts >= 3.0) {
    correctVoltages++;
    digitalWrite(LED_PIN_3, HIGH);
  }
  if(onethreeVolts <= 2.4 && onethreeVolts >= 1.4) {
    correctVoltages++;
    digitalWrite(LED_PIN_4, HIGH);
  }
  if(threeVolts <= 4.0 && threeVolts >= 2.0) {
    correctVoltages++;
    digitalWrite(LED_PIN_5, HIGH);
  }

  delay(1000);

  for(int i = 0; i < correctVoltages; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(700);
    digitalWrite(LED_BUILTIN, LOW);
    delay(700);
  }

  for(int i = 0; i < 10; ++i) {
    int batteryVoltage = analogRead(A6);
    if(batteryVoltage <= 1023 && batteryVoltage > 909){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(batteryVoltage <= 909 && batteryVoltage > 795){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(batteryVoltage <= 795 && batteryVoltage > 681){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 681 && batteryVoltage > 567){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 567 && batteryVoltage > 453){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 453 && batteryVoltage > 339){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 339 && batteryVoltage > 225){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 225 && batteryVoltage > 111){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(batteryVoltage <= 111 && batteryVoltage > 0){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW); 
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        
        delay(500);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        
        delay(500);
      }
      return;
    }
    delay(500);
  }
  for(int i = 0; i < 5; ++i){
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    
    delay(200);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int fiveVoltage = analogRead(A1);
    if(fiveVoltage <= 1023 && fiveVoltage > 909){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(fiveVoltage <= 909 && fiveVoltage > 795){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(fiveVoltage <= 795 && fiveVoltage > 681){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 681 && fiveVoltage > 567){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 567 && fiveVoltage > 453){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 453 && fiveVoltage > 339){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 339 && fiveVoltage > 225){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 225 && fiveVoltage > 111){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(fiveVoltage <= 111 && fiveVoltage > 0){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        
        delay(500);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    
    delay(200);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int twothreeVoltage = analogRead(A2);
    if(twothreeVoltage <= 1023 && twothreeVoltage > 909){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(twothreeVoltage <= 909 && twothreeVoltage > 795){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(twothreeVoltage <= 795 && twothreeVoltage > 681){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 681 && twothreeVoltage > 567){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 567 && twothreeVoltage > 453){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 453 && twothreeVoltage > 339){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 339 && twothreeVoltage > 225){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 225 && twothreeVoltage > 111){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(twothreeVoltage <= 111 && twothreeVoltage > 0){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        
        delay(500);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 2; ++i){
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    
    delay(200);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int onethreeVoltage = analogRead(A3);
    if(onethreeVoltage <= 1023 && onethreeVoltage > 909){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(onethreeVoltage <= 909 && onethreeVoltage > 795){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(onethreeVoltage <= 795 && onethreeVoltage > 681){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 681 && onethreeVoltage > 567){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 567 && onethreeVoltage > 453){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 453 && onethreeVoltage > 339){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 339 && onethreeVoltage > 225){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 225 && onethreeVoltage > 111){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(onethreeVoltage <= 111 && onethreeVoltage > 0){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        
        delay(500);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        
        delay(500);
      }
      return;
    }
    delay(500);
  }

  for(int i = 0; i < 3; ++i){
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
    digitalWrite(LED_PIN_5, HIGH);
    digitalWrite(LED_PIN_6, HIGH);
    digitalWrite(LED_PIN_7, HIGH);
    digitalWrite(LED_PIN_8, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    
    delay(200);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
    digitalWrite(LED_PIN_5, LOW);
    digitalWrite(LED_PIN_6, LOW);
    digitalWrite(LED_PIN_7, LOW);
    digitalWrite(LED_PIN_8, LOW);
    digitalWrite(LED_PIN_9, LOW);
    
    delay(200);
  }

  for(int i = 0; i < 10; ++i) {
    int threeVoltage = analogRead(A0);
    if(threeVoltage <= 1023 && threeVoltage > 909){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(threeVoltage <= 909 && threeVoltage > 795){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, HIGH);
      
    }
    else if(threeVoltage <= 795 && threeVoltage > 681){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, HIGH);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 681 && threeVoltage > 567){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, HIGH);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 567 && threeVoltage > 453){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, HIGH);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 453 && threeVoltage > 339){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 339 && threeVoltage > 225){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 225 && threeVoltage > 111){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW);
      
    }
    else if(threeVoltage <= 111 && threeVoltage > 0){
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
      digitalWrite(LED_PIN_6, LOW);
      digitalWrite(LED_PIN_7, LOW);
      digitalWrite(LED_PIN_8, LOW);
      digitalWrite(LED_PIN_9, LOW); 
    }
    else {
      for(int i = 0; i < 5; ++i){
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_9, HIGH);
        
        delay(500);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_9, LOW);
        
        delay(500);
      }
      return;
    }
    delay(500);
  }
}
