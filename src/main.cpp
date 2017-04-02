#include <Arduino.h>
#include <TM1637Display.h>

unsigned long time;

int leds[] = {5, 4, 0, 2};
#define SIZE 4
#define CLK D0
#define DIO D5

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < SIZE; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  display.setBrightness(0x0f);
}

void setLedState(int ledNumber) {
  for(int i = 0; i < SIZE; i++) {
    if(i <= ledNumber) {
      digitalWrite(leds[i], HIGH);
    }
    else {
      digitalWrite(leds[i], LOW);
    }
  }
}

void loop() {
  int pot = analogRead(A0);
  display.showNumberDec(330*pot/1024, false, 4, 0);

  if(pot > 750) {
    setLedState(3);
  }
  else if(pot > 500) {
    setLedState(2);
  }
  else if(pot > 250) {
    setLedState(1);
  }
  else if(pot > 10) {
    setLedState(0);
  }
}
