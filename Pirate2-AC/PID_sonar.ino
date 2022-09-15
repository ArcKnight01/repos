//Proportional Integral Differential Controller Program
//To drive forward to wall until at exact distance (dist) desired away from wall
float CheckPID(float dist){
  
float Kp = 5; //proportional gain
float Kd =  0.5; //differential gain

float distance;  //distance  away from wall
float error = -1;  // put error as -1 initially so it doesnt effect program by starting as 0 will at first make PID controller inaccurate, but redefined in PID program
float prev_error;  //previous error
float ref = dist; //desired distance away from wall 
float diff_error; //difference between the error and the previous error
float driveSpeed; //speed of motors
int seconds;

while(true){
  if(error != 0){
    distance = prizm.readSonicSensorCM(Sonar); //get distance in cm
    prev_error = error; //store current error into previous error for next cycle
    error = distance - ref; //error value between target dist and actual
    diff_error = error - prev_error;  // difference between current error and previous error
    driveSpeed = Kp * error + Kd * diff_error; //PID Calculation using proportional gain and differential gain to determine new speed
    
    //constrain motor speed
    if (driveSpeed > 180) {driveSpeed = 180;}
    if (driveSpeed < -180) {driveSpeed = -180;}
    // driveSpeed = constrain(driveSpeed, -180, 180);
    
    prizm.setMotorSpeeds(driveSpeed, driveSpeed);
    Serial.println(error);   // print the CM distance to the serial monitor
    delay(50); //small delay
  }
  else{
    //exit loop when at desired distance.
    prizm.setRedLED(HIGH); //indication light
    delay(2500);
    prizm.setRedLED(LOW);
    delay(50);
    break; //exit loop when error == 0
    
  }
   
  }
}
