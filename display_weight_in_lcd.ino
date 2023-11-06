#include "HX711.h"
#include <LiquidCrystal.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

float no_weight_reading = 186889.0;
float calibration_factor = 0.00442, weight_in_gram, reading;
int weight;

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.print("Apply Force!");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0,0);
  
}

void loop() {

  if(scale.is_ready()){
      reading = scale.read_average(5);
      weight = int((reading - no_weight_reading)*calibration_factor);
      lcd.setCursor(0 ,0);
      lcd.print("Weight: ");
      lcd.setCursor(5, 1);
      lcd.print(weight);
      lcd.print(" gm"); 
    }
      else {
      lcd.print("Check connection");
    }
    delay(100);
    

  
  
}
