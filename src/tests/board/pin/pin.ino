#include <Board.h>
#include <Pin.h>

using namespace Board;

DigitalPin pin(10, Pin::Mode::_OUTPUT);

void setup() {
  SerialIO::Init(9600);
}

void loop() {
  pin.high();
  pin.log();
  Time::Delay(1000);
  pin.low();
  pin.log();
  Time::Delay(1000);
}
