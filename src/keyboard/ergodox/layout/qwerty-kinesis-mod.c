/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../../../lib/key-functions/private.h"
#include "../matrix.h"
#include "../layout.h"
#include "default--matrix-control.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
    _equal,     _1,         _2,      _3,      _4,    _5, _esc,
      _tab,     _Q,         _W,      _E,      _R,    _T, _esc,
    _ctrlL,     _A,         _S,      _D,      _F,    _G,
   _shiftL,     _Z,         _X,      _C,      _V,    _B,    1,
      _esc, _grave, _backslash, _arrowL, _arrowR,
                                                  _guiL, _altL,
                                              0,      0, _home,
                                            _bs,   _del,  _end,
// right hand
       _6, _6,      _7,      _8,       _9,         _0,      _dash,
     _esc, _Y,      _U,      _I,       _O,         _P, _backslash,
           _H,      _J,      _K,       _L, _semicolon,     _quote,
        3, _N,      _M,  _comma,  _period,     _slash,    _shiftR,
               _arrowU, _arrowD,_bracketL,  _bracketR,      _guiR,
 4, _insert,
_pageU,      0,      0,
_pageD, _enter, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: function and symbol keys
// unused
0,
// left hand
       0,        _F1,        _F2,       _F3,       _F4,       _F5,  _F6,
       0,        _F13,      _F14,      _F15,      _F16,      _F17, _F18,
  _ctrlL,           0,         0,         0,         0,         0,
       0,           0,         0,         0,         0,         0,    1,
       0,           0,         0,         0,         0,
0, 0,
0, 0, 0,
0, 0, 0,
// right hand
 _F6,       _F7,    _F8,        _F9,       _F10,         _F11,     _F12,
   0,      _F19,   _F20,       _F21,       _F22,         _F23,     _F24,
   0,         0,      0,          0,          0,            0,
   0,         0,      0,          0,          0,            0,        0,
                      0,          0,          0,            0,        0,
0, 0,
0, 0, 0,
0, 0, 0),


	KB_MATRIX_LAYER(  // layout: layer 2: keyboard functions
// unused
0,
// left hand
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,
0, 0,
0, 0, 0,
0, 0, 0,
// right hand
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
  	  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
              0,  0,  0,  0,  0,
0, 0,
0, 0, 0,
0, 0, 0),


	KB_MATRIX_LAYER(  // layout: layer 3: numpad
// unused
0,
// left hand
      0, _mul_kp, _div_kp, _mul_kp,     0, 0, 0,
   _tab, _sub_kp,   _9_kp,   _8_kp, _7_kp, 0, 0,
      0, _add_kp,   _6_kp,   _5_kp, _4_kp, 0,
_shiftL,       0,   _3_kp,   _2_kp, _1_kp, 0, 0,
   _esc,  _comma, _period,   _0_kp, _0_kp,
0, 0,
0, 0, 0,
0, 0, 0,
// right hand
0, 0,     0, _equal_kp, _div_kp,   _mul_kp,       0,
0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp,       0,
   0, _4_kp,     _5_kp,   _6_kp,   _add_kp,       0,
3, 0, _1_kp,     _2_kp,   _3_kp,         0, _shiftR,
      _0_kp,     _0_kp, _period,    _comma,       0,
0, 0,
0, 0, 0,
0, 0, 0),

	KB_MATRIX_LAYER(  // layout: layer 4: weechat
// unused
0,
// left hand
  1,  2,  3,  4,  5,  6,  7,
  8,  9, 10, 11, 12, 13, 14,
 15, 16, 17, 18, 19, 20,
 21, 22, 23, 24, 25, 26, 27,
 28, 29, 30, 31, 32,
4, 0,
0, 0, 0,
0, 0, 0,
// right hand
      33,  34,  35,  36,  37,  38,  39,
      40,  41,  42,  43,  44,  45,  46,
  	  47,  48,  49,  50,  51,  52,
      53,  54,  55,  56,  57,  58,  59,
              60,  61,  62,  63,  64,
0, 0,
0, 0, 0,
0, 0, 0),
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

#define  bufchg   &switch_buffer

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         slpunum, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                         kprrel, kprrel, kprrel, kprrel, kprrel,
 lpush4, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL, lpush1,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
          NULL,   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                          NULL,   NULL,   NULL,   NULL, NULL,
   NULL, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


	KB_MATRIX_LAYER(  // press: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // press: layer 3: numpad
// unused
NULL,
// left hand
 dbtldr, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
           NULL, NULL,   NULL, kprrel, kprrel, kprrel, NULL,
           NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
                 NULL, kprrel, kprrel, kprrel, kprrel, NULL,
        slponum, NULL, kprrel, kprrel, kprrel,   NULL, NULL,
                       kprrel, kprrel, kprrel,   NULL, NULL,
   NULL, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),

	KB_MATRIX_LAYER(  // press: layer 4: weechat
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   lpush4,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop1,
 kprrel, kprrel, kprrel, kprrel, kprrel,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
          NULL, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 lpop4, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,  lpop1,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
          NULL,   NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                          NULL,   NULL,   NULL,   NULL, NULL,
   NULL, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


	KB_MATRIX_LAYER(  // release: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer 3: numpad
// unused
NULL,
// left hand
 NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
           NULL, NULL,   NULL, kprrel, kprrel, kprrel, NULL,
           NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL,
                 NULL, kprrel, kprrel, kprrel, kprrel, NULL,
           NULL, NULL, kprrel, kprrel, kprrel,   NULL, NULL,
                       kprrel, kprrel, kprrel,   NULL, NULL,
   NULL, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),

	KB_MATRIX_LAYER(  // release: layer 4: weechat
// unused
NULL,
// left hand
   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
          bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
                    bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
          bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
                              bufchg,   bufchg,   bufchg,   bufchg,   bufchg,
  lpop4,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer N: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   bufchg,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,     NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,     NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,     NULL,   NULL,   NULL )

};

