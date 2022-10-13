#include "Pin.h"

Board::Pin::Pin(uint8_t pin, Mode mode) : pin(pin) {
  BoardIO::SetPin(pin, mode);
}

void Board::Pin::log() const {
  SerialIO::Print("Pin: ");
  SerialIO::Print(this->pin);
  SerialIO::Print(" | Data: ");
  SerialIO::Print(this->data, true);
}

Board::AnalogPin::AnalogPin(uint8_t pin, Mode mode)
  : Pin(pin, mode) {}

void Board::AnalogPin::high() {
  this->data = Data::_HIGH;
  BoardIO::AnalogWrite(this->pin, Data::_HIGH);
}

void Board::AnalogPin::low() {
  this->data = Data::_LOW;
  BoardIO::AnalogWrite(this->pin, Data::_LOW);
}

Board::DigitalPin::DigitalPin(uint8_t pin, Mode mode)
  : Pin(pin, mode) {}

void Board::DigitalPin::high() {
  this->data = Data::_HIGH;
  BoardIO::DigitalWrite(this->pin, Data::_HIGH);
}

void Board::DigitalPin::low() {
  this->data = Data::_LOW;
  BoardIO::DigitalWrite(this->pin, Data::_LOW);
}
