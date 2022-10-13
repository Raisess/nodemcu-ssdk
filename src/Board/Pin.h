#ifndef Pin_h
#define Pin_h

#include <cstdint>
#include "Board.h"

namespace Board {

class Pin {
public:
  enum Mode {
    _INPUT = 1,
    _OUTPUT,
  };

  enum Data {
    _LOW = 0,
    _HIGH = 255,
  };

  void log() const;

protected:
  uint8_t pin;
  Data data = Data::_LOW;

  Pin(uint8_t pin, Mode);

  virtual void high() = 0;
  virtual void low() = 0;
};

class AnalogPin : public Pin {
public:
  AnalogPin(uint8_t pin, Mode);

  void high() final override;
  void low() final override;
};

class DigitalPin : public Pin {
public:
  DigitalPin(uint8_t pin, Mode);

  void high() final override;
  void low() final override;
};

}

#endif
