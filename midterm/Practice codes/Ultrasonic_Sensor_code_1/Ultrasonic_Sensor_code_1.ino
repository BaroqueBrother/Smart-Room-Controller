
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
  display.clearDisplay();
}




void loop() {
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2/2.54;
  Serial.printf("Distance %0.1f inches \n",distance);
  if(distance <= 10){
    welcomeInfo();
  }
  else {
    display.clearDisplay();
    display.display();
  }
  

}
void welcomeInfo(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.printf("Welcome info");
  display.display();
}
