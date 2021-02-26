HardwareTimer pwmtimer4(4);
int nPWM = 0;

void setup() {
   pinMode(PB0, INPUT);
   pinMode(PA0, PWM);

   pwmtimer4.pause();
   pwmtimer4.setPrescaleFactor(1);
   pwmtimer4.setOverflow(4235);
   /*
      STM32 has 4 timers, each with 4 channels and 16 bit resolution. That means 65535 values. This value is important to us, as the resolution decides 
      how accurately the pwm duty cycle can be generated. Next, STM32 runs at speeds of 72MHz. That means that we will get 72,000,000/65535 = 1.098 kHz on our PWM pins.
      
      We need a pwm frequency of 17 kHz. If we divide the controllers base frequency by the wanted pwm frequency, we will get the overflow value. (72,000,000/17,000=+- 4235).
   */
   pwmtimer4.refresh();
   pwmtimer4.resume();

   pwmWrite(PA0, 0);

   Serial.begin(9600);
   while (!Serial);
}

void loop() {
  if (Serial.available()){

    nPWM = Serial.parseInt();
       Serial.print("Nilai Frekuensi PWM = ");
       Serial.print(nPWM);
       Serial.println(" Hz");
     
    pwmWrite(PA0, nPWM);
  }
   /*
   NOW THE MOST IMPORTANT PART(???)
      Since we changed the overflow value, the resolution has changed too. For example, arduino has an 8 bit timer, so the maximum pwm value is 255.
      Stm32's 16 bit timer has maximum pwm value of 65535. After changing the overflow value, our new maximum pwm value is 3600.
      In the code you should be using pwmWrite(pin,value) function instead of analogWrite(). The output pins should be declared as PWM (pinMode(pin, PWM))
      We have to scale the current pwm value accordingly.
      Let's take my situation: I'm using 8 bit values for my simulator, so I have to scale the pwm values by 3600/255=14.12.
      So just multiply your generated pwm value by this number.
  */
  PWMv = (4235/255) * nPWM;
  Serial.println(PWMv);
}

//https://forum.arduino.cc/index.php?topic=706130.0
