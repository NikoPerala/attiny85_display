#ifndef EPHO_DMDEF_H
#define EPHO_DMDEF_H

#include <stdint.h>
#include "button.h"
#include "pins.h"

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

#endif // EPHO_DMDEF_H
