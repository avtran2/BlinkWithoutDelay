/*
  BlinkWithoutDelay
*/
// constants won't change. Used here to set a pin number:
const int Red=12;// the number of the LED pin
const int Green=33;// the number of the LED pin
const int Blue=27;// the number of the LED pin

// Variables will change:
int ledState=HIGH;// ledState used to set the LED; set on high first so that ledState will be high on even numbered loops

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis=0;// will store last time LED was updated

// constants won't change:
const long interval=1000;// interval at which to blink (milliseconds)

//Tracks which LED to turn on
int color=0;//tracks how many loops the sketch has run

void setup() {
  // set the digital pin as output:
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);  
  pinMode(Blue, OUTPUT);
}

void loop() {  
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis=millis();
  
  if(currentMillis-previousMillis>=interval) 
  {
    //Save the last time you blinked the LED
    previousMillis=currentMillis;
  
    //if clause that checks if the LED is off turn it on and vice-versa:
    if(ledState==LOW) 
    {
      ledState=HIGH;    
      color+=1;//color increments by 1
    }
    else 
    {
      ledState=LOW;
    }     

    //If clause that checks the modulo of color
    if(color%6==0)//Check if color fits the condition in sequential order
    {
      digitalWrite(Blue, ledState);   
      color=0;//Reset the counter to allow for RGB pattern  
    }
    else if(color%4==0)
    {
      digitalWrite(Green, ledState);  
    }
    else if(color%2==0)
    {
      digitalWrite(Red, ledState); 
    }   
  }
 } 
  
