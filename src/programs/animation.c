#include <stdlib.h>
#include "dm_def.h"
#include "display.h"
#include "animation.h"

void run_animation(Displaymachine *dm, void *params)
{
    Animation *animation = params;
    for (int i = 0; i < 8; ++i){
        dm->canvas[i] = animation->frames[animation->current_frame][i];
    }

    switch (animation->direction){
        case 0:
            animation->current_frame++;
            if (animation->current_frame >= ANIMATION_FRAME_AMOUNT) animation->current_frame = 0;
            break;
        case 1:
            animation->current_frame--;
            if (animation->current_frame < 0) animation->current_frame = ANIMATION_FRAME_AMOUNT - 1;
            break;
    }
}

Animation get_animation()
{
    Animation animation = { 0 };

    animation.frames[0][0] = 0b11111111;
    animation.frames[0][1] = 0b10000001;
    animation.frames[0][2] = 0b10000001;
    animation.frames[0][3] = 0b10011001;
    animation.frames[0][4] = 0b10011001;
    animation.frames[0][5] = 0b00000001;
    animation.frames[0][6] = 0b10000001;
    animation.frames[0][7] = 0b11111111;
    
    animation.frames[1][0] = 0b00000000;
    animation.frames[1][1] = 0b01111110;
    animation.frames[1][2] = 0b01000010;
    animation.frames[1][3] = 0b01000010;
    animation.frames[1][4] = 0b01000010;
    animation.frames[1][5] = 0b01000010;
    animation.frames[1][6] = 0b01111110;
    animation.frames[1][7] = 0b00000000;

    animation.frames[2][0] = 0b00000000;
    animation.frames[2][1] = 0b00000000;
    animation.frames[2][2] = 0b00111100;
    animation.frames[2][3] = 0b00100100;
    animation.frames[2][4] = 0b00100100;
    animation.frames[2][5] = 0b00111100;
    animation.frames[2][6] = 0b00000000;
    animation.frames[2][7] = 0b00000000;

    return animation;
}

void animation_buttons(Displaymachine *dm, ButtonPressType bpt)
{
    Animation *animation = dm->run_func_params; 

    switch (bpt){
        case BUTTON_PRESS_QUICK:
            animation->direction = 1;
            break;
        case BUTTON_PRESS_DOUBLE:
            animation->direction = 0;
            break;
        case BUTTON_PRESS_LONG:
            displaymachine_set_mode(dm, dm->mode + 1);
            break;
        default:
            break;
    }
}
