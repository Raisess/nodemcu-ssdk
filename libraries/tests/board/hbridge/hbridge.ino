#include <Board.h>
#include <HBridge.h>

using namespace Board;

HBridge bridge(10, 5);

void setup() {
  SerialIO::Init(SerialIO::Rate::_ESP8266);
}

void loop() {
  bridge.forward();
  bridge.log();
  Time::Delay(1000);
  bridge.backward();
  bridge.log();
  Time::Delay(1000);
}
