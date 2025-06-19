// Author: Eric Andrechek, University of Michigan
// Modified by Benjamen Miller, University of Michigan (F2024)

// the setup routine runs once when you press reset:
void setup() {
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
    // read the input on analog pin 1:
    int sensorValue = analogRead(A1);

    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);

    // Don't worry about this until you get to
    // procedure step 5: Modifying the Code
    // float slope = 100;
    // float intercept = -50;
    // float tempC = slope * voltage + intercept;

    // print out the value you read:
    Serial.println(voltage);
    // delay so that the numbers are slightly more readable
    delay(1000); // ms
}
