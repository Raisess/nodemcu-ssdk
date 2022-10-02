#pragma once

#include <iostream>
#include <cstdint>

#define INPUT 0
#define OUTPUT 1

void pinMode(uint8_t pin, uint8_t mode) {
  std::cout << "\x1b[33m>> LOG:\x1b[0m Setup pin: " << unsigned(pin)
            << ", in mode: " << unsigned(mode) << std::endl;
}

uint16_t analogRead(uint8_t) {
  return 1;
}

void analogWrite(uint8_t pin, uint16_t data) {
  std::cout << "\x1b[33m>> LOG:\x1b[0m Set analog pin: " << unsigned(pin)
            << ", to: " << unsigned(data) << std::endl;
}

uint8_t digitalRead(uint8_t) {
  return 1;
}

void digitalWrite(uint8_t pin, uint16_t data) {
  std::cout << "\x1b[33m>> LOG:\x1b[0m Set digital pin: " << unsigned(pin)
            << ", to: " << unsigned(data) << std::endl;
}
