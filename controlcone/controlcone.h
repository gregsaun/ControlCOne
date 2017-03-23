#include "pins.h"


/*
 * An adjustement has to be increased or decreased
 * to be applied to the image (like contrast increase or
 * contrast decrease)
 */
enum ADD_SUB {
    ADD,
    SUB,
    NO_ADD_SUB,
};


/*
 * Define character for each buttons of the matrice (keypad).
 * It's like a keyboard.
 */
enum adjButtons : char {
    BTN_NOT_USED = 'a',
    BTN_EXPO,
    BTN_CONTRAST,
    BTN_SAT,
    BTN_SHADOW,
    BTN_HL,
    BTN_CLARITY,
    BTN_BAL_TEMP,
    BTN_BAL_TINT,
    BTN_ADD,  // increase one of the 8 previous adjustments
    BTN_SUB,  // decrease one of the 8 previous adjustments
    BTN_AUTO,
    BTN_RESET,
    BTN_STAR_CLEAR,   // no color
    BTN_STAR1,        // green
    BTN_STAR2,        // yellow
    BTN_STAR3,        // blue
    BTN_STAR4,        // violet
    BTN_STAR5,        // red
    BTN_STAR_TOGGLE,  // toggle between stars and colors
    BTN_PAN,
    BTN_CROP,
    BTN_ROTATION,  // each keypress will turn around straighten, freehand, left, right
    BTN_SPOT,
    BTN_DRAW_MASK,
    BTN_ERASE_MASK,
    BTN_DISPLAY_MASK,
    BTN_BAL_PICK,
    BTN_ADJ,  // toggle adjustments between copy and paste
};


/*
 * Matric of buttons
 */
const byte ROWS = 6;
const byte COLS = 5;
char btns[ROWS][COLS] = {
    { BTN_EXPO,         BTN_CONTRAST, BTN_SAT,        BTN_SHADOW,      BTN_HL,         },
    { BTN_CLARITY,      BTN_BAL_TEMP, BTN_BAL_TINT,   BTN_ADD,         BTN_SUB,        },
    { BTN_AUTO,         BTN_RESET,    BTN_STAR_CLEAR, BTN_STAR1,       BTN_STAR2,      },
    { BTN_STAR3,        BTN_STAR4,    BTN_STAR5,      BTN_STAR_TOGGLE, BTN_PAN,        },
    { BTN_CROP,         BTN_ROTATION, BTN_SPOT,       BTN_DRAW_MASK,   BTN_ERASE_MASK, },
    { BTN_DISPLAY_MASK, BTN_BAL_PICK, BTN_ADJ,        BTN_NOT_USED,    BTN_NOT_USED,   }
};
byte rowPins[ROWS] = {PIN_KEYPAD_ROW1, PIN_KEYPAD_ROW2, PIN_KEYPAD_ROW3, PIN_KEYPAD_ROW4, PIN_KEYPAD_ROW5, PIN_KEYPAD_ROW6};
byte colPins[COLS] = {PIN_KEYPAD_COL1, PIN_KEYPAD_COL2, PIN_KEYPAD_COL3, PIN_KEYPAD_COL4, PIN_KEYPAD_COL5};
const unsigned int BTN_DEBOUNCE = 50;    // ms (default 10ms)
const unsigned int BTN_HOLD_TIME = 600;  // ms (default 500ms)
const unsigned int BTN_HOLD_REPEAT_DELAY = 100;  // ms
