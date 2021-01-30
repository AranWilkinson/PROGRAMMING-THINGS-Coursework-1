#include <Zumo32U4.h>
#include <Wire.h>

#include "Turnsensor.h"


Zumo32U4Motors motors;

L3G gyro;

void setup() 
{
  // put your setup code here, to run once:

  Serial1.begin(9600);

  delay(2000);

  turnSensorSetup();
  delay(500);
  turnSensorReset();
}

void loop()
{
  // put your main code here, to run repeatedly:

  turnSensorUpdate();

  
  forward();

  delay(1000);

  stop();

  delay(1000);

  turn(90);

  delay(1000);

  /*
  if(serial1.availiable())
  {
    char input = Serial1.read(); //read in input and convert to char

    switch(input)
    {
      case 'w': //If W is recieved the zumo will move forward.
        forward();
        break;
    }
    
  }
  */
}


void forward()
{
  motors.setSpeeds(50, 50);
}

void backwards()
{
  motors.setSpeeds(-50, -50);
}

void turn(int32_t change)
{
  int32_t  startAngle = getAngle();
  int32_t  current = startAngle;
  while(current != startAngle+change)
  {
    turnSensorUpdate();
    current = getAngle();
    
    if(change > 0) motors.setSpeeds(0, 5);
    else           motors.setSpeeds(5, 0);
  }
}

void stop()
{
  motors.setSpeeds(0, 0);
}




int32_t getAngle() 
{
  // turnAngle is a variable defined in TurnSensor.cpp
  // This fancy math converts the number into degrees turned since the
  // last sensor reset.
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}
