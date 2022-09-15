void TurnOnRedLED(float Seconds){
  prizm.setRedLED(HIGH);       // flash Prizm red LED on and off until reset
  delay(Seconds*1000);
  prizm.setRedLED(LOW);
}
