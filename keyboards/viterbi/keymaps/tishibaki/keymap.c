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
#define COLEMAK 1    // QWERTY Layer
#define NUMPAD 2    // Numpad Layer
#define FUNCTION 3    // Function Layer
#define MOUSE 4    // Mouse Layer
#define ADJUST 5    // Adjust Layer
// #define COLEMAK 5    // COLEMAK Layer
// #define CLNM 6  // COLEMAK Numpad Layer
// #define CLFN 7  // COLEMAK Function Layer
// #define CLMO 8  // COLEMAK Mouse Layer
// #define CLAD 9  // COLEMAK Adjust Layer

// Fillers to make layering more clear
// #define KC_ KC_TRNS
// #define _______ KC_TRNS
// #define XXXXX KC_NO
#define KC_CTLESC CTL_T(KC_ESCAPE)
#define KC_LSFTBSL LSFT_T(KC_BSLASH)
#define KC_RSFTBSL RSFT_T(KC_BSLASH)
// #define KC_TOQWERTY TO(QWERTY)
#define KC_TGNUMPAD TG(NUMPAD)
#define KC_TGFUNCTION TG(FUNCTION)
#define KC_TGMOUSE TG(MOUSE)
#define KC_TGADJUST TG(ADJUST)
#define KC_LTNUMPAD LT(NUMPAD, KC_SPACE)
#define KC_LTLFUNCTION LT(FUNCTION, KC_F23) // KC_INT1
#define KC_LTRFUNCTION LT(FUNCTION, KC_F24) // KC_INT2
#define KC_MOMOUSE MO(MOUSE)
#define KC_MOADJUST MO(ADJUST)
#define KC_LTMOUSE LT(MOUSE, KC_SCOLON)
// #define KC_TOCOLEMAK TO(COLEMAK)
// #define KC_TOCLNM TO(CLNM)
// #define KC_TOCLFN TO(CLFN)
// #define KC_TOCLMO TO(CLMO)
// #define KC_TOCLAD TO(CLAD)
// #define KC_LTCLNM LT(CLNM, KC_SPACE)
// #define KC_LTLCLFN LT(CLFN, KC_F23) // KC_INT1
// #define KC_LTRCLFN LT(CLFN, KC_F24) // KC_INT2
// #define KC_MOCLMO MO(CLMO)
// #define KC_MOCLAD MO(CLAD)
#define KC_LTCLMO LT(MOUSE, KC_O)
#define KC_DFQWERTY DF(QWERTY)
#define KC_DFCOLEMAK DF(COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(NM)| Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(FN)|Esc/Ct|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  | ;/_MO|   '  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(MO)|LSft \|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |   \  |RSft /|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [QWERTY] = KC_KEYMAP(
     EQUAL,      GRAVE,   1,    2,        3,       4,           5,        6,        7,           8,       9,        0,       MINUS,    BSPACE,
     TGNUMPAD,   TAB,     Q,    W,        E,       R,           T,        Y,        U,           I,       O,        P,       LBRACKET, RBRACKET,
     TGFUNCTION, CTLESC,  A,    S,        D,       F,           G,        H,        J,           K,       L,        LTMOUSE, QUOTE,    ENTER,
     TGMOUSE,    LSFTBSL, Z,    X,        C,       V,           B,        N,        M,           COMMA,   DOT,      SLASH,   BSLASH,   RSFTBSL,
     TGADJUST,   LALT,    LGUI, MOADJUST, MOMOUSE, LTLFUNCTION, LTNUMPAD, LTNUMPAD, LTRFUNCTION, MOMOUSE, MOADJUST, RGUI,    RALT,     DELETE
  ),

/* COLEMAK
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(NM)| Tab  |   Q  |   W  |   F  |   P  |   G  |      |   J  |   L  |   U  |   Y  |   ;  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(FN)|Esc/Ct|   A  |   R  |   S  |   T  |   D  |      |   H  |   N  |   E  |   I  | O/_MO|   '  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(MO)|LSft \|   Z  |   X  |   C  |   V  |   B  |      |   K  |   M  |   ,  |   .  |   /  |   \  |RSft \|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [COLEMAK] = KC_KEYMAP(
     EQUAL,      GRAVE,   1,    2,        3,       4,           5,        6,        7,           8,       9,        0,      MINUS,    BSPACE,
     TGNUMPAD,   TAB,     Q,    W,        F,       P,           G,        J,        L,           U,       Y,        SCOLON, LBRACKET, RBRACKET,
     TGFUNCTION, CTLESC,  A,    R,        S,       T,           D,        H,        N,           E,       I,        LTCLMO, QUOTE,    ENTER,
     TGMOUSE,    LSFTBSL, Z,    X,        C,       V,           B,        K,        M,           COMMA,   DOT,      SLASH,  BSLASH,   RSFTBSL,
     TGADJUST,   LALT,    LGUI, MOADJUST, MOMOUSE, LTLFUNCTION, LTNUMPAD, LTNUMPAD, LTRFUNCTION, MOMOUSE, MOADJUST, RGUI,   RALT,     DELETE
  ),

/* Numpad
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(DF)| Tab  |  [   |   ]  |  (   |   )  |   `  |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(MO)|LSft \|  {   |   }  |  <   |   >  |      |      |      |   1  |   2  |   3  |   .  |      |RSft \|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |   ,  |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [NUMPAD] = KC_KEYMAP(
     EQUAL,      GRAVE,   F1,       F2,          F3,       F4,      F5,       F6,       F7, F8,    F9, F10,    F11,      F12,
     TGNUMPAD,   TAB,     LBRACKET, RBRACKET,    LPRN,     RPRN,    GRAVE,    DELETE,   7,  8,     9,  0,      LBRACKET, RBRACKET,
     TGFUNCTION, CTLESC,  KP_SLASH, KP_ASTERISK, KP_MINUS, KP_PLUS, EQUAL,    BSPACE,   4,  5,     6,  KP_DOT, NO,       ENTER,
     TGMOUSE,    LSFTBSL, LCBR,     RCBR,        LABK,     RABK,    NO,       NO,       1,  2,     3,  KP_DOT, NO,       RSFTBSL,
     TGADJUST,   LALT,    LGUI,     NO,          NO,       F23,     LTNUMPAD, LTNUMPAD, 0,  COMMA, NO, RGUI,   RALT,     DELETE
  ),

/* Function
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Tab  |  [   |   ]  |  (   |   )  |   `  |      |      | Home | End  | PgUp | PgDn |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(DF)|Esc/Ct|Enter | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(MO)|LSft \|  {   |   }  |  <   |   >  |      |      |      | Left | Down | Right|      |      |RSft \|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [FUNCTION] = KC_KEYMAP(
     EQUAL,      GRAVE,   F13,      F14,      F15,    F16,         F17,   F18,   F19,         F20,  F21,   F22,    F23,  F24,
     NO,         TAB,     LBRACKET, RBRACKET, LPRN,   RPRN,        GRAVE, NO,    HOME,        END,  PGUP,  PGDOWN, NO,   NO,
     TGFUNCTION, CTLESC,  ENTER,    BSPACE,   DELETE, BSPACE,      NO,    LEFT,  DOWN,        UP,   RIGHT, PGDOWN, NO,   ENTER,
     TGMOUSE,    LSFTBSL, LCBR,     RCBR,     LABK,   RABK,        NO,    NO,    LEFT,        DOWN, RIGHT, NO,     NO,   RSFTBSL,
     TGADJUST,   LALT,    LGUI,     NO,       NO,     LTLFUNCTION, SPACE, SPACE, LTRFUNCTION, NO,   NO,    RGUI,   RALT, DELETE
  ),

/* Mouse
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Tab  | SPD_2| W_LT | W_UP | W_RT | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(DF)|LSft \| SPD_0|MBTN_5| W_DN |MBTN_4| SPD_0|      |      |      | W_DN |      |      |      |RSft \|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(AD)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [MOUSE] = KC_KEYMAP(
     EQUAL,      GRAVE,   NO,        NO,         NO,         NO,          NO,        NO,    NO,      MS_WH_UP,   NO,       NO,      NO,   BSPACE,
     NO,   TAB,     MS_ACCEL2, MS_WH_LEFT, MS_WH_UP,   MS_WH_RIGHT, MS_ACCEL2, NO,    MS_BTN1, MS_UP,      MS_BTN2,  NO,      NO,   NO,
     NO, CTLESC,  MS_ACCEL1, MS_BTN2,    MS_BTN3,    MS_BTN1,     MS_ACCEL1, NO,    MS_LEFT, MS_DOWN,    MS_RIGHT, LTMOUSE, NO,   ENTER,
     TGMOUSE,   LSFTBSL, MS_ACCEL0, MS_BTN5,    MS_WH_DOWN, MS_BTN4,     MS_ACCEL0, NO,    NO,      MS_WH_DOWN, NO,       NO,      NO,   RSFTBSL,
     TGADJUST,   LALT,    LGUI,      NO,         MOMOUSE,    F23,         SPACE,     SPACE, F24,     MOMOUSE,    NO,       RGUI,    RALT, DELETE
  ),

/* Adjust
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |   =  |   `  |DF(QW)|DF(CL)|      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |LSft \|      |      |      |      |      |      |      |      |      |      |      |      |RSft \|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |TG(DF)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [ADJUST] = KC_KEYMAP(
    EQUAL,      GRAVE,  DFQWERTY, DFCOLEMAK,       NO, NO,  NO,    NO,    NO,  NO, NO,       NO,   NO,   BSPACE,
    NO,   TAB,    NO,        NO,       NO, NO,  NO,    NO,    NO,  NO, NO,       NO,   NO,   NO,
    NO, CTLESC, NO,        NO,       NO, NO,  NO,    NO,    NO,  NO, NO,       NO,   NO,   ENTER,
    NO,    LSFTBSL, NO,        NO,       NO, NO,  NO,    NO,    NO,  NO, NO,       NO,   NO,   RSFTBSL,
    TGADJUST,   LALT,   LGUI,      MOADJUST, NO, F23, SPACE, SPACE, F24, NO, MOADJUST, RGUI, RALT, DELETE
  ) 

// /* COLEMAK
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   -  | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TG(NM)| Tab  |   Q  |   W  |   F  |   P  |   G  |      |   J  |   L  |   U  |   Y  |   ;  |   [  |   ]  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TG(FN)|Esc/Ct|   A  |   R  |   S  |   T  |   D  |      |   H  |   N  |   E  |   I  | O/_MO|   '  |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TG(MO)|LSft \|   Z  |   X  |   C  |   V  |   B  |      |   K  |   M  |   ,  |   .  |   /  |   \  |RSft \|
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TG(AD)|  Alt | GUI  |MO(AD)|MO(MO)|EN/_FN|Sp/_NM|      |Sp/_NM|JP/_FN|MO(MO)|MO(AD)| GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [COLEMAK] = KC_KEYMAP(
//      EQUAL,  GRAVE,  1,    2,      3,      4,       5,      6,      7,       8,      9,      0,      MINUS,    BSPACE,
//      TOCLNM, TAB,    Q,    W,      F,      P,       G,      J,      L,       U,      Y,      SCOLON, LBRACKET, RBRACKET,
//      TOCLFN, CTLESC, A,    R,      S,      T,       D,      H,      N,       E,      I,      LTCLMO, QUOTE,    ENTER,
//      TOCLMO, LSFTBSL, Z,    X,      C,      V,       B,      K,      M,       COMMA,  DOT,    SLASH,  BSLASH,   RSFTBSL,
//      TOCLAD, LALT,   LGUI, MOCLAD, MOCLMO, LTLCLFN, LTCLNM, LTCLNM, LTRCLFN, MOCLMO, MOCLAD, RGUI,   RALT,     DELETE
//   ),
// 
// /* CLNumpad
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)| Tab  |  [   |   ]  |  (   |   )  |      |      | Del  |   7  |   8  |   9  |   0  |   [  |   ]  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| NUM/ | NUM* | NUM- | NUM+ |   =  |      | Bksp |   4  |   5  |   6  |   .  |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)|LSft \|  {   |   }  |  <   |   >  |      |      |      |   1  |   2  |   3  |   .  |      |RSft \|
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      |  EN  | xxxx |      | xxxx |   0  |   ,  |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [CLNM] = KC_KEYMAP(
//      EQUAL,     GRAVE,   F1,       F2,          F3,       F4,      F5,     F6,     F7, F8,    F9, F10,    F11,      F12,
//      TOCOLEMAK, TAB,     LBRACKET, RBRACKET,    LPRN,     RPRN,    NO,     DELETE, 7,  8,     9,  0,      LBRACKET, RBRACKET,
//      TOCLFN,    CTLESC,  KP_SLASH, KP_ASTERISK, KP_MINUS, KP_PLUS, EQUAL,  BSPACE, 4,  5,     6,  KP_DOT, NO,       ENTER,
//      TOCLMO,    LSFTBSL, LCBR,     RCBR,        LABK,     RABK,    NO,     NO,     1,  2,     3,  KP_DOT, NO,       RSFTBSL,
//      TOCLAD,    LALT,    LGUI,     NO,          NO,       F23,     LTCLNM, LTCLNM, 0,  COMMA, NO, RGUI,   RALT,     DELETE
//   ),
// 
// /* CLFunction
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |  F13 |  F14 |  F15 |  F16 |  F17 |      |  F18 |  F19 |  F20 |  F21 | F22  | F23  | F24  |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |  [   |   ]  |  (   |   )  |      |      |      | Home | End  | PgUp | PgDn |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|Esc/Ct|Enter | Bksp |  Del | Bksp |      |      | Left | Down |  Up  | Right| PgDn |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)|LSft \|  {   |   }  |  <   |   >  |      |      |      | Left | Down | Right|      |      |RSft \|
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(AD)|  Alt | GUI  |      |      | xxxx | Space|      |Space | xxxx |      |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [CLFN] = KC_KEYMAP(
//      EQUAL,     GRAVE,   F13,      F14,      F15,     F16,    F17,   F18,   F19,  F20,     F21,   F22,    F23,  F24,
//      TOCLNM,    TAB,     LBRACKET, RBRACKET, LPRN,    RPRN,   NO,    NO,    HOME, END,     PGUP,  PGDOWN, NO,   NO,
//      TOCOLEMAK, CTLESC,  ENTER,    BSPACE,   DELETE,  BSPACE, NO,    LEFT,  DOWN, UP,      RIGHT, PGDOWN, NO,   ENTER,
//      TOCLMO,    LSFTBSL, LCBR,     RCBR,     LABK,    RABK,   NO,    NO,    LEFT, DOWN,    RIGHT, NO,     NO,   RSFTBSL,
//      TOCLAD,    LALT,    LGUI,     NO,       LTLCLFN, NO,     SPACE, SPACE, NO,   LTRCLFN, NO,    RGUI,   RALT, DELETE
//   ),
// 
// /* CLMouse
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |      |      |      |      |      |      |      |      | W_UP |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  | SPD_2| W_LT | W_UP | W_RT | SPD_2|      |      | LCLK | M_UP | RCLK |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct| SPD_1| RCLK | MCLK | LCLK | SPD_1|      |      |M_LEFT|M_DOWN|M_RGHT| xxxx |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(QW)|LSft \| SPD_0|MBTN_5| W_DN |MBTN_4| SPD_0|      |      |      | W_DN |      |      |      |RSft \|
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|  Alt | GUI  |      | xxxx |  EN  | Space|      |Space |  JP  | xxxx |      | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [CLMO] = KC_KEYMAP(
//      EQUAL,     GRAVE,   NO,        NO,         NO,         NO,          NO,        NO,    NO,      MS_WH_UP,   NO,       NO,      NO,   BSPACE,
//      TOCLNM,    TAB,     MS_ACCEL2, MS_WH_LEFT, MS_WH_UP,   MS_WH_RIGHT, MS_ACCEL2, NO,    MS_BTN1, MS_UP,      MS_BTN2,  NO,      NO,   NO,
//      TOCLFN,    CTLESC,  MS_ACCEL1, MS_BTN2,    MS_BTN3,    MS_BTN1,     MS_ACCEL1, NO,    MS_LEFT, MS_DOWN,    MS_RIGHT, LTMOUSE, NO,   ENTER,
//      TOCOLEMAK, LSFTBSL, MS_ACCEL0, MS_BTN5,    MS_WH_DOWN, MS_BTN4,     MS_ACCEL0, NO,    NO,      MS_WH_DOWN, NO,       NO,      NO,   RSFTBSL,
//      TOCLAD,    LALT,    LGUI,      NO,         MOMOUSE,    F23,         SPACE,     SPACE, F24,     MOMOUSE,    NO,       RGUI,    RALT, DELETE
//   ),
// 
// /* CLAdjust
//  * ,------------------------------------------------.      ,------------------------------------------------.
//  * |   =  |   `  |TO(QW)|      |      |      |      |      |      |      |      |      |      |      | Bksp |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(NM)| Tab  |      |      |      |      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(FN)|Esc/Ct|      |      |      |      |      |      |      |      |      |      |      |      |Enter |
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(MO)|LSft \|      |      |      |      |      |      |      |      |      |      |      |      |RSft \|
//  * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
//  * |TO(CL)|  Alt | GUI  | xxxx |      |  EN  | Space|      |Space |  JP  |      | xxxx | GUI  | Alt  | Del  |
//  * `------------------------------------------------'      `------------------------------------------------'
//  */
//   [CLAD] = KC_KEYMAP(
//     EQUAL,     GRAVE,  TOQWERTY, NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   BSPACE,
//     TOCLNM,    TAB,    NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   NO,
//     TOCLFN,    CTLESC, NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   ENTER,
//     TOCLMO,    LSFTBSL, NO,       NO, NO, NO,  NO,    NO,    NO,  NO, NO, NO,   NO,   RSFTBSL,
//     TOCOLEMAK, LALT,   LGUI,     MOCLAD, NO, F23, SPACE, SPACE, F24, NO, MOCLAD, RGUI, RALT, DELETE
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
