//Drive Motor Function: Have the motor move set number of encoder distance(rotations) at set speed.
//Created by Aidan Carrier

void driveMotorsFwd(float encoderDistance, float motor_Speed){
  //encoder distance is number of rotations
  //motor speed is the speed (PWM) of motors
  prizm.resetEncoders();                //reset encoder count to 0 
  delay(200);                          // delay 200 Ms
  prizm.setMotorTargets(motor_Speed, (1440 * encoderDistance *in_per_ft)/(cm_per_ft*in_per_rot), motor_Speed, (1440 * encoderDistance *in_per_ft)/(cm_per_ft*in_per_rot));   //rotate motor for set number of rotations
  while(prizm.readMotorBusy(rightMotor)== busy){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay
}
void driveMotorsFwdEnc(float encoderDistance, float motor_Speed){
  //encoder distance is number of rotations
  //motor speed is the speed (PWM) of motors
  prizm.resetEncoders();                //reset encoder count to 0 
  delay(200);                          // delay 200 Ms
  prizm.setMotorTargets(motor_Speed, encoderDistance, motor_Speed, encoderDistance);   //rotate motor for set number of rotations
  while(prizm.readMotorBusy(rightMotor)== busy){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay
}
void turnRight(int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);                         //half second delay
  prizm.setMotorTargets(180, 1440 * 1.17, 180, 1440 * -1.18); //turn 90 deg right
  while(prizm.readMotorBusy(2)==1){}    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);
}
void turnLeft(int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);                         //half second delay
  prizm.setMotorTargets(180, 1440 * -1.18, 180, 1440 * 1.17); //turn 90 deg left
  while(prizm.readMotorBusy(1)==1){}    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);
}
void turnRightBWDS(int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);                         //half second delay
  prizm.setMotorTargets(180, 1440 * -1.17, 180, 1440 * 1.18); //turn 90 deg right (BWDS)
  while(prizm.readMotorBusy(2)==1){}    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);
}
void turnLeftBWDS(int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);                         //half second delay
  prizm.setMotorTargets(180, 1440 * 1.18, 180, 1440 * -1.17); //turn 90 deg left (BWDS)
  while(prizm.readMotorBusy(1)==1){}    //check to see if LEFT motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);
}
