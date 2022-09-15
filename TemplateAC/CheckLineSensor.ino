//Check Line Sensor Program:
//Created by Aidan Carrier
float checkLineSensor(float motorSpeed){
  while(prizm.readLineSensor(LineSensor) == white){ //run if line isnt detected
    Serial.println(prizm.readLineSensor(LineSensor)); //Serial Output
    prizm.setMotorSpeeds(90, 90); // set motors speeds to 90 rpm
  
    if(prizm.readLineSensor(LineSensor) == black){ //check if line sensor detects line
      prizm.setMotorSpeeds(0, 0); //stop motors
      delay(500);
      break;
    }
  }
  TurnOnRedLED(2.5);
  
}
