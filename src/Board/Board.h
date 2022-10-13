#ifndef Board_h
#define Board_h

#include <cstddef>
#include <cstdint>

namespace Board {

class SerialIO {
public:
  static void Init(uint16_t baud_rate);
  static void Print(const char* value, bool new_line = false);
  static void Print(int value, bool new_line = false);
  static void Print(float value, bool new_line = false);
  static void Write(const char* buf);
  static char* Read(size_t buf_size);
};

class BoardIO {
public:
  static void SetPin(uint8_t, uint8_t);
  static uint16_t AnalogRead(uint8_t);
  static void AnalogWrite(uint8_t, uint8_t);
  static uint8_t DigitalRead(uint8_t);
  static void DigitalWrite(uint8_t, uint8_t);
};

class Time {
public:
  static void Delay(uint16_t);
};

}

#endif
