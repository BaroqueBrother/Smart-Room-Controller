#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char customKey;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {14, 15, 16, 17};
byte colPins[COLS] = {20, 21, 22 , 23};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
customKey = customKeypad.getKey();
if (customKey){
Serial.printf("Key Pressed: %c\n", customKey);
Serial.printf("Key Pressed (Hex Code) 0x%02X\n",customKey);
//Serial.printf("Hue lights");

}
}
