#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[0] = KEYMAP(  // layer 0 : default
        // left hand
               KC_GRAVE        ,KC_1       ,KC_2           ,KC_3     ,KC_4      ,KC_5      ,KC_TRANSPARENT ,
               KC_TAB          ,KC_Q       ,KC_W           ,KC_F     ,KC_P      ,KC_G      ,KC_EQUAL       ,
               KC_ESCAPE       ,KC_A       ,KC_R           ,KC_S     ,KC_T      ,KC_D      ,
               KC_LSHIFT       ,KC_Z       ,KC_X           ,KC_C     ,KC_V      ,KC_B      ,KC_TRANSPARENT ,
               KC_PGUP         ,KC_PSCREEN ,TG(1)          ,KC_LEFT  ,KC_RIGHT  ,
               KC_LGUI         ,KC_HOME    ,
               KC_END          ,
               CTL_T(KC_SPACE) ,KC_ENTER   ,KC_TRANSPARENT ,
               // right
               KC_TRANSPARENT  ,KC_6       ,KC_7           ,KC_8     ,KC_9      ,KC_0      ,KC_MINUS       ,
               KC_LBRACKET     ,KC_J       ,KC_L           ,KC_U     ,KC_Y      ,KC_SCOLON ,KC_BSLASH      ,
               KC_H            ,KC_N       ,KC_E           ,KC_I     ,KC_O      ,KC_QUOTE  ,
               KC_RBRACKET     ,KC_K       ,KC_M           ,KC_COMMA ,KC_DOT    ,KC_SLASH  ,KC_LSHIFT      ,
               KC_DOWN         ,KC_UP      ,KC_TRANSPARENT ,TG(2)    ,KC_PGDOWN ,
               KC_INSERT       ,KC_LCTL    ,
               KC_DELETE       ,
               KC_TRANSPARENT  ,KC_BSPACE  ,ALT_T(KC_SPACE)
    ),

// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000

// TxBolt over Serial
  [1] = KEYMAP(
               KC_TRNS            , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
               KC_TRNS            , KC_TRNS , M(NM) , M(NM) , M(NM) , M(NM) , M(X) ,
               KC_TRNS            , KC_TRNS , M(Sl)  , M(Tl)  , M(Pl)  , M(Hl)  ,
               KC_TRNS            , KC_TRNS , M(Sl)  , M(Kl)  , M(Wl)  , M(Rl)  , M(X) ,
               KC_TRNS            , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
               KC_TRNS            , KC_TRNS ,
               KC_TRNS            ,
               M(Al)             , M(Ol)  , KC_TRNS ,

               KC_TRNS            , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
               M(X)            , M(NM) , M(NM) , M(NM) , M(NM) , M(NM) , KC_TRNS ,
               M(Fr) , M(Pr)  , M(Lr)  , M(Tr)  , M(Dr)  , KC_TRNS ,
               M(X)            , M(Rr)  , M(Br)  , M(Gr)  , M(Sr)  , M(Zr)  , KC_TRNS ,
               KC_TRNS            , KC_TRNS ,KC_TRNS  , KC_TRNS , KC_TRNS ,
               KC_TRNS            , KC_TRNS ,
               KC_TRNS            ,
               KC_TRNS            , M(Er)  , M(Ur)
               ),
  [2] = KEYMAP(
               KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_E           ,KC_R           ,KC_T           ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,KC_S     ,KC_D           ,KC_F           ,KC_G           ,
               KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,TO(0)          ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,
               KC_TRNS ,
               KC_TRNS ,KC_TRNS ,KC_TRNS ,

               KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_Y           ,KC_U           ,KC_I           ,KC_O           ,KC_P           ,KC_TRNS ,
               KC_TRNS ,KC_J           ,KC_K           ,KC_L           ,KC_SCOLON      ,KC_TRNS ,
               KC_TRNS ,KC_N           ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
               KC_TRNS ,KC_TRNS ,
               KC_TRNS ,
               KC_TRNS ,KC_TRNS ,KC_TRNS
               ),



/*
[1] = KEYMAP(
       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   M(NM),   M(NM),   M(NM),   M(NM),   M(NM),  KC_NO,
       KC_NO,   M(Sl),   M(Tl),   M(Pl),   M(Hl),   M(X),
       KC_NO,   M(Sl),   M(Kl),   M(Wl),   M(Rl),   M(X),   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  M(Al),   M(Ol),   KC_NO,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,  M(NM),   M(NM),   M(NM),   M(NM),   M(NM),   M(NM),
                 M(X),    M(Fr),   M(Pr),   M(Lr),   M(Tr),   M(Dr),
       KC_NO,    M(X),    M(Rr),   M(Br),   M(Gr),   M(Sr),   M(Zr),
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   M(Er),   M(Ur)
),
*/
};

uint8_t chord[4] = {0,0,0,0};
uint8_t pressed_count = 0;

void send_chord(void)
{
  for(uint8_t i = 0; i < 4; i++)
  {
    if(chord[i])
      virtser_send(chord[i]);
  }
  virtser_send(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // We need to track keypresses in all modes, in case the user
  // changes mode whilst pressing other keys.
  if (record->event.pressed)
    pressed_count++;
  else
    pressed_count--;
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function

  if (record->event.pressed) {
    uint8_t grp = (id & GRPMASK) >> 6;
    chord[grp] |= id;
  }
  else {
    if (pressed_count == 0) {
      send_chord();
      chord[0] = chord[1] = chord[2] = chord[3] = 0;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
