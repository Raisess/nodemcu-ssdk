#include <Board.h>
#include <Pin.h>

using namespace Board;

DigitalPin pin(10, BoardIO::Mode::_OUTPUT);

void setup() {
  SerialIO::Init(SerialIO::Rate::_ESP8266);
}

void loop() {
  pin.high();
  pin.log();
  Time::Delay(1000);
  pin.low();
  pin.log();
  Time::Delay(1000);
}
