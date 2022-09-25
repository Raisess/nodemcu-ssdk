#include <HBridge.h>

Board::HBridge bridge(10, 5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  bridge.forward();
  bridge.log();
  delay(1000);
}
