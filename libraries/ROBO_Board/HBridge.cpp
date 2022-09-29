#include "Board.h"
#include "HBridge.h"

Board::HBridge::HBridge(uint8_t left, uint8_t right)
  : left(left, BoardIO::Mode::_OUTPUT),
    right(right, BoardIO::Mode::_OUTPUT) {}

void Board::HBridge::log() const {
  SerialIO::Print("Left: ");
  this->left.log();
  SerialIO::Print("Left: ");
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
