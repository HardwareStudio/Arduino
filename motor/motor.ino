#include <SoftwareSerial.h>

SoftwareSerial BT(12, 11); // recev , trans // recev , trans
char val;

const byte ENA = 4;
const byte ENB = 5;
const byte IN1 = 6;
const byte IN2 = 7;
const byte IN3 = 8;
const byte IN4 = 9;


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
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void stop_A(){
  digitalWrite(ENA, LOW);
}

void start_A(){
  digitalWrite(ENA, HIGH);
}

void stop_B(){
  digitalWrite(ENB, LOW);
}

void start_B(){
  digitalWrite(ENB, HIGH);
}

void start_A_B(){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  BT.println("bluetooth begin !!");
  BT.println(HIGH);
}

char last = 'w';
void loop(){
  
  if (BT.available()){
    val = BT.read();
    start_A_B();
    if (val == 'w'){
      if (last == 's'){
        stop_A_B();
        delay(1000);
        last = 'w';
        Serial.println("Here is go delay!!");
      }
      start_A_B();
      forward_A();
      forward_B();
      
      Serial.println("Go forward !!");
    }
    else if (val == 'a'){
      stop_A();
      start_B();
      forward_B();
      Serial.println("GO left !!!");
    }

    else if (val == 's'){
      if (last == 'w'){
        stop_A_B();
        delay(1000);
        last = 's';
      }
      start_A_B();
      backward_A();
      backward_B();
      Serial.println("GO back !!!");
    }

    else if(val == 'd'){
      forward_A();
      start_A();
      stop_B();
      Serial.println("Go right !!!");
    }
    else{
      stop_A_B();
    }
    //delay(1000);
  }
  else{
    //Serial.println("STOP!!!");
    //stop_A_B();
  }


}
