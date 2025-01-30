/* Copyright 2021 weteor
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// #include <stdint.h>
#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"
#include "action_layer.h"
#include "keycodes.h"
#include "modifiers.h"
#include "print.h"
#include "./keycodes_fabian.h"
#include "g/keymap_combo.h"




enum layers {
    _ALPHA = 0,
    _BETA,
    _NAV,
    _NUM,
    _SYM,
    _SYM2,
};

// #define L_NUM TT(_NUM)
#define L_BETA OSL(_BETA)
#define L_NAV OSL(_NAV)

#define S_(k) MT(MOD_LSFT, k)
#define A_(k) MT(MOD_LALT, k)
#define G_(k) MT(MOD_LGUI, k)
#define C_(k) MT(MOD_LCTL, k)

#define U_CTL MT(MOD_LCTL, KC_U)
#define O_GUI MT(MOD_LGUI, KC_O)
#define N_ALT MT(MOD_LALT, KC_N)
#define R_SFT MT(MOD_LSFT, KC_R)
#define A_SFT MT(MOD_LSFT, KC_A)
#define S_ALT MT(MOD_LALT, KC_S)
#define V_GUI MT(MOD_LGUI, KC_V)
#define L_CTL MT(MOD_LCTL, KC_L)

#define M_CTL MT(MOD_LCTL, KC_M)
#define Q_GUI MT(MOD_LGUI, KC_Q)
#define G_ALT MT(MOD_LALT, KC_G)
#define F_SFT MT(MOD_LSFT, KC_F)
#define AE_SFT MT(MOD_LSFT, CH_AE)
#define UE_ALT MT(MOD_LALT, CH_UE)
#define J_GUI MT(MOD_LGUI, KC_J)
#define Y_CTL MT(MOD_LCTL, CH_Y)

#define LAYOUT_mirror(k0,k1,k2,k3,k4, k5,k6,k7,k8,k9, k10,k11,k12,k13,k14, k15,k16,k17) LAYOUT_split_3x5_3(k4,k3,k2,k1,k0, k0,k1,k2,k3,k4, k9,k8,k7,k6,k5, k5,k6,k7,k8,k9, k14,k13,k12,k11,k10, k10,k11,k12,k13,k14, k17, k16, k15, k15, k16,k17)
// #define LAYOUT_mirror(k0,k1,k2,k3,k4, k5,k6,k7,k8,k9, k10,k11,k12,k13,k14, k15,k16,k17) LAYOUT_split_3x5_3(k4,k3,k2,k1,k0, k0,k1,k2,k3,k4, k9,k8,k7,k6,k5, k5,k6,k7,k8,k9, k14,k13,k12,k11,k10, k10,k11,k12,k13,k14, k17, k16, k15, k15, k16,k17)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//             ┌───────────────┬───────┬───┬───┬───┐
//             │       t       │   u   │ i │ o │ p │
//             ├───────────────┼───────┼───┼───┼───┤
//             │       n       │   r   │ e │ a │ s │
//             ├───────────────┼───────┼───┼───┼───┤
//             │       h       │   f   │ c │ l │ d │
//    ┌────────┼───────────────┼───────┼───┴───┴───┘
//    │ L_BETA │ OSM(MOD_LSFT) │ L_NAV │
//    └────────┴───────────────┴───────┘
[_ALPHA] = LAYOUT_mirror(
           KC_T          , KC_U  , KC_I , KC_O , KC_P,
           KC_N          , KC_R  , KC_E , KC_A , KC_S,
           KC_H          , KC_F  , KC_C , KC_L , KC_D,
  L_BETA , OSM(MOD_LSFT) , L_NAV
),

//          ┌─────────┬─────┬───┬───┬───────┐
//          │ CH_PLUS │  1  │ 2 │ 3 │ CH_UE │
//          ├─────────┼─────┼───┼───┼───────┤
//          │    0    │  4  │ 5 │ 6 │ CH_OE │
//          ├─────────┼─────┼───┼───┼───────┤
//          │ CH_ASTR │  7  │ 8 │ 9 │ CH_AE │
//    ┌─────┼─────────┼─────┼───┴───┴───────┘
//    │     │         │     │
//    └─────┴─────────┴─────┘
[_BETA] = LAYOUT_mirror(
            CH_PLUS , KC_1    , KC_2 , KC_3 , CH_UE,
            KC_0    , KC_4    , KC_5 , KC_6 , CH_OE,
            CH_ASTR , KC_7    , KC_8 , KC_9 , CH_AE,
  _______ , _______ , _______
),

//          ┌─────────┬─────────┬────────┬─────────┬─────────┐
//          │ CH_DQUT │ CH_EQL  │ CH_QST │ CH_EXLM │ CH_CIRC │
//          ├─────────┼─────────┼────────┼─────────┼─────────┤
//          │  left   │  down   │   up   │  rght   │  CH_AT  │
//          ├─────────┼─────────┼────────┼─────────┼─────────┤
//          │ CH_QUOT │ CH_PERC │ CH_DLR │ CH_BSLS │ CH_SLSH │
//    ┌─────┼─────────┼─────────┼────────┴─────────┴─────────┘
//    │     │         │         │
//    └─────┴─────────┴─────────┘
[_NAV] = LAYOUT_mirror(
            CH_DQUT , CH_EQL  , CH_QST , CH_EXLM  , CH_CIRC,
            KC_LEFT , KC_DOWN , KC_UP  , KC_RIGHT , CH_AT  ,
            CH_QUOT , CH_PERC , CH_DLR , CH_BSLS  , CH_SLSH,
  _______ , _______ , _______
),

//          ┌─────────┬─────┬───┬───┬─────────┐
//          │ CH_MINS │  7  │ 8 │ 9 │ CH_ASTR │
//          ├─────────┼─────┼───┼───┼─────────┤
//          │ CH_DOT  │  4  │ 5 │ 6 │    0    │
//          ├─────────┼─────┼───┼───┼─────────┤
//          │ CH_COMM │  1  │ 2 │ 3 │ CH_PLUS │
//    ┌─────┼─────────┼─────┼───┴───┴─────────┘
//    │     │         │     │
//    └─────┴─────────┴─────┘
[_NUM] = LAYOUT_mirror(
            CH_MINS , KC_7    , KC_8 , KC_9 , CH_ASTR,
            CH_DOT  , KC_4    , KC_5 , KC_6 , KC_0   ,
            CH_COMM , KC_1    , KC_2 , KC_3 , CH_PLUS,
  _______ , _______ , _______
),

//          ┌─────────┬─────────┬─────────┬─────────┬─────────┐
//          │ CH_DEG  │ CH_DQUT │ CH_QUOT │ CH_GRV  │ CH_ACUT │
//          ├─────────┼─────────┼─────────┼─────────┼─────────┤
//          │ CH_HASH │ CH_PERC │ CH_QUES │ CH_EXLM │ CH_DLR  │
//          ├─────────┼─────────┼─────────┼─────────┼─────────┤
//          │ CH_TILD │ CH_EQL  │         │ CH_AMPR │ CH_PIPE │
//    ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┘
//    │     │         │         │
//    └─────┴─────────┴─────────┘
[_SYM] = LAYOUT_mirror(
            CH_DEG  , CH_DQUT , CH_QUOT , CH_GRV  , CH_ACUT,
            CH_HASH , CH_PERC , CH_QUES , CH_EXLM , CH_DLR ,
            CH_TILD , CH_EQL  , _______ , CH_AMPR , CH_PIPE,
  _______ , _______ , _______
),

//          ┌─────────┬─────┬────┬────┬───────┐
//          │ CH_SLSH │ f7  │ f8 │ f9 │ CH_AT │
//          ├─────────┼─────┼────┼────┼───────┤
//          │         │ f4  │ f5 │ f6 │  f10  │
//          ├─────────┼─────┼────┼────┼───────┤
//          │ CH_CIRC │ f1  │ f2 │ f3 │       │
//    ┌─────┼─────────┼─────┼────┴────┴───────┘
//    │     │         │     │
//    └─────┴─────────┴─────┘
[_SYM2] = LAYOUT_mirror(
            CH_SLSH , KC_F7   , KC_F8 , KC_F9 , CH_AT  ,
            _______ , KC_F4   , KC_F5 , KC_F6 , KC_F10 ,
            CH_CIRC , KC_F1   , KC_F2 , KC_F3 , _______,
  _______ , _______ , _______
)
};

// const uint16_t PROGMEM cBspcAlpha[] = { O_GUI, KC_P, COMBO_END};
// const uint16_t PROGMEM cBspcBeta[] = { KC_X, Q_GUI, COMBO_END};
// const uint16_t PROGMEM cBspcNav[] = { CH_LBRC, CH_SLSH, COMBO_END};
// const uint16_t PROGMEM cBspcNum[] = { CH_BSLS, CH_AT, COMBO_END};
// const uint16_t PROGMEM cBspcSym[] = { KC_9, CH_PLUS, COMBO_END};
// const uint16_t PROGMEM cBspcSym2[] = { KC_9, CH_PLUS, COMBO_END};
// const uint16_t PROGMEM cEscAlpha[] = { U_CTL,  KC_T, COMBO_END};
// const uint16_t PROGMEM cEscBeta[] = { CH_Z,  KC_T, COMBO_END};
// const uint16_t PROGMEM cEscNav[] = { U_CTL,  KC_T, COMBO_END};
// const uint16_t PROGMEM cEscNum[] = { U_CTL,  KC_T, COMBO_END};
// const uint16_t PROGMEM cEscSym[] = { U_CTL,  KC_T, COMBO_END};
// const uint16_t PROGMEM cEscSym2[] = { U_CTL,  KC_T, COMBO_END};
// const uint16_t PROGMEM combo6[] = { F_SFT, CH_OE, COMBO_END};
// const uint16_t PROGMEM combo7[] = { CH_LBRC, CH_LPRN, COMBO_END};
// const uint16_t PROGMEM combo8[] = { R_SFT, KC_E, COMBO_END};
// const uint16_t PROGMEM combo9[] = { A_SFT, S_ALT, COMBO_END};
// // const uint16_t PROGMEM combo10[] = { L_BETA, L_NAV, COMBO_END};
// // const uint16_t PROGMEM combo11[] = { L_NUM, L_BETA, COMBO_END};

// combo_t key_combos_del[] = {
//     COMBO(cBspcAlpha, KC_BSPC),
//     COMBO(cBspcBeta, KC_BSPC),
//     COMBO(cBspcNav, KC_BSPC),
//     COMBO(cBspcNum, KC_BSPC),
//     COMBO(cBspcSym, KC_BSPC),
//     COMBO(cBspcSym2, KC_BSPC),
//     COMBO(cEscAlpha, KC_ESCAPE),
//     COMBO(cEscBeta, KC_ESCAPE),
//     COMBO(cEscNav, KC_ESCAPE),
//     COMBO(cEscNum, KC_ESCAPE),
//     COMBO(cEscSym, KC_ESCAPE),
//     COMBO(cEscSym2, KC_ESCAPE),
//     COMBO(combo6, KC_SPACE),
//     COMBO(combo7, KC_SPACE),
//     COMBO(combo8, KC_SPACE),
//     // COMBO(combo9, ST_MACRO_AE),
//     COMBO(combo9, KC_ENTER),
//     // COMBO(combo10, OSM(_SYM)),
//     // COMBO(combo11, OSM(_SYM2)),
// };

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state;
        mod_state = get_mods();
        uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  switch (keycode) {
                case LCTL_T(CH_DQUT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(CH_DQUT); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    case ST_MACRO_TH:
    if (record->event.pressed) {
      SEND_STRING("th");
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H));
    }
    break;
    case ST_MACRO_AE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_CAPS));
    }
    break;
    case CH_AE:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool ae_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_CAPS));
                // register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                ae_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (ae_registered) {
                unregister_code(KC_DEL);
                ae_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
  }
  return true;
}


//layer_state_t layer_state_set_user(layer_state_t state) {
//    // if(layer_state_is(_BETA) && layer_state_is(_NAV)) {
//    //     state = state | ((layer_state_t)1 << _SYM);
//    // }
//    //
//    layer_state_t newstate = update_tri_layer_state(state,_BETA, _NAV, _SYM);
//    newstate = update_tri_layer_state(newstate,_BETA, _NUM, _SYM2);
//    printf("before 0x%01X, after 0x%01X\n", state, newstate);
//    return newstate;
//}

const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t ae_override = ko_make_basic(MOD_MASK_SHIFT, AE_SFT, ST_MACRO_AE);
// const key_override_t ae_override = ko_make_basic(MOD_MASK_SHIFT, AE_SFT, KC_Z);
// const key_override_t ue_override = ko_make_basic(MOD_MASK_SHIFT, UE_ALT, KC_X);
// const key_override_t oe_override = ko_make_basic(MOD_MASK_SHIFT, CH_OE, KC_Y);
// const key_override_t perc_override = ko_make_basic(MOD_MASK_SHIFT,CH_PERC, CH_CIRC);
// const key_override_t s2_override = ko_make_basic(MOD_MASK_SHIFT,CH_PERC, CH_CIRC);
const key_override_t f1override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_F1);
const key_override_t f2override = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_F2);
const key_override_t f3override = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_F3);
const key_override_t f4override = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_F4);
const key_override_t f5override = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_F5);
const key_override_t f6override = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_F6);
const key_override_t f7override = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_F7);
const key_override_t f8override = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_F8);
const key_override_t f9override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_F9);
const key_override_t f10override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F10);
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_override,
    // &ae_override,
    // &ue_override,
    // &oe_override,
    // &perc_override,
    &f1override,
    &f2override,
    &f3override,
    &f4override,
    &f5override,
    &f6override,
    &f7override,
    &f8override,
    &f9override,
    &f10override,
    NULL // Null terminate the array of overrides!
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case CH_UNDS:
        case CH_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
