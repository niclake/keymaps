/*
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

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLE,
    _FN,
    _ADJ
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLE,
    FN,
    ADJ,
    MACWIN
};

#define COLEMAK DF(_BASE)
#define QWERTY  DF(_QWERTY)
#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define ADJUST  TT(_ADJUST)
#define MACWIN  MAGIC_TOGGLE_ALT_GUI
#define RGB_ON  RGB_MODE_PLAIN
#define RGB_TW  RGB_MODE_TWINKLE

enum combos {
    WE_LBR,
    SD_LBK,
    XC_GRV,
    ER_RBR,
    DF_RBK,
    CV_TIL,
    UI_HYP,
    IO_EQU,
    KL_APO,
    COMDOT_BSL
};

/* Combo Keys */
const uint16_t PROGMEM we_com[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_com[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM xc_com[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM er_com[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_com[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_com[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ui_com[] = {KC_U, KC_I, COMBO_END};
// const uint16_t PROGMEM jk_com[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM m,_com[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM io_com[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_com[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM comdot_com[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [WE_LBR] = COMBO(we_com, KC_LCBR),
    [SD_LBK] = COMBO(sd_com, KC_LBRC),
    [XC_GRV] = COMBO(xc_com, KC_GRV),
    [ER_RBR] = COMBO(er_com, KC_RCBR),
    [DF_RBK] = COMBO(df_com, KC_RBRC),
    [CV_TIL] = COMBO(cv_com, KC_TILD),
    [UI_HYP] = COMBO(ui_com, KC_MINS),
    [IO_EQU] = COMBO(io_com, KC_EQL),
    [KL_APO] = COMBO(kl_com, KC_QUOT),
    [COMDOT_BSL] = COMBO(comdot_com, KC_BSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        FN,               KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          MO(1),   KC_RCTL
    ),

    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        FN,               KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          LOWER,   KC_RCTL
    ),

    [_RAISE] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______,          KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, _______, _______, _______,
        _______,          _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,  _______,          KC_CAPS,
        _______, _______,          _______,                   _______,                            _______, _______,          ADJUST,  _______
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        ADJUST,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
    ),

    [_ADJUST] = LAYOUT(
        XXXXXXX, RGB_ON,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_G, RGB_M_TW, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX,          RGB_TOG, RGB_MOD, RGB_HUI,  RGB_SAI, RGB_VAI,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        ADJUST,           MACWIN,  XXXXXXX, RGB_HUD, RGB_SAD,  RGB_VAD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,          XXXXXXX,                   XXXXXXX,                              XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX
    )
};
