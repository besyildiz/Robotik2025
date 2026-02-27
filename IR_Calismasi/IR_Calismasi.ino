#include <IRremote.h>

int RECV_PIN = 11;  // 12 yerine 11 dene
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("IR Alıcı hazır...");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("0x");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(100);
}