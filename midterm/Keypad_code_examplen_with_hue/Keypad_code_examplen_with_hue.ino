#include <Keypad.h>
#include <SPI.h>
#include <Ethernet.h>
#include <mac.h>
#include <hue.h>

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

}

void loop() {
  customKey = customKeypad.getKey();
   if(customKey == 0x31) {
    Serial.printf("Key Pressed: %c\n", customKey);
    Serial.printf("Key Pressed (Hex Code) 0x%02X\n",customKey);
    Serial.printf("Hue light 2");
    setHue(2, true, HueBlue, 255, 255);
    }
    else{}
    if(customKey == 0x32){
      setHue(2,false,HueBlue,0,0);
    }
    else{}
    
  
}



//else {}
