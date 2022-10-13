#include "Board.h"
#include "HBridge.h"

Board::HBridge::HBridge(uint8_t left, uint8_t right)
  : left(left, Pin::Mode::_OUTPUT),
    right(right, Pin::Mode::_OUTPUT) {}

void Board::HBridge::log() const {
  SerialIO::Print("Left: ");
  this->left.log();
  SerialIO::Print("Right: ");
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
