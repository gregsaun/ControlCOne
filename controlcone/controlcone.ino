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
* encoders to send keyboard shortcuts via USB using an Arduino. These
* shortcuts will be configured in Phase One Capture One Pro 10 to do adjustment
* on images like contrast or exposition.
* 
* Hardware used (prototyping state for now) :
*   - Arduino Micro
*   - Rotary Encoder from elecfreaks.com
*   - Several dip switches
*   - Breadboard
* 
* Ressources :
*   - Arduino : https://www.arduino.cc
*   - Phase One : https://www.phaseone.com
*
******************************************************************************/


#include <Keyboard.h>
#include "pins.h"
#include "shortcuts.h"

// Image adjustments
imageAdjustments adjustment = NO_ADJ;

// Rotary encoder variable (used by ISR)
volatile int val_encoder = 0;

// 


/* 
 * Setup the Arduino Micro Board 
 */
void setup() {
    for (int pin = 2; pin <= 11; pin++) {
        pinMode(pin, INPUT_PULLUP);
    }
    Keyboard.begin();
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_SA), isr_encoder_sa, FALLING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_SB), isr_encoder_sb, FALLING);
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
void send_shortcut(int adjustment, byte add_sub) {

    // Press shortcut start keys
    for (int i = 0; i < sizeof(SHORTCUT_START); i++) {
        Keyboard.press(SHORTCUT_START[i]);
    }
    
    // Press keys increase or decrease shortcut according to adjustment
    if (add_sub == ADD) {
        switch (adjustment) {
            case ADJ_EXPOSURE: 
                Keyboard.press(EXPOSURE_ADD);
                break;
            case ADJ_CONTRAST:
                Keyboard.press(CONTRAST_ADD);
                break;
            case ADJ_SATURATION: 
                Keyboard.press(SATURATION_ADD);
                break;
            case ADJ_SHADOW: 
                Keyboard.press(SHADOW_ADD);
                break;
            case ADJ_HIGHLIGHT: 
                Keyboard.press(HIGHLIGHT_ADD);
                break;
            case ADJ_CLARITY: 
                Keyboard.press(CLARITY_ADD);
                break;
            default:
                adjustment = NO_ADJ;
                break;
        }
    } else {
        switch (adjustment) {
            case ADJ_EXPOSURE: 
                Keyboard.press(EXPOSURE_SUB);
                break;
            case ADJ_CONTRAST:
                Keyboard.press(CONTRAST_SUB);
                break;
            case ADJ_SATURATION: 
                Keyboard.press(SATURATION_SUB);
                break;
            case ADJ_SHADOW: 
                Keyboard.press(SHADOW_SUB);
                break;
            case ADJ_HIGHLIGHT: 
                Keyboard.press(HIGHLIGHT_SUB);
                break;
            case ADJ_CLARITY: 
                Keyboard.press(CLARITY_SUB);
                break;
            default:
                adjustment = NO_ADJ;
                break;
        }
    }

    // Release pressed keys
    delay(50);
    Keyboard.releaseAll();
}


/* 
 * Main loop 
 */
void loop() {

    // capture the current time
    //currentMillis = millis();

    // Image adjustments
    if (digitalRead(PIN_BTN_EXPOSURE) == LOW) {
        adjustment = ADJ_EXPOSURE;
    } else if (digitalRead(PIN_BTN_CONTRAST) == LOW) {
        adjustment = ADJ_CONTRAST;
    } else if (digitalRead(PIN_BTN_SATURATION) == LOW) {
        adjustment = ADJ_SATURATION;
    } else if (digitalRead(PIN_BTN_SHADOW) == LOW) {
        adjustment = ADJ_SHADOW;
    } else if (digitalRead(PIN_BTN_HIGHLIGHT) == LOW) {
        adjustment = ADJ_HIGHLIGHT;
    } else if (digitalRead(PIN_BTN_CLARITY) == LOW) {
        adjustment = ADJ_CLARITY;
    }

    // ADD-SUB via button
    if (digitalRead(PIN_BTN_ADD) == LOW) {
        send_shortcut(adjustment, ADD);
        delay(150);  //debounce for button only
    } else if (digitalRead(PIN_BTN_SUB) == LOW) {
        send_shortcut(adjustment, SUB);
        delay(150);  //debounce for button only

    // ADD-SUB via rotary encoder
    } if (val_encoder > 0) {
        for (int i = 0; i < val_encoder; i++) {
            send_shortcut(adjustment, ADD);
        }
    } else if (val_encoder < 0) {
        for (int i = 0; i > val_encoder; i--) {
            send_shortcut(adjustment, SUB);
        }
    }
    val_encoder = 0;
}

