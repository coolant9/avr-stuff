// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include "VirtualWire.h"

#include <avr/interrupt.h>
#include <util/delay.h>


#define LED_PIN PB4
#define DELAY_MS 1000

//It's up and working so far. debugging aid
void on_off_routine(){
  PORTB |= _BV(LED_PIN);
  _delay_ms(DELAY_MS);
  PORTB &= ~_BV(LED_PIN);
  _delay_ms(DELAY_MS);
}

void indicate_critical_error()
{
  do {
    PORTB |= _BV(LED_PIN);
    _delay_ms(4000);
  } while(1);
}

int main(void)
{
  bool tx_outcome = false;
  // Initialise the IO and ISR
  //vw_set_ptt_inverted(1); // Required for DR3100
  vw_setup(1000);	 // Bits per sec
  sei();
  const char *msg = "hello";

  while(true){
    PORTB |= _BV(LED_PIN);
    tx_outcome = vw_send((uint8_t *)msg, strlen(msg));
    if(tx_outcome == false)
    {
      indicate_critical_error();
    }
    //on_off_routine();
    vw_wait_tx(); // Wait until the whole message is gone
    PORTB &= ~_BV(LED_PIN);

    _delay_ms(2000);

    //shows the heartbeat . debugging aid.
    //on_off_routine();
  }
}
