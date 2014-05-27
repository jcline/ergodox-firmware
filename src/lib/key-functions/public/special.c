/* ----------------------------------------------------------------------------
 * key functions : special : code
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

#include <stdbool.h>
#include <stdint.h>
#include "../../../lib-other/pjrc/usb_keyboard/usb_keyboard.h"
#include "../../../lib/usb/usage-page/keyboard.h"
#include "../../../keyboard/layout.h"
#include "../../../main.h"
#include "../public.h"
#include "../private.h"

// ----------------------------------------------------------------------------

// convenience macros
#define  LAYER         main_arg_layer
#define  LAYER_OFFSET  main_arg_layer_offset
#define  ROW           main_arg_row
#define  COL           main_arg_col
#define  IS_PRESSED    main_arg_is_pressed
#define  WAS_PRESSED   main_arg_was_pressed


// ----------------------------------------------------------------------------


/*
 * [name]
 *   Shift + press|release
 *
 * [description]
 *   Generate a 'shift' press or release before the normal keypress or
 *   keyrelease
 */
void kbfun_shift_press_release(void) {
	_kbfun_press_release(IS_PRESSED, KEY_LeftShift);
	kbfun_press_release();
}

/*
 * [name]
 *   Two keys => capslock
 *
 * [description]
 *   When assigned to two keys (e.g. the physical left and right shift keys)
 *   (in both the press and release matrices), pressing and holding down one of
 *   the keys will make the second key toggle capslock
 *
 * [note]
 *   If either of the shifts are pressed when the second key is pressed, they
 *   wil be released so that capslock will register properly when pressed.
 *   Capslock will then be pressed and released, and the original state of the
 *   shifts will be restored
 */
void kbfun_2_keys_capslock_press_release(void) {
	static uint8_t keys_pressed;
	static bool lshift_pressed;
	static bool rshift_pressed;

	uint8_t keycode = kb_layout_get(LAYER, ROW, COL);

	if (!IS_PRESSED) keys_pressed--;

	// take care of the key that was actually pressed
	_kbfun_press_release(IS_PRESSED, keycode);

	// take care of capslock (only on the press of the 2nd key)
	if (keys_pressed == 1 && IS_PRESSED) {
		// save the state of left and right shift
		lshift_pressed = _kbfun_is_pressed(KEY_LeftShift);
		rshift_pressed = _kbfun_is_pressed(KEY_RightShift);
		// disable both
		_kbfun_press_release(false, KEY_LeftShift);
		_kbfun_press_release(false, KEY_RightShift);

		// press capslock, then release it
		_kbfun_press_release(true, KEY_CapsLock);
		usb_keyboard_send();
		_kbfun_press_release(false, KEY_CapsLock);
		usb_keyboard_send();

		// restore the state of left and right shift
		if (lshift_pressed)
			_kbfun_press_release(true, KEY_LeftShift);
		if (rshift_pressed)
			_kbfun_press_release(true, KEY_RightShift);
	}

	if (IS_PRESSED) keys_pressed++;
}

/* ----------------------------------------------------------------------------
 * numpad functions
 * ------------------------------------------------------------------------- */

static uint8_t numpad_layer_id;

static inline void numpad_toggle_numlock(void) {
	_kbfun_press_release(true, KEY_LockingNumLock);
	usb_keyboard_send();
	_kbfun_press_release(false, KEY_LockingNumLock);
	usb_keyboard_send();
}

/*
 * [name]
 *   Numpad on
 *
 * [description]
 *   Set the numpad to on (put the numpad layer, specified in the keymap, in an
 *   element at the top of the layer stack, and record that element's id) and
 *   toggle numlock (regardless of whether or not numlock is currently on)
 *
 * [note]
 *   Meant to be assigned (along with "numpad off") instead of a normal numlock
 *   key
 */
void kbfun_layer_push_numpad(void) {
	uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
	main_layers_pop_id(numpad_layer_id);
	numpad_layer_id = main_layers_push(keycode, eStickyNone);
	numpad_toggle_numlock();
}

/*
 * [name]
 *   Numpad off
 *
 * [description]
 *   Set the numpad to off (pop the layer element created by "numpad on" out of
 *   the stack) and toggle numlock (regardless of whether or not numlock is
 *   currently on)
 *
 * [note]
 *   Meant to be assigned (along with "numpad on") instead of a normal numlock
 *   key
 */
void kbfun_layer_pop_numpad(void) {
	main_layers_pop_id(numpad_layer_id);
	numpad_layer_id = 0;
	numpad_toggle_numlock();
}

/*
 * [name]
 *   Media Key Press Release
 *
 * [description]
 *   Generate a keypress for a media key, such as play/pause, next track, or
 *   previous track
 *
 */
void kbfun_mediakey_press_release(void) {
	uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
	_kbfun_mediakey_press_release(IS_PRESSED, keycode);
}

/* ----------------------------------------------------------------------------
 * Custom functionality!
 * ------------------------------------------------------------------------- */

void clear_line(void) {
	_kbfun_press_release(true, KEY_LeftControl);
	usb_keyboard_send();
	_kbfun_press_release(true, KEY_u_U);
	usb_keyboard_send();
	_kbfun_press_release(false, KEY_u_U);
	usb_keyboard_send();
	_kbfun_press_release(false, KEY_LeftControl);
	usb_keyboard_send();
}

void press_unpress(uint8_t key) {
	_kbfun_press_release(true, key);
	usb_keyboard_send();
	_kbfun_press_release(false, key);
	usb_keyboard_send();
}

void send_number(uint8_t number) {
	switch(number) {
		case 0:
			press_unpress(KEY_0_RightParenthesis);
			break;
		case 1:
			press_unpress(KEY_1_Exclamation);
			break;
		case 2:
			press_unpress(KEY_2_At);
			break;
		case 3:
			press_unpress(KEY_3_Pound);
			break;
		case 4:
			press_unpress(KEY_4_Dollar);
			break;
		case 5:
			press_unpress(KEY_5_Percent);
			break;
		case 6:
			press_unpress(KEY_6_Caret);
			break;
		case 7:
			press_unpress(KEY_7_Ampersand);
			break;
		case 8:
			press_unpress(KEY_8_Asterisk);
			break;
		case 9:
			press_unpress(KEY_9_LeftParenthesis);
			break;
		default:
			break;
	}
}

void switch_buffer(void) {
	uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
	clear_line();
	press_unpress(KEY_Slash_Question);
	press_unpress(KEY_b_B);
	press_unpress(KEY_Spacebar);

	if (keycode > 99) {
		send_number(1);
		keycode %= 100;
		if (keycode > 9) {
			send_number(keycode/10);
			keycode %= 10;
		} else {
			send_number(0);
		}
	} else if (keycode > 9) {
		send_number(keycode/10);
		keycode %= 10;
	}

	send_number(keycode);

	press_unpress(KEY_ReturnEnter);
}

