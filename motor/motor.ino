#include <SoftwareSerial.h>

SoftwareSerial BT(12, 11); // recev , trans // recev , trans
char val;

const byte IN1 = 6;
const byte IN2 = 7;
const byte IN3 = 8;
const byte IN4 = 9;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 // Serial.begin(9600);
  BT.begin(9600);
}

void forward_A(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void backward_A(){
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
}

void forward_B(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward_B(){
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void stop_A_B(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop(){

  if (BT.available()){
    val = BT.read();
    if (val == 'w'){
      forward_A();
      forward_B();
    }
    else if (val == 'a'){
      backward_A();
      forward_B();
    }

    else if (val == 's'){
      backward_A();
      backward_B();
    }

    else if(val == 'd'){
      forward_A();
      backward_B();
    }
    delay(2000);
  }
  else{
    stop_A_B();
  }
}
