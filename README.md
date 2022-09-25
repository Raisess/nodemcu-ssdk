# NODEMCU SIMPLE SDK

## Dependencies

- [Arduino CLI](https://github.com/arduino/arduino-cli)
- [Picocom](https://github.com/npat-efault/picocom)

## Setup

Cloning the repository:

```shell
git clone --recursive https://github.com/Raisess/nodemcu-ssdk
```

Setup the sdk:

```shell
cd nodemcu-ssdk
make init
```

- add the esp8266 board core url `https://arduino.esp8266.com/stable/package_esp8266com_index.json`
to the `board_manager.additional_urls` array, at the `~/.arduino15/arduino-cli.yaml` file.

Installing board core:

```shell
make install
```

Building, flashing and serial monitor:

```shell
make
make upload
make serial
```
