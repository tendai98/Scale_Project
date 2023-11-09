
#include "HX711.h"

const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void calibrateScale(int refMass, int sampleTimes){
    scale.calibrate_scale(100, 5);
}

void resetScale(){
  scale.tare();
}

void initScale() {
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(127.15);
  resetScale();
}

int getAverageValue() {
  int value = scale.get_units(10);
  return value;
}
