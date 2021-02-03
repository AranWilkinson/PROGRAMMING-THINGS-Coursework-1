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

  delay(2000);                //Wait 2 secs to make sure the serails are set up correctly..

  turnSensorSetup();          //Start up code for the turnsensor
  delay(500);
  turnSensorReset();          //Reset the turn sensor

  delay(100);
}

void loop()
{
  // put your main code here, to run repeatedly:

  turnSensorUpdate();       //Updates the turn sensor rotation.

  if(Serial1.available() > 0)
  {

    ledGreen(1);    //Green led lights up when Serial1 is ready...
    
    char input = Serial1.read(); //read in input and convert to char

    switch(input)               //Takes the input char and does the correct operation based on the char
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
     ledRed(1);     //Red led lights up when Serial1 is not ready...
  }

}


void forwards()
{
  motors.setSpeeds(maxSpeed, maxSpeed);   //Motors move forward at maxSpeed;
  delay(1000);                            //Wait 1 sec...
  motors.setSpeeds(0, 0);                 //Motors stop moving;
}

void backwards()
{
  motors.setSpeeds(-maxSpeed, -maxSpeed); //Motors move backward at maxSpeed;
  delay(1000);                            //Wait 1 sec...
  motors.setSpeeds(0, 0);                 //Motors stop moving;
}

void turnLeft(int degrees) 
{
  turnSensorReset();                                  //Reset turnsensor
  motors.setSpeeds(-turnSpeed, turnSpeed);            //Make motors turn left.
  int angle = 0;                                      //Set angle to 0
  do 
  {                                                   //Whilst robot still needs to turn (eangle is not met)
    delay(1);                                         //Wait 1ms
    turnSensorUpdate();                               //Update turn sensor
    angle = (((int32_t)turnAngle >> 16) * 360) >> 16; //get current angle
  } 
  while (angle < degrees);                            //Check is current angle is the same as the target one.
  
  motors.setSpeeds(0, 0);                             //Turn motors off.. (turn completed)
}

void turnRight(int degrees) 
{
  turnSensorReset();                                   //Reset turnsensor
  motors.setSpeeds(turnSpeed, -turnSpeed);             //Make motors turn right.
  int angle = 0;                                       //Set angle to 0
  do 
  {                                                    //Whilst robot still needs to turn (eangle is not met)
    delay(1);                                          //Wait 1ms
    turnSensorUpdate();                                //Update turn sensor
    angle = (((int32_t)turnAngle >> 16) * 360) >> 16;  //get current angle
  } 
  while (angle > -degrees);                            //Check is current angle is the same as the target one.
  
  motors.setSpeeds(0, 0);                              //Turn motors off.. (turn completed)
}



//A simple helper function to convert the sensor reading to angle.
int32_t getAngle() 
{
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}
