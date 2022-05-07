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
 pinMode(pin1, OUTPUT);
 pinMode(pin2, OUTPUT); 
 pinMode(pin3, OUTPUT);
 pinMode(pin4, OUTPUT);
 pinMode(pin5, OUTPUT);
 pinMode(pin6, OUTPUT);
 pinMode(pin7, OUTPUT);
 pinMode(pin8, OUTPUT);
 _pin1 = pin1;
 _pin2 = pin2; 
 _pin3 = pin3; 
 _pin4 = pin4; 
 _pin5 = pin5; 
 _pin6 = pin6; 
 _pin7 = pin7;
 _pin8 = pin8;  
}

GMotors::GMotors(int pin1, int pin2)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2; 
}

GMotors::GMotors(int pin1, int pin2, int pin3, int pin4)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2; 
  _pin5 = pin3;
  _pin6 = pin4; 
}

void GMotors::Motor(float vel)
{
  _vel = vel;
  if(vel > 0)
  {
    digitalWrite(_pin2, LOW);
    analogWrite(_pin1, vel);
  }
  else if(vel < 0)
  {
    digitalWrite(_pin1, LOW);
    analogWrite(_pin2, vel * -1);
  }
  else
  {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);  
  }
}

void GMotors::Motor(float vel, int m)
{
  _vel = vel;
  if(m == 1)
  {
    if(vel > 0)
    {
      digitalWrite(_pin2, LOW);
      analogWrite(_pin1, vel);
    }
    else if(vel < 0)
    {
      vel = vel * -1;
      digitalWrite(_pin1, LOW);
      analogWrite(_pin2, vel); 
    }
    else if(vel == 0)
    {
      digitalWrite(_pin1, LOW);
      digitalWrite(_pin2, LOW); 
    }
  }
  else if(m == 2)
  {
    if(vel > 0)
    {
      digitalWrite(_pin4, LOW);
      analogWrite(_pin3, vel);
    }
    else if(vel < 0)
    {
      vel = vel * -1;
      digitalWrite(_pin3, LOW);
      analogWrite(_pin4, vel); 
    }
    else if(vel == 0)
    {
      digitalWrite(_pin3, LOW);
      digitalWrite(_pin4, LOW); 
    }
  }
  else if(m == 3)
  {
    if(vel > 0)
    {
      digitalWrite(_pin6, LOW);
      analogWrite(_pin5, vel);
    }
    else if(vel < 0)
    {
      vel = vel * -1;
      digitalWrite(_pin5, LOW);
      analogWrite(_pin6, vel); 
    }
    else if(vel == 0)
    {
      digitalWrite(_pin5, LOW);
      digitalWrite(_pin6, LOW); 
    }
  }
  else if(m == 4)
  {
    if(vel > 0)
    {
      digitalWrite(_pin8, LOW);
      analogWrite(_pin7, vel);
    }
    else if(vel < 0)
    {
      vel = vel * -1;
      digitalWrite(_pin7, LOW);
      analogWrite(_pin8, vel); 
    } 
    else if(vel == 0)
    {
      digitalWrite(_pin7, LOW);
      digitalWrite(_pin8, LOW); 
    }
  }
}


void GMotors::Release()
{
 digitalWrite(_pin1, LOW);
 digitalWrite(_pin2, LOW); 
 digitalWrite(_pin3, LOW);
 digitalWrite(_pin4, LOW); 
 digitalWrite(_pin5, LOW);
 digitalWrite(_pin6, LOW); 
 digitalWrite(_pin7, LOW);
 digitalWrite(_pin8, LOW);  
}

void GMotors::Accelerate(float vel)
{

  p1 = digitalRead(_pin1);
  p2 = digitalRead(_pin2);
  p3 = digitalRead(_pin3);
  p4 = digitalRead(_pin4);
  p5 = digitalRead(_pin5);
  p6 = digitalRead(_pin6);
  p7 = digitalRead(_pin7);
  p8 = digitalRead(_pin8);
  for(float vel2 = _vel; vel2 < vel; vel2++)
  {
    if(p1 == HIGH)
    {
      analogWrite(_pin1, vel2);
    }
    if(p2 == HIGH)
    {
      analogWrite(_pin2, vel2);
    }
    if(p3 == HIGH)
    {
      analogWrite(_pin3, vel2);
    }
    if(p4 == HIGH)
    {
      analogWrite(_pin4, vel2);
    }
    if(p5 == HIGH)
    {
      analogWrite(_pin5, vel2);
    }
    if(p6 == HIGH)
    {
      analogWrite(_pin6, vel2);
    }
    if(p7 == HIGH)
    {
      analogWrite(_pin7, vel2);
    }
    if(p8 == HIGH)
    {
      analogWrite(_pin8, vel2);
    }
  }
}

void GMotors::Release(float vel1, float vel3, float d)
{
  Serial.println(_vel);
  p1 = digitalRead(_pin1);
  p2 = digitalRead(_pin2);
  p3 = digitalRead(_pin3);
  p4 = digitalRead(_pin4);
  p5 = digitalRead(_pin5);
  p6 = digitalRead(_pin6);
  p7 = digitalRead(_pin7);
  p8 = digitalRead(_pin8);
  
  for(float vel2 = _vel; vel2 > vel1; vel2-=5)
  {
    if(p1 == HIGH)
    {
      Serial.println(1);
      analogWrite(_pin1, vel2);
    }
    if(p2 == HIGH)
    {
      Serial.println(2);
      analogWrite(_pin2, vel2);
    }
    if(p3 == HIGH)
    {
      Serial.println(3);
      analogWrite(_pin3, vel2);
    }
    if(p4 == HIGH)
    {
      Serial.println(4);
      analogWrite(_pin4, vel2);
    }
    if(p5 == HIGH)
    {
      Serial.println(5);
      analogWrite(_pin5, vel2);
    }
    if(p6 == HIGH)
    {
      Serial.println(6);
      analogWrite(_pin6, vel2);
    }
    if(p7 == HIGH)
    {
      Serial.println(7);
      analogWrite(_pin7, vel2);
    }
    if(p8 == HIGH)
    {
      Serial.println(8);
      analogWrite(_pin8, vel2);
    }
    _vel = vel2;
    delay(200);
  }
  if(p1 == HIGH)
  {
    Serial.println(1);
    analogWrite(_pin1, _vel);
  }
  if(p2 == HIGH)
  {
    Serial.println(2);
    analogWrite(_pin2, _vel);
  }
  if(p3 == HIGH)
  {
    Serial.println(3);
      analogWrite(_pin3, _vel);
  }
  if(p4 == HIGH)
  {
    Serial.println(4);
    analogWrite(_pin4, _vel);
  }
  if(p5 == HIGH)
  {
    Serial.println(5);
    analogWrite(_pin5, _vel);
  }
  if(p6 == HIGH)
  {
    Serial.println(6);
    analogWrite(_pin6, _vel);
  }
  if(p7 == HIGH)
  {
    Serial.println(7);
    analogWrite(_pin7, _vel);
  }
  if(p8 == HIGH)
  {
    Serial.println(8);
    analogWrite(_pin8, _vel);
  }
  delay(d);
  for(float vel2 = _vel; vel2 > vel3; vel2--)
  {
    if(p1 == HIGH)
    {
      Serial.println(1);
      analogWrite(_pin1, vel2);
    }
    if(p2 == HIGH)
    {
      Serial.println(2);
      analogWrite(_pin2, vel2);
    }
    if(p3 == HIGH)
    {
      Serial.println(3);
      analogWrite(_pin3, vel2);
    }
    if(p4 == HIGH)
    {
      Serial.println(4);
      analogWrite(_pin4, vel2);
    }
    if(p5 == HIGH)
    {
      Serial.println(5);
      analogWrite(_pin5, vel2);
    }
    if(p6 == HIGH)
    {
      Serial.println(6);
      analogWrite(_pin6, vel2);
    }
    if(p7 == HIGH)
    {
      Serial.println(7);
      analogWrite(_pin7, vel2);
    }
    if(p8 == HIGH)
    {
      Serial.println(8);
      analogWrite(_pin8, vel2);
    }
    _vel = vel2;
    delay(200);
  }
}

void GMotors::Turn(float vel, String side)
{
 _vel = vel;
 if(side.equals("left"))
 {
   digitalWrite(_pin1, LOW);
   digitalWrite(_pin3, LOW);
   digitalWrite(_pin6, LOW);
   digitalWrite(_pin8, LOW);
   analogWrite(_pin2, vel);
   analogWrite(_pin4, vel);
   analogWrite(_pin5, vel); 
   analogWrite(_pin7, vel);
 }
 else if(side.equals("right"))
 {
   digitalWrite(_pin2, LOW);
   digitalWrite(_pin4, LOW);
   digitalWrite(_pin5, LOW);
   digitalWrite(_pin7, LOW);
   analogWrite(_pin1, vel);
   analogWrite(_pin3, vel);
   analogWrite(_pin6, vel);
   analogWrite(_pin8, vel); 
 }
}

void GMotors::Forward(float vel)
{
  _vel = vel;
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin4, LOW);
  digitalWrite(_pin8, LOW);
  digitalWrite(_pin6, LOW);
  analogWrite(_pin1, vel);
  analogWrite(_pin3, vel);
  analogWrite(_pin5, vel);
  analogWrite(_pin7, vel);
}

void GMotors::Backwards(float vel)
{
  _vel = vel;
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin3, LOW);
  digitalWrite(_pin5, LOW);
  digitalWrite(_pin7, LOW);
  analogWrite(_pin2, vel);
  analogWrite(_pin4, vel);
  analogWrite(_pin6, vel);
  analogWrite(_pin8, vel);
}

void GMotors::Left(float vel)
{
  _vel = vel;
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin4, LOW);
  digitalWrite(_pin6, LOW);
  digitalWrite(_pin7, LOW);
  analogWrite(_pin2, vel);
  analogWrite(_pin3, vel);
  analogWrite(_pin5, vel);
  analogWrite(_pin8, vel);
}

void GMotors::Right(float vel)
{
  _vel = vel;
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin3, LOW);
  digitalWrite(_pin5, LOW);
  digitalWrite(_pin8, LOW);
  analogWrite(_pin1, vel);
  analogWrite(_pin4, vel);
  analogWrite(_pin6, vel);
  analogWrite(_pin7, vel);
}

void GMotors::Diagonal(float vel, String up, String side)
{
  _vel = vel;
  if(up.equals("up") && side.equals("left"))
  {
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
    digitalWrite(_pin8, LOW);
    analogWrite(_pin1, vel);
    analogWrite(_pin7, vel);
  }
  else if(up.equals("up") && side.equals("right"))
  {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin6, LOW);
    digitalWrite(_pin7, LOW);
    digitalWrite(_pin8, LOW);
    analogWrite(_pin3, vel);
    analogWrite(_pin5, vel);
  } 
  else if(up.equals("down") && side.equals("left"))
  {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin4, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin6, LOW);
    digitalWrite(_pin7, LOW);
    analogWrite(_pin2, vel);
    analogWrite(_pin8, vel);
  }
  else if(up.equals("down") && side.equals("right"))
  {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
    digitalWrite(_pin3, LOW);
    digitalWrite(_pin5, LOW);
    digitalWrite(_pin7, LOW);
    digitalWrite(_pin8, LOW);
    analogWrite(_pin4, vel);
    analogWrite(_pin6, vel);
  } 
}

int GMotors::Return_NonRelative_Angle()
{
    compass.read();
    int angle = compass.heading();
    return angle; 
}


int GMotors::Compass1()
{
        semiAngle = Return_NonRelative_Angle() - Angle0;
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

bool GMotors::Compass(int n, int vel)
{
  compass.read();
  int heading = compass.heading();
  Actual = RelAbsAngle();
  
  if(n == 0)
  {
    if((Actual >= 0 && Actual <= 1)|| Actual <= 360 && Actual >= 359)
    {
      Release();
       return true;
    }
    else if(Actual > 1 && Actual <= 180)
    {
      Release();
      Turn(vel, "left");
      return false;
    }
    else if(Actual >  180 && Actual < 359)
    {
      Release();
      Turn(vel, "right");
      return false;
    }
  }
  else if(n == 90)
  {
    if((Actual >= 89 && Actual <= 91))
    {
      Release();
       return true;
    }
    else if(Actual > 91 && Actual <= 271)
    {
      Release();
      Turn(vel, "left");
      return false;
    }
    else if((Actual > 271 && Actual < 360) || (Actual >= 0 && Actual < 89))
    {
      Release();
      Turn(vel, "right");
      return false;
    }
  }
  else if(n == 180)
  {
    if((Actual >= 179 && Actual <= 181))
    {
       Release();
       return true;
    }
    else if((Actual >  181 && Actual <= 360)||(Actual >= 0 && Actual <= 5))
    {
      Release();
      Turn(vel,"left");
      return false;
    }
    else if(Actual < 179  && Actual > 5)
    {
      Release();
      Turn(vel, "right");
      return false;
    }
  }
  else
  {
    if((Actual >= 269 && Actual <= 271))
    {
      Release();
      return true;
    }
    else if(Actual <  269 && Actual >= 90)
    {
      Release();
      Turn(vel, "right");
      return false;
    }
    else
    {
      Release();
      Turn(vel, "left");
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
  Actual = Compass1(); 
}

