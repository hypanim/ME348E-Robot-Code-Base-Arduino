#ifndef motorControl_h
#define motorControl_h

#include <Arduino.h>
#include <AccelStepper.h>
#include "encoderStruct.h"
#include "stepStruct.h"

class motorControl {
public:
    motorControl(); //constructor
    virtual ~motorControl(); //virtual destructor
    void setup();
    void updateMotors(long, long, long, long);
    stepStruct readSteppers();
    void iterateMotion();

protected:

    //motor constants
    float maxSpeed = 1000;
    float acceleration = 1000;
    
    //motors
    int IN1_A = 25; 
    int IN2_A = 24;
    int IN3_A = 23;
    int IN4_A = 22;
    int IN1_B = 8; 
    int IN2_B = 9;
    int IN3_B = 10;
    int IN4_B = 11;
    int IN1_C = 4; 
    int IN2_C = 5;
    int IN3_C = 6;
    int IN4_C = 7;
    int IN1_D = 31; 
    int IN2_D = 30;
    int IN3_D = 29;
    int IN4_D = 28;

    //declaring stepper objects
    AccelStepper stepper1; 
    AccelStepper stepper2;
    AccelStepper stepper3;
    AccelStepper stepper4;
};

#endif