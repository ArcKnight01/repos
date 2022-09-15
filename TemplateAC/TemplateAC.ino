//Created by Aidan Carrier
#include <PRIZM.h>      // include the PRIZM Library

PRIZM prizm;            // instantiate a PRIZM object “prizm” so we can use its functions

//define variables
const int Motor1 = 1;  //port that motor 1 is connected to 
const int Motor2 = 2;  //port motor 2 is connected to
const int leftMotor = Motor1; //for ease of access: left motor is motor 1
const int rightMotor = Motor2; //for ease of access: right motor is motor 2
const int LeftEncoder = Motor1; //for ease of access: left enc is motor 1's encoder port
const int RightEncoder = Motor2; //for ease of access: left enc is motor 1's encoder port
const int leftArmServo = 5;
const int rightArmServo = 6;
const int clawServo= 4;
const float armRestPosition = 180;
const float armVerticalPosition = 65;
const float armDumpPosition = 30;
const float clawOpen = 90;
const float clawClose = 40;
const int black = 1;
const int white = 0;

const int Sonar = 3;  
const int LineSensor = 2; 
unsigned int baud = 9600;
const int busy = 1; // for ease of access busy == 1
const float NormalSpeed = 180; 
const float SlowSpeed = 90;


const float in_per_rot = 9.25; //conversion for # inches per rotation
const float in_per_ft = 12; //conversion for # inches per ft
const float cm_per_ft = 30; //conversion for # cm per ft

//7*12+8.5 inches per 10 rotations so 92.5 in per 10 rot. 9.25 in per rot
void TurnOnRedLED(float Seconds); //function that flashes a red led on and then off for a period of time (Seconds)
float checkLineSensor(float motorSpeed); //function that makes the robot go forward at set speed (motor_Speed) in dps until a line is detected
void  driveMotorsFwd(float encoderDistance, float motor_Speed); //function that makes the robot move forward a set number of rotations (encoderDistance) at set speed (motor_Speed) in dps
void  driveMotorsFwdEnc(float encoderDistance, float motor_Speed); //function that makes the robot move forward a set number of rotations (encoderDistance) at set speed (motor_Speed) in dps
void turnLeft(int motor_Speed); //function that makes the robot turn left 90 degrees at set speed (motor_Speed) in dps
void turnRight(int motor_Speed); //function that makes the robot turn right 90 degat set speed (motor_Speed) in dps
void turnLeftBWDS(int motor_Speed); //function that makes the robot turn left backwards 90 deg at set speed (motor_Speed) in dps
void turnRightBWDS(int motor_Speed); //function that makes the robot turn right backwards 90 deg at set speed (motor_Speed) in dps
void lineFollow();
//12/9.25 in 
void setup() {
  // put your setup code here, to run once:
  // initialize PRIZM
  prizm.PrizmBegin();     
  prizm.setMotorInvert(leftMotor, 1); //make left Motor go backwards so both motors spin backwards, thus both wheels spin fwd
  Serial.begin(baud);     // configure the serial monitor for 9600 baud rate
  prizm.resetEncoders();                //reset encoder count to 0
  prizm.setServoSpeed(leftArmServo, 100);
  prizm.setServoSpeed(rightArmServo, 100);
  prizm.setServoSpeed(clawServo, 75);
  delay(100);                          //10th of a second delay before starting program.
  
  
}

void loop() {
  delay(1000);
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 90);
  delay(5000);
  
  prizm.setServoPosition(5, 65);
  prizm.setServoPosition(6, 65);
  prizm.setServoPosition(4, 90);
  delay(5000);
  
  for(int CanCount = 0; CanCount <= 25; CanCount++){
//start program
  lineFollow();
  delay(5000);
  prizm.setServoPosition(5, 65);
  prizm.setServoPosition(6, 65);
  prizm.setServoPosition(4, 90);
  prizm.resetEncoders();
  while(true){
    float cm = prizm.readSonicSensorCM(Sonar); //store sonic sensor reading in variable
    Serial.println(cm); //debug
    if(cm <= 20 && cm != 0){
      prizm.setMotorSpeeds(30, 30);
    }
    else if(cm > 20 && cm != 0){
      prizm.setMotorSpeeds(0, 0);
      delay(100);
      break;
    }
    else if(cm == 0){
      //nothing
    }
  }
  float USdist = prizm.readEncoderCount(RightEncoder);
  USdist = USdist/2;
  driveMotorsFwdEnc(-USdist, 40);
  
  delay(1000);
  prizm.setServoPosition(5, 65);
  prizm.setServoPosition(6, 65);
  prizm.setServoPosition(4, 90);
  
  driveMotorsFwd(15,30);
  while(prizm.readMotorBusy(rightMotor)== busy){}
  delay(5000);
   
  prizm.setServoPosition(5, 65);
  prizm.setServoPosition(6, 65);
  prizm.setServoPosition(4, 100);
  delay(5000);
  
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 100);
  delay(5000);

   prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 100);
  delay(2000);
  prizm.setServoPosition(4, 40);
  delay(5000);
  prizm.setServoPosition(5, 60);
  prizm.setServoPosition(6, 60);
  prizm.setServoPosition(4, 40);
  delay(2500);
  prizm.setServoPosition(5, 60);
  prizm.setServoPosition(6, 60);
  prizm.setServoPosition(4, 58);
  delay(100);
  prizm.setServoPosition(5, 60);
  prizm.setServoPosition(6, 60);
  prizm.setServoPosition(4, 40);
  delay(5000);
  prizm.setServoPosition(5, 20);
  prizm.setServoPosition(6, 20);
  prizm.setServoPosition(4, 40);
  delay(8000);
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 40);
  delay(5000);
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 90);
  delay(5000);
  prizm.setServoPosition(5, 65);
  prizm.setServoPosition(6, 65);
  prizm.setServoPosition(4, 90);
  
  driveMotorsFwd(16,90);
  while(prizm.readMotorBusy(rightMotor)== busy){}
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);
  prizm.setServoPosition(4, 90);
  delay(5000);
  prizm.setServoPosition(5, 180);
  prizm.setServoPosition(6, 180);

  delay(5000);
  
  
  
  }
 //End Program:
 prizm.PrizmEnd();
}
