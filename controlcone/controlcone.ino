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
*   - Arduino : https://www.arduino.cc
*   - Teensy : https://www.pjrc.com
*   - Phase One : https://www.phaseone.com
*
******************************************************************************/


#include <Keypad.h>
#include "controlcone.h"
#include "shortcuts.h"


// Image adjustments' shortcut
shortcut_t adj_shortcut = NO_ADJ;

// Rotary encoder variable (used by ISR)
volatile int val_encoder = 0;

// Global variables for matrice of buttons (keypad)
Keypad keypad = Keypad( makeKeymap(btns), rowPins, colPins, ROWS, COLS );
char oldBtn = BTN_NOT_USED;  // keep button pressed in memory in case of holding it
unsigned long timeBtnHoldRepeat = 0;

// Keep track of time for state machine
unsigned long currentMillis = 0;


/* 
 * Setup the Arduino Micro Board 
 */
void setup() {
//    for (byte pin = 2; pin <= 11; pin++) {
//        pinMode(pin, INPUT_PULLUP);
//    }

    // Keyboard
    Keyboard.begin();

    // Encoders
    pinMode(PIN_ENC_SA, INPUT_PULLUP);
    pinMode(PIN_ENC_SB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_SA), isr_encoder_sa, FALLING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_SB), isr_encoder_sb, FALLING);

    // Buttons
    keypad.setHoldTime(BTN_HOLD_TIME);
    keypad.setDebounceTime(BTN_DEBOUNCE);

    // For debugging
    Serial.begin(9600);
}


/*
 * Interrupt for rotary encoder pin SA
 * Increase a global variable if CW rotation detected
 */
void isr_encoder_sa() {
  detachInterrupt(digitalPinToInterrupt(PIN_ENC_SB));
  if (digitalRead(PIN_ENC_SA) == 0 && digitalRead(PIN_ENC_SB) == 1) {
    val_encoder++;
  }
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_SB), isr_encoder_sb, FALLING);
}


/* 
 * Interrupt for rotary encoder pin SB
 * Decrease a global variable if CCW rotation detected
 */
void isr_encoder_sb() {
  detachInterrupt(digitalPinToInterrupt(PIN_ENC_SA));
  if (digitalRead(PIN_ENC_SA) == 1 && digitalRead(PIN_ENC_SB) == 0) {
    val_encoder--;
  }
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_SA), isr_encoder_sa, FALLING);
}


/* 
 *  Send a shortcut through USB port
 *  int adjustment: image adjustment used like ADJ_EXPOSURE or ADJ_CONTRAST
 *  byte add_sub: ADD or SUB the mode's value
 */
void send_shortcut(shortcut_t adj_shortcut, byte add_sub) {
    
    // Press keys increase or decrease shortcut according to adjustment
    if (add_sub == SUB) {
        Keyboard.set_modifier(adj_shortcut.modifier2);
        Keyboard.set_key1((byte) adj_shortcut.key2);
    } else {    // add_sub == ADD || add_sub == NO_ADD_SUB
        Keyboard.set_modifier(adj_shortcut.modifier1);
        Keyboard.set_key1((byte) adj_shortcut.key1);
    }
    
    // Send modifiers and keys together
    Keyboard.send_now();

    // Release all keys
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
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
                adj_shortcut = ADJ_CLARITY;
                Serial.println("clarity");
                break;
            case BTN_BAL_TEMP:
                adj_shortcut = ADJ_W_BAL_TEMP;
                Serial.println("white balance kelvin");
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
                send_shortcut(ADJ_AUTO, NO_ADD_SUB);
                break;
            case BTN_RESET:
                send_shortcut(ADJ_RESET, NO_ADD_SUB);
                Serial.println("reset adjustments");
                break;
            case BTN_STAR_CLEAR:
                Serial.println("no *");
                send_shortcut(ADJ_STAR_CLEAR, NO_ADD_SUB);
                break;
            case BTN_STAR1:
                Serial.println("*");
                send_shortcut(ADJ_STAR1, NO_ADD_SUB);
                break;
            case BTN_STAR2:
                Serial.println("**");
                send_shortcut(ADJ_STAR2, NO_ADD_SUB);
                break;        
            case BTN_STAR3:
                Serial.println("***");
                send_shortcut(ADJ_STAR3, NO_ADD_SUB);
                break;        
            case BTN_STAR4:
                Serial.println("****");
                send_shortcut(ADJ_STAR4, NO_ADD_SUB);
                break;        
            case BTN_STAR5:
                Serial.println("*****");
                send_shortcut(ADJ_STAR5, NO_ADD_SUB);
                break;        
            case BTN_STAR_TOGGLE:
                Serial.println("toggle between stars and colors");
                send_shortcut(ADJ_STAR_TOGGLE, NO_ADD_SUB);
                break;  
            case BTN_PAN:
                Serial.println("pan");
                send_shortcut(ADJ_PAN, NO_ADD_SUB);
                break;
            case BTN_CROP:
                Serial.println("crop");
                send_shortcut(ADJ_CROP, NO_ADD_SUB);
                break;
            case BTN_ROTATION:
                Serial.println("rotation");
                send_shortcut(ADJ_ROTATION, NO_ADD_SUB);
                break;  
            case BTN_SPOT:
                Serial.println("spot");
                send_shortcut(ADJ_SPOT, NO_ADD_SUB);
                break;
            case BTN_DRAW_MASK:
                Serial.println("draw mask");
                send_shortcut(ADJ_DRAW_MASK, NO_ADD_SUB);
                break;
            case BTN_ERASE_MASK:
                Serial.println("erase mask");
                send_shortcut(ADJ_ERASE_MASK, NO_ADD_SUB);
                break;
            case BTN_DISPLAY_MASK:
                Serial.println("display mask");
                send_shortcut(ADJ_DISPLAY_MASK, NO_ADD_SUB);
                break;
            case BTN_BAL_PICK:
                Serial.println("white balance pick");
                send_shortcut(ADJ_W_BAL_PICK, NO_ADD_SUB);
                break;
            case BTN_ADJ:
                Serial.println("copy paste adjustments");
                send_shortcut(ADJ_COPY_PASTE, NO_ADD_SUB);
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

    // ADD-SUB via rotary encoder
    if (val_encoder > 0) {
        for (int i = 0; i < val_encoder; i++) {
            send_shortcut(adj_shortcut, ADD);
        }
    } else if (val_encoder < 0) {
        for (int i = 0; i > val_encoder; i--) {
            send_shortcut(adj_shortcut, SUB);
        }
    }
    val_encoder = 0;

}

