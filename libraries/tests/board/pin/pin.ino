#include <Pin.h>

Board::DigitalPin pin(10, Board::Pin::INPUT_MODE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  pin.high();
  pin.log();
  delay(1000);
  pin.low();
  pin.log();
}
