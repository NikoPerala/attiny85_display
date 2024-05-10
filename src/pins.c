#include "pins.h"
#include "bitwise.h"

#define PULSE_DELAY

uint8_t read_pin(PinParams params)
{
    return READ_BIT(*params.port, params.pin);
}

uint8_t read_pin_invert(PinParams params){
    return !read_pin(params);
}

void write_pin(PinParams params, uint8_t val)
{
    if (val){
        SET_BIT(*params.port, params.pin);
    } else {
        CLEAR_BIT(*params.port, params.pin);
    }
}

void toggle_pin(PinParams params)
{
    TOGGLE_BIT(*params.port, params.pin);
}

void pulse_pin(PinParams params)
{
    SET_BIT(*params.port, params.pin);
    PULSE_DELAY;
    CLEAR_BIT(*params.port, params.pin);
}
