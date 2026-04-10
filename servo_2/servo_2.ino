#include <Servo.h>

Servo myServo;
int pos = 0;  // Pozisyon değişkeni

void setup() {
  myServo.attach(9);
}

void loop() {
  // 0'dan 180'e yavaşça dön
  for (pos = 0; pos <= 90; pos++) {
    myServo.write(pos);
    delay(30);  // Hız ayarı (düşük sayı = hızlı)
  }
  
  // 180'den 0'a yavaşça dön
  for (pos = 90; pos >= 0; pos--) {
    myServo.write(pos);
    delay(30);
  }
}