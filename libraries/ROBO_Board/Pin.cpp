#include "Arduino.h"
#include "Pin.h"

Board::Pin::Pin(uint8_t pin) : pin(pin) {}

void Board::Pin::log() const {
  Serial.print("Pin: ");
  Serial.print(this->pin);
  Serial.print(" | Data: ");
  Serial.println(this->data);
}

Board::AnalogPin::AnalogPin(uint8_t pin, Pin::Mode mode)
  : Board::Pin(pin) {
  pinMode(pin, mode == AnalogPin::INPUT_MODE ? INPUT : OUTPUT);
}

void Board::AnalogPin::high() {
  this->data = Pin::HIGH_DATA;
  analogWrite(this->pin, HIGH);
}

void Board::AnalogPin::low() {
  this->data = Pin::LOW_DATA;
  analogWrite(this->pin, LOW);
}

Board::DigitalPin::DigitalPin(uint8_t pin, Pin::Mode mode)
  : Board::Pin(pin) {
  pinMode(pin, mode == DigitalPin::INPUT_MODE ? INPUT : OUTPUT);
}

void Board::DigitalPin::high() {
  this->data = Pin::HIGH_DATA;
  digitalWrite(this->pin, HIGH);
}

void Board::DigitalPin::low() {
  this->data = Pin::LOW_DATA;
  digitalWrite(this->pin, LOW);
}
