#pragma once

// #include <iostream>
#include <cstdint>

#define INPUT 0
#define OUTPUT 1

void pinMode(uint8_t pin, uint8_t mode) {
  // std::cout << "Setup pin: " << pin << ", in mode: " << mode << std::endl;
}

uint16_t analogRead(uint8_t) {
  return 1;
}

void analogWrite(uint8_t pin, uint16_t data) {
  // std::cout << "Set analog pin: " << pin << ", to: " << data << std::endl;
}

uint8_t digitalRead(uint8_t) {
  return 1;
}

void digitalWrite(uint8_t pin, uint16_t data) {
  // std::cout << "Set digital pin: " << pin << ", to: " << data << std::endl;
}
