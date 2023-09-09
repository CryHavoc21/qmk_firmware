/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
};

// OLD NYQUIST LAYOUT
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |EscGrv|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Point | GUI  | Alt  |    Space    |    Space    |      | Func |      |  =   |
 * `-----------------------------------------------------------------------------------'
 *
[_QWERTY] = LAYOUT( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  _______,TG(_POINT),KC_LGUI, KC_LALT, KC_NO,  KC_SPC,  KC_SPC,  KC_NO,   _______, MO(_FUNC),_______, KC_EQL \
),
* Func - Held layer
 * ,-----------------------------------------------------------------------------------.
 * |  `   |  F10 |  F11 |  F12 |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Reset |  F7  |  F8  |  F9  |      |      |      |      | Up   |  [   |  ]   | \    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL_TOG|  F4  |  F5  |  F6  |      |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
[_FUNC] = LAYOUT( \
  KC_GRV,  KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  RESET,   KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLASH, \
  BL_TOGG, KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, _______, _______, KC_LGUI,  KC_LALT,          _______,           _______,          MO(SYMB),_______, _______, _______, KC_EQL,
                                              KC_SPC,  KC_GRV, _______,           _______, KC_MINS, KC_SPC
    ),

    [SYMB] = LAYOUT_moonlander(
        KC_GRV,  KC_F10,  KC_F11,  KC_F12,   _______, _______, _______,           _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_DEL,
        RESET,   KC_F7,   KC_F8,   KC_F9,    _______, _______, _______,           _______, _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F4,   KC_F5,   KC_F6,    _______, _______, _______,           _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,    _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                             _______, _______, _______,           _______, _______, _______
    ),
};

