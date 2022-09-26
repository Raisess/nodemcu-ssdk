#ifndef HBridge_h
#define HBridge_h

#include <cstdint>
#include "Pin.h"

namespace Board {

class HBridge {
public:
  HBridge(uint8_t left, uint8_t right);

  void log() const;
  void forward();
  void backward();
  void stop();

private:
  DigitalPin left;
  DigitalPin right;
};

}

#endif
