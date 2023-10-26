#include "motorControl.h"

motorControl::motorControl() 
    //composition:
    : encoder1(this-> encoderP1A, this-> encoderP1B), 
    encoder2(this-> encoderP2A, this-> encoderP2B),
    encoder3(this-> encoderP3A, this-> encoderP3B),
    encoder4(this-> encoderP4A, this-> encoderP4B), 
    motors1(this-> EN_A, this-> IN1_A, this-> IN2_A, this-> EN_B, this-> IN1_B, this-> IN2_B),
    motors2(this-> EN_A2, this-> IN1_A2, this-> IN2_A2, this-> EN_B2, this-> IN1_B2, this-> IN2_B2)
{

}

motorControl::~motorControl() {

}

void motorControl::setup() {
    this-> motors1.setSpeedA(0);
    this-> motors1.setSpeedB(0);
    this-> motors2.setSpeedA(0);
    this-> motors2.setSpeedB(0);
}

encoderStruct motorControl::iterateMotion(int speed1, int speed2, int speed3, int speed4){
    //update motor values
    this-> updateMotors(speed1, speed2, speed3, speed4);

    //get encoder values
    encoderStruct readings = this-> readEncoders();
    return readings;
}

void motorControl::updateMotors(int speed1, int speed2, int speed3, int speed4){
    motors1.setSpeedA(abs(speed1));
    if(speed1>=0)
    {
        this-> motors1.forwardA();
    }
    else
    {
        this-> motors1.backwardA();
    }

    motors1.setSpeedB(abs(speed2));
    if(speed2>=0)
    {
        this-> motors1.forwardB();
    }
    else
    {
        this-> motors1.backwardB();
    }

    motors2.setSpeedA(abs(speed3));
    if(speed3>=0)
    {
        this-> motors2.forwardA();
    }
    else
    {
        this-> motors2.backwardA();
    }

    motors2.setSpeedB(abs(speed4));
    if(speed4>=0)
    {
        this-> motors2.forwardB();
    }
    else
    {
        this-> motors2.backwardB();
    }
}

encoderStruct motorControl::readEncoders(){
    encoderStruct readings;
    readings.encoder1 = this-> encoder1.read();
    readings.encoder2 = this-> encoder2.read();
    readings.encoder3 = this-> encoder3.read();
    readings.encoder4 = this-> encoder4.read();
    return readings;
}