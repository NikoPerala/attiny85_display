#include "calibration.h"
#include "dm_def.h"
#include "display.h"

void calibration_buttons(Displaymachine *dm, ButtonPressType bpt)
{
    switch (bpt){
        case BUTTON_PRESS_QUICK:
            dm->offset++;
            break;
        case BUTTON_PRESS_DOUBLE:
            dm->offset--;
            break;
        case BUTTON_PRESS_LONG:
            displaymachine_set_mode(dm, dm->mode + 1);
            break;
        default:
            break;
    }
}
