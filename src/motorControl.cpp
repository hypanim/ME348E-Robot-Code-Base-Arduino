#include "motorControl.h"

motorControl::motorControl() 
    //composition:
    : stepper1(AccelStepper::FULL4WIRE, this-> IN1_A, this-> IN2_A, this-> IN3_A, this-> IN4_A),
    stepper2(AccelStepper::FULL4WIRE, this-> IN1_B, this-> IN2_B, this-> IN3_B, this-> IN4_B),
    stepper3(AccelStepper::FULL4WIRE, this-> IN1_C, this-> IN2_C, this-> IN3_C, this-> IN4_C),
    stepper4(AccelStepper::FULL4WIRE, this-> IN1_D, this-> IN2_D, this-> IN3_D, this-> IN4_D)
{

}

motorControl::~motorControl() {

}

void motorControl::setup() {
    this-> stepper1.setMaxSpeed(this-> maxSpeed);
    this-> stepper1.setAcceleration(this-> acceleration);
    this-> stepper2.setMaxSpeed(this-> maxSpeed);
    this-> stepper2.setAcceleration(this-> acceleration);
    this-> stepper3.setMaxSpeed(this-> maxSpeed);
    this-> stepper3.setAcceleration(this-> acceleration);
    this-> stepper4.setMaxSpeed(this-> maxSpeed);
    this-> stepper4.setAcceleration(this-> acceleration);
}

void motorControl::iterateMotion() {
    this-> stepper1.run();
    this-> stepper2.run();
    this-> stepper3.run();
    this-> stepper4.run();
}

void motorControl::updateMotors(long relPos1, long relPos2, long relPos3, long relPos4){
    stepper1.move(relPos1);
    stepper2.move(relPos2);
    stepper3.move(relPos3);
    stepper4.move(relPos4);
}

stepStruct motorControl::readSteppers(){
    stepStruct readings;
    readings.step1 = this-> stepper1.distanceToGo();
    readings.step2 = this-> stepper2.distanceToGo();
    readings.step3 = this-> stepper3.distanceToGo();
    readings.step4 = this-> stepper4.distanceToGo();
    return readings;
}