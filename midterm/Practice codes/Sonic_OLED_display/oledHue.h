
#include <OneButton.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3c
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
bool buttonState;
void click1(){
  buttonState = !buttonState;
}




void oledHue(){
  OneButton hueButtPin(20, false);
  buttonState = false;
  hueButtPin.tick();
  hueButtPin.attachClick(click1);
  if(buttonState){
  int rot = 2;// sample display to be replaced with bme readings
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.printf("Hue lights on");
  display.display();
  display.setRotation(rot);

  }
  
  else {
 //display.clearDisplay();
 //display.display();
  }
  }
