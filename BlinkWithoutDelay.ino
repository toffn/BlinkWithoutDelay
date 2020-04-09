//BlinkWithoutDelay
//Toff Nguyen

#include <analogWrite.h>

int state = 0;
int stateRed = 1;
int stateGreen = 2;
int stateBlue = 3;
int stateRave = 4;

unsigned long interval = 1000;
unsigned long prevMillis = 0;

int redLED = 12;
int greenLED = 27;
int blueLED = 33;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(33, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  //Turn off GB
  if(state==stateRed)
    {
      analogWrite(redLED,HIGH);
      analogWrite(greenLED,LOW);
      analogWrite(blueLED,LOW);
  
    }
    
  //Turn off RB
  else if(state==stateGreen)
    {
      analogWrite(redLED,LOW);
      analogWrite(greenLED,HIGH);
      analogWrite(blueLED,LOW);
    }
    
  //Turn off RG
  else if(state==stateBlue)
    {
      analogWrite(redLED,LOW);
      analogWrite(greenLED,LOW);
      analogWrite(blueLED,HIGH);
    }
    
  //Turn on all
  else if(state==stateRave)
    {
      analogWrite(redLED,HIGH);
      analogWrite(greenLED,HIGH);
      analogWrite(blueLED,HIGH);
    }


  //Keep incrementing state for a certain number of milliseconds, reset state to red when done with rave blinking
  if((currentMillis - prevMillis) >= interval)
    {
      state++;
      if(state==5)
        {
          state=1;
        }
      prevMillis=millis();
    }
}
