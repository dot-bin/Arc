#pragma once

#ifndef __ARC_KEYBOARD_KEY_H__
#define __ARC_KEYBOARD_KEY_H__

#include <string>
#include <SDL/SDL.h>

using std::string;

namespace Arc
{
	// Enum of all supported keyboard keys
    enum KeyboardKey
    {
        INVALID_KEY = -1,

        KEY_UNKNOWN,
        KEY_BACKSPACE,
        KEY_TAB,

        KEY_LSHIFT,
        KEY_RSHIFT,

        KEY_LCONTROL,
        KEY_RCONTROL,

        KEY_LALT,
        KEY_RALT,

        KEY_ENTER,
        KEY_CAPS_LOCK,
        KEY_ESCAPE,
        KEY_SPACE,
        KEY_END,
        KEY_HOME,
        KEY_PAGE_UP,
        KEY_PAGE_DOWN,
        KEY_INSERT,
        KEY_DELETE,
        KEY_GRAVE,
        KEY_SEMICOLON,
        KEY_QUOTE,
        KEY_BRACKET_OPEN,
        KEY_BRACKET_CLOSE,
        KEY_COMMA,
        KEY_PERIOD,
        KEY_SLASH,
        KEY_BACKSLASH,
        KEY_DASH,
        KEY_EQUALS,

        KEY_0,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,

        KEY_PAD_0,
        KEY_PAD_1,
        KEY_PAD_2,
        KEY_PAD_3,
        KEY_PAD_4,
        KEY_PAD_5,
        KEY_PAD_6,
        KEY_PAD_7,
        KEY_PAD_8,
        KEY_PAD_9,

        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,

        KEY_UP,
        KEY_DOWN,
        KEY_LEFT,
        KEY_RIGHT,

        KEY_F1,
        KEY_F2,
        KEY_F3,
        KEY_F4,
        KEY_F5,
        KEY_F6,
        KEY_F7,
        KEY_F8,
        KEY_F9,
        KEY_F10,
        KEY_F11,
        KEY_F12,

        NUM_KEYS

    }; // KeyboardKey

    const string KEYBOARD_KEY_NAMES[NUM_KEYS] =
    {
        "Unknown",
        "Backspace",
        "Tab",

        "Left Shift",
        "Right Shift",

        "Left Control",
        "Right Control",

        "Left Alt",
        "Right Alt",

        "Enter",
        "Caps Lock",
        "Escape",
        "Space",
        "End",
        "Home",
        "Page Up",
        "Page Down",
        "Insert",
        "Delete",
        "Grave",
        "Semicolon",
        "Quote",
        "Bracket Open",
        "Bracket Close",
        "Comma",
        "Period",
        "Slash",
        "Backslash",
        "Dash",
        "Equals",

        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",

        "Num Pad 0",
        "Num Pad 1",
        "Num Pad 2",
        "Num Pad 3",
        "Num Pad 4",
        "Num Pad 5",
        "Num Pad 6",
        "Num Pad 7",
        "Num Pad 8",
        "Num Pad 9",

        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N",
        "O",
        "P",
        "Q",
        "R",
        "S",
        "T",
        "U",
        "V",
        "W",
        "X",
        "Y",
        "Z",

        "Arrow Up",
        "Arrow Down",
        "Arrow Left",
        "Arrow Right",

        "F1",
        "F2",
        "F3",
        "F4",
        "F5",
        "F6",
        "F7",
        "F8",
        "F9",
        "F10",
        "F11",
        "F12",
    };

} // namespace Arc

#endif // __ARC_KEYBOARD_H__
