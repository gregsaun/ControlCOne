/*
 * Represents an image adjustment shortcut.
 * 
 * A shortcut is build using a modifier and a key. For example: For "Ctrl + Alt + F", 
 * the modifier will be "Ctrl + Alt" and the key "F". If there is no modifier nor key,
 * then value should be 0.
 * 
 * Some adjustment need to have two shortcuts: to increase and decrease a value, this
 * is why we have two modifiers and keys per shortcut.
 */
struct shortcut_t {
    int modifier1;  // modifier for single shortcut adjustment or increase adjustement
    int key1;       // key for single shortcut adjustment or increase adjustement
    int modifier2;  // modifier for an adjustment with a decrease value
    int key2;       // key for an adjustment with a decrease value
};


/*
 * All shortcuts used for image adjustments.
 * 
 * A shortcut is build using a modifier and a key. For example: For "Ctrl + Alt + F", 
 * the modifier will be "Ctrl + Alt" and the key "F".
 *   - If there is no modifier nor key, then value should be 0.
 *   - If you need multiple modifier (like Ctrl + Alt), then you must add "|" between
 *     each of them, for example: modifier1 = MODIFIERKEY_CTRL | MODIFIERKEY_ALT
 * 
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
