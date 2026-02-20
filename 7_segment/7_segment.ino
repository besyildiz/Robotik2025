// 7 Segment Display Pin Tanımlamaları (Aynı)
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;

void setup() {
  // Tüm pinleri çıkış olarak ayarla
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  // Başlangıçta tüm segmentleri söndür (HIGH yap)
  temizle();
  
  Serial.begin(9600);
  Serial.println("7 Segment Display (Ortak Anot)");
  Serial.println("0'dan 9'a sayiyor...");
}

void loop() {
  // 0'dan 9'a kadar say
  for (int sayi = 0; sayi <= 9; sayi++) {
    Serial.print("Gosterilen: ");
    Serial.println(sayi);
    
    rakamGoster(sayi);
    delay(1000); // 1 saniye bekle
    temizle();
  }
  
  Serial.println("Dongu tamamlandi, tekrar basliyor...");
}

// Rakam gösterme fonksiyonu (ORTAK ANOT için)
// DİKKAT: HIGH ve LOW'lar ters çevrildi!
void rakamGoster(int rakam) {
  switch(rakam) {
    case 0: // 0: A,B,C,D,E,F yanar (LOW), G söner (HIGH)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
      
    case 1: // 1: B,C yanar (LOW)
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
      
    case 2: // 2: A,B,G,E,D yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
      
    case 3: // 3: A,B,C,D,G yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
      
    case 4: // 4: F,G,B,C yanar (LOW)
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
      
    case 5: // 5: A,F,G,C,D yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
      
    case 6: // 6: A,F,E,D,C,G yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
      
    case 7: // 7: A,B,C yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
      
    case 8: // 8: Tüm segmentler yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
      
    case 9: // 9: A,B,C,D,F,G yanar (LOW)
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
}

// Tüm segmentleri söndür (ORTAK ANOT için HIGH yap)
void temizle() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}