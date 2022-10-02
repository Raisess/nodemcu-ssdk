#pragma once

#include <cstdint>
#include <unistd.h>

void delay(uint16_t ms) {
  usleep(ms * 1000);
}
