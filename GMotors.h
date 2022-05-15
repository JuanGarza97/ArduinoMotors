/*
  GMotors.h - Library for motor control.
  Created by Juan Carlos Garza Sánchez, July 3, 2015.
*/

#ifndef GMotors_h
#define GMotors_h

#include "Arduino.h"
#include "LSM303.h"

class GMotors
{
  public:
    GMotors(int pin1, int pin2);
    GMotors(int pin1, int pin2, int pin3, int pin4);
	GMotors(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6);
	GMotors(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8);
    void Release();
    void moveMotor(int motor, float speed);
    void Turn(float speed, String side);
    void Forward(float speed);
    void Backwards(float speed);
    void Left(float speed);
    void Right(float speed);
    void Diagonal(float speed, String up, String side);
    int Return_NonRelative_Angle();
    int RelAbsAngle();
    int Compass();
    bool Compass(int degree, int speed);
	bool Compass(int degree, int interval, int speed);
    void compassConfig(int min1, int min2, int min3, int max1, int max2, int max3);
	bool setMotorSpeed(int motor, float speed);
	void distanceInMeters(float RPM, float r, float speed, float distance);
	void distanceInCentimeters(float RPM, float r, float speed, float distance);
	//void timer_init();
  private:
	int numberOfMotors;
	int *pins;
    float currentSpeed;
	float *motorMaxSpeed;
    int Angle0;
    int semiAngle;
    int startA0; 
    int trueAngle; 
    int Actual;
    int RelAbsActual;
    LSM303::vector<int16_t> running_min;
    LSM303::vector<int16_t> running_max;
    LSM303 compass;
};

#endif

