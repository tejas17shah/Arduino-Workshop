/*
Creating a Quick-Read Thermometer That Blinks the Temperature 
If the temperature is below 20 degrees Celsius, the LED will blink twice and then pause; 
if the temperature falls between 20 and 26 degrees, the LED will blink four times and then pause; 
and if the temperature is above 26 degrees, the LED will blink six times. 

We’ll make our sketch more modular by breaking it up into distinct functions that will make the sketch 
easier to follow, and the functions will be reusable. 
Our thermometer will perform two main tasks: 
measure and categorize the temperature, and blink the LED a certain number of times (determined by the temperature). 
*/


#define LED 13 
 
int blinks = 0; 
 
void setup() 
{   
  pinMode(LED, OUTPUT); 
} 
 
int checkTemp() 
{   
  float voltage  = 0;   
  float celsius  = 0;   
  float hotTemp  = 26;   
  float coldTemp = 20;   
  float sensor   = 0;   
  int result;   
   
  sensor = analogRead(0);     // read the temperature sensor and convert the result to degrees Celsius
  voltage = (sensor * 5000) / 1024; // convert raw sensor value to millivolts   
  voltage = voltage - 500;          // remove voltage offset   
  celsius = voltage / 10;           // convert millivolts to Celsius 
 
  // act on temperature range   
  if (celsius < coldTemp)   
  {     
    result = 2;   
  } 
  else if (celsius >= coldTemp && celsius <= hotTemp) 
  {    
    result = 4;   
  }   
  else   
  {     
    result = 6;    // (celsius > hotTemp)   
  }   
  
  return result; 
} 
 
void blinkLED(int cycles, int del) 
{   
  for ( int z = 0 ; z < cycles ; z++ )   
  {     
    digitalWrite(LED, HIGH);     
    delay(del);     
    digitalWrite(LED, LOW);     
    delay(del);   
  } 
} 
 
void loop() 
{   
  blinks = checkTemp();   
  blinkLED(blinks, 500);   
  delay(2000); 
}
