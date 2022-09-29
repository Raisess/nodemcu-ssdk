#include <Board.h>
#include <String.h>

using namespace Board;

Core::String greetings = "Hello from esp8266!";

void setup() {
  SerialIO::Init(SerialIO::Rate::_ESP8266);
}

void loop() {
  SerialIO::Print(greetings.c_str(), true);
  Time::Delay(1000);
}
