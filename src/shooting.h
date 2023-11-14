#ifndef shooting_h
#define shooting_h

#include <Arduino.h>
#include <Stepper.h>


class shooting {
public:
    shooting(); //constructor
    virtual ~shooting(); //virtual destructor
    void setup();
    void shoot();

protected:
    //solenoid pin
    int Solenoid = 50;//pin value 
    
    //motors
    int IN1 = 42;//1
    int IN2 = 44;//2
    int IN3 = 46;//3
    int IN4 = 48;//4

    Stepper myStepper;// Declare Stepper instance as a member variable
};

#endif