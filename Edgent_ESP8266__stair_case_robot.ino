
#define BLYNK_TEMPLATE_ID "TMPL3MU1Qq9cL"
#define BLYNK_DEVICE_NAME "staircaserobot"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
 
int forwards=D0,right=D1,left=D2,reverses=D5;
int forwards1=D6,right1=D7,left1=D8,reverses1=3;
int forwardState;
int reversesState;
int leftState;
int rightState;

BLYNK_WRITE(V0) {
  forwardState = param.asInt();
  digitalWrite(forwards, forwardState);
}
BLYNK_WRITE(V1) {
  reversesState = param.asInt();
  digitalWrite(reverses, reversesState);
}
BLYNK_WRITE(V2) {
  leftState = param.asInt();
  digitalWrite(left, leftState);
}
BLYNK_WRITE(V3) {
  rightState = param.asInt();
  digitalWrite(right, rightState);
}

void setup()
{
  Serial.begin(115200);
   pinMode(forwards, OUTPUT);
  pinMode(right, OUTPUT); 
  pinMode(left, OUTPUT);  
  pinMode(reverses, OUTPUT);
  pinMode(forwards1, OUTPUT);
  pinMode(right1, OUTPUT); 
  pinMode(left1, OUTPUT);  
  pinMode(reverses1, OUTPUT);
  delay(1000);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
    if(forwardState==HIGH)
{
  digitalWrite(forwards,HIGH);
digitalWrite(right,LOW);
digitalWrite(left,LOW);
digitalWrite(reverses,HIGH); 

 digitalWrite(forwards1,HIGH);
digitalWrite(right1,LOW);
digitalWrite(left1,LOW);
digitalWrite(reverses1,HIGH); 

Serial.println("forward");
}
 else if(reversesState==HIGH) 
{
digitalWrite(forwards,LOW);
digitalWrite(right,HIGH);
digitalWrite(left,HIGH);
digitalWrite(reverses,LOW);

digitalWrite(forwards1,LOW);
digitalWrite(right1,HIGH);
digitalWrite(left1,HIGH);
digitalWrite(reverses1,LOW);
Serial.println("REVERSE");
} 
else if(leftState==HIGH) 
{
digitalWrite(forwards,LOW);
digitalWrite(right,HIGH);
digitalWrite(left,LOW);
digitalWrite(reverses,HIGH); 

digitalWrite(forwards1,LOW);
digitalWrite(right1,HIGH);
digitalWrite(left1,LOW);
digitalWrite(reverses1,HIGH); 
Serial.println("LEFT");
} 
 else if(rightState==HIGH) 
{
digitalWrite(forwards,HIGH);
digitalWrite(right,LOW);
digitalWrite(left,HIGH);
digitalWrite(reverses,LOW); 

digitalWrite(forwards1,HIGH);
digitalWrite(right1,LOW);
digitalWrite(left1,HIGH);
digitalWrite(reverses1,LOW); 
Serial.println("RIGHT");
}
else
{
 digitalWrite(forwards,LOW);
digitalWrite(right,LOW);
digitalWrite(left,LOW);
digitalWrite(reverses,LOW); 

digitalWrite(forwards1,LOW);
digitalWrite(right1,LOW);
digitalWrite(left1,LOW);
digitalWrite(reverses1,LOW); 
Serial.println("STOP");  
}

delay(50);
}
