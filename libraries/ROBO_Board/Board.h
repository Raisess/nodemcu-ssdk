#ifndef Board_h
#define Board_h

#include <cstdint>

namespace Board {

class SerialIO {
public:
  enum Rate {
    _ESP8266 = 9600,
    _UNO = 9600,
  };

  static void Init(Rate baud_rate);
  static void Print(const char*, bool new_line = false);
  static void Print(int, bool new_line = false);
  static void Print(float, bool new_line = false);
};

class BoardIO {
public:
  enum Mode {
    _INPUT = 1,
    _OUTPUT,
  };

  enum Data {
    _LOW = 0,
    _HIGH = 255,
  };

  static void SetPin(uint8_t, Mode);
  static uint16_t AnalogRead(uint8_t);
  static void AnalogWrite(uint8_t, Data);
  static uint8_t DigitalRead(uint8_t);
  static void DigitalWrite(uint8_t, Data);
};

class Time {
public:
  static void Delay(uint16_t);
};

}

#endif
