#ifndef EPHO_COMMON_H
#define EPHO_COMMON_H

#include <stdint.h>
#include "pins.h"

uint8_t read_button_pin(void *read_params);
uint8_t read_button_pin_invert(void *params);
void shift_out(uint8_t byte, PinParams data, PinParams latch, PinParams clock);

#endif // EPHO_COMMON_H
