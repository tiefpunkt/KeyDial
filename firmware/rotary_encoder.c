#include "rotary_encoder.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#define PHASE_A		(ENC_PIN & 1<<ENC_PIN0)
#define PHASE_B		(ENC_PIN & 1<<ENC_PIN1)

volatile int8_t current_phase = 0;

ISR(TIMER0_COMP_vect) {
	enc_value = enc_read();
}

void enc_init() {
	ENC_DDR &= ~(_BV(ENC_PIN0) | _BV(ENC_PIN1)); // Set pins as input
	ENC_PORT |= _BV(ENC_PIN0) | _BV(ENC_PIN1); //Enable pullups
	
	TCCR0 |= (_BV(WGM01)); //CTC on Timer0
	TCCR0 |= _BV(CS01) | _BV(CS00); //prescaler to 64
	OCR0 = 250 - 1;
	TIMSK |= _BV(OCIE0);
}

int8_t enc_read() {
	switch (current_phase) {
	case 0:
		if (PHASE_A && !PHASE_B) {
			current_phase = 1;
		} else if(!PHASE_A && PHASE_B) {
			current_phase = 3;
			return -1;
		}
		break;

	case 1:

		if (!PHASE_A && !PHASE_B) {
			current_phase = 2;
		} else if (PHASE_A && PHASE_B) {
			current_phase = 0;
		} else if (!PHASE_A && PHASE_B) {
			current_phase = 0;
		}
		break;

	case 2:

		if (!PHASE_A && PHASE_B) {
			current_phase = 3;
		} else if (PHASE_A && !PHASE_B) {
			current_phase = 1;
		} else if (PHASE_A && PHASE_B) {
			current_phase = 0;
		}
		break;

	case 3:

		if (PHASE_A && PHASE_B) {
			current_phase = 0;
			return 1;
		} else if (!PHASE_A && !PHASE_B) {
			current_phase = 2;
		}  else if (PHASE_A && !PHASE_B) {
			current_phase = 0;
		}
		break;
	default:
		break;

	}
	return 0;
}
