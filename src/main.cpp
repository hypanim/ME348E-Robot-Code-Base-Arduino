#include <Arduino.h>
#include "motorControl.h"
#include "shooting.h"

motorControl controller;
shooting shooter
stepStruct reading;

//previous count for shooting to ensure fire one puck at a time
int prevCount = 0;

//function prototype:
void serialCommunicate();

void setup() {
  Serial.begin(115200);
  controller.setup();
  shooter.setup();
  while (!Serial) {
    ;  // Wait for the serial port to be ready
  }
}

void loop() {
  // reading = controller.iterateMotion(150, 150, 150, 150);
  // Serial.println(reading.encoder1);
  // Serial.println(reading.encoder2);
  // Serial.println(reading.encoder3);
  // Serial.println(reading.encoder4);
  // delay(1000);
  // reading = controller.iterateMotion(0, 0, 0, 0);
  // Serial.println(reading.encoder1);
  // Serial.println(reading.encoder2);
  // Serial.println(reading.encoder3);
  // Serial.println(reading.encoder4);
  // delay(1000);
  // reading = controller.iterateMotion(-150, -150, -150, -150);
  // Serial.println(reading.encoder1);
  // Serial.println(reading.encoder2);
  // Serial.println(reading.encoder3);
  // Serial.println(reading.encoder4);
  // delay(1000);
  // reading = controller.iterateMotion(0, 0, 0, 0);
  // Serial.println(reading.encoder1);
  // Serial.println(reading.encoder2);
  // Serial.println(reading.encoder3);
  // Serial.println(reading.encoder4);
  // delay(1000);
  serialCommunicate();
}

void serialCommunicate(){
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');  // Read until newline
    
    // Separate the comma-separated values
    int values[5];
    int currentIndex = 0;
    int commaIndex = inputString.indexOf(',');
    while (commaIndex != -1) {
      values[currentIndex] = inputString.substring(0, commaIndex).toInt();
      inputString = inputString.substring(commaIndex + 1);
      commaIndex = inputString.indexOf(',');
      currentIndex++;
    }

    // Handle the last value
    if (currentIndex < 5) {
      values[currentIndex] = inputString.toInt();
    }
  
    //write the values to the arduino
    controller.updateMotors(values[0], values[1], values[2], values[3]);

    //loading and shooting values write to arduino
    if(values[4] > prevCount){
      shooter.shoot();
      prevCount = values[4] = 0;
    }
  }
  //read from the motor
  reading = controller.readSteppers();
  Serial.print(reading.step1);
  Serial.print(',');
  Serial.print(reading.step2);
  Serial.print(',');
  Serial.print(reading.step3);
  Serial.print(',');
  Serial.print(reading.step4);
  Serial.println();

  //move steps
  controller.iterateMotion();
}