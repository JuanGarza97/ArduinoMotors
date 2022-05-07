/*
  GMotors.h - Library for motor control.
  Created by Juan Carlos Garza Sánchez, July 3, 2015.
*/

#ifndef GMotors_h
#define GMotors_h

#include "Arduino.h"

class GMotors
{
  public:
    GMotors(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8);
    GMotors(int pin1, int pin2);
    void Release();
    void Release(float vel1, float vel3, float d);
    void Accelerate(float vel);
    void Motor(float vel);
    void Motor(float vel, int m);
    void Turn(float vel, String side);
    void Forward(float vel);
    void Backwards(float vel);
    void Left(float vel);
    void Right(float vel);
    void Diagonal(float vel, String up, String side);
    int Return_NonRelative_Angle();
    int Compass1();
    int RelAbsAngle();
    bool Compass(int n, int vel);
    void compassConfig(int min1, int min2, int min3, int max1, int max2, int max3);
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _pin5;
    int _pin6;
    int _pin7;
    int _pin8;
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    int p6;
    int p7;
    int p8;
    float _vel;
    float _vel2;
    int Angle0;
    int semiAngle;
    int startA0; 
    int trueAngle; 
    int Actual;
    int RelAbsActual;
};

#endif

