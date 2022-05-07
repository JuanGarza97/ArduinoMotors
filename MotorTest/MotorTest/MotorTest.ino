#include <GMotors.h> //import GMotors library
#include <Wire.h>
#include <LSM303.h>

GMotors M(2,3,4,5,6,7,8,9); //Make a reference to 4 motors

/*
Methods

Motor(int speed, int motor) moves just one motor at indicated speed and direction
Forward(int speed) the robot goes forward at the indicated speed
Backwards(int speed) the robot goes backwards at the indicated speed
Left(int speed) the robot goes left at the indicated speed
Right(int speed) the robot goes right at the indicated speed
Diagonal(int speed, int up, int side) 
Release () turns off the motors
Accelerate () goes from actual speed to indicated speed
Release (int sctuslSpeed, int desiredSpeed, int delay) deaccelerates actualSpeed to indicatedSpeed
Turn (int speed, String direction) the robot turns in the indicated speed and direction
Compass (int degree, int speed) the robot turns to the indicated angle 0, 90, 180, 270 to the indicated speed
compassConfig(int min1, int min2, int min3, int max1, int max2, int max3) configure the compass 
*/

void setup()
{
  compassConfig(-6135, -2777, -3425, -2427, 339, -2903);
}

void loop()
{
  Compass();
}
