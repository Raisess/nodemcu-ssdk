#include <Board.h>
#include <string>

using namespace Board;

char* buf;

void setup() {
  SerialIO::Init(9600);
}

void loop() {
  SerialIO::Write("test");
  buf = SerialIO::Read(4);
  SerialIO::Print(buf, true);
  Time::Delay(1000);
}
