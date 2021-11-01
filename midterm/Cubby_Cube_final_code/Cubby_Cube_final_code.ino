#include <Keypad.h>
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue.h>
#include <Wire.h>
#include <wemo.h>


#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
Adafruit_BME280 bme;
EthernetClient client;




float tempC;
float pressPA;
float humidRH;
bool status;
float tempF;
const char degree = 0xF8;
float presPa;
float inhg = .000295;
float pressInhg;
const byte ROWS = 4;
const byte COLS = 4;
const int trigpin = 6;
const int echopin = 7;
float distance;
long duration;
char customKey;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {14, 15, 16, 17};
byte colPins[COLS] = {20, 21, 22 , 23};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.printf("SSD1306 allocation failed");
    for (;;);
  }
  status = bme.begin(0x76);
  if (status == false) {
    Serial.printf("BME280 at address 0x%02X failed to start", 0x76);
  }
  else {}
  Ethernet.begin(mac);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
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
    readTempC();
    readHumidity();
    printOled();// bme280 info
  }
  else {}
  setHomeLighting();
}
void welcomeInfo(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Welcome info");
  display.display();
  display.setRotation(rot);
}

void livingRoomOn(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Living Room Hue ON");
  display.display();

}
void livingRoomOff(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Living Room Hue OFF");
  display.display();

}
void bedroomOn(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom Hue On");
  display.display();
}
void bedroomOff(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom Hue OFF");
  display.display();
}
void bedroom_2_On(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom 2 Hue On");
  display.display();
}
void bedroom_2_Off(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom 2 Hue Off");
  display.display();
}
void bedroom_3_On(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom 3 Hue On");
  display.display();
}
void bedroom_3_Off(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Bedroom 3 Hue Off");
  display.display();
}
void kitchenOn(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Kitchen Hue On");
  display.display();
}
void kitchenOff(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Kitchen Hue Off");
  display.display();
}
void hallwayOn(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Hallway Hue On");
  display.display();
}
void hallwayOff(void) {
  int rot = 0;// sample display to be temp,humidity,time
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Hallway Hue Off");
  display.display();
}
void hueinfo(void) {
  int rot = 0;// sample display to be replaced which hue lights are on
  display.setRotation(rot);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("hue info");
  display.display();

}
void airConditionerOn(void) {
  int rot = 0;// sample display to be replaced which hue lights are on
  display.setRotation(rot);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Air Conditoner ON");
  display.display();
}
void airConditionerOff(void) {
  int rot = 0;// sample display to be replaced which hue lights are on
  display.setRotation(rot);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Air Conditioner OFF");
  display.display();

}
void teaKettleOn(void) {
  int rot = 0;// sample display to be replaced which hue lights are on
  display.setRotation(rot);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Tea Kettle is On");
  display.display();

}
void teaKettleOff(void) {
  int rot = 0;// sample display to be replaced which hue lights are on
  display.setRotation(rot);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Tea Kettle is Off");
  display.display();

}
void readTempC() {
  tempC = bme.readTemperature();
  tempF = map(tempC, 0, 100, 32, 212);
  //Serial.printf("Temperature %.01f %c \n", tempF, degree);

}
void readPressureInhg() {
  pressPA = bme.readPressure();
  pressInhg = pressPA * inhg;
  //Serial.printf("Pressure %.01f \n", pressInhg);

}
void readHumidity() {
  humidRH = bme.readHumidity();
  //Serial.printf("Humidity %0.1f \n", humidRH);

}
void printOled(void) {
  int rot = 0;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.setRotation(rot);
  display.printf("Temperature %0.1fF \n Humidity %0.1f \n", tempF, humidRH);
  display.display();
}
void setHomeLighting(void) {
  switch (customKey) {
    case 0x31:
      setHue(1, true, HueBlue, 255, 0);
      livingRoomOn();
      break;
    case 0x32:
      setHue(1, false, HueBlue, 0, 0);
      livingRoomOff();
      break;
    case 0x33:
      setHue(2, true, HueBlue, 255, 0);
      bedroomOn();
      break;
    case 0x34:
      setHue(2, false, HueBlue, 0, 0);
      bedroomOff();
      break;
    case 0x35:
      setHue(3, true, HueBlue, 255, 0);
      bedroom_2_On();
      break;
    case 0x36:
      setHue(3, false, HueBlue, 0, 0);
      bedroom_2_Off();
      break;
    case 0x37:
      setHue(4, true, HueBlue, 255, 0);
      bedroom_3_On();
      break;
    case 0x38:
      setHue(4, false, HueBlue, 0, 0);
      bedroom_3_Off();
      break;
    case 0x39:
      setHue(5, true, HueBlue, 255, 0);
      kitchenOn();
      break;
    case 0x30:
      setHue(5, false, HueBlue, 0, 0);
      kitchenOff();
      break;
    case 0x41:
      setHue(6, true, HueBlue, 255, 0);
      hallwayOn();
      break;
    case 0x42:
      setHue(6, false, HueBlue, 0, 0);
      hallwayOff();
      break;
    case 0x43:
      switchON(1);
      airConditionerOn();
      break;
    case 0x44:
      switchOFF(1);
      airConditionerOff();
      break;
    case 0x2A:
      switchON(2);
      teaKettleOn();
      break;
    case 0x23:
      switchOFF(2);
      teaKettleOff();
      break;
  }
}
