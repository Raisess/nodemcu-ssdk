#pragma once

#include <iostream>
#include <cstddef>
#include <cstdint>

class _Serial {
public:
  _Serial() {}
  ~_Serial() {}

  void begin(uint16_t baud_rate) {
    std::cout << "\x1b[33m>> LOG:\x1b[0m Seiral.begin with: " << baud_rate << " baud rate" << std::endl;
  }

  void print(const char* value) {
    std::cout << value;
  }

  void print(int value) {
    std::cout << value;
  }

  void print(float value) {
    std::cout << value;
  }

  void println(const char* value) {
    std::cout << value << std::endl;
  }

  void println(int value) {
    std::cout << value << std::endl;
  }

  void println(float value) {
    std::cout << value << std::endl;
  }

  void readBytes(char*& buf, size_t) {
    buf = this->buf;
    std::cout << "\x1b[33m>> LOG:\x1b[0m Seiral.readBytes buffer: " << buf << std::endl;
  }

  void write(const char* buf) {
    this->buf = (char*) buf;
    std::cout << "\x1b[33m>> LOG:\x1b[0m Seiral.write buffer: " << buf << std::endl;
  }

private:
  char* buf = (char*) "";
};

auto Serial = _Serial();
