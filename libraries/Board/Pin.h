#ifndef Pin_h
#define Pin_h

#include <cstdint>
#include "Board.h"

namespace Board {

class Pin {
public:
  void log() const;

protected:
  uint8_t pin;
  BoardIO::Data data = BoardIO::Data::_LOW;

  Pin(uint8_t pin, BoardIO::Mode);

  virtual void high() = 0;
  virtual void low() = 0;
};

class AnalogPin : public Pin {
public:
  AnalogPin(uint8_t pin, BoardIO::Mode);

  void high() final override;
  void low() final override;
};

class DigitalPin : public Pin {
public:
  DigitalPin(uint8_t pin, BoardIO::Mode);

  void high() final override;
  void low() final override;
};

}

#endif
