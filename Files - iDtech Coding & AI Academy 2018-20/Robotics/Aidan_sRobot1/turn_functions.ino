/********Turn Left**************/

void turnLeft(int motorSpeed){
  spinRightMotor(motorSpeed);
  spinLeftMotor(-motorSpeed);
}

/********Turn Right*************/

void turnRight(int motorSpeed){
  spinRightMotor(-motorSpeed);
  spinRightMotor(motorSpeed);
}
