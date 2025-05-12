
#include <RBD_WaterSensor.h>  // water senseor library
#include <RBD_Capacitance.h>  // required to properly run the RBD_WaterSensor
#include <RBD_Threshold.h>    // required to properly run the RBD_WaterSensor
#define WATER_SENSOR_PIN A0   //water pin
//pins responsible for the LED colour
#define redPin 9 
#define greenPin 10
#define bluePin 11
//--------------------------The Function to control the LED--------------------------//
void LEDStateByWater(int sensorValue) {
  if (sensorValue >= 264) {// if the water level is equal to or greater than 80% the LED will be red to indicate that the water level is at a criticaly high level and that imediate action is needed
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  } else if (sensorValue < 264 && sensorValue >= 198) {// If the water level is less than 80% but equal to or greater than 60% the LED will be orange to indicate that the water level is high
    analogWrite(redPin, 255);
    analogWrite(greenPin, 165);
    analogWrite(bluePin, 0);
  } else if (sensorValue < 198 && sensorValue >= 132) { // If the water level is less than 60% but greater than or equal to 40% the LED will be green to inicate that the water level is optimal.
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  } else if (sensorValue < 132 && sensorValue >= 66) { //If the water level is less than 40% and higher or equal to 20% the LED will be Safety Yellow to warn that the water level is Low
    analogWrite(redPin, 128);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 128);
  } else if (sensorValue < 66) { // If the water level is less than 20% the LED will be purple to indicate that the water level is sriticaly low and more water is needed immediantely
    analogWrite(redPin, 255);
    analogWrite(bluePin, 255);
    analogWrite(greenPin, 0);
  } else { // If it is not working the LED should be off
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
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
   // Read the input on analog pin 0
  int sensorValue = analogRead(WATER_SENSOR_PIN);

  // Print out the value you read
  Serial.print("Water Level: ");
  Serial.println(sensorValue);

  LEDStateByWater(sensorValue);
  delay(100);// checks the value every second by restarting the program
}
