#include <Adafruit_NeoPixel.h>
#include <colors.h>
const int PIXELPIN = 17;
const int PIXELCOUNT = 16;




const int trigpin = 6;
const int echopin = 7;
float distance;
long duration;
float tenInches = 10.0;
float fifthteenInches = 15.0;
float thrityInches = 30;
float brightLvl;
Adafruit_NeoPixel pixel(PIXELCOUNT,PIXELPIN,NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pixel.begin();
  pixel.show();

}

void loop() {
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2/2.54;
  if(distance == 3){
    pixel.fill(blue,0,16);
    pixel.setBrightness(10);
    pixel.show();
  
  //float brightLvl = map(distance,0,100,0,255);
//  if(distance <= tenInches){
//  pixel.fill(blue,0,16);
//  pixel.setBrightness(10);
//  pixel.show();
//  pixel.clear();
//  pixel.show();
//  }
//  if(distance > tenInches){
//  pixel.fill(blue,0,16);
//  pixel.setBrightness(255);
//  pixel.show();
//  pixel.clear();
//  pixel.show();
  
  }
  if(distance == 10) {
    pixel.clear();
    pixel.show();
  }
//  if(distance = t
//  else{
//    pixel.clear();
//    pixel.show();
//  }
//  if(distance <= fifthteenInches){
//    pixel.fill(teal,3,15);
//    pixel.setBrightness(33);
//    pixel.show();
//  }
//  else{ 
//    pixel.clear();
//    pixel.show();
//  }
  //if(distance > feewtAway)
  //delay(500);
  
  
  
  Serial.printf("Distance %0.1f inches \n",distance); 

}
