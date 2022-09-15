
 void lineFollow(){
  float thresh = 10; //threshold distance 
  float a = -50; 
  float b = 90;
  a = map(a, 0, 100, 0, 360);
  b = map(b, 0, 100, 0, 360);

  
 // beam reflected, no line detected
 while(true){
  
  Serial.println(prizm.readSonicSensorCM(Sonar));
  
  if(prizm.readSonicSensorCM(Sonar)> thresh){

    //run line follow
    if(prizm.readLineSensor(LineSensor) == 0){
      prizm.setMotorSpeeds(b,a); 
      prizm.setRedLED(LOW);
    }  

  // no relected beam, line detected
    if(prizm.readLineSensor(LineSensor) == 1){
     prizm.setMotorSpeeds(a,b); 
     prizm.setRedLED(HIGH);
    } 

  }
  else if (prizm.readSonicSensorCM(Sonar)<= thresh){
    prizm.setMotorSpeeds(0,0);
    delay(500);
    if(prizm.readSonicSensorCM(Sonar)<=thresh){
    Serial.println("detected at:");
    Serial.println(prizm.readSonicSensorCM(Sonar));
    delay(1000);
    TurnOnRedLED(1);
    break;
    } else {
      Serial.println("ERROR!!!!");
      
    }
    
  }
  
 
  
  } //end while loop
 
 } //end func

 
 
