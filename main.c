#include <stdlib.h>
#include <avr/interrupt.h>
#include "rotary_encoder.h"


int main( void )
{
	DDRC = 0xff; 						//Port C as Output
	
	enc_init();
	sei();
	
	while (42) {
		PORTC = enc_value;
	}
	
}

