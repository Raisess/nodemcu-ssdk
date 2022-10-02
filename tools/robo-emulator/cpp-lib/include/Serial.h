#pragma once

#include <iostream>
#include <cstdint>

class _Serial {
public:
  _Serial() {}
  ~_Serial() {}

  void begin(uint16_t) {}

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
};

auto Serial = _Serial();
