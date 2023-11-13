#include "shooting.h"

shooting::shooting() 
{

}

shooting::~shooting() {

}

void shooting::setup() {
    Stepper myStepper(200, IN1, IN2, IN3, IN4)
    myStepper.setSpeed(25);
    pinMode(solenoidPin, OUTPUT); 
}


void shooting::shoot(){
    //Shooting Code, may need to adjust delays
    digitalWrite(solenoidPin, HIGH); 
    myStepper.step(-125);     //Switch Solenoid ON
    delay(100);                          
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
    //Reload code
    //need to verify rotation duration/trial&error?
    delay(300);
    myStepper.step(125);
}