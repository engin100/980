// These are the pins your MicroSD Card Adapter will be connected to.
// MOSI, MISO, and CLK are the Arduino's hardware SPI pins. They are fixed,
// should not change, and are shared by every SPI device (like the BME680).
// MOSI - pin 11
// MISO - pin 12
// CLK  - pin 13
// CS (chip select) can be any unused digital pin, but it must NOT be shared
// with another SPI device. Change this if you wire CS to a different pin.
const int chipSelect = 10;

// These are the pins your accelerometer lines are connected to.
// Replace each ?? with the analog pin you wired it to (for example, A1).
const int xAccelPin = ??;
const int yAccelPin = ??;
const int zAccelPin = ??;

// This is the pin your voltage divider is connected to.
// Replace ?? with the analog pin you wired it to.
const int vDivPin = ??;

// This is the string that goes at the top of your csv file. It is the column headers for your spreadsheet.
// You can change this as needed.
const String header = "Time (ms),Voltage (raw), X Accel (raw), Y Accel (raw), Z Accel (raw)";

#include <SPI.h>
#include <SD.h>

void setup() {
    Serial.begin(9600);

    delay(100); // arbitrary delay to let the serial monitor start up
    Serial.print("Initializing SD card...");

    // see if the card is present and can be initialized.
    // if it isn't, wait 2 seconds and check again so you can
    // fix the wiring or reseat the card without re-uploading.
    while (!SD.begin(chipSelect)) {
        Serial.println("Card failed, or not present. Checking again in 2 seconds...");
        delay(2000);
    }
    Serial.println("card initialized.");

    // now, before we actually start reading data, we need to write the header to the file.
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if (dataFile) {
        dataFile.println(header);
        dataFile.close();
    } else {
        Serial.println("error opening datalog.csv");
    }
}

void loop() {
    int xAccelRaw = analogRead(xAccelPin);
    int yAccelRaw = analogRead(yAccelPin);
    int zAccelRaw = analogRead(zAccelPin);

    int vDivRaw = analogRead(vDivPin);

    // Now let's make a nice string to write to the file.
    // This is a comma-separated value (csv) file, so we need to separate each value with a comma.
    String dataString = "";
    // add the time (since boot) in milliseconds
    dataString += String(millis());
    dataString += ",";
    // add the raw voltage divider value
    dataString += String(vDivRaw);
    dataString += ",";
    // add the raw acceleration values
    dataString += String(xAccelRaw);
    dataString += ",";
    dataString += String(yAccelRaw);
    dataString += ",";
    dataString += String(zAccelRaw);

    // now let's open the file again
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    // if the file is available, write to it:
    if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();

        // ################ UNCOMMENT THIS LINE TO PRINT TO SERIAL ################
        // Serial.println(dataString);
    }
    // if the file isn't open, pop up an error and try to reconnect to the card
    // (for example, if it got bumped loose). data will resume once it reconnects.
    else {
        Serial.println("error opening datalog.csv, reconnecting to SD card...");
        SD.begin(chipSelect);
    }

    delay(500);
}
