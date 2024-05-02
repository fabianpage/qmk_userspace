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

#include "action_layer.h"
#include "keycodes.h"
#include "modifiers.h"
#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"
#include "print.h"

#define CH_Z KC_Y
#define CH_DLR KC_NUHS // $
#define CH_AE CH_ADIA
#define CH_OE CH_ODIA
#define CH_UE CH_UDIA
#define CH_Y KC_Z
#define CH_QST S(KC_MINS)
// #define CH_EXLM S(KC_RBRC)
// #define CH_PERC S(KC_5)
// #define CH_AT ALGR(KC_2)
// #define CH_BSLS ALGR(KC_NUBS)
// #define CH_SLSH S(KC_7)
#define CH_PAST S(KC_3)
// #define CH_LCBR ALGR(KC_QUOT)
// #define CH_LBRC ALGR(KC_LBRC)
// #define CH_LPRN S(KC_8)
#define CH_LESS KC_NUBS
// #define CH_RCBR ALGR(KC_NUHS)
// #define CH_RBRC ALGR(KC_RBRC)
// #define CH_RPRN S(KC_9)
#define CH_MORE S(KC_NUBS)
// #define CH_PLUS S(KC_1)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_AE,
};


enum layers {
    _ALPHA = 0,
    _BETA,
    _NAV,
    _NUM,
    _SYM,
    _SYM2,
};

#define L_NUM TT(_NUM)
#define L_BETA OSL(_BETA)
#define L_NAV TT(_NAV)

#define S_(k) MT(MOD_LSFT, k)


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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//            ┌────────┬───────┬───┬───────┬───────┐
//            │   t    │ U_CTL │ i │ O_GUI │   p   │
//            ├────────┼───────┼───┼───────┼───────┤
//            │ N_ALT  │ R_SFT │ e │ A_SFT │ S_ALT │
//            ├────────┼───────┼───┼───────┼───────┤
//            │   h    │ V_GUI │ c │ L_CTL │   d   │
//    ┌───────┼────────┼───────┼───┴───────┴───────┘
//    │ L_NUM │ L_BETA │ L_NAV │
//    └───────┴────────┴───────┘
[_ALPHA] = LAYOUT_mirror(
          KC_T   , U_CTL , KC_I , O_GUI , KC_P ,
          N_ALT  , R_SFT , KC_E , A_SFT , S_ALT,
          KC_H   , V_GUI , KC_C , L_CTL , KC_D ,
  L_NUM , L_BETA , L_NAV
),

//          ┌───────┬───────┬───────┬────────┬────────┐
//          │ CH_Z  │ M_CTL │   w   │ Q_GUI  │   x    │
//          ├───────┼───────┼───────┼────────┼────────┤
//          │ G_ALT │ F_SFT │ CH_OE │ AE_SFT │ UE_ALT │
//          ├───────┼───────┼───────┼────────┼────────┤
//          │   b   │ J_GUI │   k   │ Y_CTL  │        │
//    ┌─────┼───────┼───────┼───────┴────────┴────────┘
//    │     │       │       │
//    └─────┴───────┴───────┘
[_BETA] = LAYOUT_mirror(
            CH_Z    , M_CTL   , KC_W  , Q_GUI  , KC_X   ,
            G_ALT   , F_SFT   , CH_OE , AE_SFT , UE_ALT ,
            KC_B    , J_GUI   , KC_K  , Y_CTL  , _______,
  _______ , _______ , _______
),

//                    ┌───────────────┬───────────────┬─────────┬─────────┬────────────┐
//                    │    CH_LESS    │    CH_LPRN    │ CH_LCBR │ CH_LBRC │  CH_SLSH   │
//                    ├───────────────┼───────────────┼─────────┼─────────┼────────────┤
//                    │     left      │     down      │   up    │  rght   │  CH_BSLS   │
//                    ├───────────────┼───────────────┼─────────┼─────────┼────────────┤
//                    │    CH_MORE    │    CH_RPRN    │ CH_RCBR │ CH_RBRC │ TO(_ALPHA) │
//    ┌───────────────┼───────────────┼───────────────┼─────────┴─────────┴────────────┘
//    │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │
//    └───────────────┴───────────────┴───────────────┘
[_NAV] = LAYOUT_mirror(
                  CH_LESS       , CH_LPRN       , CH_LCBR , CH_LBRC  , CH_SLSH   ,
                  KC_LEFT       , KC_DOWN       , KC_UP   , KC_RIGHT , CH_BSLS   ,
                  CH_MORE       , CH_RPRN       , CH_RCBR , CH_RBRC  , TO(_ALPHA),
  OSM(MOD_LCTL) , OSM(MOD_LSFT) , OSM(MOD_LGUI)
),

//          ┌─────────┬─────┬───┬───┬────────────┐
//          │ CH_MINS │  7  │ 8 │ 9 │  CH_PLUS   │
//          ├─────────┼─────┼───┼───┼────────────┤
//          │ CH_DOT  │  4  │ 5 │ 6 │     0      │
//          ├─────────┼─────┼───┼───┼────────────┤
//          │ CH_COMM │  1  │ 2 │ 3 │ TO(_ALPHA) │
//    ┌─────┼─────────┼─────┼───┴───┴────────────┘
//    │     │         │     │
//    └─────┴─────────┴─────┘
[_NUM] = LAYOUT_mirror(
            CH_MINS , KC_7    , KC_8 , KC_9 , CH_PLUS   ,
            CH_DOT  , KC_4    , KC_5 , KC_6 , KC_0      ,
            CH_COMM , KC_1    , KC_2 , KC_3 , TO(_ALPHA),
  _______ , _______ , _______
),

//          ┌─────────┬─────────────────────┬─────────┬─────────┬────────────┐
//          │ CH_SLSH │       CH_DOT        │ CH_COMM │ CH_BSLS │   CH_AT    │
//          ├─────────┼─────────────────────┼─────────┼─────────┼────────────┤
//          │ CH_HASH │ QK_CAPS_WORD_TOGGLE │ CH_DQUO │ CH_DEG  │   CH_DLR   │
//          ├─────────┼─────────────────────┼─────────┼─────────┼────────────┤
//          │ CH_QUOT │       CH_CIRC       │         │         │ TO(_ALPHA) │
//    ┌─────┼─────────┼─────────────────────┼─────────┴─────────┴────────────┘
//    │     │         │                     │
//    └─────┴─────────┴─────────────────────┘
[_SYM] = LAYOUT_mirror(
            CH_SLSH , CH_DOT              , CH_COMM , CH_BSLS , CH_AT     ,
            CH_HASH , QK_CAPS_WORD_TOGGLE , CH_DQUO , CH_DEG  , CH_DLR    ,
            CH_QUOT , CH_CIRC             , _______ , _______ , TO(_ALPHA),
  _______ , _______ , _______
),

//          ┌─────────┬─────┬────┬────┬────────────┐
//          │ CH_SLSH │ f7  │ f8 │ f9 │   CH_AT    │
//          ├─────────┼─────┼────┼────┼────────────┤
//          │         │ f4  │ f5 │ f6 │    f10     │
//          ├─────────┼─────┼────┼────┼────────────┤
//          │ QK_BOOT │ f1  │ f2 │ f3 │ TO(_ALPHA) │
//    ┌─────┼─────────┼─────┼────┴────┴────────────┘
//    │     │         │     │
//    └─────┴─────────┴─────┘
[_SYM2] = LAYOUT_mirror(
            CH_SLSH , KC_F7   , KC_F8 , KC_F9 , CH_AT     ,
            _______ , KC_F4   , KC_F5 , KC_F6 , KC_F10    ,
            QK_BOOT , KC_F1   , KC_F2 , KC_F3 , TO(_ALPHA),
  _______ , _______ , _______
)
};

const uint16_t PROGMEM cBspcAlpha[] = { O_GUI, KC_P, COMBO_END};
const uint16_t PROGMEM cBspcBeta[] = { KC_X, Q_GUI, COMBO_END};
const uint16_t PROGMEM cBspcNav[] = { CH_LBRC, CH_SLSH, COMBO_END};
const uint16_t PROGMEM cBspcNum[] = { CH_BSLS, CH_AT, COMBO_END};
const uint16_t PROGMEM cBspcSym[] = { KC_9, CH_PLUS, COMBO_END};
const uint16_t PROGMEM cBspcSym2[] = { KC_9, CH_PLUS, COMBO_END};
const uint16_t PROGMEM cEscAlpha[] = { U_CTL,  KC_T, COMBO_END};
const uint16_t PROGMEM cEscBeta[] = { CH_Z,  KC_T, COMBO_END};
const uint16_t PROGMEM cEscNav[] = { U_CTL,  KC_T, COMBO_END};
const uint16_t PROGMEM cEscNum[] = { U_CTL,  KC_T, COMBO_END};
const uint16_t PROGMEM cEscSym[] = { U_CTL,  KC_T, COMBO_END};
const uint16_t PROGMEM cEscSym2[] = { U_CTL,  KC_T, COMBO_END};
const uint16_t PROGMEM combo6[] = { F_SFT, CH_OE, COMBO_END};
const uint16_t PROGMEM combo7[] = { CH_LBRC, CH_LPRN, COMBO_END};
const uint16_t PROGMEM combo8[] = { R_SFT, KC_E, COMBO_END};
const uint16_t PROGMEM combo9[] = { A_SFT, S_ALT, COMBO_END};
// const uint16_t PROGMEM combo10[] = { L_BETA, L_NAV, COMBO_END};
// const uint16_t PROGMEM combo11[] = { L_NUM, L_BETA, COMBO_END};

combo_t key_combos[] = {
    COMBO(cBspcAlpha, KC_BSPC),
    COMBO(cBspcBeta, KC_BSPC),
    COMBO(cBspcNav, KC_BSPC),
    COMBO(cBspcNum, KC_BSPC),
    COMBO(cBspcSym, KC_BSPC),
    COMBO(cBspcSym2, KC_BSPC),
    COMBO(cEscAlpha, KC_ESCAPE),
    COMBO(cEscBeta, KC_ESCAPE),
    COMBO(cEscNav, KC_ESCAPE),
    COMBO(cEscNum, KC_ESCAPE),
    COMBO(cEscSym, KC_ESCAPE),
    COMBO(cEscSym2, KC_ESCAPE),
    COMBO(combo6, KC_SPACE),
    COMBO(combo7, KC_SPACE),
    COMBO(combo8, KC_SPACE),
    // COMBO(combo9, ST_MACRO_AE),
    COMBO(combo9, KC_ENTER),
    // COMBO(combo10, OSM(_SYM)),
    // COMBO(combo11, OSM(_SYM2)),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H));
    }
    case ST_MACRO_AE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_CAPS));
    }
    break;
  }
  return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // if(layer_state_is(_BETA) && layer_state_is(_NAV)) {
    //     state = state | ((layer_state_t)1 << _SYM);
    // }
    //
    layer_state_t newstate = update_tri_layer_state(state,_BETA, _NAV, _SYM);
    newstate = update_tri_layer_state(newstate,_BETA, _NUM, _SYM2);
    printf("before 0x%01X, after 0x%01X\n", state, newstate);
    return newstate;
}

const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t ae_override = ko_make_basic(MOD_MASK_SHIFT, AE_SFT, ST_MACRO_AE);
// const key_override_t ae_override = ko_make_basic(MOD_MASK_SHIFT, AE_SFT, KC_Z);
const key_override_t ue_override = ko_make_basic(MOD_MASK_SHIFT, UE_ALT, KC_X);
const key_override_t oe_override = ko_make_basic(MOD_MASK_SHIFT, CH_OE, KC_Y);
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_override,
    &ae_override,
    &ue_override,
    &oe_override,
    NULL // Null terminate the array of overrides!
};
