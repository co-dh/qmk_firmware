#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_steno.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[0] = LAYOUT_ergodox(  // layer 0 : colemak
        // left hand
               KC_GRAVE        ,KC_1       ,KC_2           ,KC_3     ,KC_4      ,KC_5      ,KC_TRANSPARENT ,
               KC_TAB          ,KC_Q       ,KC_W           ,KC_F     ,KC_P      ,KC_V      ,KC_EQUAL       ,
               KC_ESCAPE       ,KC_A       ,KC_R           ,KC_S     ,KC_T      ,KC_G      ,
               KC_LSHIFT       ,KC_Z       ,KC_X           ,KC_C     ,KC_D      ,KC_B      ,KC_TRANSPARENT ,
               KC_PGUP         ,KC_PSCREEN ,TG(1)          ,KC_LEFT  ,KC_RIGHT  ,
               KC_LGUI         ,KC_HOME    ,
               KC_END          ,
               CTL_T(KC_SPACE) ,KC_ENTER   ,MO(2) ,
               // right
               KC_TRANSPARENT  ,KC_6       ,KC_7           ,KC_8     ,KC_9      ,KC_0      ,KC_MINUS       ,
               KC_LBRACKET     ,KC_J       ,KC_L           ,KC_U     ,KC_Y      ,KC_SCOLON ,KC_BSLASH      ,
               KC_M            ,KC_N       ,KC_E           ,KC_I     ,KC_O      ,KC_QUOTE  ,
               KC_RBRACKET     ,KC_K       ,KC_H           ,KC_COMMA ,KC_DOT    ,KC_SLASH  ,KC_LSHIFT      ,
               KC_DOWN         ,KC_UP      ,KC_TRANSPARENT ,TG(2)    ,KC_PGDOWN ,
               KC_INSERT       ,TG(1),
               KC_DELETE       ,
               MO(2)  ,KC_BSPACE  ,ALT_T(KC_SPACE)

    ),


/* Keymap 3: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */


//77675213
// TxBolt over Serial
[1] = LAYOUT_ergodox(
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  
                KC_NO,  KC_NO,    STN_S1,  STN_TL,  STN_PL,  STN_HL,  
       KC_NO,   KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, 
       KC_NO,   KC_NO,   TG(1),   KC_NO,   KC_NO,
                                           KC_TRNS, KC_NO,
                                                    KC_NO,
                                  STN_A,   STN_O,   KC_NO,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
                 STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  KC_NO,
       STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,   KC_NO,    
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   STN_E,   STN_U
),

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_GEMINI
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
