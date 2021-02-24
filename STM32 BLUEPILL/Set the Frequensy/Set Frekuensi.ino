HardwareTimer pwmtimer4(4);
int pwmValue = 0;

void setup() {
   pinMode(PB0, INPUT);
   pinMode(PA0, OUTPUT);

   pwmtimer4.pause();
   pwmtimer4.setPrescaleFactor(1);
   pwmtimer4.setOverflow(4235);
   pwmtimer4.refresh();
   pwmtimer4.resume();

   pwmWrite(PA0, 0);

   Serial.begin(9600);
   while (!Serial);
}

void loop() {
  if (Serial.available()){

    pwmValue = Serial.parseInt();
    Serial.println(pwmValue);
  }

  pwmWrite(PA0, pwmValue);
}
