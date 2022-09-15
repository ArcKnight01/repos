void driveMotors(int leftMotorSpeed, int rightMotorSpeed){
  spinRightMotor(leftMotorSpeed);
  spinLeftMotor(rightMotorSpeed);
}
void driveForward(int motorSpeed){
  driveMotors(motorSpeed, motorSpeed);
}

void driveBackwards(int motorSpeed){
  driveMotors(motorSpeed, -motorSpeed);
}

void stopMotors(){
  driveMotors(0, 0);
}

//driveSpeed = constrain(driveSpeed, -255, 255);
//  driveSpeed = abs(driveSpeed);
