// https://www.tinkercad.com/things/77ibaWnQszw/editel?sharecode=_Exj4Vu_K5mOj6F2o0-ENN4WiPG993eK5CgKXsMhkdA


// Potansiyometre ve LED pin tanımlamaları
const int potPin = A0;        // Potansiyometre analog pin A0'a bağlı
const int ledPins[] = {5, 6, 7, 8};  // LED'lerin bağlı olduğu dijital pinler

//  ledPin[0]=1 ledPin[1]=2

// PWM kontrol değişkenleri
int potValue = 0;             // Potansiyometreden okunan değer
int brightness = 0;           // LED parlaklık değeri (0-255)
bool ledsActive = false;      // LED'lerin aktif olup olmadığını kontrol et

void setup() {
  Serial.begin(9600);         // Seri iletişimi başlat
  
  // Tüm LED pinlerini çıkış olarak ayarla
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  Serial.println("Potansiyometre LED Kontrol Devresi");
  Serial.println("Pot değeri 600-800 arasındayken LED'ler aktif olacak");
  Serial.println("-------------------------------------");
}

void loop() {
  // Potansiyometre değerini oku (0-1023)
  potValue = analogRead(potPin);
  
  // Potansiyometre değerini seri porta yazdır
  Serial.print("Pot Degeri: ");
  Serial.print(potValue);
  Serial.print(" - ");
  
  // Eğer pot değeri 0-330 aralığındaysa
  if (potValue >= 0 && potValue <= 330) {
    ledsActive = true;
    
    // 0-330  arasındaki değeri 0-255 aralığına map et (PWM değeri için)
    brightness = map(potValue, 0, 330, 0, 255);
    
    // Tüm LED'leri aynı parlaklıkta yak
    for (int i = 0; i < 4; i++) {
      analogWrite(ledPins[i], brightness);
    }
    
    Serial.print("LED'ler AKTIF - Parlaklik: ");
    Serial.println(brightness);
  } 
  else {
    // Pot değeri aralık dışındaysa LED'leri söndür
    if (ledsActive) {
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
      }
      ledsActive = false;
      Serial.println("LED'ler PASIF");
    } else {
      Serial.println("LED'ler PASIF");
    }
  }
  
  delay(100);  // Okuma hızını yavaşlat (100ms)
}
