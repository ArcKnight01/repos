void driveMotorsFwd(float encoderDistance, int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(200);                          // delay
  prizm.setMotorTargets(motor_Speed, 1440 * encoderDistance * 2.5, motor_Speed, 1440 * encoderDistance * 2.5);  
  while(prizm.readMotorBusy(rightMotor)== busy){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                         //half second delay
}
void clockwiseTurn(int motor_Speed){
  
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay 
  prizm.setMotorTargets(Speed, 1440 * 4.1, Speed, 0); //turn 90 deg counterclockwise
  while(prizm.readMotorBusy(leftMotor)== busy){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay

}
void counterClockwiseTurn(int motor_Speed){
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay 
  prizm.setMotorTargets(motor_Speed, 0, motor_Speed, 1440 * 4.1); //turn 90 deg counterclockwise 
  while(prizm.readMotorBusy(rightMotor)== busy){}    //check to see if motor is running, if so... keep running motors until they reach targets
  prizm.resetEncoders();                //reset encoder count to 0
  delay(500);                           //half second delay
}
