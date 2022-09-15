float CheckPID(float dist){
  
float Kp = 5;
float Kd =  0.5;
float distance;
float error = -1;
float prev_error;
float ref = dist;
float diff_error;
float driveSpeed;
int seconds;
while(true){
  if(error != 0){
    distance = prizm.readSonicSensorCM(Sonar);
    prev_error = error;
    error = distance - ref;
    diff_error = error - prev_error;
    driveSpeed = Kp * error + Kd * diff_error;
    if (driveSpeed > 180) {driveSpeed = 180;}
    if (driveSpeed < -180) {driveSpeed = -180;}
    // driveSpeed = constrain(driveSpeed, -180, 180);
    prizm.setMotorSpeeds(driveSpeed, driveSpeed);
//    Serial.println(error);   // print the CM distance to the serial monitor
    delay(50);
  }
  else{
//    prizm.setGreenLED(HIGH);       // flash Prizm red LED on and off until reset
//    delay(2500);
//    prizm.setGreenLED(LOW);
//    delay(500);
    prizm.setRedLED(HIGH);
    delay(2500);
    prizm.setRedLED(LOW);
    delay(50);
    break;
  }
   
  }
}
