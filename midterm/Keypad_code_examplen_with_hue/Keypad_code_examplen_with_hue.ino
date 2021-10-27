#include <Keypad.h>
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);



const byte ROWS = 4;
const byte COLS = 4;
char customKey;
const int trigpin = 6;
const int echopin = 7;
float distance;
long duration;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {14, 15, 16, 17};
byte colPins[COLS] = {18, 19, 20 , 21};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Ethernet.begin(mac);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.printf("SSD1306 allocation failed");
    for (;;);
  }
}

void loop() {
  customKey = customKeypad.getKey();
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2 / 2.54; // converts cm to inches
  Serial.printf("Distance %0.1f inches \n", distance);
  if (distance <= 3) {
    welcomeInfo();
  }
  else {}
  if (distance >3){
    hueinfo();
  }
  else{
  }
}
//  if (customKey == 0x31) {
//    setHue(1, true, HueBlue, 255, 0);
//    if(setHue(1,true,HueBlue,255,0)){
//      hue_1();
//    }
//    else{}
//
//  }
//  else {}
//
//
//
//  if (customKey == 0x32) {
//    setHue(1, false, HueBlue, 0, 0);
//  }
//  else {}
//
//  if (customKey == 0x33) {
//    setHue(2, true, HueBlue, 255, 0);
//  }
//  else {}
//
//  if (customKey == 0x34) {
//    setHue(2, false, HueBlue, 0, 0);
//  }
//  else {}
//
//  if (customKey == 0x35) {
//    setHue(3, true, HueBlue, 255, 0);
//  }
//  else {}
//
//  if (customKey == 0x36) {
//    setHue(3, false, HueBlue, 0, 0);
//  }
//  else {}
//
//  if (customKey == 0x37) {
//    setHue(4, true, HueBlue, 255, 0);
//  }
//  else {}
//
//  if (customKey == 0x38) {
//    setHue(4, false, HueBlue, 0, 0);
//  }
//  else {}
//
//  if (customKey == 0x39) {
//    setHue(5, true, HueBlue, 255, 0);
//  }
//  else {}
//
//  if (customKey == 0x30) {
//    setHue(5, false, HueBlue, 0, 0);
//  }
//  else {}
//
//  if (customKey == 0x41) {
//    setHue(6, true, HueBlue, 255, 0);
//  }
//  else {}
//
//  if (customKey == 0x42) {
//    setHue(6, false, HueBlue, 0, 0);
//  }
//  else {}
//
//}
void welcomeInfo(void) {
  int rot = 2;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Welcome info");
  display.display();
  display.setRotation(rot);
}

void hue_1() {
  int rot = 2;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Hue 1");
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
