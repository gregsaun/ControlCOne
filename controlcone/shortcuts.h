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
const shortcut_t NO_ADJ           = { 0, 0, 0, 0 };
const shortcut_t ADJ_EXPOSURE     = { MODIFIERKEY_ALT, KEYPAD_PLUS,
                                      MODIFIERKEY_ALT, KEYPAD_MINUS };
const shortcut_t ADJ_CONTRAST     = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F1,
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F2 };
const shortcut_t ADJ_SATURATION   = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT, KEYPAD_PLUS,
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT, KEYPAD_MINUS };
const shortcut_t ADJ_SHADOW       = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F3,
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F4 };
const shortcut_t ADJ_HIGHLIGHT    = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F5,
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F6 };
const shortcut_t ADJ_CLARITY      = { MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F7,
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F8 };
const shortcut_t ADJ_W_BAL_TEMP   = { MODIFIERKEY_SHIFT, KEYPAD_PLUS,
                                      MODIFIERKEY_SHIFT, KEYPAD_MINUS };
const shortcut_t ADJ_W_BAL_TINT   = { MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEYPAD_PLUS,
                                      MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEYPAD_MINUS };
const shortcut_t ADJ_AUTO         = { MODIFIERKEY_CTRL, KEY_L,
                                      0, 0 };
const shortcut_t ADJ_RESET         = { MODIFIERKEY_CTRL, KEY_R,
                                      0, 0 };
const shortcut_t ADJ_STAR_CLEAR   = { 0, KEY_0,                                                          // clear *
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F9 };  // clear color
const shortcut_t ADJ_STAR1        = { 0, KEY_1,                        // *
                                      MODIFIERKEY_GUI, KEYPAD_MINUS }; // red
const shortcut_t ADJ_STAR2        = { 0, KEY_2,                                                           // **
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F10 };  // violet
const shortcut_t ADJ_STAR3        = { 0, KEY_3,                                                           // ***
                                      MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT, KEY_F11 };  // blue
const shortcut_t ADJ_STAR4        = { 0, KEY_4,                        // ****
                                      0, KEYPAD_ASTERIX };             // yellow
const shortcut_t ADJ_STAR5        = { 0, KEY_5,                        // *****
                                      MODIFIERKEY_GUI, KEYPAD_PLUS };  // green
const shortcut_t ADJ_STAR_TOGGLE  = { 0, 0,
                                      0, 0 };
const shortcut_t ADJ_PAN          = { 0, KEY_H,
                                      0, 0 };
const shortcut_t ADJ_CROP         = { 0, KEY_C,
                                      0, 0 };
const shortcut_t ADJ_ROTATION     = { 0, KEY_R,
                                      0, 0 };
const shortcut_t ADJ_SPOT         = { 0, KEY_O,
                                      0, 0 };
const shortcut_t ADJ_DRAW_MASK    = { 0, KEY_B,
                                      0, 0 };
const shortcut_t ADJ_ERASE_MASK   = { 0, KEY_E,
                                      0, 0 };
const shortcut_t ADJ_DISPLAY_MASK = { 0, KEY_M,
                                      0, 0 };
const shortcut_t ADJ_W_BAL_PICK   = { 0, KEY_W,
                                      0, 0 };
const shortcut_t ADJ_COPY_PASTE   = { 0, KEY_A,
                                      0, 0 };


