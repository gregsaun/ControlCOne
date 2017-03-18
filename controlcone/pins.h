/*
 * All button used to select adjustements to modify
 * an image. This will not do any changes to the image
 * until we increase or decrease this adjustment.
 */
const byte PIN_BTN_EXPOSURE = 4;
const byte PIN_BTN_CONTRAST = 5;
const byte PIN_BTN_SATURATION = 6;
const byte PIN_BTN_SHADOW = 9;
const byte PIN_BTN_HIGHLIGHT = 10;
const byte PIN_BTN_CLARITY = 11;
//const int PIN_BTN_BALANCE_KELVIN = ?;
//const int PIN_BTN_BALANCE_TINT = ?;


/*
 * Two buttons to increase or decrease an adjustment
 */
const byte PIN_BTN_ADD = 7;
const byte PIN_BTN_SUB = 8;


/*
 * Pins for the Rotary Encoder . It is used to increase
 * or decrease an adjustment.
 * Both pins need to be connected to an interrupt
 */
const byte PIN_ENC_SA = 2;  // ISR
const byte PIN_ENC_SB = 3;  // ISR
