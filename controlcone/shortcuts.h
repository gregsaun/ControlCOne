/*
 * Represents an image adjustment shortcut.
 * 
 * A shortcut is build using a modifier and a key. For example: For "Ctrl + Alt + F", 
 * the modifier will be "Ctrl + Alt" and the key "F". If there is no modifier nor key,
 * then value should be 0.
 * 
 * Some adjustments need to have two shortcuts (to increase and decrease a value or
 * to switch between colors and stars notation). This is why we have two structures.
 */
struct shortcut_single_t {
    int modifier;  // modifier shortcut
    int key;       // key shortcut
};
struct shortcut_double_t {
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
 *   - For an adjustment, you can have a single shortcut (shortcut_single_t) or double
 *     shortcuts (shortcut_double_t) (to increase or decrease for example)
 * 
 * All available keys are displayed in this page: https://www.pjrc.com/teensy/td_keyboard.html
 */
// to ease reading (doesn't take more place inside the Arduino)
const int MODIFIER_CTRL  = MODIFIERKEY_CTRL;
const int MODIFIER_ALT   = MODIFIERKEY_ALT;
const int MODIFIER_SHIFT = MODIFIERKEY_SHIFT;
const int MODIFIER_GUI   = MODIFIERKEY_GUI;
const int MODIFIER_CTRL_ALT   = MODIFIERKEY_CTRL | MODIFIERKEY_ALT;
const int MODIFIER_CTRL_SHIFT = MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT;
const int MODIFIER_ALT_SHIFT  = MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;
const int MODIFIER_CTRL_ALT_SHIFT = MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT;

// Shortcuts for adjustments
const shortcut_double_t NO_ADJ           = { 0, 0, 0 ,0 };
const shortcut_double_t ADJ_EXPOSURE     = { MODIFIER_ALT, KEYPAD_PLUS,
                                             MODIFIER_ALT, KEYPAD_MINUS };
const shortcut_double_t ADJ_CONTRAST     = { MODIFIER_CTRL_ALT_SHIFT, KEY_F1,
                                             MODIFIER_CTRL_ALT_SHIFT, KEY_F2 };
const shortcut_double_t ADJ_SATURATION   = { MODIFIER_CTRL_ALT, KEYPAD_PLUS,
                                             MODIFIER_CTRL_ALT, KEYPAD_MINUS };
const shortcut_double_t ADJ_SHADOW       = { MODIFIER_CTRL_ALT_SHIFT, KEY_F3,
                                             MODIFIER_CTRL_ALT_SHIFT, KEY_F4 };
const shortcut_double_t ADJ_HIGHLIGHT    = { MODIFIER_CTRL_ALT_SHIFT, KEY_F5,
                                             MODIFIER_CTRL_ALT_SHIFT, KEY_F6 };
const shortcut_double_t ADJ_CLARITY      = { MODIFIER_CTRL_ALT_SHIFT, KEY_F7,
                                             MODIFIER_CTRL_ALT_SHIFT, KEY_F8 };
const shortcut_double_t ADJ_W_BAL_TEMP   = { MODIFIER_SHIFT, KEYPAD_PLUS,
                                             MODIFIER_SHIFT, KEYPAD_MINUS };
const shortcut_double_t ADJ_W_BAL_TINT   = { MODIFIER_ALT_SHIFT, KEYPAD_PLUS,
                                             MODIFIER_ALT_SHIFT, KEYPAD_MINUS };
const shortcut_single_t ADJ_AUTO  = { MODIFIER_CTRL, KEY_L };
const shortcut_single_t ADJ_RESET = { MODIFIER_CTRL, KEY_R };
const shortcut_double_t ADJ_STAR_COLOR_CLEAR = { 0, KEY_0,                           // clear *
                                                 MODIFIER_CTRL_ALT_SHIFT, KEY_F9 };  // clear color
const shortcut_double_t ADJ_1STAR_RED        = { 0, KEY_1,                           // *
                                                 MODIFIER_GUI, KEYPAD_MINUS };    // red
const shortcut_double_t ADJ_2STARS_BLUE      = { 0, KEY_2,                           // **
                                                 MODIFIER_CTRL_ALT_SHIFT, KEY_F12 }; // blue
const shortcut_double_t ADJ_3STARS_ORANGE    = { 0, KEY_3,                           // ***
                                                 MODIFIER_CTRL_ALT_SHIFT, KEY_F10 }; // orange
const shortcut_double_t ADJ_4STARS_YELLOW    = { 0, KEY_4,                           // ****
                                                 0, KEYPAD_ASTERIX };                // yellow
const shortcut_double_t ADJ_5STARS_GREEN     = { 0, KEY_5,                           // *****
                                                 MODIFIER_CTRL_ALT_SHIFT, KEY_F11 }; // green
const shortcut_single_t ADJ_PAN          = { 0, KEY_H };
const shortcut_single_t ADJ_CROP         = { 0, KEY_C };
const shortcut_single_t ADJ_ROTATION     = { MODIFIER_SHIFT, KEY_R };
const shortcut_single_t ADJ_SPOT         = { 0, KEY_O };
const shortcut_single_t ADJ_DRAW_MASK    = { 0, KEY_B };
const shortcut_single_t ADJ_ERASE_MASK   = { 0, KEY_E };
const shortcut_single_t ADJ_DISPLAY_MASK = { 0, KEY_M };
const shortcut_single_t ADJ_W_BAL_PICK   = { 0, KEY_W };
const shortcut_single_t ADJ_COPY_PASTE   = { MODIFIER_SHIFT, KEY_A };
const shortcut_single_t ADJ_UNDO         = { MODIFIER_CTRL, KEY_Y };  // something wrong here with keyboard layout
const shortcut_single_t ADJ_REDO         = { MODIFIER_CTRL, KEY_Z };  // something wrong here with keyboard layout
const shortcut_double_t ADJ_BRUSH_SIZE     = { MODIFIER_CTRL_ALT_SHIFT, KEY_HOME,
                                               MODIFIER_CTRL_ALT_SHIFT, KEY_END };
const shortcut_double_t ADJ_BRUSH_HARDNESS = { MODIFIER_CTRL_ALT_SHIFT, KEY_PAGE_UP,
                                               MODIFIER_CTRL_ALT_SHIFT, KEY_PAGE_DOWN };


