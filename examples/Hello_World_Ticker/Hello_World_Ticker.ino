/*
   Example for prescaler_MsTicker Library
   Instances for timing
*/
#include <Prescaler_MsTicker.h>

uint32_t beginTime = 0;

Prescaler_MsTicker bme280Ticker;
//uint32_t bme280Interval = 1000;//Interval in ms
//Prescaler_MsTicker bme280Ticker(bme280Interval);
Prescaler_MsTicker scd30Ticker;
void setup() {
  Serial.begin(112500);
  delay(200);
  Serial.print("\n\nPrescaler_MsTicker start..");


  bme280Ticker.setInterval(1000);
  scd30Ticker.setInterval(3000);
  Serial.print("\n-> bme280Ticker.setInterval: " + (String)bme280Ticker.getInterval());
  Serial.print("\n-> scd30Ticker.setInterval:  " + (String)scd30Ticker.getInterval());
  beginTime = millis() + 1000; //Begin one second after now
  bme280Ticker.update();
  bme280Ticker.begin(beginTime);
  scd30Ticker.update();
  scd30Ticker.begin(beginTime);
  Serial.print("\n-> bme280Ticker.getStatus: " + (String) bme280Ticker.getStatus());
  Serial.print("\n-> scd30Ticker.getStatus:  " + (String) scd30Ticker.getStatus());
  Serial.print("\n-> Delaying 10 seconds: ");
  for (int i = 0; i < 10; i++) {
    Serial.print(".");
    delay(1000);
  }
  bme280Ticker.update();
  bme280Ticker.begin(beginTime);
  scd30Ticker.update();
  scd30Ticker.begin(beginTime);
  Serial.print("\n-> bme280Ticker.getStatus: " + (String) bme280Ticker.getStatus());
  Serial.print("\n-> scd30Ticker.getStatus:  " + (String) scd30Ticker.getStatus());
  Serial.println();
}

void loop() {
  bme280Ticker.update();
  while (bme280Ticker.getStatus()) {
    runBme280Function(); //timed function call
    Serial.print("\nrunBme280Function ran once now. Status: ");
    Serial.print(bme280Ticker.getStatus());
  }
  scd30Ticker.update();
  while (scd30Ticker.getStatus()) {
    runScd30Function(); //timed function call
    Serial.print("\n\trunScd30Function ran once now. Status: ");
    Serial.print(bme280Ticker.getStatus());
  }
}
//########### functions  ##############

uint8_t runBme280Function() {
  return bme280Ticker.decStatus();
}

uint8_t runScd30Function() {
  return scd30Ticker.decStatus();
}