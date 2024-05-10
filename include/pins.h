#ifndef EPHO_PINS_H
#define EPHO_PINS_H

#include <stdint.h>

typedef struct PinParams {
    volatile uint8_t *port;
    uint8_t pin;
} PinParams;

uint8_t read_pin(PinParams params);
uint8_t read_pin_invert(PinParams params);
void write_pin(PinParams params, uint8_t val);
void toggle_pin(PinParams params);
void pulse_pin(PinParams params);

#endif // EPHO_PINS_H
