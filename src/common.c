#include "common.h"
#include "pins.h"
#include "bitwise.h"

uint8_t read_button_pin(void *read_params)
{
    PinParams *params = (PinParams*) read_params;
    return read_pin(*params);
}

uint8_t read_button_pin_invert(void *params)
{
    return !read_button_pin(params);
}

void shift_out(uint8_t byte, PinParams data, PinParams latch, PinParams clock)
{
    write_pin(latch, 0);
    for (int i = 0; i < 8; ++i){
        write_pin(data, READ_BIT(byte, i));
        pulse_pin(clock);
    }
    write_pin(latch, 1);
}

