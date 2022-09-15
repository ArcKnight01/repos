#include <PRIZM.h>      // include the PRIZM Library

PRIZM prizm;            // instantiate a PRIZM object “prizm” so we can use its functions

const int Motor1 = 1;
const int Motor2 = 2;
const int leftMotor = 1;
const int rightMotor = 2;
const int Sonar = 3;
const int LineSensor = 2;
unsigned int baud = 9600;
const int busy = 1;
int Speed = 180;

void TurnOnRedLED(float Seconds);
float CheckPID(float dist);
float checkLineSensor(float motorSpeed);
void  driveMotorsFwd(float encoderDistance, int motor_Speed);
void  clockwiseTurn(int motor_Speed);
void  counterClockwiseTurn(int motor_Speed);
void  lineFollow();
void setup() {
  // put your setup code here, to run once:
  prizm.PrizmBegin();     // initialize PRIZM
  prizm.setMotorInvert(rightMotor, 1); //make right Motor go backwards so both motors spin backwards thus both wheels spin fwd
  Serial.begin(baud);     // configure the serial monitor for 9600 baud rate
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);
  //TurnOnRedLED(1); 
}

void loop() {
 //  while(true){ Serial.println(prizm.readSonicSensorCM(Sonar));}
  //test one aspect:
 delay(1000);                           //half second delay
 checkLineSensor(180); //works
  delay(500);             //works
  TurnOnRedLED(2.5);      //works
  delay(100);
  
  lineFollow();           //doesnt work
  delay(1000);            //
  TurnOnRedLED(2.5);      //
  CheckPID(10);
  delay(1000);
  CheckPID(10);
  delay(2000); 
  checkLineSensor(180);
  prizm.setMotorSpeeds(0,0); 
  delay(100);
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                           //half second delay
  prizm.setMotorTargets(Speed, 1440 * 0.2*2.5, Speed, 1440 * 0.2*2.5);  //0.2 distance
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay

  
  while(true){Serial.println(prizm.readLineSensor(2));} //infinite loop;
  
  // put your main code here, to run repeatedly:
  delay(500);
  checkLineSensor(180); //Drive to line.
  delay(500);
  TurnOnRedLED(2.5);
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                           //half second delay
  prizm.setMotorTargets(Speed, 1440 * 0.2*2.5, Speed, 1440 * 0.2*2.5);  //0.2 distance
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay

  prizm.setMotorTargets(Speed, 1440 * 2, Speed, 1440 * -2); //turn 90 deg clockwise SWITCH!!!!!!!!!!!

  while(prizm.readMotorBusy(1)==1){}    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);
  prizm.setMotorTargets(Speed, 1440 * 2*2.5, Speed, 1440 * 2*2.5); 
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay

CheckPID(30);
delay(200);
clockwiseTurn(Speed);

//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//  prizm.setMotorTargets(Speed, 0, Speed, 1440 * 4.1); //turn 90 deg clockwise  SWITCH!!!!!!!!!!!
//  while(prizm.readMotorBusy(2)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);   //half second delay
//
CheckPID(25);
delay(200);
clockwiseTurn(Speed);

//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//  prizm.setMotorTargets(Speed, 0, Speed, 1440 * 4.1); //turn 90 deg clockwise
//  while(prizm.readMotorBusy(2)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//
CheckPID(30);
delay(200);
counterClockwiseTurn(Speed);
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay 
//  prizm.setMotorTargets(Speed, 1440 * 4.1, Speed, 0); //turn 90 deg counterclockwise
//  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//
  CheckPID(30);
  delay(200);
  counterClockwiseTurn(Speed);
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay 
//  prizm.setMotorTargets(Speed, 1440 * 4.1, Speed, 0); //turn 90 deg counterclockwise
//  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//
  CheckPID(30);
  delay(200);
  clockwiseTurn(Speed);
  
//  prizm.resetEncoders();                //reset encoder count to 0
//  delay(500);                           //half second delay
//  prizm.setMotorTargets(Speed, 0, Speed, 1440 * 4.1); //turn 90 deg clockwise
//  while(prizm.readMotorBusy(2)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
//  prizm.resetEncoders();                //reset encoder count to 0
  delay(1000);                           //half second delay
 checkLineSensor(180); //works
  delay(500);             //works
  TurnOnRedLED(2.5);      //works
  delay(100);
  
  lineFollow();           //doesnt work
  delay(1000);            //
  TurnOnRedLED(2.5);      //
  CheckPID(15);
  delay(1000);
  while(prizm.readLineSensor(LineSensor) == 0){
      prizm.setMotorSpeeds(90,-50); 
      prizm.setRedLED(LOW);
   if(prizm.readLineSensor(LineSensor) == 1){
     prizm.setMotorSpeeds(0,0); 
     delay(100);
     prizm.setRedLED(HIGH);
    } 
    }
    CheckPID(15);
    delay(2000); 
  checkLineSensor(180);
  prizm.setMotorSpeeds(0,0); 
  delay(100);
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                           //half second delay
  prizm.setMotorTargets(Speed, 1440 * 0.2*2.5, Speed, 1440 * 0.2*2.5);  //0.2 distance
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay
  
  
  //End Program:
 prizm.PrizmEnd();

  
}
