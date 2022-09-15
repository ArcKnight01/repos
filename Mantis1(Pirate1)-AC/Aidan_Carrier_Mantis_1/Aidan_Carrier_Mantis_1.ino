/*  PRIZM Controller example program 
 *  Spin DC motor channel 1 for 5 seconds, then coast to a stop.                                      
 *  After stopping, wait for 2 seconds, spin in opposite direction. 
 *  Continue to repeat until RED reset button is pressed. 
 *  author PWU on 08/05/2016 
*/
//Aidan Carrier Mantis Program
  #define REVOLUTION 1440  
  #include <PRIZM.h>    // include the PRIZM library in the sketch 
  PRIZM prizm;          // instantiate a PRIZM object “prizm” so we can use its functions 
   
  int leftMotor = 1; //Motor Pin for left motor
  int rightMotor = 2; //Motor Pin for right motor
   
void setup() {         
 
  prizm.PrizmBegin();   // Initialize the PRIZM controller 
  prizm.setMotorInvert(leftMotor, 1); //invert left motor
  
}
void loop() {     // repeat in a loop 
  float rotationCount = 25; //10>>25>>30>>25rot test 2 //first rotation count
  int motorSpeed = 360;                               // motor speed in dps.
  float rotations = 1440 * rotationCount; //for first rotation
  int seconds;                                                                                                                                                                                                                                                        
  int milisecs = 1000*seconds;          //conversion factor from seconds to milisecond
  //about 10 rot = 4 tiles = 4 ft ... according to a test where robot moved foew
  //about 25 rot = 10 tiles  2.5 rot /ft
                                        // 1FT = 12 IN = 12*2.54 CM 
  float cm = 1/(12*2.54);               //Conversion factor: 1 cm in terms of ft.
  prizm.resetEncoders();                //set motor encoders to 0
  prizm.setMotorTargets(motorSpeed, rotations, motorSpeed, rotations); //move rob 10 tiles fwd to black line
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay
  prizm.setMotorTargets(motorSpeed, 1440 * 3, motorSpeed, 1440 * -3); //turn 315 degrees counter clockwise
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay
  prizm.setMotorTargets(motorSpeed, 1440 * 7*2.5, motorSpeed, 1440 * 7*2.5); //move forward to blue line, (7 ft) 
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay
  prizm.setMotorTargets(motorSpeed, 1440 * -3, motorSpeed, 1440 * 3); //turn 315 deg clockwise
  while(prizm.readMotorBusy(1)==1){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay
  prizm.setMotorTargets(motorSpeed, 1440 * (6-2.5*cm)*2.5, motorSpeed, 1440 * (6-2.5*cm)*2.5); //move forward 2.5 cm less than 6 ft to black line.
  while(prizm.readMotorBusy(1)==1){}   //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();               //reset encoder count to 0
  delay(500);                          //half second delay
  prizm.PrizmEnd();                    //stop program

}
