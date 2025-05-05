#include <RBD_WaterSensor.h> // water senseor library
#include <RBD_Capacitance.h> // Dependecy required to properly run the RBD_WaterSensor
#include <RBD_Threshold.h> // Dependecy required to properly run the RBD_WaterSensor
#define WATER_SENSOR_PIN A0 
void Water_Level(){
  int H2OValue = analogRead(A0);
  int outputValue = (H2OValue)/1023*100;
}
void setup() {
  //begin the serial print
 Serial.begin(9600);
 pinMode(WATER_SENSOR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
