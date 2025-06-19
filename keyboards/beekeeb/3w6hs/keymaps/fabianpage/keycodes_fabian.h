#pragma once

// #include QMK_KEYBOARD_H

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_AE,
  ST_MACRO_TH,
  TD_P_NUM,
  TD_D_NAV,
};


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
#define CH_DQUT S(CH_2)
// #define CH_PLUS S(KC_1)
//
enum layers {
    _ALPHA = 0,
    _BETA,
    _NAV,
    _NUM,
    _BRC,
};
