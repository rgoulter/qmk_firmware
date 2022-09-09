/* Copyright 2021 Richard Goulter
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

#include "x_2.h"

#ifdef RGB_MATRIX_ENABLE

// - all in left-to-right
// - switch + backlight in triplets
//   of (switch, backlight, switch)
//
// Indices:
//   00-03 first 4: in middle
//   04-09  next 6: LHS, row 5
//   10-15  next 6: LHS, row 4
//   16-24  next 9: LHS, row 3 + LHS BL,
//   25-30  next 6: LHS, row 2,
//   31-36  next 6: LHS, row 1,
//   37-42  next 6: RHS, row 1
//   43-48  next 6: RHS, row 2
//   49-57  next 9: RHS, row 3 + LHS BL,
//   58-63  next 6: RHS, row 4,
//   64-69  next 6: RHS, row 5,

led_config_t g_led_config = {
  {
   // Key Matrix to LED Index

   { 31, 32, 33, 34, 35, 36,   37, 38, 39, 40, 41, 42, },
   { 25, 26, 27, 28, 29, 30,   43, 44, 45, 46, 47, 48, },
   { 16, 18, 19, 21, 22, 24,   49, 51, 52, 54, 55, 57, },
   { 10, 11, 12, 13, 14, 15,   58, 59, 60, 61, 62, 63, },
   {  4,  5,  6,  7,  8,  9,   64, 65, 66, 67, 68, 69, },

  },
  {
    // LED Index to Physical Position

    // 16 times table:
    //  16,  32,  48,  64,  80,
    //  96, 112, 128, 144, 160,
    // 176, 192, 208, 224, 240,

    //   00-03 first 4: in middle
    {  96,  48 }, {  105,  48 }, { 115,  48 }, { 128,  48 },

    //   04-09  next 6: LHS, row 5
    { 0, 64 }, { 16, 64 }, { 32, 64 }, { 48, 64 }, { 64, 64 }, { 80, 64 },
    //   10-15  next 6: LHS, row 4
    { 0, 48 }, { 16, 48 }, { 32, 48 }, { 48, 48 }, { 64, 48 }, { 80, 48 },
    //   16-24  next 9: LHS, row 3 + LHS BL,
    { 0, 32 },{ 8, 32 },{ 16, 32 }, { 32, 32 },{ 40, 32 },{ 48, 32 }, { 64, 32 },{ 72, 32 },{ 80, 32 },
    //   25-30  next 6: LHS, row 2,
    { 0, 16 }, { 16, 16 }, { 32, 16 }, { 48, 16 }, { 64, 16 }, { 80, 16 },
    //   31-36  next 6: LHS, row 1,
    { 0, 0 }, { 16, 0 }, { 32, 0 }, { 48, 0 }, { 64, 0 }, { 80, 0 },

    //   37-42  next 6: RHS, row 1
    { 0, 0 }, { 16, 0 }, { 32, 0 }, { 48, 0 }, { 64, 0 }, { 80, 0 },
    //   43-48  next 6: RHS, row 2
    { 0, 16 }, { 16, 16 }, { 32, 16 }, { 48, 16 }, { 64, 16 }, { 80, 16 },
    //   49-57  next 9: RHS, row 3 + LHS BL,
    { 0, 32 },{ 8, 32 },{ 16, 32 }, { 32, 32 },{ 40, 32 },{ 48, 32 }, { 64, 32 },{ 72, 32 },{ 80, 32 },
    //   58-63  next 6: RHS, row 4,
    { 0, 48 }, { 16, 48 }, { 32, 48 }, { 48, 48 }, { 64, 48 }, { 80, 48 },
    //   64-69  next 6: RHS, row 5,
    { 0, 64 }, { 16, 64 }, { 32, 64 }, { 48, 64 }, { 64, 64 }, { 80, 64 },

  },
  {

    // LED Index to Flag
    //   0x01 = modifier
    //   0x02 = underglow
    //   0x04 = key backlight
    //   0x08 = state indicator

    8, 8, 8, 8,

    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4,2,4, 4,2,4, 4,2,4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,

    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4,2,4, 4,2,4, 4,2,4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,

  }
};

#endif
