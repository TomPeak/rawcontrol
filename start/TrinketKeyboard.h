/*
This is the part of the TrinketKeyboard code that is exposed to the user

Copyright (c) 2013 Adafruit Industries
All rights reserved.

TrinketKeyboard is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

TrinketKeyboard is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with TrinketKeyboard. If not, see
<http://www.gnu.org/licenses/>.
*/

#ifndef _TRINKETKEYBOARD_H_
#define _TRINKETKEYBOARD_H_

#include <stdint.h>
#include <Print.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

class Trinket_Keyboard : public Print
{
  private:
  public:
    Trinket_Keyboard(); // empty constructor, ignore me
    void begin(); // starts the USB driver, causes re-enumeration
    void poll(); // this (or "press" something) must be called at least once every 10ms
    char isConnected(); // checks if USB is connected, 0 if not connected

    // presses up to 6 keys, and modifiers (modifiers are keys like shift, CTRL, etc)
    void pressKey(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, uint8_t keycode4, uint8_t keycode5, uint8_t keycode6);
    void pressKey(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, uint8_t keycode4, uint8_t keycode5);
    void pressKey(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, uint8_t keycode4);
    void pressKey(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3);
    void pressKey(uint8_t modifiers, uint8_t keycode1, uint8_t keycode2);
    void pressKey(uint8_t modifiers, uint8_t keycode1);

    // presses a list of keys
    void pressKeys(uint8_t modifiers, uint8_t* keycodes, uint8_t sz);

    // type out a single ASCII character
    void typeChar(uint8_t ascii);

    // returns the state of the three LEDs on a keyboard (caps/num/scroll lock)
    uint8_t getLEDstate();

    // inherit from "Print", these two write functions are implemented
    virtual size_t write(uint8_t);
    using Print::write;
    // other "print" and "println" functions are automatically available
    using Print::print;
    using Print::println;
};

// helps translate ASCII characters into keycode and modifier combinations, while taking into account whether or not caps lock is on
void ASCII_to_keycode(uint8_t ascii, uint8_t ledState, uint8_t* modifier, uint8_t* keycode);

// an instance that the user can use
extern Trinket_Keyboard TrinketKeyboard;
//http://forum.pjrc.com/threads/25368-How-do-I-receive-a-numlock-capslock-LED-signal-from-the-PC
// LED state masks
#define KB_LED_NUM      0x01
#define KB_LED_CAPS     0x02
#define KB_LED_SCROLL   0x04
#define KB_LED_CAPS_SCROLL      0x06
#define KB_LED_NUM_CAPS_SCROLL    0x07

// some convenience definitions for modifier keys
#define LEFT_CONTROL  0x01
#define LEFT_SHIFT    0x02
#define LEFT_ALT    0x04
#define LEFT_GUI    0x08
#define RIGHT_CONTROL 0x10
#define RIGHT_SHIFT   0x20
#define RIGHT_ALT   0x40
#define RIGHT_GUI   0x80

// some more keycodes
#define KEY_CAPS_LOCK       0x39
#define KEY_LEFT_CONTROL  0xE0
#define KEY_LEFT_SHIFT    0xE1
#define KEY_LEFT_ALT    0xE2
#define KEY_LEFT_GUI    0xE3
#define KEY_RIGHT_CONTROL 0xE4
#define KEY_RIGHT_SHIFT   0xE5
#define KEY_RIGHT_ALT   0xE6
#define KEY_RIGHT_GUI   0xE7
#define KEY_1       0x1E
#define KEY_2       0x1F
#define KEY_3       0x20
#define KEY_4       0x21
#define KEY_5       0x22
#define KEY_6       0x23
#define KEY_7       0x24
#define KEY_8       0x25
#define KEY_9       0x26
#define KEY_0       0x27
#define KEY_A       0x04
#define KEY_B       0x05
#define KEY_C       0x06
#define KEY_D       0x07
#define KEY_E       0x08
#define KEY_F       0x09
#define KEY_G       0x0A
#define KEY_H       0x0B
#define KEY_I       0x0C
#define KEY_J       0x0D
#define KEY_K       0x0E
#define KEY_L       0x0F
#define KEY_M       0x10
#define KEY_N       0x11
#define KEY_O       0x12
#define KEY_P       0x13
#define KEY_Q       0x14
#define KEY_R       0x15
#define KEY_S       0x16
#define KEY_T       0x17
#define KEY_U       0x18
#define KEY_V       0x19
#define KEY_W       0x1A
#define KEY_X       0x1B
#define KEY_Y       0x1C
#define KEY_Z       0x1D
#define KEY_COMMA     0x36
#define KEY_PERIOD      0x37
#define KEY_ADD     0x2C
#define KEY_MINUS     0x2D
#define KEY_EQUAL     0x2E
#define KEY_BACKSLASH   0x31
#define KEY_SQBRAK_LEFT   0x2F
#define KEY_SQBRAK_RIGHT  0x30
#define KEY_SLASH     0x38
#define KEY_F1        0x3A
#define KEY_F2        0x3B
#define KEY_F3        0x3C
#define KEY_F4        0x3D
#define KEY_F5        0x3E
#define KEY_F6        0x3F
#define KEY_F7        0x40
#define KEY_F8        0x41
#define KEY_F9        0x42
#define KEY_F10       0x43
#define KEY_F11       0x44
#define KEY_F12       0x45
#define KEY_APP       0x65
#define KEY_ENTER     0x28
#define KEY_BACKSPACE   0x2A
#define KEY_ESC       0x29
#define KEY_TAB       0x2B
#define KEY_SPACE     0x2C
#define KEY_INSERT      0x49
#define KEY_HOME      0x4A
#define KEY_PAGE_UP     0x4B
#define KEY_DELETE      0x4C
#define KEY_END       0x4D
#define KEY_PAGE_DOWN   0x4E
#define KEY_PRINTSCREEN   0x46
#define KEY_ARROW_RIGHT   0x4F
#define KEY_ARROW_LEFT    0x50
#define KEY_ARROW_DOWN    0x51
#define KEY_ARROW_UP    0x52

#endif
