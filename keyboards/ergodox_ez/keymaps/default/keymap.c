#include "ergodox_ez.h"
#include "keymap_steno.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP(
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
  // 7 7 6 7 5 2 1 3
  [1] = KEYMAP(
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_E           ,KC_R           ,KC_T           ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_S           ,KC_D           ,KC_F           ,KC_G           ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,TO(0)          ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,

               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_Y           ,KC_U           ,KC_I           ,KC_O           ,KC_P           ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_J           ,KC_K           ,KC_L           ,KC_SCOLON      ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_N           ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,
               KC_TRANSPARENT ,
               KC_TRANSPARENT ,KC_TRANSPARENT ,KC_TRANSPARENT
               ),

/* Keymap 2: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      | TG   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   #  |   #  |   #  |   #  | *    |           |  *   |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |  H   |------|           |------|   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  | *    |           |  *   |   R  |   B  |   G  |   S  |   Z  |        |
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

  [2] = KEYMAP(
               KC_BSPC , KC_NO     ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_TRNS ,
               KC_NO   ,   KC_NO   ,   STN_NUM ,   STN_NUM ,   STN_NUM ,   STN_NUM ,   STN_ST1 ,
               KC_NO   ,   KC_NO   ,   STN_S1  ,   STN_TL  ,  STN_PL   ,   STN_HL  ,
               KC_NO   ,   KC_NO   ,   STN_S2  ,   STN_KL  ,   STN_WL  ,   STN_RL  ,   STN_ST2 ,
               KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
               KC_NO   ,   KC_NO   ,
               KC_NO   ,
               STN_A  ,   STN_O  ,   KC_NO   ,
               // right hand
               KC_NO   ,    KC_NO  ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_NO   ,
               STN_ST1 ,   STN_NUM ,   STN_NUM ,   STN_NUM ,   STN_NUM ,   STN_NUM ,    KC_NO  ,
                           STN_FR  ,   STN_PR  ,   STN_LR  ,   STN_TR  ,   STN_DR  ,   KC_NO   ,
               STN_ST2 ,   STN_RR ,   STN_BR  ,   STN_GR  ,   STN_SR  ,   STN_ZR  ,    KC_NO  ,
               KC_NO   ,   KC_NO   ,   KC_NO   ,   KC_TRNS ,   KC_NO   ,
               KC_NO   ,   KC_NO   ,
               KC_NO   ,
               KC_NO   ,   STN_E  ,   STN_U
               ),

};

void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_BOLT
};

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;
};
