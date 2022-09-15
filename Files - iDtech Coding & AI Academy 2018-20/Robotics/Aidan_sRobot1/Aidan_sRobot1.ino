#include <SoftwareSerial.h>
enum STATE {Fwd, Bwd, TurnRight, TurnLeft, Stop, PID};
//enum SENSOR {true, false};
STATE state = Bwd;
SoftwareSerial serialTest(9, 10);
//variables:
float distance = 0;
float ref = 20;//target value
float error; //
float driveSpeed = 150;
float prev_error = 0;
float diff_error;
float Kp = 0.5;// OR 5
float Kd = 0.5;
float sum_error = 0;
float Ki = 0.1;
float timer = 0;
float turnSpeed;
unsigned long baud = 9600;
bool templateOnScreen;

//functions
void spinLeftMotor(int motorSpeed);
void spinRightMotor(int motorSpeed);
void driveMotors(int leftMotorSpeed, int rightMotorSpeed);
float getDistance();
void turnLeft(int motorSpeed);
void turnRight(int motorSpeed);
void driveForward(int motorSpeed);
void driveBackwards(int motorSpeed);
void stopMotors();
void checkPID();


//ultrasonic sensor pins
const int trig = 11;
const int echo = 12;

// right motor
const int AIN1 = 7; // control motor pin A1
const int AIN2 = 4; // control motor pin A2
const int PWMA = 6; // control the A speed

// left motor
const int BIN1 = 2;  // control motor pin B1
const int BIN2 = 3;  // control motor pin B2
const int PWMB = 5;  // control the B speed

//switch pin
int switchPin = 13;   // start the program
//pins available: , 13
//int motorSpeed = 0;  // starting motor speed

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud);              //start the serial
  serialTest.begin(baud);
  serialTest.setTimeout(300);
  Serial.println("serial initialized"); 
  delay(10);
  
  pinMode(switchPin, INPUT_PULLUP); // button 
  
  pinMode(AIN1, OUTPUT);            // motor OUTPUTs
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.println("robot initialized"); 
  delay(10);
}
enum CURRENTSTATE {a, b};
CURRENTSTATE currentState = a;

void loop() {
  currentState = b;
  Serial.println("hi");
  switch(currentState){
      case a:
        //case 1
        currentState = b;
        break;
      
      case b:
        //case 2
        currentState = b;
        break;
      
      default:
        //default case
        break;
  }
  delay (1);
  
  /*
  int switchOn = digitalRead(switchPin); // check to see if the switch is on
  //  distance = getDistance();              //check the sensor reading
  if (switchOn == LOW) { //switch is on
    // put your main code here, to run repeatedly:
    checkPID();
    delay(10);
    //PID into FWD into BWD
/*
    //  distance = getDistance();
    //  prev_error = error;
    //  error = distance - ref;
    //  sum_error += error;
    //  diff_error = error - prev_error;rect
    //  driveSpeed = Kp * error + Ki*sum_error + Kd * diff_error;
    //  driveForward(driveSpeed);
    //  delay(50);
    *//*
//  }
//  else{
//    stopMotors();
//  }
  */
}
