#include <GMotors.h> //import GMotors library
#include <Wire.h>
#include <LSM303.h>

/*
Methods

moveMotor(int motor, int speed) moves just one motor at indicated speed and direction
Forward(int speed) the robot goes forward at the indicated speed
Backwards(int speed) the robot goes backwards at the indicated speed
Left(int speed) the robot goes left at the indicated speed
Right(int speed) the robot goes right at the indicated speed
Diagonal(int speed, int up, int side) 
Release () turns off the motors
Turn (int speed, String direction) the robot turns in the indicated speed and direction
Compass() returns current angle relative to the starting position
Compass (int degree, int speed) the robot turns to the indicated angle 0, 90, 180, 270 to the indicated speed
compassConfig(int min1, int min2, int min3, int max1, int max2, int max3) configure the compass 
setMotorSpeed(int motor, int max speed) sets maximum speed for that motor
distanceInMeters(float RPM, float wheel_radius, float desired_speed, float distance) delay with the time needed to move the indicated distance at indicated speed (0 - 255)
distanceInCentimeters(float RPM, float wheel_radius, float desired_speed, float distance) delay with the time needed to move the indicated distance at indicated speed (0 - 255)
*/

GMotors M(2,3,4,5,6,7,8,9); //Make a reference to 4 motors

void setup()
{
  //configure the compass
  M.compassConfig(-6135, -2777, -3425, -2427, 339, -2903);

  //sets maximum speed for all motors to 255
  M.setMotorSpeed(1, 255);
  M.setMotorSpeed(2, 255);
  M.setMotorSpeed(3, 255);
  M.setMotorSpeed(4, 255);
}

void loop()
{
  //Turns 90 degrees to the right at speed of 75
  while(!M.Compass(90, 75)){}

  //Moves forward at speed of 200 for 1 second
  M.Forward(200);
  delay(1000);
  M.Release();

  //Moves backwards at speed of 200 for 1 second
  M.Backwards(200);
  delay(1000);
  M.Release();

  //Moves left at speed of 200 for 1 second
  M.Left(200);
  delay(1000);
  M.Release();

  //Moves right at speed of 200 for 1 second
  M.Backwards(200);
  delay(1000);
  M.Release();

  //Moves diagonaly at speed of 200 for 1 second
  M.Diagonal(200, "up", "right");
  delay(1000);
  M.Release();

  //Turns left at speed of 200 for 1 second
  M.Turn(200, "left");
  delay(1000);
  M.Release();

  //Turns right at speed of 200 for 1 second
  M.Turn(200, "right");
  delay(1000);
  M.Release();

  //Moves forward at speed of 200 with motors of 100 RPM with wheels of 5.08 cm of radius for 40 cm
  M.Forward(200);
  M.distanceInCentimeters(100, 5.08, 200, 40);
  
  
}
