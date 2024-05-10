#ifndef EPHO_DISPLAYMACHINE_H
#define EPHO_DISPLAYMACHINE_H

#include <stdint.h>
#include "dm_def.h"
#include "attiny85.h"
#include "button.h"
#include "pins.h"
#include "common.h"

#include "programs/calibration.h"
#include "programs/random.h"

#define _PIN_CT_CLK    0
#define _PIN_SR_DATA   1
#define _PIN_SR_LATCH  2
#define _PIN_SR_CLK    3
#define _PIN_BUTTON    4

#define FRAME_DELAY 150

/*
enum MODES {
    MODE_CALIBRATION,
    MODE_RANDOM,
    MODE_COUNT
};

enum PINS {
    PIN_CT_CLK,
    PIN_SR_DATA,
    PIN_SR_LATCH,
    PIN_SR_CLK,
    PIN_BUTTON,
    PIN_COUNT
};

typedef struct Displaymachine Displaymachine;
struct Displaymachine {
    uint8_t row_ct     : 3;
    uint8_t offset     : 3;
    uint8_t running    : 1;
    uint8_t mode       : 2;
    uint32_t prev_action;
    Button button;
    PinParams pins[PIN_COUNT];
    uint8_t canvas[8];
    void *run_func_params;
    void (*run_func)(Displaymachine *dm, void *params);
    void (*button_func)(Displaymachine *dm, ButtonPressType bpt);
};
*/
void initialize_displaymachine(Displaymachine *dm);
void display_row(Displaymachine *dm);
void displaymachine_set_mode(Displaymachine *dm, uint8_t mode);
void display_machine_action(Displaymachine *dm, uint32_t time);

#endif // EPHO_DISPLAY_H
