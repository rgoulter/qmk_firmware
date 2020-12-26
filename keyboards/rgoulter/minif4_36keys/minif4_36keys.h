/* Copyright 2020 Richard Goulter
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

#pragma once

#include "quantum.h"

#define LAYOUT_split_3x5_3( \
  L11, L12, L13, L14, L15,           R11, R12, R13, R14, R15, \
  L21, L22, L23, L24, L25,           R21, R22, R23, R24, R25, \
  L31, L32, L33, L34, L35,           R31, R32, R33, R34, R35, \
                 L41, L42, L43, R41, R42, R43 \
  ) \
  { \
    { L11, L12, L13, L14, L15 }, \
    { L21, L22, L23, L24, L25 }, \
    { L31, L32, L33, L34, L35 }, \
    { KC_NO, KC_NO, L41, L42, L43 }, \
    { R15, R14, R13, R12, R11 }, \
    { R25, R24, R23, R22, R21 }, \
    { R35, R34, R33, R32, R31 }, \
    { KC_NO, KC_NO, R43, R42, R41 }  \
  }
