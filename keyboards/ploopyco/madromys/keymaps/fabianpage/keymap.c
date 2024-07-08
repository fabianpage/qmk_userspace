/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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
#include <stdlib.h>
#include "madromys.h"
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum custom_keycodes {
    CURSOR_SCROLL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN4, DPI_CONFIG, DRAG_SCROLL, CURSOR_SCROLL, KC_BTN1, KC_BTN2 )
};

bool set_cursor_scrolling = false;


// Modify these values to adjust the scrolling speed
#define CURSOR_DIVISOR_H 8.0
#define CURSOR_DIVISOR_V 8.0

// Variables to store accumulated scroll values
int cursor_accumulated_x = 0;
int cursor_accumulated_y = 0;

const int CURSOR_TICKS = 128;


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_cursor_scrolling) {
        // mouse_report.h = mouse_report.x;
        // mouse_report.v = mouse_report.y;
        // mouse_report.x = 0;
        // mouse_report.y = 0;
        //
        // Calculate and accumulate scroll values based on mouse movement and divisors
        // cursor_accumulated_h += (float)mouse_report.x / CURSOR_DIVISOR_H;
        // cursor_accumulated_v += (float)mouse_report.y / CURSOR_DIVISOR_V;
        if(abs(mouse_report.x) > abs(mouse_report.y)) {
            cursor_accumulated_x += mouse_report.x;
        } else {
            cursor_accumulated_y += mouse_report.y;
        }

        // int signX = cursor_accumulated_x > 0 ? 1 : -1;

        // while(cursor_accumulated_x * signX > 0) {
        //     cursor_accumulated_x -= 128*signX;
        //     if(signX > 0)
        //         SEND_STRING(SS_TAP(X_LEFT));
        //     else
        //         SEND_STRING(SS_TAP(X_RIGHT));
        // }
        while(cursor_accumulated_x >= CURSOR_TICKS) {
            cursor_accumulated_x -= CURSOR_TICKS;
            SEND_STRING(SS_TAP(X_RIGHT));
        }

        while(cursor_accumulated_x <= -CURSOR_TICKS) {
            cursor_accumulated_x += CURSOR_TICKS;
            SEND_STRING(SS_TAP(X_LEFT));
        }

        while(cursor_accumulated_y >= CURSOR_TICKS) {
            cursor_accumulated_y -= CURSOR_TICKS;
            SEND_STRING(SS_TAP(X_DOWN));
        }

        while(cursor_accumulated_y <= -CURSOR_TICKS) {
            cursor_accumulated_y += CURSOR_TICKS;
            SEND_STRING(SS_TAP(X_UP));
        }

        // Assign integer parts of accumulated scroll values to the mouse report
        // mouse_report.h = (int8_t)cursor_accumulated_h;
        // mouse_report.v = (int8_t)cursor_accumulated_v;



        // Update accumulated scroll values by subtracting the integer parts
        // cursor_accumulated_h -= (int8_t)cursor_accumulated_h;
        // cursor_accumulated_v -= (int8_t)cursor_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;

        //     for(int i = 0; i < abs(mouse_report.x); i++) {
        //         if(mouse_report.x > 0)
        //             SEND_STRING(SS_TAP(X_LEFT));
        //         else
        //             SEND_STRING(SS_TAP(X_RIGHT));
        //     }
        // }

    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CURSOR_SCROLL && record->event.pressed) {
        set_cursor_scrolling = !set_cursor_scrolling;
    }
    return true;
}
