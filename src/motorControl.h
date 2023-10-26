#ifndef motorControl_h
#define motorControl_h

#include <Arduino.h>
#include <Encoder.h>
#include <L298NX2.h>
#include "encoderStruct.h"
#include "motorStruct.h"

class motorControl {
public:
    motorControl(); //constructor
    virtual ~motorControl(); //virtual destructor
    void setup();
    encoderStruct iterateMotion(int, int, int, int);

protected:
    void updateMotors(int, int, int, int);
    encoderStruct readEncoders();

    //encoders
    int encoderP1A = 2;
    int encoderP1B = 4;
    int encoderP2A = 3;
    int encoderP2B = 5;
    int encoderP3A = 14;
    int encoderP3B = 18;
    int encoderP4A = 15;
    int encoderP4B = 19;
    Encoder encoder1;
    Encoder encoder2;
    Encoder encoder3;
    Encoder encoder4;

    //motors
    int EN_A = 8;
    int IN1_A = 9; 
    int IN2_A = 10;
    int EN_B = 13;
    int IN1_B = 11;
    int IN2_B = 12;
    int EN_A2 = 27;
    int IN1_A2 = 26; 
    int IN2_A2 = 25;
    int EN_B2 = 22;
    int IN1_B2 = 24;
    int IN2_B2 = 23;
    L298NX2 motors1;
    L298NX2 motors2;
};

#endif