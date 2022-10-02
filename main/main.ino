#include <Board.h>
#include <string>

using namespace Board;

std::string greetings = "Hello from esp8266!";

void setup() {
  SerialIO::Init(SerialIO::Rate::_ESP8266);
}

void loop() {
  SerialIO::Print(greetings.c_str(), true);
  Time::Delay(1000);
}
