# NODEMCU SIMPLE SDK

## Dependencies

- [Arduino CLI](https://github.com/arduino/arduino-cli)
- [Picocom](https://github.com/npat-efault/picocom)

## Setup

Cloning the repository:

```shell
git clone --recursive https://github.com/Raisess/nodemcu-ssdk
```

Installing board core:

```shell
cd nodemcu-ssdk
make install
```

Building, flashing and serial monitor:

```shell
make
make upload
make serial
```
