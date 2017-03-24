/*******************************************************************************
*
* ControlCOne
* Hardware control panel for Phase One Capture One Pro 10
*
* Author: Grégoire Saunier
* Website: www.ekunn.com
* 
* Description :
* This control panel will use mecanical interface such as buttons and rotary
* encoders to send keyboard shortcuts via USB using a Teensy 3.5 board. These
* shortcuts are configured in Phase One Capture One Pro 10 to do adjustment on
* images like contrast or exposition.
* 
* Hardware used (prototyping state for now) :
*   - Teensy 3.5 (comparable to Arduino but with fast 32bits microcontroller,
*                 compact form factor, HID support and tons of IO)
*   - Rotary Encoder from elecfreaks.com
*   - Several dip switches
*   - Breadboard
* 
* Ressources :
*   - Arduino     : https://www.arduino.cc
*   - Teensy      : https://www.pjrc.com
*   - Phase One   : https://www.phaseone.com
*   - Keypad lib  : https://www.pjrc.com/teensy/td_libs_Keypad.html
*   - Encoder lib : https://www.pjrc.com/teensy/td_libs_Encoder.html
*   - Keyboard    : https://www.pjrc.com/teensy/td_keyboard.html
*
******************************************************************************/


#include <Keypad.h>
#include <Encoder.h>
#include "controlcone.h"
#include "shortcuts.h"


// Used to select different adjustments modes
shortcut_double_t adj_shortcut = NO_ADJ;
boolean isStarsMode = true;

// Matrice of buttons (keypad)
Keypad keypad = Keypad( makeKeymap(btns), rowPins, colPins, ROWS, COLS );
char oldBtn = BTN_NOT_USED;  // keep button pressed in memory in case of holding it
unsigned long timeBtnHoldRepeat = 0;

// Encoders
Encoder encAddSub(PIN_ENC_ADDSUB_SA, PIN_ENC_ADDSUB_SB);
Encoder encBrushSize(PIN_ENC_BRUSH_SIZE_SA, PIN_ENC_BRUSH_SIZE_SB);
Encoder encBrushHardness(PIN_ENC_BRUSH_HARD_SA, PIN_ENC_BRUSH_HARD_SB);

// Keep track of time for state machine
unsigned long currentMillis = 0;


/* 
 * Setup the Arduino Micro Board 
 */
void setup() {
    // HID USB Keyboard
    Keyboard.begin();

    // Buttons
    keypad.setHoldTime(BTN_HOLD_TIME);
    keypad.setDebounceTime(BTN_DEBOUNCE);

    // For debugging
    Serial.begin(9600);
}


/* 
 *  Send a double shortcut through USB port
 *  int adjustment: image adjustment used like ADJ_EXPOSURE or ADJ_CONTRAST
 *  byte isAddorStar: ADD/SUB or STAR/COLOR mode
 */
void send_shortcut(shortcut_double_t adj_shortcut, boolean isAddOrStar) {
    
    // Press keys increase or decrease shortcut according to adjustment
    if (isAddOrStar) {
        Keyboard.set_modifier(adj_shortcut.modifier1);
        Keyboard.set_key1((byte) adj_shortcut.key1);
    } else {
        Keyboard.set_modifier(adj_shortcut.modifier2);
        Keyboard.set_key1((byte) adj_shortcut.key2);
    }
    
    // Send modifiers and keys together
    Keyboard.send_now();

    // Release all keys
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
}


/*
 * Send a single shortcut through USB port
 * int adjustment: image adjustment used like ADJ_CROP or ADJ ROTATION
 */
void send_shortcut(shortcut_single_t adj_shortcut) {
    send_shortcut({adj_shortcut.modifier, adj_shortcut.key, 0, 0}, ADD);
}


/* 
 * Main loop 
 */
void loop() {

    // Capture the current time
    currentMillis = millis();

    // Get button value if pressed
    if (char btn = keypad.getKey()) {

        // Keep button pressed in memory because if holded
        // it will be lost when main loop start again
        // (because keypad.getKey() will not return a key)
        oldBtn = btn;
        
        Serial.print("button pressed: ");
        switch (btn) {
            case BTN_EXPO:
                Serial.println("expo");
                adj_shortcut = ADJ_EXPOSURE;
                break;
            case BTN_CONTRAST:
                Serial.println("contrast");
                adj_shortcut = ADJ_CONTRAST;
                break;
            case BTN_SAT:
                Serial.println("sat");
                adj_shortcut = ADJ_SATURATION;
                break;
            case BTN_SHADOW:
                adj_shortcut = ADJ_SHADOW;
                Serial.println("shadow");
                break;
            case BTN_HL:
                adj_shortcut = ADJ_HIGHLIGHT;
                Serial.println("highlight");
                break;
            case BTN_CLARITY:
                Serial.println("clarity");
                adj_shortcut = ADJ_CLARITY;
                break;
            case BTN_BAL_TEMP:
                Serial.println("white balance kelvin");
                adj_shortcut = ADJ_W_BAL_TEMP;
                break;
            case BTN_BAL_TINT:
                adj_shortcut = ADJ_W_BAL_TINT;
                Serial.println("white balance tint");
                break;
            case BTN_ADD:
                Serial.println("+");
                send_shortcut(adj_shortcut, ADD);
                break;  
            case BTN_SUB:
                Serial.println("-");
                send_shortcut(adj_shortcut, SUB);
                break;
            case BTN_AUTO:
                Serial.println("auto adjustments");
                send_shortcut(ADJ_AUTO);
                break;
            case BTN_RESET:
                Serial.println("reset adjustments");
                send_shortcut(ADJ_RESET);
                break;
            case BTN_STAR_CLEAR:
                if (isStarsMode) {
                    Serial.println("no *");
                    send_shortcut(ADJ_STAR_COLOR_CLEAR, STAR);
                } else {
                    Serial.println("no color");
                    send_shortcut(ADJ_STAR_COLOR_CLEAR, COLOR);
                }
                break;
            case BTN_STAR1:
                if (isStarsMode) {
                    Serial.println("*");
                    send_shortcut(ADJ_1STAR_RED, STAR);
                } else {
                    Serial.println("red");
                    send_shortcut(ADJ_1STAR_RED, COLOR);
                }
                break;
            case BTN_STAR2:
                if (isStarsMode) {
                    Serial.println("**");
                    send_shortcut(ADJ_2STARS_BLUE, STAR);
                } else {
                    Serial.println("blue");
                    send_shortcut(ADJ_2STARS_BLUE, COLOR);
                }
                break;        
            case BTN_STAR3:
                if (isStarsMode) {
                    Serial.println("***");
                    send_shortcut(ADJ_3STARS_ORANGE, STAR);
                } else {
                    Serial.println("orange");
                    send_shortcut(ADJ_3STARS_ORANGE, COLOR);
                }
                break;        
            case BTN_STAR4:
                if (isStarsMode) {
                    Serial.println("****");
                    send_shortcut(ADJ_4STARS_YELLOW, STAR);
                } else {
                    Serial.println("yellow");
                    send_shortcut(ADJ_4STARS_YELLOW, COLOR);
                }
                break;        
            case BTN_STAR5:
                if (isStarsMode) {
                    Serial.println("*****");
                    send_shortcut(ADJ_5STARS_GREEN, STAR);
                } else {
                    Serial.println("green");
                    send_shortcut(ADJ_5STARS_GREEN, COLOR);
                }
                break;        
            case BTN_STAR_TOGGLE:
                Serial.println("toggle between stars and colors");
                isStarsMode = !isStarsMode;
                break;  
            case BTN_PAN:
                Serial.println("pan");
                send_shortcut(ADJ_PAN);
                break;
            case BTN_CROP:
                Serial.println("crop");
                send_shortcut(ADJ_CROP);
                break;
            case BTN_ROTATION:
                Serial.println("rotation");
                send_shortcut(ADJ_ROTATION);
                break;  
            case BTN_SPOT:
                Serial.println("spot");
                send_shortcut(ADJ_SPOT);
                break;
            case BTN_DRAW_MASK:
                Serial.println("draw mask");
                send_shortcut(ADJ_DRAW_MASK);
                break;
            case BTN_ERASE_MASK:
                Serial.println("erase mask");
                send_shortcut(ADJ_ERASE_MASK);
                break;
            case BTN_DISPLAY_MASK:
                Serial.println("display mask");
                send_shortcut(ADJ_DISPLAY_MASK);
                break;
            case BTN_BAL_PICK:
                Serial.println("white balance pick");
                send_shortcut(ADJ_W_BAL_PICK);
                break;
            case BTN_ADJ:
                Serial.println("copy paste adjustments");
                send_shortcut(ADJ_COPY_PASTE);
                break;
            case BTN_UNDO:
                Serial.println("undo");
                send_shortcut(ADJ_UNDO);
                break;
            case BTN_REDO:
                Serial.println("redo");
                send_shortcut(ADJ_REDO);
                break;
            default:
                break;
        }
    }


    // Check if ADD or SUB button are hold to continue
    // adding or substracting adjustement value
    if (keypad.getState() == HOLD
        && (oldBtn == BTN_ADD || oldBtn == BTN_SUB)
        && currentMillis-timeBtnHoldRepeat>=BTN_HOLD_REPEAT_DELAY) {
          
        switch (oldBtn) {
            case BTN_ADD:
                Serial.println("button hold   : +");
                send_shortcut(adj_shortcut, ADD);
                break;  
            case BTN_SUB:
                Serial.println("button hold   : -");
                send_shortcut(adj_shortcut, SUB);
                break;
        }

        timeBtnHoldRepeat = currentMillis;
    }

    // Adjustment increase/decrease via rotary encoder
    int valEncAddSub = encAddSub.read() / 4;
    if (valEncAddSub > 0) {
        encAddSub.write(0);
        for (int i = 0; i < valEncAddSub; i++) {
            Serial.println("Encoder ADD-SUB : +");
            send_shortcut(adj_shortcut, ADD);
        }
    } else if (valEncAddSub < 0) {
        encAddSub.write(0);
        for (int i = 0; i > valEncAddSub; i--) {
            Serial.println("Encoder ADD-SUB : -");
            send_shortcut(adj_shortcut, SUB);
        }
    }

    // Brush size via rotary encoder
    int valEncBrushSize = encBrushSize.read() / 4;
    if (valEncBrushSize > 0) {
        encBrushSize.write(0);
        for (int i = 0; i < valEncBrushSize; i++) {
            Serial.println("Encoder BR SIZE : +");
            send_shortcut(ADJ_BRUSH_SIZE, ADD);
        }
    } else if (valEncBrushSize < 0) {
        encBrushSize.write(0);
        for (int i = 0; i > valEncBrushSize; i--) {
            Serial.println("Encoder BR SIZE : -");
            send_shortcut(ADJ_BRUSH_SIZE, SUB);
        }
    }

    // Brush hardness via rotary encoder
    int valEncBrushHardness = encBrushHardness.read() / 4;
    if (valEncBrushHardness > 0) {
        encBrushHardness.write(0);
        // send to times because increase is too small
        for (int i = 0; i < 2*valEncBrushHardness; i++) {
            Serial.println("Encoder BR HARD : +");
            send_shortcut(ADJ_BRUSH_HARDNESS, ADD);
        }
    } else if (valEncBrushHardness < 0) {
        encBrushHardness.write(0);
        // send to times because decrease is too small
        for (int i = 0; i > 2*valEncBrushHardness; i--) {
            Serial.println("Encoder BR HARD : -");
            send_shortcut(ADJ_BRUSH_HARDNESS, SUB);
        }
    }

}

