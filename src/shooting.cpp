#include "shooting.h"

shooting::shooting() :myStepper(200, IN1, IN2, IN3, IN4){
// Constructor initializer list to initialize myStepper
}

shooting::~shooting() {

}

void shooting::setup() {
    myStepper.setSpeed(25);
    pinMode(Solenoid, OUTPUT); 
}


void shooting::shoot(){
    //Shooting Code, may need to adjust delays
    digitalWrite(Solenoid, HIGH); 
    delay(100);
    digitalWrite(Solenoid, LOW); 
    myStepper.step(-130);     //Switch Solenoid ON
    //delay(100);                          
          //Switch Solenoid OFF
    //Reload code
    //need to verify rotation duration/trial&error?
    //delay(300);
    myStepper.step(130);
}