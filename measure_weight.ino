#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

float no_weight_reading = 186889.0;
float calibration_factor = 0.00442, weight_in_gram, reading;
int weight;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("Starting reading in 6 seconds.");
  for(int i = 0; i < 6; i++){
    delay(1000);
    Serial.print(".");
  }
  Serial.println();

}

void loop() {
    if(scale.is_ready()){
      reading = scale.read_average(5);
      weight = int((reading - no_weight_reading)*calibration_factor);
      Serial.println(weight);  
    }
      else {
      Serial.println("HX711 not found.");
    }
    delay(100);
    

}
