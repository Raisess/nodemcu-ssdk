#include <Pin.h>

Core::Board::DigitalPin pin(10, Core::Board::Pin::INPUT_MODE);

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
