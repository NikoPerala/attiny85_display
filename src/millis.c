#include "millis.h"
#include "attiny85.h"

volatile uint32_t millis_ct = 0;
ISR(TIMER0_COMPA_vect){
    millis_ct++;
}

void millis_init()
{
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    OCR0A = 15;
    TIMSK = (1 << OCIE0A);
    sei();
}

uint32_t millis()
{
    uint32_t millis_val;

    cli();
    millis_val = millis_ct;
    sei();
    return millis_val;
}
