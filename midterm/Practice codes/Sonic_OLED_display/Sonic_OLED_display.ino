//#include "oledHue.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);


const int trigpin = 6;
const int echopin = 7;
float distance;
long duration;



void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
  Serial.printf("SSD1306 allocation failed");
  for(;;); 
  }
  display.clearDisplay(); // sets default to blank screen
}




void loop() {
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2/2.54; // converts cm to inches
  Serial.printf("Distance %0.1f inches \n",distance);
  if(distance <= 3){ // when within 10 in, turns on led 
    welcomeInfo(); 
  }
  else {
  }
  if(distance>10){
   hueinfo();
  }
  else {
    //display.clearDisplay(); // returns blank screen after leaving 10 inches away from sensor
    //display.display();
    
  }

}
void welcomeInfo(){
  int rot = 2;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.printf("Welcome info");
  display.display();
  display.setRotation(rot);
}
void hueinfo(){
  int rot = 2;// sample display to be replaced which hue lights are on
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.printf("hue info");
  display.display();
  display.setRotation(rot);
}
