float checkLineSensor(float motorSpeed){
while(prizm.readLineSensor(2)== 0){
  Serial.println(prizm.readLineSensor(2));
  prizm.setMotorSpeeds(90, 90);
  
  if(prizm.readLineSensor(2)==1){
    Serial.println("detected at:");
    Serial.println(prizm.readLineSensor(2));
    prizm.setMotorSpeeds(0, 0);
    delay(200);
//    break;
  }
}
  
  prizm.setRedLED(HIGH);       // flash Prizm red LED on and off until reset
  delay(2500);
  prizm.setRedLED(LOW);
  
}
