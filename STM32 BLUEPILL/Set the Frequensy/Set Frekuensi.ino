HardwareTimer pwmtimer4(4);
int pwmValue = 0;

void setup() {
   pinMode(PB0, INPUT);
   pinMode(PA0, OUTPUT);

   pwmtimer4.pause();
   pwmtimer4.setPrescaleFactor(1);
   pwmtimer4.setOverflow(4235);
   /*
      Pertama, STM32 memiliki 4 timers, masing-masing dengan 4 channels dan resolusi 16 bit. Itu berarti 65535 nilai.
      STM32 berjalan dengan kecepatan 72MHz. Itu berarti kita akan mendapatkan 72.000.000Hz / 65535 = 1.098 kHz pada pin PWM.
      
      4235 => 72.000.000 Hz / 17.000Hz(target frekuensi) = +- 4235
   */
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
