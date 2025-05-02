#include <Arduino.h>
#include <RCSwitch.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define RF_PIN 27
#define IR_LED_PIN 4

RCSwitch mySwitch = RCSwitch();
IRsend irsend(IR_LED_PIN);

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(digitalPinToInterrupt(RF_PIN));
  irsend.begin();
  Serial.println("Listo para recibir RF");
}

void loop() {
  if (mySwitch.available()) {
    unsigned long rf_value = mySwitch.getReceivedValue();

    if (rf_value == 0) {
      Serial.println("Error de recepción");
    } else {
      Serial.print("RF recibido: ");
      Serial.println(rf_value);

    }
    mySwitch.resetAvailable();
  }
}
