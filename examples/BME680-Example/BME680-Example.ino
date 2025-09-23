// These are the pins your MicroSD Card Adapter and BME680 will be connected to.
// These pins are specific and should not change. You do not need to worry
// about why these are the pins, just connect them as listed.
// MOSI - pin 11
// MISO - pin 12
// CLK  - pin 13

// You will pick which digital pin to connect to the chip select pin of the BME
const int BMEchipSelect = ??;

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

Adafruit_BME680 bme(BMEchipSelect);

void setup() {
    Serial.begin(9600);

    delay(100); // arbitrary delay to let the serial monitor start up

    // Initialize the BME and check if it's connected
    if (!bme.begin()) {
        Serial.println("Could not find a valid BME680 sensor, check wiring!");
        while (1);
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_1X);
    bme.setHumidityOversampling(BME680_OS_1X);
    bme.setPressureOversampling(BME680_OS_1X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms
}

void loop() {
    bme.performReading(); // Take a reading from the BME680 - all sensor values get measured at once

    Serial.print("Temperature = ");
    Serial.print(bme.temperature); // Access the temperature from the latest reading
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.pressure); // Pressure
    Serial.println(" hPa");

    Serial.print("Humidity = ");
    Serial.print(bme.humidity); // Humidity
    Serial.println(" %");

    Serial.print("Gas = ");
    Serial.print(bme.gas_resistance / 1000.0); // Resistance of the VOC gas sensor. This value can be correlated with the VOC gas concentration
    Serial.println(" KOhms");

    delay(500);
}
