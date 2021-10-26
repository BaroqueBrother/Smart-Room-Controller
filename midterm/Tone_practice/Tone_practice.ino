
const int spkpin = 21;




void setup() {
Serial.begin(9600);
while(!Serial);
}

void loop() {
tone(spkpin,432,200);
delay(5000);
noTone(spkpin);
}
