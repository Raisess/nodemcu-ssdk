#include "Arduino.h"
#include "Board.h"

void Board::SerialIO::Init(Boards board) {
  Serial.begin(board);
}

void Board::SerialIO::Print(const char* str) {
  Serial.print(str);
}

void Board::SerialIO::Println(const char* str) {
  Serial.println(str);
}

void Board::BoardIO::Delay(uint16_t ms) {
  delay(ms);
}

void Board::BoardIO::SetPin(uint8_t pin, BoardIO::Mode mode) {
  pinMode(pin, mode == BoardIO::Mode::_INPUT ? INPUT : OUTPUT);
}

uint16_t Board::BoardIO::AnalogRead(uint8_t pin) {
  return analogRead(pin);
}

void Board::BoardIO::AnalogWrite(uint8_t pin, Data data) {
  analogWrite(pin, data);
}

uint8_t Board::BoardIO::DigitalRead(uint8_t pin) {
  return digitalRead(pin);
}

void Board::BoardIO::DigitalWrite(uint8_t pin, Data data) {
  digitalWrite(pin, data);
}
