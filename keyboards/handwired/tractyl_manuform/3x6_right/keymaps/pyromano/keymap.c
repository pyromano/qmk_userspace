// Copyright 2024 pyromano
// SPDX-License-Identifier: GPL-3.0-or-later

#include "quantum.h"

// Layer names
enum layers {
    _QWERTY = 0,
    _MOUSE,
    _RAISE,
    _LOWER,
    _GRAPHITE,
    _GRAPHITE_RAISE,
    _GRAPHITE_LOWER,
};

// Left-hand home row mods (QWERTY)
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)

// Right-hand home row mods (QWERTY)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Left-hand home row mods (Graphite)
#define CTL_GrN LCTL_T(KC_N)
#define ALT_GrR LALT_T(KC_R)
#define GUI_GrT LGUI_T(KC_T)

// Right-hand home row mods (Graphite)
#define GUI_GrA RGUI_T(KC_A)
#define ALT_GrE LALT_T(KC_E)
#define CTL_GrI RCTL_T(KC_I)

// Custom keycodes for trackball modes on hold, key on tap
enum custom_keycodes {
    SNIP_COMM = SAFE_RANGE,
    DRG_X,
    DRG_DOT,
    SNIP_C,
    TG_GRAP,
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_3x6_right(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  CTL_A,   ALT_S,   GUI_D,   KC_F,    KC_G,                            KC_H,  KC_J,   GUI_K,   ALT_L,   CTL_SCLN,KC_QUOT,
        KC_LSFT, KC_Z,    DRG_X,   SNIP_C,  KC_V,    KC_B,                            KC_N,  KC_M,   SNIP_COMM, DRG_DOT,  KC_SLSH, KC_RSFT,
                          KC_LBRC, KC_RBRC,                                            KC_MINS, KC_PLUS,
                                    KC_LSFT, MS_BTN1,                               LT(_RAISE, KC_SPC),
                                    TG_GRAP, MO(_LOWER),                   KC_ENT,
                                    KC_LGUI, KC_LCTL,            MS_BTN2, MS_BTN3
    ),

    [_MOUSE] = LAYOUT_3x6_right(
        _______, _______, _______, _______, DPI_RMOD, DPI_MOD,                          _______, _______, _______, _______, _______, _______,
        _______, SNIPING, DRGSCRL, MS_BTN1, MS_BTN2, MS_BTN3,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______,                                             _______, _______,
                                    _______, _______,                                   _______,
                                    _______, _______,                      _______,
                                    _______, _______,            _______, _______
    ),

    [_RAISE] = LAYOUT_3x6_right(
        // KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_GRV, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MPLY,
        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_MUTE,
                          KC_BRID, KC_BRIU,                                             KC_VOLD, KC_VOLU,
                                    _______, _______,                                   _______,
                                    _______, _______,                      _______,
                                    _______, _______,            _______, _______
    ),

    [_LOWER] = LAYOUT_3x6_right(
        // KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        // _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
        _______, _______, _______, _______, _______, _______,                         KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,                         KC_MINS, KC_4,    KC_5,    KC_6,    KC_EQL, _______,
        _______, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT, _______,
                          _______, _______,                                             _______, _______,
                                    _______, _______,                                   _______,
                                    _______, _______,                      _______,
                                    _______, _______,            _______, _______
    ),

    [_GRAPHITE] = LAYOUT_3x6_right(
        KC_ESC,  KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                            KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,    KC_BSPC,
        KC_TAB,  CTL_GrN, ALT_GrR, GUI_GrT, KC_S,    KC_G,                            KC_Y,    KC_H,    GUI_GrA, ALT_GrE, CTL_GrI, KC_SCLN,
        KC_LSFT, KC_Q,    DRG_X,    SNIP_C,    KC_C,    KC_V,                         KC_K,    KC_P,    SNIP_COMM, DRG_DOT,  KC_SLSH, KC_RSFT,
                          KC_LBRC, KC_RBRC,                                            KC_MINS, KC_PLUS,
                                    KC_LSFT, MS_BTN1,                               LT(_GRAPHITE_RAISE, KC_SPC),
                                    TG_GRAP, MO(_GRAPHITE_LOWER),                   KC_ENT,
                                    KC_LGUI, KC_LCTL,            MS_BTN2, MS_BTN3
    ),

    [_GRAPHITE_RAISE] = LAYOUT_3x6_right(
        KC_GRV, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MPLY,
        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_MUTE,
                          KC_BRID, KC_BRIU,                                             KC_VOLD, KC_VOLU,
                                    _______, _______,                                   _______,
                                    _______, _______,                      _______,
                                    _______, _______,            _______, _______
    ),

    [_GRAPHITE_LOWER] = LAYOUT_3x6_right(
        _______, _______, _______, _______, _______, _______,                         KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,                         KC_MINS, KC_4,    KC_5,    KC_6,    KC_EQL, _______,
        _______, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT, _______,
                          _______, _______,                                             _______, _______,
                                    _______, _______,                                   _______,
                                    _______, _______,                      _______,
                                    _______, _______,            _______, _______
    ),
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

static uint16_t snip_timer;
static uint16_t drg_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRG_DOT:
            if (record->event.pressed) {
                drg_timer = timer_read();
                charybdis_set_pointer_dragscroll_enabled(true);
            } else {
                charybdis_set_pointer_dragscroll_enabled(false);
                if (timer_elapsed(drg_timer) < TAPPING_TERM) {
                    tap_code(KC_DOT);
                }
            }
            return false;
        case SNIP_C:
            if (record->event.pressed) {
                snip_timer = timer_read();
                charybdis_set_pointer_sniping_enabled(true);
            } else {
                charybdis_set_pointer_sniping_enabled(false);
                if (timer_elapsed(snip_timer) < TAPPING_TERM) {
                    tap_code((default_layer_state & (1 << _GRAPHITE)) ? KC_M : KC_C);
                }
            }
            return false;
        case SNIP_COMM:
            if (record->event.pressed) {
                snip_timer = timer_read();
                charybdis_set_pointer_sniping_enabled(true);
            } else {
                charybdis_set_pointer_sniping_enabled(false);
                if (timer_elapsed(snip_timer) < TAPPING_TERM) {
                    tap_code(KC_COMM);
                }
            }
            return false;
        case DRG_X:
            if (record->event.pressed) {
                drg_timer = timer_read();
                charybdis_set_pointer_dragscroll_enabled(true);
            } else {
                charybdis_set_pointer_dragscroll_enabled(false);
                if (timer_elapsed(drg_timer) < TAPPING_TERM) {
                    tap_code(KC_X);
                }
            }
            return false;
        case TG_GRAP:
            if (record->event.pressed) {
                set_single_persistent_default_layer((default_layer_state & (1 << _GRAPHITE)) ? _QWERTY : _GRAPHITE);
            }
            return false;
    }
    return true;
}
