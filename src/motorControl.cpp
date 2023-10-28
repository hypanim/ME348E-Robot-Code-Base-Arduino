#include "motorControl.h"

motorControl::motorControl() 
    //composition:
    : stepper1(AccelStepper::FULL4WIRE, this-> IN1_A, this-> IN2_A, this-> IN3_A, this-> IN4_A),
    stepper2(AccelStepper::FULL4WIRE, this-> IN1_B, this-> IN2_B, this-> IN3_B, this-> IN4_B)
{

}

motorControl::~motorControl() {

}

void motorControl::setup() {
    this-> stepper1.setMaxSpeed(this-> maxSpeed);
    this-> stepper1.setAcceleration(this-> acceleration);
    this-> stepper2.setMaxSpeed(this-> maxSpeed);
    this-> stepper2.setAcceleration(this-> acceleration);
}

void motorControl::iterateMotion() {
    this-> stepper1.run();
    this-> stepper2.run();
}

void motorControl::updateMotors(long relPos1, long relPos2, long relPos3, long relPos4){
    stepper1.move(relPos1);
    stepper2.move(relPos2);
}

stepStruct motorControl::readSteppers(){
    stepStruct readings;
    readings.step1 = this-> stepper1.distanceToGo();
    readings.step2 = this-> stepper2.distanceToGo();
    return readings;
}