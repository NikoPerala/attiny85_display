CC=avr-gcc
CFLAGS=-g -Os -Wall -Wextra -mmcu=attiny85
PORT=/dev/ttyUSB0
INCLUDES=-Iinclude -Iinclude/programs
SRC=./src/main.c ./src/millis.c ./src/button.c ./src/pins.c ./src/common.c ./src/programs/calibration.c ./src/programs/random.c ./src/display.c 

OUT=out

all: $(OUT).hex

$(OUT).elf: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUT).elf $(SRC)

$(OUT).hex: $(OUT).elf
	avr-objcopy -O ihex -R .eeprom $(OUT).elf $(OUT).hex

deploy:
	avrdude -c arduino -p attiny85 -P $(PORT) -b 19200 -U flash:w:$(OUT).hex:i

clean:
	rm -f $(OBJ) $(OUT).elf $(OUT).hex
