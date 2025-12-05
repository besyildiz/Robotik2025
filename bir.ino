void setup()
{
  pinMode(13,OUTPUT);

}

void loop()
{

digitalWrite(13,1);
  delay(250);
  digitalWrite(13,0);
  delay(250);
}




/*

void setup() {
 // setup() fonksiyonu sadece bir kez çalışır.
 // setup() function runs only once.
 pinMode(ledPin, OUTPUT); // LED pinini çıkış (OUTPUT) olarak ayarla / set pin as OUTPUT
}
void loop() {
 // loop() fonksiyonu sürekli tekrar eder.
 // loop() function repeats forever.
  digitalWrite(ledPin, HIGH); // LED’i yak / turn LED ON
 delay(1000); // 1 saniye bekle / wait 1 second (1000 ms)
 digitalWrite(ledPin, LOW); // LED’i söndür / turn LED OFF
 delay(1000); // 1 saniye bekle / wait 1 second
}
*/
