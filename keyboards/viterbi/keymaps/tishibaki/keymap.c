// ぼくのかんがえたさいきょうのキーマップ(仮)

#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0    // QWERTY Layer
#define _NM 1    // Numpad Layer
#define _FN 2    // Function Layer
#define _MO 3    // Mouse Layer
#define _AD 4    // Adjust Layer
#define _CL 5    // COLEMAK Layer
#define _CLNM 6  // COLEMAK Numpad Layer
#define _CLFN 7  // COLEMAK Function Layer
#define _CLMO 8  // COLEMAK Mouse Layer
#define _CLAD 9  // COLEMAK Adjust Layer

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ESCTL CTL_T(KC_ESC)
#define KC_SCLNMO LT(_MO, KC_SCLN)
#define KC_LTFN23 LT(_FN, KC_F23) //KC_INT1
#define KC_LTFN24 LT(_FN, KC_F24) //KC_INT2
#define KC_LTNMSP LT(_NM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QW/QWERTY
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
  [_QW] = KC_KEYMAP(
     EQL, GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, BSPC,
     TO(_NM), TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC,
     TO(_FN), ESCTL, A, S, D, F, G, H, J, K, L, SCLNMO, QUOT, ENT,
     TO(_MO), LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, BSLS, RSFT,
     TO(_AD), LALT, LGUI, MO(_AD), MO(_MO), LTFN23, LTNMSP, LTNMSP, LTFN24, MO(_MO), MO(_AD), RGUI, RALT, DEL
  )

// /* _NM/Numpad
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)| Tab  |  (   |   )  |  [   |   ]  |      |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      |   1  |   2  |   3  |   .  |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |      |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_NM] = KC_KEYMAP(
//      KC_EQUAL, KC_GRAVE,         KC_F1,       KC_F2,          KC_F3,       KC_F4,       KC_F5,    KC_F6,     KC_F7, KC_F8, KC_F9, KC_F10,    KC_F11,      KC_F12,
//      TO(_QW),  KC_TAB,           KC_LPRN,     KC_RPRN,        KC_LBRACKET, KC_RBRACKET, KC_NO,    KC_DELETE, KC_7,  KC_8,  KC_9,  KC_0,      KC_LBRACKET, KC_RBRACKET,
//      TO(_FN),  CTL_T(KC_ESCAPE), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_PLUS,  KC_EQUAL, KC_BSPACE, KC_4,  KC_5,  KC_6,  KC_KP_DOT, KC_NO,       KC_ENTER,
//      TO(_MO),  KC_LSHIFT,        KC_LABK,     KC_RABK,        KC_LCBR,     KC_RCBR,     KC_NO,    KC_NO,     KC_1,  KC_2,  KC_3,  KC_KP_DOT, KC_NO,       KC_RSHIFT,
//      TO(_AD),  KC_LALT,          KC_LGUI,     KC_NO,          KC_F23/*KC_INT1*/,      KC_NO,       KC_NO,    KC_NO,     KC_0,  KC_NO, KC_NO, KC_RGUI,   KC_RALT,     KC_DELETE
//   ),
// 
// /* _FN/Function
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |  (   |   )  |  [   |   ]  |      |      |      | Home | End  | PgUp | PgDn |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)|Esc/Ct|      | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      | Left | Down | Right|      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_FN] = KC_KEYMAP(
//      KC_EQUAL, KC_GRAVE,         KC_F13,  KC_F14,    KC_F15,      KC_F16,      KC_F17,   KC_F18,   KC_F19,  KC_F20, KC_F21,   KC_F22,    KC_F23,  KC_F24,
//      TO(_NM),  KC_TAB,           KC_LPRN, KC_RPRN,   KC_LBRACKET, KC_RBRACKET, KC_NO,    KC_NO,    KC_HOME, KC_END, KC_PGUP,  KC_PGDOWN, KC_NO,   KC_NO,
//      TO(_QW),  CTL_T(KC_ESCAPE), KC_NO,   KC_BSPACE, KC_DELETE,   KC_BSPACE,   KC_NO,    KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_PGDOWN, KC_NO,   KC_ENTER,
//      TO(_MO),  KC_LSHIFT,        KC_LABK, KC_RABK,   KC_LCBR,     KC_RCBR,     KC_NO,    KC_NO,    KC_LEFT,   KC_DOWN,  KC_RIGHT,    KC_NO,     KC_NO,   KC_RSHIFT,
//      TO(_AD),  KC_LALT,          KC_LGUI, KC_NO,     KC_NO,       KC_NO,       KC_SPACE, KC_SPACE, KC_NO,   KC_NO,  KC_NO,    KC_RGUI,   KC_RALT, KC_DELETE
//   ),
// 
// /* _MO/Mouse
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  | SPD_2|      |      |      | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)| Shift| SPD_0|      |      |      | SPD_0|      |      |      | W_DN |      |      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_MO] = KC_KEYMAP(
//      KC_EQUAL, KC_GRAVE,         KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,        KC_NO,    KC_NO,      KC_MS_WH_UP,   KC_NO,       KC_NO,   KC_NO,   KC_BSPACE,
//      TO(_NM),  KC_TAB,           KC_MS_ACCEL2, KC_NO,      KC_NO,      KC_NO,      KC_MS_ACCEL2, KC_NO,    KC_MS_BTN1, KC_MS_UP,      KC_MS_BTN2,  KC_NO,   KC_NO,   KC_NO,
//      TO(_FN),  CTL_T(KC_ESCAPE), KC_MS_ACCEL1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_MS_ACCEL1, KC_NO,    KC_MS_LEFT, KC_MS_DOWN,    KC_MS_RIGHT, KC_NO,   KC_NO,   KC_ENTER,
//      TO(_QW),  KC_LSHIFT,        KC_MS_ACCEL0, KC_NO,      KC_NO,      KC_NO,      KC_MS_ACCEL0, KC_NO,    KC_NO,      KC_MS_WH_DOWN, KC_NO,       KC_NO,   KC_NO,   KC_RSHIFT,
//      TO(_AD),  KC_LALT,          KC_LGUI,      KC_NO,      KC_NO,      KC_F23,     KC_SPACE,     KC_SPACE, KC_F24/*KC_INT2*/,     KC_NO,         KC_NO,       KC_RGUI, KC_RALT, KC_DELETE
//   ),
// 
// /* _AD/Adjust
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |TO(CL)|      |      |      |      |      |      |      |      |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|      |      |      |      |      |      |      |      |      |      |      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_AD] = KC_KEYMAP(
//     KC_EQUAL, KC_GRAVE,         TO(_CL), KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_BSPACE,
//     TO(_NM),  KC_TAB,           KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
//     TO(_FN),  CTL_T(KC_ESCAPE), KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_ENTER,
//     TO(_MO),  KC_LSHIFT,        KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_RSHIFT,
//     TO(_QW),  KC_LALT,          KC_LGUI, KC_NO, KC_NO, KC_F23/*KC_INT1*/, KC_SPACE, KC_SPACE, KC_F24/*KC_INT2*/, KC_NO, KC_NO, KC_RGUI, KC_RALT, KC_DELETE
//   ), 
// 
// /* _CL/COLEMAK
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |   Q  |   W  |   F  |   P  |   G  |      |   J  |   L  |   U  |   Y  |   ;  |   [  |   ]  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct|   A  |   R  |   S  |   T  |   D  |      |   H  |   N  |   E  |   I  | O/_MO|   '  |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|   Z  |   X  |   C  |   V  |   B  |      |   K  |   M  |   ,  |   .  |   /  |   \  |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_CL] = KC_KEYMAP(
//      KC_EQUAL, KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_BSPACE,
//      TO(_CLNM), KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_LBRACKET, KC_RBRACKET,
//      TO(_CLFN), CTL_T(KC_ESCAPE), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, LT(_CLMO, KC_O), KC_QUOTE, KC_ENTER,
//      TO(_CLMO), KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH, KC_RSHIFT,
//      TO(_CLAD), KC_LALT, KC_LGUI, MO(_CLAD), MO(_CLMO), LT(_CLFN, KC_F23/*KC_INT2*/), LT(_CLNM, KC_SPACE), LT(_CLNM, KC_SPACE), LT(_CLFN, KC_F24/*KC_INT2*/), MO(_CLMO), MO(_CLAD), KC_RGUI, KC_RALT, KC_DELETE
//   ),
// 
// /* _CLNM/Numpad
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)| Tab  |  (   |   )  |  [   |   ]  |      |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      |   1  |   2  |   3  |   .  |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |      |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_CLNM] = KC_KEYMAP(
//      KC_EQUAL,  KC_GRAVE,         KC_F1,       KC_F2,          KC_F3,       KC_F4,       KC_F5,    KC_F6,     KC_F7, KC_F8, KC_F9, KC_F10,    KC_F11,      KC_F12,
//      TO(_CL),   KC_TAB,           KC_LPRN,     KC_RPRN,        KC_LBRACKET, KC_RBRACKET, KC_NO,    KC_DELETE, KC_7,  KC_8,  KC_9,  KC_0,      KC_LBRACKET, KC_RBRACKET,
//      TO(_CLFN), CTL_T(KC_ESCAPE), KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_PLUS,  KC_EQUAL, KC_BSPACE, KC_4,  KC_5,  KC_6,  KC_KP_DOT, KC_NO,       KC_ENTER,
//      TO(_CLMO), KC_LSHIFT,        KC_LABK,     KC_RABK,        KC_LCBR,     KC_RCBR,     KC_NO,    KC_NO,     KC_1,  KC_2,  KC_3,  KC_KP_DOT, KC_NO,       KC_RSHIFT,
//      TO(_CLAD), KC_LALT,          KC_LGUI,     KC_NO,          KC_F23/*KC_INT1*/,      KC_NO,       KC_NO,    KC_NO,     KC_0,  KC_NO, KC_NO, KC_RGUI,   KC_RALT,     KC_DELETE
//   ),
// 
// /* _CLFN/Function
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |  (   |   )  |  [   |   ]  |      |      |      | Home | End  | PgUp | PgDn |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|Esc/Ct|      | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|   <  |   >  |  {   |   }  |      |      |      | Left | Down | Right|      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_CLFN] = KC_KEYMAP(
//      KC_EQUAL,  KC_GRAVE,         KC_F13,  KC_F14,    KC_F15,      KC_F16,      KC_F17,   KC_F18,   KC_F19,  KC_F20,  KC_F21,      KC_F22,    KC_F23,  KC_F24,
//      TO(_CLNM), KC_TAB,           KC_LPRN, KC_RPRN,   KC_LBRACKET, KC_RBRACKET, KC_NO,    KC_NO,    KC_HOME, KC_END,  KC_PGUP,     KC_PGDOWN, KC_NO,   KC_NO,
//      TO(_CL),   CTL_T(KC_ESCAPE), KC_NO,   KC_BSPACE, KC_DELETE,   KC_BSPACE,   KC_NO,    KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,    KC_PGDOWN, KC_NO,   KC_ENTER,
//      TO(_CLMO), KC_LSHIFT,        KC_LABK, KC_RABK,   KC_LCBR,     KC_RCBR,     KC_NO,    KC_NO,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,     KC_NO,   KC_RSHIFT,
//      TO(_CLAD), KC_LALT,          KC_LGUI, KC_NO,     KC_NO,       KC_NO,       KC_SPACE, KC_SPACE, KC_NO,   KC_NO,   KC_NO,       KC_RGUI,   KC_RALT, KC_DELETE
//   ),
// 
// /* _CLMO/Mouse
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  | SPD_2|      |      |      | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)| Shift| SPD_0|      |      |      | SPD_0|      |      |      | W_DN |      |      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_CLMO] = KC_KEYMAP(
//      KC_EQUAL,  KC_GRAVE,         KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,        KC_NO,    KC_NO,      KC_MS_WH_UP,   KC_NO,       KC_NO,   KC_NO,   KC_BSPACE,
//      TO(_CLNM), KC_TAB,           KC_MS_ACCEL2, KC_NO,      KC_NO,      KC_NO,      KC_MS_ACCEL2, KC_NO,    KC_MS_BTN1, KC_MS_UP,      KC_MS_BTN2,  KC_NO,   KC_NO,   KC_NO,
//      TO(_CLFN), CTL_T(KC_ESCAPE), KC_MS_ACCEL1, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_MS_ACCEL1, KC_NO,    KC_MS_LEFT, KC_MS_DOWN,    KC_MS_RIGHT, KC_NO,   KC_NO,   KC_ENTER,
//      TO(_CL),   KC_LSHIFT,        KC_MS_ACCEL0, KC_NO,      KC_NO,      KC_NO,      KC_MS_ACCEL0, KC_NO,    KC_NO,      KC_MS_WH_DOWN, KC_NO,       KC_NO,   KC_NO,   KC_RSHIFT,
//      TO(_CLAD), KC_LALT,          KC_LGUI,      KC_NO,      KC_NO,      KC_F23/*KC_INT1*/,     KC_SPACE,     KC_SPACE, KC_F24/*KC_INT2*/,     KC_NO,         KC_NO,       KC_RGUI, KC_RALT, KC_DELETE
//   ),
// 
// /* _CLAD/Adjust
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |TO(QW)|      |      |      |      |      |      |      |      |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)| Shift|      |      |      |      |      |      |      |      |      |      |      |      |Shift |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [_CLAD] = KC_KEYMAP(
//     KC_EQUAL,  KC_GRAVE,         TO(_QW), KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_BSPACE,
//     TO(_CLNM), KC_TAB,           KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
//     TO(_CLFN), CTL_T(KC_ESCAPE), KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_ENTER,
//     TO(_CLMO), KC_LSHIFT,        KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_RSHIFT,
//     TO(_CL),   KC_LALT,          KC_LGUI, KC_NO, KC_NO, KC_F23/*KC_INT1*/, KC_SPACE, KC_SPACE, KC_F24/*KC_INT2*/, KC_NO, KC_NO, KC_RGUI, KC_RALT, KC_DELETE
//   )
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
