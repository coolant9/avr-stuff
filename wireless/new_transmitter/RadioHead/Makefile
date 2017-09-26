#MCU=attiny2313
MCU=attiny85
#MCU=atmega16a
#m16 for atmega16a
#USBASP_PART=t2313
CC=avr-gcc
CPP=avr-g++
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-c -g -mmcu=$(MCU) -Wall -Os -mcall-prologues -I . -DF_CPU=8000000UL -DRH_PLATFORM=RH_PLATFORM_GENERIC_AVR8 -DRH_ASK_TX_PIN=PIN4 -DRH_ASK_TX_DDR=DDRB -DRH_ASK_RX_DDR=DDRB -DRH_ASK_RX_PIN=PIN3 -DRH_ASK_TIMER_INDEX=0 -DHIGH=1 -DLOW=0 -DRH_ASK_RX_PORT=PORTB -DRH_ASK_TX_PORT=PORTB
DEPS=RH_ASK.h RHGenericDriver.h

all: RH_ASK.o RHCRC.o RHGenericDriver.o

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

# erase the AVR before it is programmed
clean:
	rm -f *.o *.map *.out *.hex
