#ifndef Pin_h
#define Pin_h

namespace Core {
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

  Data _data = Data::LOW_DATA;

  Pin(int pin);

  virtual void high() = 0;
  virtual void low() = 0;

private:
  int _pin;
};

class AnalogPin : public Pin {
public:
  AnalogPin(int pin, Pin::Mode);

  void high() final override;
  void low() final override;

private:
  unsigned int _pin;
};

class DigitalPin : public Pin {
public:
  DigitalPin(int pin, Pin::Mode);

  void high() final override;
  void low() final override;

private:
  unsigned int _pin;
};

}
}

#endif
