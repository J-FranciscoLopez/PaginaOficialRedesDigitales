#include <Arduino.h>

const int ledPin = 13;    
const int botonPin = 12;  

// Variable para almacenar el estado del LED
bool estadoLED = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botonPin, INPUT);
}

void loop() {
  int estadoB = digitalRead(botonPin);
  if (estadoB == HIGH) {
    // Invierte el estado del LED
    estadoLED = !estadoLED;
    digitalWrite(ledPin, estadoLED);
  }
}
