/*
  GMotors.h - Library for motor control.
  Created by Juan Carlos Garza Sánchez, July 3, 2015.
*/

#include "Arduino.h"
#include "GMotors.h"
#include "Wire.h"
#include "LSM303.h"

GMotors::GMotors(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8)
{
	float motorSpeed[4] = {255, 255, 255, 255};
	int newPins[8] = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8};
	motorMaxSpeed = motorSpeed;
	pins = newPins;
	
	for(int i = 0; i < 8; i++)
	{
		pinMode(*(pins + i), OUTPUT);
	}
	numberOfMotors = 4;
}

GMotors::GMotors(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
{
	float motorSpeed[3] = {255, 255, 255};
	int newPins[6] = {pin1, pin2, pin3, pin4, pin5, pin6};
	motorMaxSpeed = motorSpeed;
	pins = newPins;
	
	for(int i = 0; i < 6; i++)
	{
		pinMode(*(pins + i), OUTPUT);
	}
	numberOfMotors = 3;
}

GMotors::GMotors(int pin1, int pin2, int pin3, int pin4)
{
	float motorSpeed[2] = {255, 255};
	int newPins[4] = {pin1, pin2, pin3, pin4};
	motorMaxSpeed = motorSpeed;
	pins = newPins;
	
	for(int i = 0; i < 4; i++)
	{
		pinMode(*(pins + i), OUTPUT);
	}
	numberOfMotors = 2;
}

GMotors::GMotors(int pin1, int pin2)
{
	float motorSpeed[1] = {255};
	int newPins[2] = {pin1, pin2};
	motorMaxSpeed = motorSpeed;
	pins = newPins;
  
	for(int i = 0; i < 2; i++)
	{
		pinMode(*(pins + i), OUTPUT);
	}
	numberOfMotors = 1;
}

bool GMotors::setMotorSpeed(int motor, float speed)
{
	if (motor >= numberOfMotors)
		return false;
	*(motorMaxSpeed + motor) = speed;
	return true;
}

void GMotors::moveMotor(int motor, float speed)
{
  if(speed > 0)
  {
	digitalWrite(*(pins + (motor * 2 + 1)), LOW);
	analogWrite(*(pins + (motor * 2)), (*(motorMaxSpeed + motor) * speed) / 255);
  }
  else if(speed < 0)
  {
	digitalWrite(*(pins + (motor * 2)), LOW);
	analogWrite(*(pins + (motor * 2 + 1)), (*(motorMaxSpeed + motor) * -speed) / 255);
  }
  else
  {
	digitalWrite(*(pins + (motor * 2)), LOW);
	digitalWrite(*(pins + (motor * 2 + 1)), LOW);
  }
}


void GMotors::Release()
{
	for(int i = 0; i < numberOfMotors; i++)
	{
		moveMotor(i, 0);
	}
	currentSpeed = 0;
}

void GMotors::Turn(float speed, String side)
{
	currentSpeed = speed;
	if(side.equals("left"))
	{
		if(numberOfMotors == 4)
		{
			for(int i = 0; i < numberOfMotors; i+=2)
			{
				moveMotor(i , -speed);
				moveMotor(i + 1, speed);
			}
		}
		else
		{
			for(int i = 0; i < numberOfMotors; i++)
			{
				moveMotor(i, -speed);
			}
		}
	}
	else if(side.equals("right"))
	{
		if(numberOfMotors == 4)
		{
			for(int i = 0; i < numberOfMotors; i+=2)
			{
				moveMotor(i , speed);
				moveMotor(i + 1, -speed);
			}
		}
		else
		{
			for(int i = 0; i < numberOfMotors; i++)
			{
				moveMotor(i, speed);
			}
		}
	}
}

void GMotors::Forward(float speed)
{
	currentSpeed = speed;
	if(numberOfMotors == 4)
	{
		for(int i = 0; i < numberOfMotors; i++)
		{
			moveMotor(i, speed);
		}
	}
	else
	{
		for(int i = 1; i < 5; i++)
			digitalWrite(*(pins + i), LOW);
		moveMotor(0, speed);
		moveMotor(2, -speed);
	}
}

void GMotors::Backwards(float speed)
{
	currentSpeed = speed;
	if(numberOfMotors == 4)
	{
		for(int i = 0; i < numberOfMotors; i++)
		{
			moveMotor(i, -speed);
		}
	}
	else
	{
		for(int i = 1; i < 5; i++)
			digitalWrite(*(pins + i), LOW);
		moveMotor(0, -speed);
		moveMotor(2, speed);
	}
}

void GMotors::Left(float speed)
{
  currentSpeed = speed;
  if(numberOfMotors == 4)
  {
	  moveMotor(0, speed);
	  moveMotor(1, -speed);
	  moveMotor(2, -speed);
	  moveMotor(3, speed);
  }
  else
  {
	moveMotor(0, -speed);
	moveMotor(1, speed);
	moveMotor(2, -speed);
  }
}

void GMotors::Right(float speed)
{
	currentSpeed = speed;
	if(numberOfMotors == 4)
	{
		moveMotor(0, -speed);
		moveMotor(1, speed);
		moveMotor(2, speed);
		moveMotor(3, -speed);
	}
	else
	{
		moveMotor(0, speed);
		moveMotor(1, -speed);
		moveMotor(2, speed);
	}
}

void GMotors::Diagonal(float speed, String up, String side)
{
  currentSpeed = speed;
  Release();
  if(up.equals("up") && side.equals("left"))
  {
	if(numberOfMotors == 4)
	{
		moveMotor(0, speed);
		moveMotor(3, speed);
	}
	else
	{
		moveMotor(0, speed);
		moveMotor(1, speed);
	}
  }
  else if(up.equals("up") && side.equals("right"))
  {
	if(numberOfMotors == 4)
	{
		moveMotor(1, speed);
		moveMotor(2, speed);
	}
	else
	{
		moveMotor(1, -speed);
		moveMotor(2, -speed);
	}
  }
  else if(up.equals("down") && side.equals("left"))
  {
	if(numberOfMotors == 4)
	{
		moveMotor(1, -speed);
		moveMotor(2, -speed);
	}
	else
	{
		moveMotor(0, -speed);
		moveMotor(1, speed);
	}
  }
  else if(up.equals("down") && side.equals("right"))
  {
	if(numberOfMotors == 4)
	{
		moveMotor(0, -speed);
		moveMotor(3, -speed);
	}
	else
	{
		moveMotor(1, -speed);
		moveMotor(2, speed);
	}
  }
}

void GMotors::distanceInMeters(float RPM, float r, float speed, float distance)
{
	float v, d;
	v = (r / 100) * RPM * 0.10472;
	d = distance / v;
	d = (255 * d)/ speed;
	delay((d * 1000));
	Release();
}

void GMotors::distanceInCentimeters(float RPM, float r, float speed, float distance)
{
	float v, d;
	v = (r / 100) * RPM * 0.10472;
	d = (distance / 100) / v;
	d = (255 * d)/ speed;
	delay((d * 1000));
	Release();
}

int GMotors::Return_NonRelative_Angle()
{
	compass.read();
	int angle = compass.heading();
	return angle;
}

int GMotors::RelAbsAngle()
{     
  // = angle(relative to nort) - starting angle(Angle0) [in start equal to 0]   
      semiAngle = Return_NonRelative_Angle() - startA0;
  //to reset to 360 if the resultant angle is lower than 0 [angle = 10 - 70 = -60 = 360 - 60 = 300°]
  
      if (semiAngle < 0)
      {
       trueAngle = 360 - abs(semiAngle);
      }
      else 
      {
        trueAngle = semiAngle;
      }
      return trueAngle;
}

int GMotors::Compass()
{
  compass.read();
  int heading = compass.heading();
  Actual = RelAbsAngle();
  return Actual;
}

bool GMotors::Compass(int degree, int speed)
{
  compass.read();
  int heading = compass.heading();
  Actual = RelAbsAngle();
  
  if(degree == 0)
  {
    if((Actual >= 0 && Actual <= 5)|| Actual <= 360 && Actual >= 355)
    {
      Release();
       return true;
    }
    else if(Actual > 5 && Actual <= 180)
    {
      Release();
      Turn(speed, "left");
      return false;
    }
    else if(Actual >  180 && Actual < 355)
    {
      Release();
      Turn(speed, "right");
      return false;
    }
  }
  else if(degree == 90)
  {
    if((Actual >= 85 && Actual <= 95))
    {
      Release();
       return true;
    }
    else if(Actual > 95 && Actual <= 275)
    {
      Release();
      Turn(speed, "left");
      return false;
    }
    else if((Actual > 275 && Actual < 360) || (Actual >= 0 && Actual < 85))
    {
      Release();
      Turn(speed, "right");
      return false;
    }
  }
  else if(degree == 180)
  {
    if((Actual >= 175 && Actual <= 185))
    {
       Release();
       return true;
    }
    else if((Actual >  185 && Actual <= 360)||(Actual >= 0 && Actual <= 5))
    {
      Release();
      Turn(speed,"left");
      return false;
    }
    else if(Actual < 175  && Actual > 5)
    {
      Release();
      Turn(speed, "right");
      return false;
    }
  }
  else
  {
    if((Actual >= 265 && Actual <= 275))
    {
      Release();
      return true;
    }
    else if(Actual <  265 && Actual >= 85)
    {
      Release();
      Turn(speed, "right");
      return false;
    }
    else
    {
      Release();
      Turn(speed, "left");
      return false;
    }
  }
  delay(10);
  Release(); 
  delay(10);
}

bool GMotors::Compass(int degree, int interval, int speed)
{
	compass.read();
	int heading = compass.heading();
	Actual = RelAbsAngle();
	interval /= 2;
	if(degree == 0)
	{
		if((Actual >= 0 && Actual <= interval)|| Actual <= 360 && Actual >= 360 - interval)
		{
			Release();
			return true;
		}
		else if(Actual > interval && Actual <= 180)
		{
			Release();
			Turn(speed, "left");
			return false;
		}
		else if(Actual >  180 && Actual < 360 - interval)
		{
			Release();
			Turn(speed, "right");
			return false;
		}
	}
	else if(degree == 90)
	{
		if((Actual >= 90 - interval && Actual <= 90 + interval))
		{
			Release();
			return true;
		}
		else if(Actual > 90 + interval && Actual <= 270 + interval)
		{
			Release();
			Turn(speed, "left");
			return false;
		}
		else if((Actual > 270 + interval && Actual < 360) || (Actual >= 0 && Actual < 90 - interval))
		{
			Release();
			Turn(speed, "right");
			return false;
		}
	}
	else if(degree == 180)
	{
		if((Actual >= 180 - interval && Actual <= 180 + interval))
		{
			Release();
			return true;
		}
		else if((Actual >  180 + interval && Actual <= 360)||(Actual >= 0 && Actual <= interval))
		{
			Release();
			Turn(speed,"left");
			return false;
		}
		else if(Actual < 180 - interval  && Actual > interval)
		{
			Release();
			Turn(speed, "right");
			return false;
		}
	}
	else
	{
		if((Actual >= 270 - interval && Actual <= 270 + interval))
		{
			Release();
			return true;
		}
		else if(Actual <  270 - interval && Actual >= 90 - interval)
		{
			Release();
			Turn(speed, "right");
			return false;
		}
		else
		{
			Release();
			Turn(speed, "left");
			return false;
		}
	}
	delay(10);
	Release();
	delay(10);
}

void GMotors::compassConfig(int min1, int min2, int min3, int max1, int max2, int max3)
{
  
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){min1,  min2,  min3};//{-4628,  -3232,   +821};  
  compass.m_max = (LSM303::vector<int16_t>){max1, max2,  max3};//{-4610,  -3211,   +835};
  compass.read();
  int heading = compass.heading();
  Angle0 = Return_NonRelative_Angle();
  startA0 = Return_NonRelative_Angle();
  Actual = RelAbsAngle(); 
}

