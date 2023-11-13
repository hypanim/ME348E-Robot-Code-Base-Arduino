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
    int Solenoid = ;//pin value 
    
    //motors
    int IN1 = ;//1
    int IN2 = ;//2
    int IN3 = ;//3
    int IN4 = ;//4
};

#endif