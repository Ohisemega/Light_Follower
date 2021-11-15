#include "bump_sensors.h"

#define READ_INTERVAL 300

unsigned long current_ts;
unsigned long bump_ts = 0;
unsigned long elapsed_t;
BumpSensor_c bumpSensors;
void setup() {
  // put your setup code here, to run once:
  bumpSensors.initialise();
  delay(3000);
  bumpSensors.Calibrate_Bump_Sensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  current_ts = millis();

  elapsed_t = current_ts - bump_ts;
  if(elapsed_t >= READ_INTERVAL){

    bumpSensors.Read_Bump_Sensors();
    bump_ts = millis();
  }

}
