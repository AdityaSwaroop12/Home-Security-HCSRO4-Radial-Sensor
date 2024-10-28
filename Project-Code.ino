#include "Arduino.h"

const int BUZZER_PIN = 9;    // Pin for buzzer
const int ECHOPIN = 10;
const int TRIGPIN = 11;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(5);

  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGPIN,LOW);
  float duration = pulseIn(ECHOPIN,HIGH);
  float distance = duration/58; // in cm

  if (distance < 10) {
    tone(BUZZER_PIN, 1000); // Play 1kHz tone
  } else {
    noTone(BUZZER_PIN); // Stop tone
  }

  delay(100); // Loop delay to avoid rapid toggling
}
