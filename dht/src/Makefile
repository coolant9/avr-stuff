MCU=atmega16a
CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
	CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues -DF_CPU=1000000UL -D__AVR_ATmega16__

all: dht.hex

dht.hex : dht.out
	$(OBJCOPY) -R .eeprom -O ihex dht.out dht.hex

dht.out : main.o dht.o uart.o
	$(CC) $(CFLAGS) -o dht.out -Wl,-Map,dht.map main.o dht.o uart.o

main.o : main.c
	$(CC) $(CFLAGS) -Os -c main.c

dht.o : dht/dht.c
	$(CC) $(CFLAGS) -Os -c dht/dht.c

uart.o : uart/uart.c
	$(CC) $(CFLAGS) -Os -c uart/uart.c

# erase the AVR before it is programmed
load: dht.hex
	avrdude -c usbasp -p m16 -b 115200  -u -U dht.hex

clean:
	rm -f *.o *.map *.out *.hex
