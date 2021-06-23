/*  -*-  eval: (turn-on-orgtbl); -*-
 *
 * This keymap is based on default HHKB Layout.
 *
 * Copyright 2021 Munehiro Yamamoto <munepixyz@gmail.com>
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

/* from quantum/keymap_extras/keymap_jp.h */
#define JP_MEISU KC_LANG2 // Eisū (英数) on macOS
#define JP_MKANA KC_LANG1 // Kana (かな) on macOS

enum layer_names {
    _BASE,
    _FN,
    _RALT,
};

#define KC_FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer _BASE: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

         |------+-----------+-----------------------+-----------+------|
         | LAlt | EISU/LGUI | **** Space/Shift **** | KANA/RGUI | RAlt |
         |------+-----------+-----------------------+-----------+------|
    */

    [_BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_FN,
        KC_LALT, GUI_T(JP_MEISU), /*        */ SFT_T(KC_SPC), LT(_RALT, JP_MKANA), KC_RCTL),

    /* Layer _FN: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+-------+
                 | **** | **** | ******************** | **** | RESET |
                 |------+------+----------------------+------+-------+

     */

    [_FN] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET),

    [_RALT] = LAYOUT( //  default layer + vim-style hjkl keys with RALT
                     RALT(KC_ESC),  RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),   RALT(KC_0),    RALT(KC_MINS), RALT(KC_EQL),  RALT(KC_BSLS), RALT(KC_GRV),
                     RALT(KC_TAB),  RALT(KC_Q), RALT(KC_W), RALT(KC_E), RALT(KC_R), RALT(KC_T), RALT(KC_Y), RALT(KC_U), RALT(KC_I),    RALT(KC_O),   RALT(KC_P),    RALT(KC_LBRC), RALT(KC_RBRC), RALT(KC_BSPC),
                     RALT(KC_LCTL), RALT(KC_A), RALT(KC_S), RALT(KC_D), RALT(KC_F), RALT(KC_G),   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,   RALT(KC_SCLN), RALT(KC_QUOT), RALT(KC_ENT),
                     RALT(KC_LSFT), RALT(KC_Z), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), RALT(KC_N), RALT(KC_M), RALT(KC_COMM), RALT(KC_DOT), RALT(KC_SLSH), RALT(KC_RSFT), RALT(KC_FN),
                     KC_LALT, RALT(KC_LGUI), /*        */ RALT(KC_SPC), KC_TRNS, RALT(KC_RCTL)),

};
