#include <Zumo32U4.h>
#include <Wire.h>

#include "Turnsensor.h"

const int16_t maxSpeed = 200;
int turnSpeed = 150;

Zumo32U4Motors motors;

L3G gyro;

void setup() 
{
  // put your setup code here, to run once:

  Serial1.begin(9600);        //The xBee Port...
  Serial.begin(9600);         //The USB Port...

  delay(2000);

  turnSensorSetup();
  delay(500);
  turnSensorReset();

  delay(100);

  forwards();
}

void loop()
{
  // put your main code here, to run repeatedly:

  turnSensorUpdate();

  if(Serial1.available() > 0)
  {

    ledGreen(1);
    
    char input = Serial1.read(); //read in input and convert to char

    switch(input)
    {
      case 'w': //If W is recieved the zumo will move forward.
        forwards();
        break;
      case 'a': //If A is recieved the zumo will turn left.
        turnLeft(90);
        break;
      case 's': //If S is recieved the zumo will move backwards.
        backwards();
        break;
      case 'd': //If D is recieved the zumo will turn right.
        turnRight(90);
        break;
    }
  }
  else 
  {
     ledRed(1);
  }

}


void forwards()
{
  motors.setSpeeds(maxSpeed, maxSpeed);
  delay(1000);
  motors.setSpeeds(0, 0);
}

void backwards()
{
  motors.setSpeeds(-maxSpeed, -maxSpeed);
  delay(1000);
  motors.setSpeeds(0, 0);
}

void turnLeft(int degrees) {
  turnSensorReset();
  motors.setSpeeds(-turnSpeed, turnSpeed);
  int angle = 0;
  do {
    delay(1);
    turnSensorUpdate();
    angle = (((int32_t)turnAngle >> 16) * 360) >> 16;
  } while (angle < degrees);
  motors.setSpeeds(0, 0);
}

void turnRight(int degrees) {
  turnSensorReset();
  motors.setSpeeds(turnSpeed, -turnSpeed);
  int angle = 0;
  do {
    delay(1);
    turnSensorUpdate();
    angle = (((int32_t)turnAngle >> 16) * 360) >> 16;
  } while (angle > -degrees);
  motors.setSpeeds(0, 0);
}




int32_t getAngle() 
{
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}
