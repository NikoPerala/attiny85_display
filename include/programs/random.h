#ifndef EPHO_DISPLAYMACHINE_RANDOM_H
#define EPHO_DISPLAYMACHINE_RANDOM_H

#include "dm_def.h"
#include "display.h"
#include "button.h"

void run_random(Displaymachine *dm, void *params);
void random_buttons(Displaymachine *dm, ButtonPressType bpt);

#endif // EPHO_DISPLAYMACHINE_RANDOM_H
