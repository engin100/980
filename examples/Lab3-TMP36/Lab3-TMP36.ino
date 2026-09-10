// Author: Eric Andrechek, University of Michigan
// Modified by Benjamen Miller, University of Michigan (F2024)

// These are the hardware SPI pins used by the BME680.
// These pins are fixed and should not change.
// MOSI - pin 11
// MISO - pin 12
// CLK  - pin 13

// Choose the digital pin connected to the BME680 chip-select (CS) pin.
const int BMEchipSelect = ??;

// Include necessary libraries for BME below:


// Instantiate BME here:


// The setup routine runs once when you press reset.
void setup() {
    // Initialize serial communication at 9600 bits per second.
    Serial.begin(9600);

    // Initialize the BME, oversampling, filter, and gas heater below:


}

// The loop routine runs over and over again forever.
void loop() {
    // Placeholder temperature value for the BME680.
    // We only care about temperature for this lab.
    float bmeTemperature = NAN;

    // Perform a BME680 reading below:


    // Update bmeTemperature with the temperature from the latest BME680 reading below:


    // Read the TMP36 input on analog pin 1, or change A1 to the pin you are using.
    int sensorValue = analogRead(A1);

    // Convert the analog reading (0-1023) to a voltage (0-5 V).
    float voltage = sensorValue * (5.0 / 1023.0);

    // Do not worry about this until Procedure Step 7: Modifying the Code.
    // float slope = 100;
    // float intercept = -50;
    // float tempC = slope * voltage + intercept;

    // Build one comma-separated line containing the TMP36 voltage and
    // BME680 temperature so both values can be viewed together.
    String dataString;
    dataString += String(voltage);
    dataString += ",";
    dataString += String(bmeTemperature); // Degrees Celsius

    // Print the data to the Serial Monitor and Serial Plotter.
    Serial.println(dataString);

    // Delay so that the numbers are easier to read.
    delay(1000); // ms
}
