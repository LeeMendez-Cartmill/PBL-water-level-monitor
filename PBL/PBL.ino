#include <RBD_WaterSensor.h>  // water senseor library
#include <RBD_Capacitance.h>  // required to properly run the RBD_WaterSensor
#include <RBD_Threshold.h>    // required to properly run the RBD_WaterSensor
#define WATER_SENSOR_PIN A0   //water pin
//pins responsible for the LED colour
#define redPin 9
#define greenPin 10
#define bluePin 11
//--------------------------The Function to control the LED--------------------------//
void LEDStateByWater(int outputValue) {
  if (outputValue >= 80) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  } else if (outputValue < 80 && outputValue >= 60) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 165);
    analogWrite(bluePin, 0);
  } else if (outputValue < 60 && outputValue >= 40) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  } else if (outputValue < 40 && outputValue >= 20) {
    analogWrite(redPin, 238);
    analogWrite(bluePin, 210);
    analogWrite(greenPin, 2);
  } else if (outputValue < 20) {
    analogWrite(redPin, 128);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 128);
  } else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}
//-----------The function to convert our Waterlevel value into a percentage-----------//
int Water_Level() {
  int H2OValue = analogRead(A0);
  int outputValue = (H2OValue) / 1023*100;
  return outputValue;
}
void setup() {
  //begin the serial print
  Serial.begin(9600);
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int outputValue;
  outputValue = Water_Level();
  LEDStateByWater(outputValue);
  delay(1000);
}
