#include <Board.h>
#include <Pin.h>

using namespace Board;

DigitalPin pin(10, BoardIO::Mode::_OUTPUT);

void setup() {
  SerialIO::Init(SerialIO::Boards::_ESP8266);
}

void loop() {
  pin.high();
  pin.log();
  BoardIO::Delay(1000);
  pin.low();
  pin.log();
  BoardIO::Delay(1000);
}
