#include <Servo.h>  // Servo kütüphanesini ekle

Servo myServo;  // Servo nesnesi oluştur

void setup() {
  myServo.attach(9);  // Servoyu pin 9'a bağla
}

void loop() {
  myServo.write(0);   // 0 dereceye dön
  delay(1000);        // 1 saniye bekle
  
  myServo.write(90);  // 90 dereceye dön (orta)
  delay(1000);        // 1 saniye bekle
  
  myServo.write(180); // 180 dereceye dön
  delay(1000);        // 1 saniye bekle
}