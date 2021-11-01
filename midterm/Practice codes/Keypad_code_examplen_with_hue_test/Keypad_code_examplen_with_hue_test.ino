
#include <Keypad.h>
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue.h>
#include "displayMenus.h"

const byte ROWS = 4;
const byte COLS = 4;
char customKey;

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
  Serial.begin(9600);
  while (!Serial);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Ethernet.begin(mac);
//Setup for Sonic controlled OLED
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
  Serial.printf("SSD1306 allocation failed");
  for(;;); 
  }
  display.clearDisplay(); // sets default to blank screen

}

void loop() {
  hue_2();
}
void hue_2() {
  customKey = customKeypad.getKey();
  if (customKey == 0x31) {
    setHue(2, true, HueBlue, 255, 255);
    int rot = 2;// sample display to be replaced which hue lights are on
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.printf("Hue 2 on");
    display.display();
    display.setRotation(rot);
    Serial.printf("Key Pressed: %c\n", customKey);
    Serial.printf("Key Pressed (Hex Code) 0x%02X\n", customKey);
    Serial.printf("Hue light 2");
  }
  else {}
  if (customKey == 0x32) {
    setHue(2, false, HueBlue, 0, 0);
    int rot = 2;// sample display to be replaced which hue lights are on
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(S SD1306_WHITE);
    display.setCursor(0, 0);
    display.printf("Hue 2 off");
    display.display();
    display.setRotation(rot);
  }
  else {}
}


// maybe code:
// while (setHue(2, false, HueBlue, 0, 0)) { //practice code for simpler hue toggle
//    if (customKey == 0x31) {
//      setHue(2, true, HueBlue, 0, 0);
//    }
//else {}
// }
