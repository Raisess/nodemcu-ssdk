#ifndef Board_h
#define Board_h

#include <cstdint>

namespace Board {

class SerialIO {
public:
  enum Boards {
    _ESP8266 = 9600,
  };

  static void Init(Boards);
  static void Print(const char*);
  static void Println(const char*);
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

  static void Delay(uint16_t ms);
  static void SetPin(uint8_t, Mode);
  static uint16_t AnalogRead(uint8_t);
  static void AnalogWrite(uint8_t, Data);
  static uint8_t DigitalRead(uint8_t);
  static void DigitalWrite(uint8_t, Data);
};

}

#endif
