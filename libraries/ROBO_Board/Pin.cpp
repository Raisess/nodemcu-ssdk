#include "Pin.h"

Board::Pin::Pin(uint8_t pin, BoardIO::Mode mode) : pin(pin) {
  BoardIO::SetPin(pin, mode);
}

void Board::Pin::log() const {
  SerialIO::Print("Pin: ");
  SerialIO::Print(this->pin);
  SerialIO::Print(" | Data: ");
  SerialIO::Print(this->data, true);
}

Board::AnalogPin::AnalogPin(uint8_t pin, BoardIO::Mode mode)
  : Pin(pin, mode) {}

void Board::AnalogPin::high() {
  this->data = BoardIO::Data::_HIGH;
  BoardIO::AnalogWrite(this->pin, BoardIO::Data::_HIGH);
}

void Board::AnalogPin::low() {
  this->data = BoardIO::Data::_LOW;
  BoardIO::AnalogWrite(this->pin, BoardIO::Data::_LOW);
}

Board::DigitalPin::DigitalPin(uint8_t pin, BoardIO::Mode mode)
  : Pin(pin, mode) {}

void Board::DigitalPin::high() {
  this->data = BoardIO::Data::_HIGH;
  BoardIO::DigitalWrite(this->pin, BoardIO::Data::_HIGH);
}

void Board::DigitalPin::low() {
  this->data = BoardIO::Data::_LOW;
  BoardIO::DigitalWrite(this->pin, BoardIO::Data::_LOW);
}
