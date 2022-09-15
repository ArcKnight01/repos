/*------------------ Right Motor ------------------*/

void spinLeftMotor(int motorSpeed) { // this drives the (left) motor
  //  motorSpeed = map(motorSpeed, 0, 100, 0, 255);
  if (motorSpeed > 0) {          // if the motor is given a positive speed
    digitalWrite(AIN1, HIGH);    //pin 1 is high
    digitalWrite(AIN2, LOW);     // pin 2 is low
  }
  else if (motorSpeed < 0) {     //if the motor should drive backwards (negative speed)
    digitalWrite(AIN1, LOW);     //set pin 1 to low
    digitalWrite(AIN2, HIGH);    //set pin 2 to high
  }
  else {                         //if the motor should stop
    digitalWrite(AIN1, LOW);     //set pin 1 to low
    digitalWrite(AIN2, LOW);     //set pin 2 to low
  }
  analogWrite(PWMA, abs(motorSpeed));//now that the motor direction is set, drive it at the entered speed
  motorSpeed = constrain(motorSpeed, -255, 255);


}

/*------------------ Right Motor ------------------*/

void spinRightMotor(int motorSpeed) { // this drives the(right) motor
  if (motorSpeed > 0) {           // if the motor is given a positive speed
    digitalWrite(BIN1, HIGH);     //pin 1 is high
    digitalWrite(BIN2, LOW);      // pin 2 is low
  }
  else if (motorSpeed < 0) {      //if the motor should drive backwards (negative speed)
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, HIGH);     //set pin 2 to high
  }
  else {                          //if the motor should stop
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, LOW);      //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed)); //now that the motor direction is set, drive it at the entered speed
  motorSpeed = constrain(motorSpeed, -255, 255);
}
