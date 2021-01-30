#include <Zumo32U4.h>
#include <Wire.h>

#include <Turnsensor.h>

Zumo32U4Motors motors;

L3G gyro;

void setup() 
{
  // put your setup code here, to run once:

  Serial1.begin(9600);

  delay(2000);
}

void loop()
{
  // put your main code here, to run repeatedly:

  forward();

  delay(1000);

  stop();

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

void turn(int a)
{
  
}

void stop()
{
  motors.setSpeeds(0, 0);
}
