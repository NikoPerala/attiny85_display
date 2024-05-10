#include <stdlib.h>
#include "dm_def.h"
#include "display.h"
#include "calibration.h"

void run_random(Displaymachine *dm, void *params)
{
    (void) params;
    for (int i = 0; i < 8; ++i){
        dm->canvas[i] = rand() % 0xFF;
    }
}

void random_buttons(Displaymachine *dm, ButtonPressType bpt)
{
    switch (bpt){
        case BUTTON_PRESS_QUICK:
            dm->running = 1;
            break;
        case BUTTON_PRESS_DOUBLE:
            dm->running = 0;
            break;
        case BUTTON_PRESS_LONG:
            displaymachine_set_mode(dm, dm->mode + 1);
            break;
        default:
            break;
    }
}
