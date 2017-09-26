#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include <avr/interrupt.h>
#include <util/delay.h>

#define UART_BAUD_RATE 9600
#include "uart/uart.h"


int main(void)
{
    //init uart
    uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

    //init interrupt
    sei();


		/* INITIALIZE */
		/* enable PB0 as output */
		DDRB|= _BV(PB0); //what's _BV??


		/* BLINK, BLINK ... */

		/* PC5 is 5 (see file include/avr/iom8.h) and _BV(PC5) is 00100000 */
		while (1) {
				/* led on, pin=0 */
				PORTB&= ~_BV(PB0);
        uart_puts("LED off\r\n");

				_delay_ms(1000);
				/* set output to 5V, LED off */
				PORTB|= _BV(PB0);
        uart_puts("LED on\r\n");

				_delay_ms(1000);
		}
		return 0;
}
