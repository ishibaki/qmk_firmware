// ぼくのかんがえたさいきょうのキーマップ(仮)

#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define QWERTY 0    // QWERTY Layer
#define NUMPAD 1    // Numpad Layer
#define FUNCTION 2    // Function Layer
#define MOUSE 3    // Mouse Layer
#define ADJUST 4    // Adjust Layer
#define COLEMAK 5    // COLEMAK Layer
#define CLNM 6  // COLEMAK Numpad Layer
#define CLFN 7  // COLEMAK Function Layer
#define CLMO 8  // COLEMAK Mouse Layer
#define CLAD 9  // COLEMAK Adjust Layer

// Fillers to make layering more clear
// #define KC_ KC_TRNS
// #define _______ KC_TRNS
// #define XXXXX KC_NO
#define KC_CTLESC CTL_T(KC_ESCAPE)
#define KC_TOQWERTY TO(QWERTY)
#define KC_TONUMPAD TO(NUMPAD)
#define KC_TOFUNCTION TO(FUNCTION)
#define KC_TOMOUSE TO(MOUSE)
#define KC_TOADJUST TO(ADJUST)
#define KC_LTNUMPAD LT(NUMPAD, KC_SPACE)
#define KC_LTLFUNCTION LT(FUNCTION, KC_F23) // KC_INT1
#define KC_LTRFUNCTION LT(FUNCTION, KC_F24) // KC_INT2
#define KC_MOMOUSE MO(MOUSE)
#define KC_MOADJUST MO(ADJUST)
#define KC_LTMOUSE LT(MOUSE, KC_SCOLON)
#define KC_TOCOLEMAK TO(COLEMAK)
#define KC_TOCLNM TO(CLNM)
#define KC_TOCLFN TO(CLFN)
#define KC_TOCLMO TO(CLMO)
#define KC_TOCLAD TO(CLAD)
#define KC_LTCLNM LT(CLNM, KC_SPACE)
#define KC_LTLCLFN LT(CLFN, KC_F23) // KC_INT1
#define KC_LTRCLFN LT(CLFN, KC_F24) // KC_INT2
#define KC_MOCLMO MO(CLMO)
#define KC_MOCLAD MO(CLAD)
#define KC_LTCLMO LT(CLMO, KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  | ;/_MO|   '  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |   \  |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [QWERTY] = KC_KEYMAP(
     EQUAL,      GRAVE,  1,    2,        3,       4,           5,        6,        7,           8,       9,        0,       MINUS,    BSPACE,
     TONUMPAD,   TAB,    Q,    W,        E,       R,           T,        Y,        U,           I,       O,        P,       LBRACKET, RBRACKET,
     TOFUNCTION, CTLESC, A,    S,        D,       F,           G,        H,        J,           K,       L,        LTMOUSE, QUOTE,    ENTER,
     TOMOUSE,    LSHIFT, Z,    X,        C,       V,           B,        N,        M,           COMMA,   DOT,      SLASH,   BSLASH,   RSHIFT,
     TOADJUST,   LALT,   LGUI, MOADJUST, MOMOUSE, LTLFUNCTION, LTNUMPAD, LTNUMPAD, LTRFUNCTION, MOMOUSE, MOADJUST, RGUI,    RALT,     DELETE
  ),

/* Numpad
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(QW)| Tab  |  (   |   )  |  [   |   ]  |      |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      |   1  |   2  |   3  |   .  |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |      |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [NUMPAD] = KC_KEYMAP(
     EQUAL,      GRAVE,  F1,       F2,          F3,       F4,       F5,    F6,     F7, F8, F9, F10,    F11,      F12,
     TOQWERTY,   TAB,    LPRN,     RPRN,        LBRACKET, RBRACKET, NO,    DELETE, 7,  8,  9,  0,      LBRACKET, RBRACKET,
     TOFUNCTION, CTLESC, KP_SLASH, KP_ASTERISK, KP_MINUS, KP_PLUS,  EQUAL, BSPACE, 4,  5,  6,  KP_DOT, NO,       ENTER,
     TOMOUSE,    LSHIFT, LABK,     RABK,        LCBR,     RCBR,     NO,    NO,     1,  2,  3,  KP_DOT, NO,       RSHIFT,
     TOADJUST,   LALT,   LGUI,     NO,          F23,      NO,       NO,    NO,     0,  NO, NO, RGUI,   RALT,     DELETE
  ),

/* Function
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |  (   |   )  |  [   |   ]  |      |      |      | Home | End  | PgUp | PgDn |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(QW)|Esc/Ct|      | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      | Left | Down | Right|      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [FUNCTION] = KC_KEYMAP(
     EQUAL,    GRAVE,  F13,  F14,    F15,      F16,      F17,   F18,   F19,  F20,  F21,   F22,    F23,  F24,
     TONUMPAD, TAB,    LPRN, RPRN,   LBRACKET, RBRACKET, NO,    NO,    HOME, END,  PGUP,  PGDOWN, NO,   NO,
     TOQWERTY, CTLESC, NO,   BSPACE, DELETE,   BSPACE,   NO,    LEFT,  DOWN, UP,   RIGHT, PGDOWN, NO,   ENTER,
     TOMOUSE,  LSHIFT, LABK, RABK,   LCBR,     RCBR,     NO,    NO,    LEFT, DOWN, RIGHT, NO,     NO,   RSHIFT,
     TOADJUST, LALT,   LGUI, NO,     NO,       NO,       SPACE, SPACE, NO,   NO,   NO,    RGUI,   RALT, DELETE
  ),

/* Mouse
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  | SPD_2|      |      |      | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(QW)| Shift| SPD_0|      |      |      | SPD_0|      |      |      | W_DN |      |      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [MOUSE] = KC_KEYMAP(
     EQUAL,      GRAVE,  NO,        NO,      NO,      NO,      NO,        NO,    NO,      MS_WH_UP,   NO,       NO,   NO,   BSPACE,
     TONUMPAD,   TAB,    MS_ACCEL2, NO,      NO,      NO,      MS_ACCEL2, NO,    MS_BTN1, MS_UP,      MS_BTN2,  NO,   NO,   NO,
     TOFUNCTION, CTLESC, MS_ACCEL1, MS_BTN2, MS_BTN3, MS_BTN1, MS_ACCEL1, NO,    MS_LEFT, MS_DOWN,    MS_RIGHT, NO,   NO,   ENTER,
     TOQWERTY,   LSHIFT, MS_ACCEL0, NO,      NO,      NO,      MS_ACCEL0, NO,    NO,      MS_WH_DOWN, NO,       NO,   NO,   RSHIFT,
     TOADJUST,   LALT,   LGUI,      NO,      NO,      F23,     SPACE,     SPACE, F24,     NO,         NO,       RGUI, RALT, DELETE
  ),

/* _AD/Adjust
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |TO(CL)|      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|      |      |      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(QW)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [ADJUST] = KC_KEYMAP(
    EQUAL,      GRAVE,  TOCOLEMAK, NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   BSPACE,
    TONUMPAD,   TAB,    NO,        NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   NO,
    TOFUNCTION, CTLESC, NO,        NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   ENTER,
    TOMOUSE,    LSHIFT, NO,        NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   RSHIFT,
    TOQWERTY,   LALT,   LGUI,      NO, NO, F23, SPACE, SPACE, F24, NO, NO, RGUI, RALT, DELETE
  ), 

/* COLEMAK
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |   Q  |   W  |   F  |   P  |   G  |      |   J  |   L  |   U  |   Y  |   ;  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct|   A  |   R  |   S  |   T  |   D  |      |   H  |   N  |   E  |   I  | O/_MO|   '  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   Z  |   X  |   C  |   V  |   B  |      |   K  |   M  |   ,  |   .  |   /  |   \  |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [COLEMAK] = KC_KEYMAP(
     EQUAL,  GRAVE,  1,    2,      3,      4,       5,      6,      7,       8,      9,      0,      MINUS,    BSPACE,
     TOCLNM, TAB,    Q,    W,      F,      P,       G,      J,      L,       U,      Y,      SCOLON, LBRACKET, RBRACKET,
     TOCLFN, CTLESC, A,    R,      S,      T,       D,      H,      N,       E,      I,      LTCLMO, QUOTE,    ENTER,
     TOCLMO, LSHIFT, Z,    X,      C,      V,       B,      K,      M,       COMMA,  DOT,    SLASH,  BSLASH,   RSHIFT,
     TOCLAD, LALT,   LGUI, MOCLAD, MOCLMO, LTLCLFN, LTCLNM, LTCLNM, LTRCLFN, MOCLMO, MOCLAD, RGUI,   RALT,     DELETE
  ),

/* CLNumpad
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(CL)| Tab  |  (   |   )  |  [   |   ]  |      |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      |   1  |   2  |   3  |   .  |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |      |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [CLNM] = KC_KEYMAP(
     EQUAL,     GRAVE,  F1,       F2,          F3,       F4,       F5,    F6,     F7, F8, F9, F10,    F11,      F12,
     TOCOLEMAK, TAB,    LPRN,     RPRN,        LBRACKET, RBRACKET, NO,    DELETE, 7,  8,  9,  0,      LBRACKET, RBRACKET,
     TOCLFN,    CTLESC, KP_SLASH, KP_ASTERISK, KP_MINUS, KP_PLUS,  EQUAL, BSPACE, 4,  5,  6,  KP_DOT, NO,       ENTER,
     TOCLMO,    LSHIFT, LABK,     RABK,        LCBR,     RCBR,     NO,    NO,     1,  2,  3,  KP_DOT, NO,       RSHIFT,
     TOCLAD,    LALT,   LGUI,     NO,          F23,      NO,       NO,    NO,     0,  NO, NO, RGUI,   RALT,     DELETE
  ),

/* CLFunction
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |  (   |   )  |  [   |   ]  |      |      |      | Home | End  | PgUp | PgDn |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(CL)|Esc/Ct|      | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      | Left | Down | Right|      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [CLFN] = KC_KEYMAP(
     EQUAL,     GRAVE,  F13,  F14,    F15,      F16,      F17,   F18,   F19,  F20,  F21,   F22,    F23,  F24,
     TOCLNM,    TAB,    LPRN, RPRN,   LBRACKET, RBRACKET, NO,    NO,    HOME, END,  PGUP,  PGDOWN, NO,   NO,
     TOCOLEMAK, CTLESC, NO,   BSPACE, DELETE,   BSPACE,   NO,    LEFT,  DOWN, UP,   RIGHT, PGDOWN, NO,   ENTER,
     TOCLMO,    LSHIFT, LABK, RABK,   LCBR,     RCBR,     NO,    NO,    LEFT, DOWN, RIGHT, NO,     NO,   RSHIFT,
     TOCLAD,    LALT,   LGUI, NO,     NO,       NO,       SPACE, SPACE, NO,   NO,   NO,    RGUI,   RALT, DELETE
  ),

/* CLMouse
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  | SPD_2|      |      |      | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(QW)| Shift| SPD_0|      |      |      | SPD_0|      |      |      | W_DN |      |      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(CL)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [CLMO] = KC_KEYMAP(
     EQUAL,     GRAVE,  NO,        NO,      NO,      NO,      NO,        NO,    NO,      MS_WH_UP,   NO,       NO,   NO,   BSPACE,
     TOCLNM,    TAB,    MS_ACCEL2, NO,      NO,      NO,      MS_ACCEL2, NO,    MS_BTN1, MS_UP,      MS_BTN2,  NO,   NO,   NO,
     TOCLFN,    CTLESC, MS_ACCEL1, MS_BTN2, MS_BTN3, MS_BTN1, MS_ACCEL1, NO,    MS_LEFT, MS_DOWN,    MS_RIGHT, NO,   NO,   ENTER,
     TOCOLEMAK, LSHIFT, MS_ACCEL0, NO,      NO,      NO,      MS_ACCEL0, NO,    NO,      MS_WH_DOWN, NO,       NO,   NO,   RSHIFT,
     TOCLAD,    LALT,   LGUI,      NO,      NO,      F23,     SPACE,     SPACE, F24,     NO,         NO,       RGUI, RALT, DELETE
  ),

/* CLAdjust
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |TO(QW)|      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(NM)| Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(FN)|Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(MO)| Shift|      |      |      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TO(CL)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [CLAD] = KC_KEYMAP(
    EQUAL,     GRAVE,  TOQWERTY, NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   BSPACE,
    TOCLNM,    TAB,    NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   NO,
    TOCLFN,    CTLESC, NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   ENTER,
    TOCLMO,    LSHIFT, NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   RSHIFT,
    TOCOLEMAK, LALT,   LGUI,     NO, NO, F23, SPACE, SPACE, F24, NO, NO, RGUI, RALT, DELETE
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
//         #endif
//         persistent_default_layer_set(1UL<<_QWERTY);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       return false;
//       break;
//   }
//   return true;
// }
