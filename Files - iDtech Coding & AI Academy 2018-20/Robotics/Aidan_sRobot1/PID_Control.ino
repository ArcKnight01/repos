void checkPID(){
  
   int screenCenter = 80; 
   float motor_a;
   float motor_b;
   
if (serialTest.available() > 0){
  int positionX = serialTest.parseInt();
  //int positionX = 0;
  Serial.println(positionX);

  
  if (positionX > 0){
     templateOnScreen = true;
     //run pid
     prev_error = error; //get previous error
     error = positionX - screenCenter; //calculate error
     sum_error += error; //integral control (sum of errors)
     diff_error = error - prev_error; //differential control (rate of change of error)
     
     turnSpeed = Kp * error + Ki * sum_error + Kd * diff_error; //pid controller
      //turnspeed = Kp - error;
      
      motor_a = driveSpeed + turnSpeed;
      motor_b = driveSpeed - turnSpeed;
      
      if (motor_a > 255){
        motor_a = 255;
      }
      if (motor_b > 255){ 
        motor_b = 255; 
      }
      else{
        //templateOnScreen = true;
      }
      driveMotors(motor_a, motor_b);
  }  
}
}
