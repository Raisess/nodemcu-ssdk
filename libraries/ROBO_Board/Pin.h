#ifndef Pin_h
#define Pin_h

#include <cstdint>

namespace Board {

class Pin {
public:
  enum Mode {
    INPUT_MODE = 1,
    OUTPUT_MODE,
  };

  void log() const;

protected:
  enum Data {
    LOW_DATA = 0,
    HIGH_DATA,
  };

  uint8_t pin;
  Data data = Data::LOW_DATA;

  Pin(uint8_t pin);

  virtual void high() = 0;
  virtual void low() = 0;
};

class AnalogPin : public Pin {
public:
  AnalogPin(uint8_t pin, Pin::Mode);

  void high() final override;
  void low() final override;
};

class DigitalPin : public Pin {
public:
  DigitalPin(uint8_t pin, Pin::Mode);

  void high() final override;
  void low() final override;
};

}

#endif
