#include "oled.h"
#include "loadcell.h"

#define MAX_BUFFER 32

char buffer[MAX_BUFFER];
int reading = 0;
String data = "";

void runCalibration(){
    scale.tare();
    scale.get_units(10);
    
    for(int t=5; t>=0; t--){
      data = "Calibrating in "+String(t);
      data.toCharArray(buffer, MAX_BUFFER);
      setString(buffer, 8, 24);
      delay(900);
    } 

    clearScreen();
    setString("Running -> 100g", 8, 24);
    scale.get_units(10);
    scale.calibrate_scale(100, 5);
    delay(3000);
    
    setString("Calibrated", 8, 24);
    delay(1000);
    clearScreen();
}

void setup(){
    
    initOLED();
    initScale();
    setString(" - Dee Tech -", 8, 24);
    delay(5000);
    clearScreen();

    setString("[!] Empty Scale", 8, 24);
    delay(1000);
    clearScreen();
    runCalibration();
}



void loop(){
  
  reading = getAverageValue();
    
  if(reading > 0 && reading > 10){
    data = String("Weight: ")+String(reading)+String(" g");
    data.toCharArray(buffer, MAX_BUFFER);  
    setString(buffer, 8, 24);
  }else if(10 > reading){
    setString("No weight", 8, 24);
  }

  delay(250);
}
