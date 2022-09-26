#include "Arduino.h"
#include "HBridge.h"

Board::HBridge::HBridge(uint8_t left, uint8_t right)
  : left(left, Pin::Mode::OUTPUT_MODE),
    right(right, Pin::Mode::OUTPUT_MODE) {}

void Board::HBridge::log() const {
  Serial.print("Left: ");
  this->left.log();
  Serial.print("Right: ");
  this->right.log();
}

void Board::HBridge::forward() {
  this->left.low();
  this->right.high();
}

void Board::HBridge::backward() {
  this->left.high();
  this->right.low();
}

void Board::HBridge::stop() {
  this->left.low();
  this->right.low();
}
