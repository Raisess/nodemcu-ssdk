#ifndef HBridge_h
#define HBridge_h

#include "Pin.h"

namespace Board {

class HBridge {
public:
  HBridge(int left, int right);

  void log() const;
  void forward();
  void reverse();
  void stop();

private:
  DigitalPin _left;
  DigitalPin _right;
};

}

#endif
