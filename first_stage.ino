#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

float reading, reading1, calibration_factor;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("First of all remove all weight from scale\n");
  Serial.print("waiting for 10 seconds .");
  for(int i = 0; i < 10; i++){
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  if (scale.is_ready()) {
    reading = scale.read_average(20);
    Serial.print("reading when no load is applied:\t\t");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }
  Serial.println("Apply 720gm or 0.72kg load to the scale");
  Serial.print("Waiting for 10 seconds .");
  for(int j = 0; j < 10; j++){
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  if (scale.is_ready()) {
    reading1 = scale.read_average(20);
    Serial.print("reading when 720gm or 0.72Kg load is applied:\t\t");
    Serial.println(reading1);
  } else {
    Serial.println("HX711 not found.");
  }
  calibration_factor = (720.0/(reading1-reading))*1000;
  Serial.print("\n\n\n calibration factor: ");
  Serial.println(calibration_factor);
}

void loop() {

  

  delay(1000);
  
}
