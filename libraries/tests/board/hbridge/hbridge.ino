#include <Board.h>
#include <HBridge.h>

using namespace Board;

HBridge bridge(10, 5);

void setup() {
  SerialIO::Init(SerialIO::Boards::_ESP8266);
}

void loop() {
  bridge.forward();
  bridge.log();
  BoardIO::Delay(1000);
}
