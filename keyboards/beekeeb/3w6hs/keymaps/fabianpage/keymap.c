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
#define L_BETA TT(_BETA)
#define L_NAV TT(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌─────────────────┬─────────────────┬───┬─────────────────┬─────────────────┐                    ┌─────────────────┬─────────────────┬───┬─────────────────┬─────────────────┐
//        │        p        │ MT(MOD_LGUI, o) │ i │ MT(MOD_LCTL, u) │        t        │                    │        t        │ MT(MOD_LCTL, u) │ i │ MT(MOD_LGUI, o) │        p        │
//        ├─────────────────┼─────────────────┼───┼─────────────────┼─────────────────┤                    ├─────────────────┼─────────────────┼───┼─────────────────┼─────────────────┤
//        │ MT(MOD_LALT, s) │ MT(MOD_LSFT, a) │ e │ MT(MOD_LSFT, r) │ MT(MOD_LALT, n) │                    │ MT(MOD_LALT, n) │ MT(MOD_LSFT, r) │ e │ MT(MOD_LSFT, a) │ MT(MOD_LALT, s) │
//        ├─────────────────┼─────────────────┼───┼─────────────────┼─────────────────┤                    ├─────────────────┼─────────────────┼───┼─────────────────┼─────────────────┤
//        │        d        │ MT(MOD_LCTL, l) │ c │ MT(MOD_LGUI, v) │        h        │                    │        h        │ MT(MOD_LGUI, v) │ c │ MT(MOD_LCTL, l) │        d        │
//        └─────────────────┴─────────────────┴───┼─────────────────┼─────────────────┼────────────┬───────┼─────────────────┼─────────────────┼───┴─────────────────┴─────────────────┘
//                                                │ LT(_ALPHA, spc) │  LT(_NAV, ent)  │ LT(3, tab) │ L_NUM │     L_BETA      │      L_NAV      │
//                                                └─────────────────┴─────────────────┴────────────┴───────┴─────────────────┴─────────────────┘
[_ALPHA] = LAYOUT_split_3x5_3(
      KC_P               , MT(MOD_LGUI, KC_O) , KC_I , MT(MOD_LCTL, KC_U)   , KC_T               ,                         KC_T               , MT(MOD_LCTL, KC_U) , KC_I , MT(MOD_LGUI, KC_O) , KC_P              ,
      MT(MOD_LALT, KC_S) , MT(MOD_LSFT, KC_A) , KC_E , MT(MOD_LSFT, KC_R)   , MT(MOD_LALT, KC_N) ,                         MT(MOD_LALT, KC_N) , MT(MOD_LSFT, KC_R) , KC_E , MT(MOD_LSFT, KC_A) , MT(MOD_LALT, KC_S),
      KC_D               , MT(MOD_LCTL, KC_L) , KC_C , MT(MOD_LGUI, KC_V)   , KC_H               ,                         KC_H               , MT(MOD_LGUI, KC_V) , KC_C , MT(MOD_LCTL, KC_L) , KC_D              ,
                                                       LT(_ALPHA, KC_SPACE) , LT(_NAV, KC_ENTER) , LT(3, KC_TAB) , L_NUM , L_BETA             , L_NAV
),

//        ┌──────────────────────┬─────────────────────┬───────┬─────────────────┬─────────────────┐           ┌─────────────────┬─────────────────┬───────┬─────────────────────┬─────────────────────┐
//        │          x           │   MT(MOD_LGUI, q)   │   w   │ MT(MOD_LCTL, m) │      CH_Z       │           │      CH_Z       │ MT(MOD_LCTL, m) │   w   │   MT(MOD_LGUI, q)   │          x          │
//        ├──────────────────────┼─────────────────────┼───────┼─────────────────┼─────────────────┤           ├─────────────────┼─────────────────┼───────┼─────────────────────┼─────────────────────┤
//        │ MT(MOD_LALT, CH_DLR) │ MT(MOD_LSFT, CH_AE) │ CH_OE │ MT(MOD_LSFT, f) │ MT(MOD_LALT, g) │           │ MT(MOD_LALT, g) │ MT(MOD_LSFT, f) │ CH_OE │ MT(MOD_LSFT, CH_AE) │ MT(MOD_LALT, CH_UE) │
//        ├──────────────────────┼─────────────────────┼───────┼─────────────────┼─────────────────┤           ├─────────────────┼─────────────────┼───────┼─────────────────────┼─────────────────────┤
//        │        CH_UE         │ MT(MOD_LCTL, CH_Y)  │   k   │ MT(MOD_LGUI, j) │        b        │           │        b        │ MT(MOD_LGUI, j) │   k   │ MT(MOD_LCTL, CH_Y)  │     TO(_ALPHA)      │
//        └──────────────────────┴─────────────────────┴───────┼─────────────────┼─────────────────┼─────┬─────┼─────────────────┼─────────────────┼───────┴─────────────────────┴─────────────────────┘
//                                                             │                 │                 │     │     │                 │                 │
//                                                             └─────────────────┴─────────────────┴─────┴─────┴─────────────────┴─────────────────┘
[_BETA] = LAYOUT_split_3x5_3(
      KC_X                 , MT(MOD_LGUI, KC_Q)  , KC_W  , MT(MOD_LCTL, KC_M) , CH_Z               ,                     CH_Z               , MT(MOD_LCTL, KC_M) , KC_W  , MT(MOD_LGUI, KC_Q)  , KC_X               ,
      MT(MOD_LALT, CH_DLR) , MT(MOD_LSFT, CH_AE) , CH_OE , MT(MOD_LSFT, KC_F) , MT(MOD_LALT, KC_G) ,                     MT(MOD_LALT, KC_G) , MT(MOD_LSFT, KC_F) , CH_OE , MT(MOD_LSFT, CH_AE) , MT(MOD_LALT, CH_UE),
      CH_UE                , MT(MOD_LCTL, CH_Y)  , KC_K  , MT(MOD_LGUI, KC_J) , KC_B               ,                     KC_B               , MT(MOD_LGUI, KC_J) , KC_K  , MT(MOD_LCTL, CH_Y)  , TO(_ALPHA)         ,
                                                           _______            , _______            , _______ , _______ , _______            , _______
),

//        ┌─────────┬───────────────┬───────────────┬───────────────┬─────────┐                     ┌───────────────┬───────────────┬─────────┬─────────┬────────────┐
//        │ CH_QST  │     home      │    pAGE_UP    │     pgdn      │   end   │                     │    CH_LESS    │    CH_LPRN    │ CH_LCBR │ CH_LBRC │            │
//        ├─────────┼───────────────┼───────────────┼───────────────┼─────────┤                     ├───────────────┼───────────────┼─────────┼─────────┼────────────┤
//        │ CH_EXLM │     left      │      up       │     down      │  rght   │                     │     left      │     down      │   up    │  rght   │            │
//        ├─────────┼───────────────┼───────────────┼───────────────┼─────────┤                     ├───────────────┼───────────────┼─────────┼─────────┼────────────┤
//        │         │ OSM(MOD_LGUI) │ OSM(MOD_LALT) │ OSM(MOD_LCTL) │ CH_PERC │                     │    CH_MORE    │    CH_RPRN    │ CH_RCBR │ CH_RBRC │ TO(_ALPHA) │
//        └─────────┴───────────────┴───────────────┼───────────────┼─────────┼─────┬───────────────┼───────────────┼───────────────┼─────────┴─────────┴────────────┘
//                                                  │               │         │     │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │ OSM(MOD_LGUI) │
//                                                  └───────────────┴─────────┴─────┴───────────────┴───────────────┴───────────────┘
[_NAV] = LAYOUT_split_3x5_3(
      CH_QST  , KC_HOME       , KC_PAGE_UP    , KC_PGDN       , KC_END   ,                           CH_LESS       , CH_LPRN       , CH_LCBR , CH_LBRC  , _______   ,
      CH_EXLM , KC_LEFT       , KC_UP         , KC_DOWN       , KC_RIGHT ,                           KC_LEFT       , KC_DOWN       , KC_UP   , KC_RIGHT , _______   ,
      _______ , OSM(MOD_LGUI) , OSM(MOD_LALT) , OSM(MOD_LCTL) , CH_PERC  ,                           CH_MORE       , CH_RPRN       , CH_RCBR , CH_RBRC  , TO(_ALPHA),
                                                _______       , _______  , _______ , OSM(MOD_LCTL) , OSM(MOD_LSFT) , OSM(MOD_LGUI)
),

//        ┌─────┬───┬───┬─────┬─────┐           ┌─────┬─────┬───┬───┬─────────┐
//        │     │ 9 │ 8 │  7  │     │           │     │  7  │ 8 │ 9 │ CH_PLUS │
//        ├─────┼───┼───┼─────┼─────┤           ├─────┼─────┼───┼───┼─────────┤
//        │  0  │ 6 │ 5 │  4  │     │           │     │  4  │ 5 │ 6 │    0    │
//        ├─────┼───┼───┼─────┼─────┤           ├─────┼─────┼───┼───┼─────────┤
//        │     │ 3 │ 2 │  1  │     │           │     │  1  │ 2 │ 3 │         │
//        └─────┴───┴───┼─────┼─────┼─────┬─────┼─────┼─────┼───┴───┴─────────┘
//                      │     │     │     │     │     │     │
//                      └─────┴─────┴─────┴─────┴─────┴─────┘
[_NUM] = LAYOUT_split_3x5_3(
      _______ , KC_9 , KC_8 , KC_7    , _______ ,                     _______ , KC_7    , KC_8 , KC_9 , CH_PLUS,
      KC_0    , KC_6 , KC_5 , KC_4    , _______ ,                     _______ , KC_4    , KC_5 , KC_6 , KC_0   ,
      _______ , KC_3 , KC_2 , KC_1    , _______ ,                     _______ , KC_1    , KC_2 , KC_3 , _______,
                              _______ , _______ , _______ , _______ , _______ , _______
),

//        ┌─────────┬─────────┬─────────┬─────────┬─────────┐           ┌─────────┬─────┬─────┬─────────┬────────────┐
//        │  CH_AT  │ CH_BSLS │    ,    │    .    │ CH_SLSH │           │ CH_SLSH │  .  │  ,  │ CH_BSLS │   CH_AT    │
//        ├─────────┼─────────┼─────────┼─────────┼─────────┤           ├─────────┼─────┼─────┼─────────┼────────────┤
//        │ CH_PAST │ CH_LCBR │ CH_LBRC │ CH_LPRN │ CH_LESS │           │         │     │     │         │            │
//        ├─────────┼─────────┼─────────┼─────────┼─────────┤           ├─────────┼─────┼─────┼─────────┼────────────┤
//        │         │ CH_RCBR │ CH_RBRC │ CH_RPRN │ CH_MORE │           │         │     │     │         │ TO(_ALPHA) │
//        └─────────┴─────────┴─────────┼─────────┼─────────┼─────┬─────┼─────────┼─────┼─────┴─────────┴────────────┘
//                                      │         │         │     │     │         │     │
//                                      └─────────┴─────────┴─────┴─────┴─────────┴─────┘
[_SYM] = LAYOUT_split_3x5_3(
      CH_AT   , CH_BSLS , KC_COMMA , KC_DOT  , CH_SLSH ,                     CH_SLSH , KC_DOT  , KC_COMMA , CH_BSLS , CH_AT     ,
      CH_PAST , CH_LCBR , CH_LBRC  , CH_LPRN , CH_LESS ,                     _______ , _______ , _______  , _______ , _______   ,
      _______ , CH_RCBR , CH_RBRC  , CH_RPRN , CH_MORE ,                     _______ , _______ , _______  , _______ , TO(_ALPHA),
                                     _______ , _______ , _______ , _______ , _______ , _______
),

//        ┌─────────┬─────────┬─────────┬─────────┬─────────┐           ┌─────────┬─────┬─────┬─────────┬────────────┐
//        │  CH_AT  │ CH_BSLS │    ,    │    .    │ CH_SLSH │           │ CH_SLSH │  .  │  ,  │ CH_BSLS │   CH_AT    │
//        ├─────────┼─────────┼─────────┼─────────┼─────────┤           ├─────────┼─────┼─────┼─────────┼────────────┤
//        │ CH_PAST │ CH_LCBR │ CH_LBRC │ CH_LPRN │ CH_LESS │           │         │     │     │         │            │
//        ├─────────┼─────────┼─────────┼─────────┼─────────┤           ├─────────┼─────┼─────┼─────────┼────────────┤
//        │         │ CH_RCBR │ CH_RBRC │ CH_RPRN │ CH_MORE │           │         │     │     │         │ TO(_ALPHA) │
//        └─────────┴─────────┴─────────┼─────────┼─────────┼─────┬─────┼─────────┼─────┼─────┴─────────┴────────────┘
//                                      │         │         │     │     │         │     │
//                                      └─────────┴─────────┴─────┴─────┴─────────┴─────┘
[_SYM2] = LAYOUT_split_3x5_3(
      CH_AT   , CH_BSLS , KC_COMMA , KC_DOT  , CH_SLSH ,                     CH_SLSH , KC_DOT  , KC_COMMA , CH_BSLS , CH_AT     ,
      CH_PAST , CH_LCBR , CH_LBRC  , CH_LPRN , CH_LESS ,                     _______ , _______ , _______  , _______ , _______   ,
      _______ , CH_RCBR , CH_RBRC  , CH_RPRN , CH_MORE ,                     _______ , _______ , _______  , _______ , TO(_ALPHA),
                                     _______ , _______ , _______ , _______ , _______ , _______
)
};



const uint16_t PROGMEM combo0[] = { MT(MOD_LGUI, KC_O), KC_P, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_X, MT(MOD_LGUI, KC_Q), COMBO_END};
const uint16_t PROGMEM combo2[] = { CH_QST, KC_END, COMBO_END};
const uint16_t PROGMEM combo3[] = { CH_BSLS, CH_AT, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_9, CH_PLUS, COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LCTL, KC_U), MT(MOD_LALT, KC_T), COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_LSFT, KC_F), CH_OE, COMBO_END};
const uint16_t PROGMEM combo7[] = { CH_LBRC, CH_LPRN, COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_LSFT, KC_R), KC_E, COMBO_END};
const uint16_t PROGMEM combo9[] = { MT(MOD_LSFT, KC_A), MT(MOD_LALT, KC_S), COMBO_END};
const uint16_t PROGMEM combo10[] = { L_BETA, L_NAV, COMBO_END};
const uint16_t PROGMEM combo11[] = {L_NUM, L_BETA, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo0, KC_BSPC),
    COMBO(combo1, KC_BSPC),
    COMBO(combo2, KC_BSPC),
    COMBO(combo3, KC_BSPC),
    COMBO(combo4, KC_BSPC),
    COMBO(combo5, KC_ESCAPE),
    COMBO(combo6, KC_SPACE),
    COMBO(combo7, KC_SPACE),
    COMBO(combo8, KC_SPACE),
    // COMBO(combo9, ST_MACRO_0),
    COMBO(combo9, KC_ENTER),
    COMBO(combo10, TT(_SYM)),
    COMBO(combo11, TT(_SYM2)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_H));
    }
    case ST_MACRO_AE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(100) "ä" SS_DELAY(100) SS_TAP(X_CAPS));
    }
    break;

  }
  return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // if(layer_state_is(_BETA) && layer_state_is(_NAV)) {
    //     state = state | ((layer_state_t)1 << _SYM);
    // }
    // state = update_tri_layer_state(state,_BETA, _NAV, _NUM);
    return state;
}

const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t ae_override = ko_make_basic(MOD_MASK_SHIFT, CH_AE, ST_MACRO_AE);
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_override,
    &ae_override,
    NULL // Null terminate the array of overrides!
};
