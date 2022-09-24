#include <String.h>

Core::String greetings = "Hello from esp8266!";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(greetings.c_str());
  delay(1000);
}
