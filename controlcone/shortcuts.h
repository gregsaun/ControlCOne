/*
 * All shortcuts modifiers used.
 * For example: "Ctrl + Alt" for a "Ctrl + Alt + F" shortcut
 * If there is no modifier, then it should be
 */
const int MODIF_EXPOSURE   = MODIFIERKEY_ALT;
const int MODIF_CONTRAST   = MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIF_SATURATION = MODIFIERKEY_CTRL | MODIFIERKEY_ALT;
const int MODIF_SHADOW     = MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIF_HIGHLIGHT  = MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIF_CLARITY    = MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIF_W_BAL_TEMP = MODIFIERKEY_SHIFT;
const int MODIF_W_BAL_TINT = MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIF_PAN        = 0;
const int MODIF_CROP       = 0;

/*
 * All shortcuts keys used.
 * For example: "F" for a "Ctrl + Alt + F" shortcut
 */
//const int SHORTCUT_START = KEY_LEFT_CTRL | KEY_LEFT_ALT | KEY_LEFT_SHIFT;
const int KEY_EXPOSURE_ADD   = KEYPAD_PLUS;
const int KEY_EXPOSURE_SUB   = KEYPAD_MINUS;
const int KEY_CONTRAST_ADD   = KEY_F1;
const int KEY_CONTRAST_SUB   = KEY_F2;
const int KEY_SATURATION_ADD = KEYPAD_PLUS;
const int KEY_SATURATION_SUB = KEYPAD_MINUS;
const int KEY_SHADOW_ADD     = KEY_F3;
const int KEY_SHADOW_SUB     = KEY_F4;
const int KEY_HIGHLIGHT_ADD  = KEY_F5;
const int KEY_HIGHLIGHT_SUB  = KEY_F6;
const int KEY_CLARITY_ADD    = KEY_F7;
const int KEY_CLARITY_SUB    = KEY_F8;
const int KEY_W_BAL_TEMP_ADD = KEYPAD_PLUS;
const int KEY_W_BAL_TEMP_SUB = KEYPAD_MINUS;
const int KEY_W_BAL_TINT_ADD = KEYPAD_PLUS;
const int KEY_W_BAL_TINT_SUB = KEYPAD_MINUS;
const int KEY_PAN            = KEY_H;
const int KEY_CROP           = KEY_C;

    /*BTN_EXPO,
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
    BTN_MASK_DRAW,
    BTN_MASK_ERASE,
    BTN_MASK_DISPLAY,
    BTN_BAL_PICK,
    BTN_ADJ,  // toggle adjustments between copy and paste*/
