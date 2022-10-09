# Board

The core lib who implements all platform specific code.

```cpp
namespace Board;
```

Init board serial:

```cpp
static void Board::SerialIO::Init(uint16_t baud_rate);
```

Print on serial:

```cpp
static void Board::SerialIO::Print(int | float | const char*);
```

Set a new board gpio:

```cpp
static void Board::BoardIO::SetPin(uint8_t pin, uint8_t mode);
```

Get data from an analog gpio:

```cpp
static uint16_t Board::BoardIO::AnalogRead(uint8_t pin);
```

Write data to an analog gpio:

```cpp
static void Board::BoardIO::AnalogWrite(uint8_t pin, uint8_t data);
```

Get data from an digital gpio:

```cpp
static uint8_t Board::BoardIO::DigitalRead(uint8_t pin);
```

Write data to an digital gpio:

```cpp
static void Board::BoardIO::DigitalWrite(uint8_t pin, uint8_t data);
```

Pause code for a specific time:

```cpp
static void Board::Time::Delay(uint16_t ms);
```
