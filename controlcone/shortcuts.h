/*
 * All image adjustments that can be applied via this device.
 * After an adjustment has been selected we can increase or
 * decrease it's value. For example, we click "contrast"
 * adjustment and then "add" to increase the contrast.
 */
enum imageAdjustments {
    NO_ADJ,
    ADJ_EXPOSURE,
    ADJ_CONTRAST,
    ADJ_SATURATION,
    ADJ_SHADOW,
    ADJ_HIGHLIGHT,
    ADJ_CLARITY,
    ADJ_BALANCE_KELVIN,
    ADJ_BALANCE_TINT
};


/*
 * An adjustement has to be increased or decreased
 * to be applied to the image (like contrast increase or
 * contrast decrease)
 */
const boolean ADD = true;
const boolean SUB = false;


/*
 * All shortcuts used. We use the same keys for
 * the begining of all shortcuts
 */
const int SHORTCUT_START = KEY_LEFT_CTRL | KEY_LEFT_ALT | KEY_LEFT_SHIFT;
const int EXPOSURE_ADD = KEY_F1;
const int EXPOSURE_SUB = KEY_F2;
const int CONTRAST_ADD = KEY_A;
const int CONTRAST_SUB = KEY_F4;
const int SATURATION_ADD = KEY_F5;
const int SATURATION_SUB = KEY_F6;
const int SHADOW_ADD = KEY_F7;
const int SHADOW_SUB = KEY_F8;
const int HIGHLIGHT_ADD = KEY_F9;
const int HIGHLIGHT_SUB = KEY_F10;
const int CLARITY_ADD = KEY_F11;
const int CLARITY_SUB = KEY_F12;
//const int BALANCE_KELVIN_ADD = ?;
//const int BALANCE_KELVIN_SUB = ?;
//const int BALANCE_TINT_ADD = ?;
//const int BALANCE_TINT_SUB = ?;
