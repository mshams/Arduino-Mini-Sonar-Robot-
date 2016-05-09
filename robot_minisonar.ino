/************************
* http://blog.mshams.ir *
*************************/

#include <NewPing.h>

//pin numbers
const byte pinMotor1=4, pinMotor2=5, pinMotor3=6, pinMotor4=7;
const byte pinLed=8, pinTone=10, pinSonar1=11, pinSonar2=12;
//sound freq
const int toneFreq = 800;
//sonar distances
const byte minDistance = 42, maxDistance = 80;
//motor states
const byte M_STOP = 0, M_GO = 1, M_BACK = 2, M_RIGHT = 3, M_LEFT = 4, M_RIGHT2X = 5, M_LEFT2X = 6;
//robot states
const byte R_START = 0, R_DRIVE = 1, R_BLOCK = 2, R_TURN = 3;
//detect hangover
const int hangoverWait = 5000;
//block detect go back
const int backDist = 700, turnDist = 200;
//random behaviour
const int randomChance = 300, randomStopWait = 10000, randomTurnWait = 200;

byte state = R_START;
int i, counter = 0;
int dist;
NewPing sonar(pinSonar1, pinSonar2, 3000);

void setup() {
  randomSeed(analogRead(1));

  //init motor pins
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);  
  pinMode(pinSonar1, OUTPUT); 
  pinMode(pinSonar2, INPUT);

  //init LED pin
  pinMode(pinLed, OUTPUT);  
}

void loop() {

  switch (state){
  case R_START:
    Motor(M_GO);
    Melody();
    state = R_DRIVE;
    break;

  case R_DRIVE:
    dist = Pingu();
    if (dist>0 && dist < minDistance){
      Motor(M_STOP);
      state = R_BLOCK;
    }
    else if (random(0, randomChance) == 5) {
      RandomTone();
      Motor(M_STOP);
      delay(randomStopWait); 
      Motor(random(M_BACK, M_LEFT2X+1));
      delay(randomTurnWait);
      Motor(M_GO);
    }
    break;

  case R_BLOCK:
    Beep();
    Motor(M_BACK);
    delay(backDist);
    Motor(random(M_RIGHT2X, M_LEFT2X+1));
    delay(turnDist);
    state = R_TURN;
    break;

  case R_TURN:
    dist = Pingu();
    if (dist==0 || dist >= maxDistance){
      Motor(M_STOP);
      Motor(M_GO); 
      counter = 0;
      Beep();     
      state = R_DRIVE;
    }
    else{
      counter +=1;
      if (counter >= hangoverWait){
        counter = 0;
        Motor(M_STOP);
        RandomTone();
        state = R_BLOCK;
      }
    }
    break;
  }

}

void Blink(byte state){
  digitalWrite(pinLed, state);
}

void Beep(){
  Blink(1);
  SpeakTone(2);
  SpeakTone(1);
  Blink(0);  
}

void Melody(){
  Blink(1);
  for (int i=1; i<10; i++){
    SpeakTone(i);
  }
  Blink(0);
}

void RandomTone(){
  Blink(1);
  for (int i=1; i<10; i++){
    SpeakTone(random(1, 10));
  }
  Blink(0);
}

void SpeakTone(byte note){
  tone(pinTone, toneFreq * note);
  delay(100);
  noTone(pinTone);
}


void Motor(byte state){
  byte m1, m2, m3, m4;

  switch (state){
  case M_STOP: 
    m1 = m2 = m3 = m4 = LOW; 
    break;
  case M_GO: 
    m1=HIGH; 
    m2=LOW;
    m3=HIGH;
    m4=LOW;
    break;
  case M_BACK: 
    m1=LOW; 
    m2=HIGH;
    m3=LOW;
    m4=HIGH;
    break;
  case M_RIGHT: 
    m1=HIGH; 
    m2=LOW;
    m3=LOW;
    m4=LOW;
    break;
  case M_LEFT: 
    m1=LOW; 
    m2=LOW;
    m3=HIGH;
    m4=LOW;
    break;    
  case M_RIGHT2X: 
    m1=HIGH; 
    m2=LOW;
    m3=LOW;
    m4=HIGH;
    break;
  case M_LEFT2X: 
    m1=LOW; 
    m2=HIGH;
    m3=HIGH;
    m4=LOW;
    break;
  }
  digitalWrite(pinMotor1, m1);
  digitalWrite(pinMotor2, m2);
  digitalWrite(pinMotor3, m3);
  digitalWrite(pinMotor4, m4);   
}

int Pingu(){  
  //digitalWrite(pinSonar1, LOW);
  //delayMicroseconds(5);
  //digitalWrite(pinSonar1, HIGH);
  //delayMicroseconds(5);
  //digitalWrite(pinSonar1, LOW);
  //delayMicroseconds(2);
  //long duration = pulseIn(pinSonar2, HIGH);
  return (sonar.ping_median(5)/29/2);
}

