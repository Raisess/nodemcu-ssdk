PROJECT_NAME=main

BOARD=esp8266:esp8266
BOARD_TYPE=nodemcuv2

PORT=/dev/ttyUSB0
BAUD_RATE=9600

build:
	arduino-cli compile --fqbn $(BOARD):$(BOARD_TYPE) $(PROJECT_NAME)

build-test: $(eval PROJECT_NAME=test) build

upload:
	sudo chmod 666 $(PORT)
	arduino-cli upload -p $(PORT) --fqbn $(BOARD):$(BOARD_TYPE) $(PROJECT_NAME)

upload-test: $(eval PROJECT_NAME=test) upload

install:
	arduino-cli core update-index
	arduino-cli core install $(BOARD)

boards:
	arduino-cli board list

serial:
	sudo chmod 666 $(PORT)
	picocom -b $(BAUD_RATE) $(PORT)
