int led1 = 2; // Sol dış
int led2 = 3; // Sol iç
int led3 = 4; // Orta
int led4 = 5; // Sağ iç
int led5 = 6; // Sağ dış

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  // ORTADAN DIŞA DOĞRU YANMA
  digitalWrite(led3, HIGH); delay(150);
  digitalWrite(led2, HIGH); digitalWrite(led4, HIGH); delay(150);
  digitalWrite(led1, HIGH); digitalWrite(led5, HIGH); delay(300);

  // TÜMÜ SÖNSÜN
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(300);
}
