#include <Servo.h>
#include "ServoEasing.hpp"
#include <IBusBM.h>

IBusBM ibus;

int W1_IN1=22;
int W1_IN2=23;
int W2_IN3=24;
int W2_IN4=25;
int W3_IN1=26;
int W3_IN2=27;
int W4_IN3=28;
int W4_IN4=29;
int W5_IN1=30;
int W5_IN2=31;
int W6_IN3=32;
int W6_IN4=33;

int W1_ENA=13;
int W2_ENB=12;
int W3_ENA=11;
int W4_ENB=10;
int W5_ENA=9;
int W6_ENB=8;

ServoEasing servo1;
ServoEasing servo2;
ServoEasing servo3;
ServoEasing servo4;

int ch1,ch2,ch3,ch4=0;

int servo_angle=0;
int dc_speed=0;
int W5_speed=0;



int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}



void setup() {
  Serial.begin(115200);
  ibus.begin(Serial1,IBUSBM_NOTIMER);

  servo1.attach(7, DEFAULT_MICROSECONDS_FOR_0_DEGREE, DEFAULT_MICROSECONDS_FOR_180_DEGREE, 0, 90);
  servo1.write(45);
  servo1.setSpeed(600);
  
  servo2.attach(6, DEFAULT_MICROSECONDS_FOR_0_DEGREE, DEFAULT_MICROSECONDS_FOR_180_DEGREE, 0, 90);
  servo2.write(45);
  servo2.setSpeed(600);
  
  servo3.attach(4, DEFAULT_MICROSECONDS_FOR_0_DEGREE, DEFAULT_MICROSECONDS_FOR_180_DEGREE, 0, 90);
  servo3.write(45);
  servo3.setSpeed(600);
  
  servo4.attach(5, DEFAULT_MICROSECONDS_FOR_0_DEGREE, DEFAULT_MICROSECONDS_FOR_180_DEGREE, 0, 90);
  servo4.write(45);
  servo4.setSpeed(600);



  //Set all pins to Output Mode
  pinMode(W1_IN1,OUTPUT);
  pinMode(W1_IN2,OUTPUT);
  pinMode(W2_IN3,OUTPUT);
  pinMode(W2_IN4,OUTPUT);
  pinMode(W3_IN1,OUTPUT);
  pinMode(W3_IN2,OUTPUT);
  pinMode(W4_IN3,OUTPUT);
  pinMode(W4_IN4,OUTPUT);
  pinMode(W5_IN1,OUTPUT);
  pinMode(W5_IN2,OUTPUT);
  pinMode(W6_IN3,OUTPUT);
  pinMode(W6_IN4,OUTPUT);

  pinMode(W1_ENA,OUTPUT);
  pinMode(W2_ENB,OUTPUT);
  pinMode(W3_ENA,OUTPUT);
  pinMode(W4_ENB,OUTPUT);
  pinMode(W5_ENA,OUTPUT);
  pinMode(W6_ENB,OUTPUT);
  
  // Initial State- All motors are swithced off
  digitalWrite(W1_IN1, LOW);
  digitalWrite(W1_IN2, LOW);
  digitalWrite(W2_IN3, LOW);
  digitalWrite(W2_IN4, LOW);
  digitalWrite(W3_IN1, LOW);
  digitalWrite(W3_IN2, LOW);
  digitalWrite(W4_IN3, LOW);
  digitalWrite(W4_IN4, LOW);
  digitalWrite(W5_IN1, LOW);
  digitalWrite(W5_IN2, LOW);
  digitalWrite(W6_IN3, LOW);
  digitalWrite(W6_IN4, LOW);

}

void loop() {

  //reading data from the RC transmitter
  ibus.loop();
  ch1=readChannel(0, -100, 100, 0); //left and right motion
  ch2=readChannel(1, -100, 100, 0); //front and back motion
  ch3=readChannel(2, -100, 100, 0); //Speed control


  dc_speed=map(ch3,-100,100,0,255);
  W5_speed=map(ch3,-100,100,0,55);
  servo_angle=map(ch1,-100,100,0,90);
  
  

  


  //Forward Motion
  if(dc_speed>0 && ch2<=-90)
  {

    digitalWrite(W1_IN1,LOW);
    digitalWrite(W1_IN2,HIGH);
    
    digitalWrite(W2_IN3,HIGH);
    digitalWrite(W2_IN4,LOW);

    digitalWrite(W3_IN1,HIGH);
    digitalWrite(W3_IN2,LOW);

    digitalWrite(W4_IN3,HIGH);
    digitalWrite(W4_IN4,LOW);

    digitalWrite(W5_IN1,HIGH);
    digitalWrite(W5_IN2,LOW);

    digitalWrite(W6_IN3,HIGH);
    digitalWrite(W6_IN4,LOW);

    analogWrite(W1_ENA,dc_speed);
    analogWrite(W2_ENB,dc_speed);
    analogWrite(W3_ENA,dc_speed);
    analogWrite(W4_ENB,dc_speed);
    analogWrite(W5_ENA,W5_speed);
    analogWrite(W6_ENB,dc_speed);


  }

  //Backward Motion

  if(dc_speed>0 && ch2>=90)
  {

    digitalWrite(W1_IN1,HIGH);
    digitalWrite(W1_IN2,LOW);
    
    digitalWrite(W2_IN3,LOW);
    digitalWrite(W2_IN4,HIGH);

    digitalWrite(W3_IN1,LOW);
    digitalWrite(W3_IN2,HIGH);

    digitalWrite(W4_IN3,LOW);
    digitalWrite(W4_IN4,HIGH);

    digitalWrite(W5_IN1,LOW);
    digitalWrite(W5_IN2,HIGH);

    digitalWrite(W6_IN3,LOW);
    digitalWrite(W6_IN4,HIGH);

    analogWrite(W1_ENA,dc_speed);
    analogWrite(W2_ENB,dc_speed);
    analogWrite(W3_ENA,dc_speed);
    analogWrite(W4_ENB,dc_speed);
    analogWrite(W5_ENA,W5_speed);
    analogWrite(W6_ENB,dc_speed);


  }

  //stop
  if(ch2==0 || ch3==0)
  {
    digitalWrite(W1_IN1,LOW);
    digitalWrite(W1_IN2,LOW);
    
    digitalWrite(W2_IN3,LOW);
    digitalWrite(W2_IN4,LOW);

    digitalWrite(W3_IN1,LOW);
    digitalWrite(W3_IN2,LOW);

    digitalWrite(W4_IN3,LOW);
    digitalWrite(W4_IN4,LOW);

    digitalWrite(W5_IN1,LOW);
    digitalWrite(W5_IN2,LOW);

    digitalWrite(W6_IN3,LOW);
    digitalWrite(W6_IN4,LOW);
  }

  
  if(ch1>0)
  {
    servo1.startEaseTo(servo_angle);
    servo2.startEaseTo(servo_angle);
    servo3.startEaseTo(servo_angle);
    servo4.startEaseTo(servo_angle);
  }

  if(ch1<0)
  {
    servo1.startEaseTo(servo_angle);
    servo2.startEaseTo(servo_angle);
    servo3.startEaseTo(servo_angle);
    servo4.startEaseTo(servo_angle);

  }

  if(ch1==0)
  {
    servo1.startEaseTo(45);
    servo2.startEaseTo(45);
    servo3.startEaseTo(45);
    servo4.startEaseTo(45);
  }

  


}



