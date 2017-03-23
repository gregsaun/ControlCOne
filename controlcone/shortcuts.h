/*
 * 
 */
struct shortcut_t {
    int modifier1;
    int key1;
    int modifier2;
    int key2;
};


/*
 * All shortcuts modifiers used.
 * For example: For "Ctrl + Alt + F", the modifier will be "Ctrl + Alt" and the key "F"
 * If there is no modifier nor key, then value should be 0
 * All available keys are displayed in this page: https://www.pjrc.com/teensy/td_keyboard.html
 */


const shortcut_t NO_ADJ         = { 0, 0, 0, 0 };
const shortcut_t ADJ_EXPOSURE   = { MODIFIERKEY_ALT, KEYPAD_PLUS,
                                    MODIFIERKEY_ALT, KEYPAD_MINUS };
const shortcut_t ADJ_CONTRAST   = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F1,
                                    MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F2 };
const shortcut_t ADJ_SATURATION = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT, KEYPAD_PLUS,
                                    MODIFIERKEY_CTRL | MODIFIERKEY_ALT, KEYPAD_MINUS };
const shortcut_t ADJ_SHADOW     = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F3,
                                    MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F4 };
const shortcut_t ADJ_HIGHLIGHT  = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F5,
                                    MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F6 };
const shortcut_t ADJ_CLARITY    = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F7,
                                    MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F8 };
const shortcut_t ADJ_W_BAL_TEMP = { MODIFIERKEY_SHIFT, KEYPAD_PLUS,
                                    MODIFIERKEY_SHIFT, KEYPAD_MINUS };
const shortcut_t ADJ_W_BAL_TINT = { MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEYPAD_PLUS,
                                    MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEYPAD_MINUS };
const shortcut_t ADJ_PAN        = { 0, KEY_H,
                                    0, 0 };
const shortcut_t ADJ_CROP       = { 0, KEY_C,
                                    0, 0 };
