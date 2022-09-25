PROJECT_NAME=main

# use "," to add another lib paths
LIBRARIES=./libraries

PORT=/dev/ttyUSB0
BAUD_RATE=9600

# fqbn: $(BOARD):$(BOARD_TYPE)
BOARD=esp8266:esp8266
BOARD_TYPE=nodemcuv2

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

build:
	arduino-cli compile --fqbn $(BOARD):$(BOARD_TYPE) --libraries $(LIBRARIES) $(call args,$(PROJECT_NAME))

# e.g.: build-test board/pin
build-test:
	arduino-cli compile --fqbn $(BOARD):$(BOARD_TYPE) --libraries $(LIBRARIES) $(LIBRARIES)/tests/$(call args)

upload:
	sudo chmod 666 $(PORT)
	arduino-cli upload -p $(PORT) --fqbn $(BOARD):$(BOARD_TYPE) $(call args,$(PROJECT_NAME))

# e.g.: upload-test board/pin
upload-test:
	sudo chmod 666 $(PORT)
	arduino-cli upload -p $(PORT) --fqbn $(BOARD):$(BOARD_TYPE) $(LIBRARIES)/tests/$(call args)

init:
	arduino-cli config init

install:
	arduino-cli core update-index
	arduino-cli core install $(BOARD)

boards:
	arduino-cli board list

serial:
	sudo chmod 666 $(PORT)
	picocom -b $(BAUD_RATE) $(PORT)
