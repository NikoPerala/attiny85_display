#include <stdint.h>

#include "attiny85.h"
#include "bitwise.h"
#include "millis.h"
#include "pins.h"
#include "button.h"
#include "common.h"
#include "display.h"

void setup()
{
    DDRB = 0xff;                 // Set every pin as output
    CLEAR_BIT(DDRB, _PIN_BUTTON); // Set button pin as input
    PORTB = 0;                   // Set everypin low
    SET_BIT(PORTB, _PIN_BUTTON);  // Enable button pins pull-up
    millis_init();
}

int main(void)
{
    setup();
    
    Displaymachine dm;
    initialize_displaymachine(&dm);

    uint32_t current_time = 0;

    for (;;){
        
        current_time = millis();

        if (read_button(&dm.button, current_time)){
            dm.button_func(&dm, get_button_press_type(&dm.button));
        }
       
        display_machine_action(&dm, current_time);

        display_row(&dm);
    }

    return 0;
}
