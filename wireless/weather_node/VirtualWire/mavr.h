#define WGM12 CTC1

	//	Declare my own timer setup function
	static inline void my_vw_timerSetup(uint8_t speed) __attribute__ ((always_inline));

	//	VirtualWire has a special routine for detecting prescaler and the number of ticks
	//	   automatically, but needs to be declared first in order to be used
	uint8_t vw_timer_calc(uint16_t speed, uint16_t max_ticks, uint16_t *nticks);

	//	Instruct VirtualWire to use my timer setup routine and my interrupt vector
	#define vw_timerSetup(speed) my_vw_timerSetup(speed);

	//	Define my setup timer routine, that uses OCR1B as compare register
	static inline void my_vw_timerSetup(uint8_t speed)
	{
		uint16_t nticks;
		uint8_t prescaler;

		// Figure out prescaler value and counter match value
		prescaler = vw_timer_calc(speed, (uint16_t)-1, &nticks);
		if (!prescaler)
		{
			return; // fault
		}

		TCCR1 = _BV(WGM12); // Turn on CTC mode

		// Convert prescaler index to TCCR1B prescaler bits CS10, CS11, CS12
		TCCR1 |= prescaler;

		// Caution: special procedures for setting 16 bit regs
		// is handled by the compiler
		OCR1B = nticks;

		//	Enable interrupt
		TIMSK |= _BV(OCIE0B);
	}
