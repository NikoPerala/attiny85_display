#ifndef EPHO_DISPLAYMACHINE_ANIMATION_H
#define EPHO_DISPLAYMACHINE_ANIMATION_H

#include "dm_def.h"
#include "display.h"
#include "button.h"

#define ANIMATION_FRAME_AMOUNT 3

typedef struct Animation {
    uint8_t direction     : 1;
    uint8_t current_frame : 2;
    uint8_t frames[ANIMATION_FRAME_AMOUNT][8];
} Animation;

Animation get_animation();
void run_animation(Displaymachine *dm, void *params);
void animation_buttons(Displaymachine *dm, ButtonPressType bpt);

#endif // EPHO_DISPLAYMACHINE_ANIMATION_H
