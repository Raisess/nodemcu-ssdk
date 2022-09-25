#include "Arduino.h"
#include "Pin.h"

Board::Pin::Pin(int pin) : _pin(pin) {}

void Board::Pin::log() const {
  Serial.print("Pin: ");
  Serial.print(_pin);
  Serial.print(" | Data: ");
  Serial.println(_data);
}

Board::AnalogPin::AnalogPin(int pin, Pin::Mode mode)
  : Board::Pin(pin) {
  pinMode(_pin, mode == AnalogPin::INPUT_MODE ? INPUT : OUTPUT);
}

void Board::AnalogPin::high() {
  _data = Pin::HIGH_DATA;
  analogWrite(_pin, HIGH);
}

void Board::AnalogPin::low() {
  _data = Pin::LOW_DATA;
  analogWrite(_pin, LOW);
}

Board::DigitalPin::DigitalPin(int pin, Pin::Mode mode)
  : Board::Pin(pin) {
  pinMode(_pin, mode == DigitalPin::INPUT_MODE ? INPUT : OUTPUT);
}

void Board::DigitalPin::high() {
  _data = Pin::HIGH_DATA;
  digitalWrite(_pin, HIGH);
}

void Board::DigitalPin::low() {
  _data = Pin::LOW_DATA;
  digitalWrite(_pin, LOW);
}
