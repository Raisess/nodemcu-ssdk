PROJECT_NAME=main

LIB_PATH=/usr/local/include/robo
LOCAL_LIB_PATH=./libraries

# use "," to add another lib paths
LIBRARIES=$(LOCAL_LIB_PATH),~/Arduino/libraries

PORT=/dev/ttyUSB0
BAUD_RATE=9600

# fqbn: $(BOARD):$(BOARD_TYPE)
BOARD=esp8266:esp8266
BOARD_TYPE=nodemcuv2
#BOARD=arduino:samd
#BOARD_TYPE=mkr1000

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

# BOARD
build:
	arduino-cli compile --clean --fqbn $(BOARD):$(BOARD_TYPE) --libraries $(LIBRARIES) $(call args,$(PROJECT_NAME))

upload:
	sudo chmod 666 $(PORT)
	arduino-cli upload -p $(PORT) --fqbn $(BOARD):$(BOARD_TYPE) $(call args,$(PROJECT_NAME))

# -- e.g.: build-test board/pin
build-test:
	arduino-cli compile --clean --fqbn $(BOARD):$(BOARD_TYPE) --libraries $(LIBRARIES) $(LIBRARIES)/tests/$(call args)

# -- e.g.: upload-test board/pin
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

cores:
	arduino-cli core list

# -- e.g.: search-lib FTDebouncer
search-lib:
	arduino-cli lib search $(call args)

# -- e.g.: install-lib FTDebouncer
install-lib:
	arduino-cli lib install $(call args)

serial:
	sudo chmod 666 $(PORT)
	picocom -b $(BAUD_RATE) $(PORT)

# UTILS
install-required:
	sudo mkdir -p $(LIB_PATH)
	sudo cp -r $(LOCAL_LIB_PATH)/* $(LIB_PATH)
	sudo mkdir -p /usr/local/include/robo/emulator
	sudo cp -r ./tools/robo-emulator/cpp-lib/include/* /usr/local/include/robo/emulator
	sudo mkdir -p /usr/local/etc/robo
	sudo cp -r ./main /usr/local/etc/robo
	sudo cp ./etc/LICENSE.template /usr/local/etc/robo/LICENSE
	sudo cp ./etc/README.md.template /usr/local/etc/robo/README.md
	sudo cp ./etc/Makefile.template /usr/local/etc/robo/Makefile

# CLI
build-cli:
	make clean -C ./tools/robo-cli
	make -C ./tools/robo-cli

install-cli:
	make install -C ./tools/robo-cli
