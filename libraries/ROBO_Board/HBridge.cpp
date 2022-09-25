#include "Arduino.h"
#include "HBridge.h"

Board::HBridge::HBridge(int left, int right)
  : _left(left, Pin::Mode::OUTPUT_MODE),
    _right(right, Pin::Mode::OUTPUT_MODE) {}

void Board::HBridge::log() const {
  Serial.print("Left: ");
  _left.log();
  Serial.print("Right: ");
  _right.log();
}

void Board::HBridge::forward() {
  _left.low();
  _right.high();
}

void Board::HBridge::reverse() {
  _left.high();
  _right.low();
}

void Board::HBridge::stop() {
  _left.low();
  _right.low();
}
