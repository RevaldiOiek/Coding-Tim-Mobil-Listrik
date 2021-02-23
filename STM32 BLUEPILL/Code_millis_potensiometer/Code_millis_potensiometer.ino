const int pinPot = PB0;
const int pinLED = PA0;
int sensor = 0;
long waktuTerakhir = 0;
int nilaiLed;

void setup() {
  pinMode(pinPot, INPUT);
  pinMode(pinLED, OUTPUT);
  }

void loop() {
 sensor = analogRead(pinPot);
 if (millis() > waktuTerakhir + sensor) {
 if (nilaiLed == LOW) {
   nilaiLed = HIGH;
 }
 else {
 nilaiLed = LOW;
 }
 waktuTerakhir = millis();
 digitalWrite(pinLED, nilaiLed);
 }
 }
