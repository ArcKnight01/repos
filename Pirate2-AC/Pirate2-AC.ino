//Pirate 2 Program created by Aidan Carrier
//Copy for Jazzy Wright to use 
/*
 * Dear Jazzy,
 * Thank you for being my friend. 
 * Here is the Pirate 2 Program that i made last year 
 * I am modifying it so it is commented 
 * and slightly simpler for you to use 
 * so I sincerely apologize if this is at all late
 * You have done so much for me and I owe you so much
 * You are an amazing person and one of my best friends ever.
 * I'll explain what I am doing in the comments so it is easier to personalize to your own use
 * Note the files in this program are "tabbed" meaning that all my functions are imported from them as source / header files
 * However this is done automatically so it shouldnt effect you.
 * Also, I apologize for the code being so complicated ( I was using Proportional Integral Differential Controllers in order to get 1st Place 
 * (i dont remember if i did for this, I think it might have gotten second while the first one got 1st, (due to time i think bc this takes a while to run) 
 * I had modified it after wards i remember, bc I was kinda a perfectionist then and i wanted an absolute 100 % accuracy / precision rate
 * I hope you like this, if you are confused about anything send me an email or we can zoom 
 * Thanks again for being one of the best friends I have ever had.
 * Your friend,
 *    Aidan Carrier
 *    
 *P.S. Pls modify this code so its more in your style and delete any messages / comments to you that i have left here
 *Also you need this code simplified email me and ill try to simplify it, i was just busy with a lot of hw so i didnt get to simplify it as much as you would want me to
 */

#include <PRIZM.h>      // include the PRIZM Library
PRIZM prizm;            // instantiate a PRIZM object “prizm” so we can use its functions

const int Motor1 = 1; //Pin for motor 1
const int Motor2 = 2; //Pin for motor 2

//set motors to motor pins
const int leftMotor = Motor1; 
const int rightMotor = Motor2;

//sensor pins 
const int Sonar = 3; //pin for ultrasound
const int LineSensor = 2; //pin for line sensor

//serial monitor
unsigned int baud = 9600; //baud rate
const int busy = 1; //value if serial is busy

//the speed for the motors to travel at
int Speed = 180;

//function definitions
void TurnOnRedLED(float Seconds); //turn on red led as indicator for seconds
float CheckPID(float dist); //Function to run proportional integral differential controller (PID), to move until distance (dist) away from obstacle
float checkLineSensor(float motorSpeed); //drive forward and check if line is sensed, in which case stop
void  driveMotorsFwd(float encoderDistance, int motor_Speed); //move forward distance at the set speed
void  clockwiseTurn(int motor_Speed); //make a 90 degree clockwise turn
void  counterClockwiseTurn(int motor_Speed); //counter clockwise turn
void  lineFollow(); //function to follow line as precisely as possible

void setup() {
  // put your setup code here, to run once:
  prizm.PrizmBegin();     // initialize PRIZM
  prizm.setMotorInvert(rightMotor, 1); //make right Motor go backwards so both motors spin backwards thus both wheels spin fwd
  Serial.begin(baud);     // configure the serial monitor for 9600 baud rate
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                              //1/10th second delay
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500); //delay here before loop starts:

  //Part I: Drive to Line
  checkLineSensor(180);   //drive to line then stop
  delay(500);             //half second delay (not needed)
  
  TurnOnRedLED(2.5);      //visual feedback of turning on red light for 2.5 seconds
  
  prizm.resetEncoders();                                                //reset encoder count to 0
  delay(100);                                                           //half second delay
  
  prizm.setMotorTargets(Speed, 1440 * 0.2*2.5, Speed, 1440 * 0.2*2.5);  //move froward for 0.2 inch distance at speed (aligning)
  while(prizm.readMotorBusy(1)==1){}                                    //check to see if motor is running, if so... keep running motors until they reach targets
  
  prizm.resetEncoders();                                                //reset encoder count to 0
  delay(500);                                                           //half second delay

  prizm.setMotorTargets(Speed, 1440 * 2, Speed, 1440 * -2);             //turn 90 deg clockwise (tank turn)

  while(prizm.readMotorBusy(1)==1){}                                    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  
  prizm.resetEncoders();                                                //reset encoder count to 0
  delay(500);                                                           //half second delay
  
  prizm.setMotorTargets(Speed, 1440 * 2*2.5, Speed, 1440 * 2*2.5);      //Run forward for 2 inches (aligning)
  while(prizm.readMotorBusy(1)==1){}                                    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                                                //reset encoder count to 0
  delay(500);                                                           //half second delay

//Part II: Navigate the Maze

/*
 * Hi Jazz,
 * the following distances away will need to be modified for your purposes (also, idk if Mr.O'Connor still has the maze being used if not u can modify this part
 * If this doesnt fit to your program, i am willing to make u a new modified version b/c u are my friend. =)
 * -Aidan
 */
  CheckPID(30);           //drive to wall using Proportional Integral Differential (PID) control to maintain accuracy till distance of 30 away
  delay(200);             // small delay
  clockwiseTurn(Speed);   //turn right (normal turn?)

  CheckPID(25);           //drive to wall using Proportional Integral Differential (PID) control to maintain accuracy till distance of 25 away, and then turn right
  delay(200);             
  clockwiseTurn(Speed);
 
  CheckPID(30); //drive to wall till 30 away, turn left
  delay(200);
  counterClockwiseTurn(Speed);
 
  CheckPID(30); //drive to wall till 30 away, turn left
  delay(200);
  counterClockwiseTurn(Speed);
 
  CheckPID(30); //drive to wall till 30 away, turn right
  delay(200);
  clockwiseTurn(Speed);
  
  delay(1000);  //one second delay before Line finder program begins

  //Part III drive to line
  Serial.println("Line finder started"); //Serial Output for debugging
  delay(10);                             //tiny delay  
                             
  checkLineSensor(180);  //drive forward to line
  delay(500);             //half seconds
  TurnOnRedLED(2.5);      //indication light once line detected

  //Part IV Follow the Line
  Serial.println("Line follower started"); //serial output for debugging indicating start of line follow
  delay(100);             //delay
  lineFollow();           // line follower program: Follow line until a certain distance from wood block
  delay(1000);            //delay 1 sec
  TurnOnRedLED(2.5);      //indication light

  //Part 4.5: move to be exactly 10 cm away from block
  Serial.println("Line follower Finished PID started"); //debug serial
  delay(100); //delay
  CheckPID(10); //PID control go to 10cm away from  block
  delay(100); //delay 
  Serial.println("PID finished"); //serial debug output
  delay(5000); // 5 seconds to remove block

  //Part V: Drive to X:
  //drive 10 cm forward to where the block was
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                           //half second delay
  prizm.setMotorTargets(Speed, 1440 * (1/3)*2.5, Speed, 1440 * (1/3)*2.5);  //0.2 distance
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay


  /* hey jazzy this may not work for your program 
    *b/c it was just to get 100% accuracy results and idk if it fully succeeded, i think i got it working at the end -- but your program and scenario will be slightly different)
    *either way you should prob add the part till the X, that will at least get u a sucess, the rest would center it on the X but that was not working that well and 
    *tbh it messed it up when i actually had it almost perfect. But i think i did fix it afterwards, but you should run the program to double check
     */
     
  //drive to approx location of X:
  driveMotorsFwd(2.5, 180); //drive forward 2.5 ft using drive forward program
  TurnOnRedLED(2.5); //indication light
  
  checkLineSensor(90); //drive to black X:
  prizm.setMotorSpeeds(0,0);  //stop
  delay(100);   //delay
  TurnOnRedLED(2.5);      //indication light

  Serial.println("On  X"); //debug serial output for feedback to user
  delay(100); 

  //now that it is on edge of X drive forward ).25 ft to center of X
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(100);                           //half second delay
  prizm.setMotorTargets(Speed, 1440 * (1/4)*2.5, Speed, 1440 * (1/4)*2.5);  
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay


  
  //End Program:
 prizm.PrizmEnd();

  
}
