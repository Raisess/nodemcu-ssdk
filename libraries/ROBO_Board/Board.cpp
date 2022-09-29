#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Board.h"

void Board::SerialIO::Init(Boards board) {
  Serial.begin(board);
}

template<typename T>
void serial_print(T value, bool new_line) {
  if (new_line) {
    Serial.println(value);
  } else {
    Serial.print(value);
  }
}

void Board::SerialIO::Print(const char* value, bool new_line) {
  serial_print<const char*>(value, new_line);
}

void Board::SerialIO::Print(int value, bool new_line) {
  serial_print<int>(value, new_line);
}

void Board::SerialIO::Print(float value, bool new_line) {
  serial_print<float>(value, new_line);
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
