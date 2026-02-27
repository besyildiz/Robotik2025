#include <IRremote.h>

#define IR_RECEIVE_PIN 11

// RGB pinleri (PWM)
const int kirmiziPin = 9;
const int yesilPin   = 10;
const int maviPin    = 6;

void rgbYak(int r, int g, int b) {
  analogWrite(kirmiziPin, r);
  analogWrite(yesilPin, g);
  analogWrite(maviPin, b);
}

void setup() {

  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);

  rgbYak(255,255,255); // başlangıçta kapalı

  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);

  Serial.println("RGB hazir...");
}

void loop() {

  if (IrReceiver.decode()) {

    uint8_t cmd = IrReceiver.decodedIRData.command;

    Serial.print("Command: ");
    Serial.println(cmd);

    if (cmd == 1) {          // 1 tuşu
      Serial.println("KIRMIZI");
      rgbYak(0,255,255);
    }
    else if (cmd == 2) {     // 2 tuşu
      Serial.println("YESIL");
      rgbYak(255,0,255);
    }
    else if (cmd == 3) {     // 3 tuşu
      Serial.println("SARI");
      rgbYak(0,0,255);
    }
    else if (cmd == 12) {   // Kapama tuşu
      Serial.println("KAPAT");
      rgbYak(255,255,255);
    }

    IrReceiver.resume();
  }
}