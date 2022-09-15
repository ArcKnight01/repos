//Aidan Carrier
//Red LED function
void TurnOnRedLED(float Seconds){
  // flash Prizm red LED on and off 
  prizm.setRedLED(HIGH); //turn on led
  delay(Seconds*1000);   //delay set number of seconds
  prizm.setRedLED(LOW);  //turn off
} 
