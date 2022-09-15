//Program to go to line then stop.
float checkLineSensor(float motorSpeed){
  
  while(prizm.readLineSensor(2)== 0){ //Check if line is sensed, if not go forward
    Serial.println(prizm.readLineSensor(2)); //read line sensor
    prizm.setMotorSpeeds(90, 90); //set motor speeds to 90
  
    if(prizm.readLineSensor(2)==1){ //if line detected exit
      Serial.println("detected at:"); // serial output
      Serial.println(prizm.readLineSensor(2)); //print line sensor value to serial
      prizm.setMotorSpeeds(0, 0); //stop motors
      delay(500); //half sec delay
      //break;
    }
  }
  
  prizm.setRedLED(HIGH);       // flash Prizm red LED on and off  as indication light
  delay(2500);
  prizm.setRedLED(LOW);
  
}
