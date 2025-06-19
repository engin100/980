// These are the pins your MicroSD Card Adapter will be connected to.
// These pins are specific and should not change. You do not need to worry
// about why these are the pins, just connect them as listed.
// MOSI - pin 11
// MISO - pin 12
// CLK  - pin 13
// CS   - pin 10
const int chipSelect = 10;

// should data be logged
// HIGH = log data
int shouldLogData = LOW;
unsigned long lastDataLogChange = 0;


// This is the pin your TMP36 is connected to.
// Change this as needed.
const int tmpPin = 7;

const int POWER_LED_PIN = ???;

const int DATA_LOG_LED_PIN = ???;

// This is the pin your voltage divider is connected to.
// Change this as needed.
const int vDivPin = 0;

// For future labs, you may find it helpful to copy the above settings for additional sensors.
// **HINT HINT WINK WINK**

// This is the string that goes at the top of your csv file. It is the column headers for your spreadsheet.
// You can change this as needed.
const String header = "Time (ms),TMP36 (Raw),Voltage (Raw)";

#include <SPI.h>
#include <SD.h>

const int DATA_LOG_INPUT_PIN = ???;


void setup() {
    Serial.begin(9600);

    delay(100); // arbitrary delay to let the serial monitor start up
    Serial.print("Initializing SD card...");

    // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect)) {
        Serial.println("Card failed, or not present");
        // don't do anything more:
        while (1);
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
    int dataLogInput = digitalRead(DATA_LOG_INPUT_PIN);
    unsigned long currentTime = millis();
    if(dataLogInput == LOW && currentTime - lastDataLogChange > 5000){
      shouldLogData = shouldLogData == HIGH ? LOW : HIGH;
      lastDataLogChange = currentTime;
    }

    digitalWrite(POWER_LED_PIN, HIGH);
    digitalWrite(DATA_LOG_LED_PIN, shouldLogData);
    
    if(shouldLogData == HIGH){
      // do all data logging here

      // Note: in future labs, you may need to change this to add additional sensors.
      int tmpVal = analogRead(tmpPin);
      int vDivVal = analogRead(vDivPin);

      // Now let's make a nice string to write to the file.
      // This is a comma-separated value (csv) file, so we need to separate each value with a comma.
      String dataString = "";
      // add the time (since boot) in milliseconds
      dataString += String(millis());
      dataString += ",";
      // add the raw TMP36 value
      dataString += String(tmpVal);
      dataString += ",";
      // add the raw voltage divider value
      dataString += String(vDivVal);

      // now let's open the file again
      File dataFile = SD.open("datalog.csv", FILE_WRITE);
      // if the file is available, write to it:
      if (dataFile) {
          dataFile.println(dataString);
          dataFile.close();

          // ################ UNCOMMENT THIS LINE TO PRINT TO SERIAL ################
          // Serial.println(dataString);
      }
      // if the file isn't open, pop up an error:
      else {
          Serial.println("error opening datalog.txt");
      }

    }

    delay(100);
}
