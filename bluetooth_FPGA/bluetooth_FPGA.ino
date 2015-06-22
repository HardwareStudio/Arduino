/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#include <SoftwareSerial.h>

SoftwareSerial BT(10, 9);
char ch;
const byte ledPin[3] = {5, 6, 7};


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
  BT.print("BT is ready!");
}

// the loop function runs over and over again forever
void loop() {
  if(BT.available()){
    ch = BT.read();
    byte val = ch - '0';
    
    Serial.print("blue tooth = ");
    Serial.println(val);
    for(int i = 0; i < 3; ++i)
      if (val & (1<<i))
        digitalWrite(ledPin[i], HIGH);
      else
        digitalWrite(ledPin[i], LOW);
    
  }
}
