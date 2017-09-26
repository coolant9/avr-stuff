#MCU=attiny2313
MCU=attiny85
#MCU=atmega16a
#m16 for atmega16a
#USBASP_PART=t2313
CC=avr-gcc
CPP=avr-g++
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-c -g -mmcu=$(MCU) -Wall -Os -mcall-prologues -I . -DF_CPU=8000000UL

all: virtualwire.o

virtualwire.o : VirtualWire.cpp
	$(CPP) $(CFLAGS) -Os -s VirtualWire.cpp

# erase the AVR before it is programmed
clean:
	rm -f *.o *.map *.out *.hex
