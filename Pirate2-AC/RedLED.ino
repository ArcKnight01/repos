//flash led as indicator
void TurnOnRedLED(float Seconds){
  prizm.setRedLED(HIGH);       // flash Prizm red LED on and off 
  delay(Seconds*1000);
  prizm.setRedLED(LOW);
}
