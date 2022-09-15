//follow the line till gets to block distance of 8 away

 void lineFollow(){
  const float thresh = 10; //threshold distance 
  float a = -50;  //motor speed percenatage
  float b = 90;   //motor speed percentage
  // a and b motor speeds alternate between left and right motors below
  a = map(a, 0, 100, 0, 360); //map the percentage to rotations
  b = map(b, 0, 100, 0, 360); //~~~~~~~~~~~~~~

  
 // beam reflected, no line detected
 while(true){ //infinite loop until break
  float centimeters = prizm.readSonicSensorCM(Sonar); //store sonic sensor reading in variable
  Serial.println(centimeters); //debug
  
  if(centimeters > 8 && centimeters != 0){ //check if sonic sensor cm value is greater than 8, and not 0. if so run linefollow

    //run line follow
    if(prizm.readLineSensor(LineSensor) == 0){ //if no line detected do this:
      prizm.setMotorSpeeds(b,a); 
      prizm.setRedLED(LOW);
    }  

  // no relected beam, line detected do this:
    if(prizm.readLineSensor(LineSensor) == 1){
     prizm.setMotorSpeeds(a,b); 
     prizm.setRedLED(HIGH);
    } 

  }
  
    if (centimeters <= 8 && centimeters!= 0){ //check if sonic sensor value in cms is less than 8 not including zero to avoid sensor noise effecting program
      prizm.setMotorSpeeds(0,0); //stop motors
      delay(500); //delay half second
    
      if(centimeters <= 8){ //double check for debugging purposes
        Serial.println("detected at:");
        Serial.println(prizm.readSonicSensorCM(Sonar)); //print in sonic sensor value
        delay(1000); //delay 1000
        prizm.setMotorSpeeds(0,0); //stop
        TurnOnRedLED(1); //debug
        break; //exit loop
        } 
        else 
       {
        //error
        Serial.println("ERROR!!!!");
        delay(100);
        break;
      }
  }

  if (centimeters == 0){
    //error
    Serial.println("ERROR(ZERO)");
    delay(10);
  }
 
  
  } //end while loop
 
 } //end func

 
 
