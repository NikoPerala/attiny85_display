#include <stdlib.h>
#include "display.h"

void initialize_displaymachine(Displaymachine *dm)
{
    displaymachine_set_mode(dm, MODE_CALIBRATION);
    
    dm->row_ct = 0;
    dm->offset = 0;
    dm->running = 1;
    dm->prev_action = 0;

    dm->pins[PIN_CT_CLK] = (PinParams) { &PORTB, _PIN_CT_CLK };
    dm->pins[PIN_SR_DATA] = (PinParams) { &PORTB, _PIN_SR_DATA };
    dm->pins[PIN_SR_LATCH] = (PinParams) { &PORTB, _PIN_SR_LATCH };
    dm->pins[PIN_SR_CLK] = (PinParams) { &PORTB, _PIN_SR_CLK };
    dm->pins[PIN_BUTTON] = (PinParams) { &PINB, _PIN_BUTTON };

    dm->button.press = BUTTON_PRESS_NONE;
    dm->button.previous_state = 0;
    dm->button.press_time = 0;
    dm->button.read_params = &dm->pins[PIN_BUTTON];
    dm->button.read_func = read_button_pin_invert;


}

void display_row(Displaymachine *dm)
{
    uint8_t c_index = dm->row_ct + dm->offset;
    if (c_index >= 8) c_index -= 8;
    shift_out(dm->canvas[c_index],
             dm->pins[PIN_SR_DATA],
             dm->pins[PIN_SR_LATCH],
             dm->pins[PIN_SR_CLK]);
    pulse_pin(dm->pins[PIN_CT_CLK]);
    dm->row_ct++;
}

void displaymachine_set_mode(Displaymachine *dm, uint8_t mode)
{
    dm->mode = mode;
    if (dm->mode >= MODE_COUNT) dm->mode = 0;
    switch (dm->mode){
        case MODE_CALIBRATION:
            dm->run_func = NULL;
            dm->button_func = calibration_buttons;
            dm->canvas[0] = 0b10000001;
            dm->canvas[1] = 0b01111110;
            dm->canvas[2] = 0b01000010;
            dm->canvas[3] = 0b01011010;
            dm->canvas[4] = 0b01011010;
            dm->canvas[5] = 0b01000010;
            dm->canvas[6] = 0b01111110;
            dm->canvas[7] = 0b10000001;
            break;
        case MODE_RANDOM:
            dm->run_func = run_random;
            dm->button_func = random_buttons;
            break;
    }
}

void display_machine_action(Displaymachine *dm, uint32_t time)
{
    if (!dm->running || dm->run_func == NULL) return;
    
    if (time - dm->prev_action >= FRAME_DELAY){
        dm->prev_action = time;
        dm->run_func(dm, dm->run_func_params);
    }
}
