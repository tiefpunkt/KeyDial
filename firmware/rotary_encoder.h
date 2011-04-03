#ifndef __ROTARY_ENCODER_H
#define __ROTARY_ENCODER_H

#include <avr/io.h>

#define ENC_PORT	PORTD
#define ENC_DDR		DDRD
#define ENC_PIN		PIND
#define ENC_PIN0	PD6
#define ENC_PIN1	PD7

volatile int8_t enc_value;

void enc_init();
int8_t enc_read();

#endif
