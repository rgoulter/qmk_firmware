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

#include "minif4_36.h"

#if defined(RGB_MATRIX_ENABLE)
led_config_t g_led_config = {
  {
   // Key Matrix to LED Index

   // LHS
   { 0, 1, 2, 3, 4 },
   { 5, 6, 7, 8, 9 },
   { 10, 11, 12, 13, 14 },
   { NO_LED, NO_LED, 15, 16, 17 },
   // 18, 19, 20, 21 are underneath

   // RHS
   { 22, 23, 24, 25, 26 },
   { 27, 28, 29, 30, 31 },
   { 32, 33, 34, 35, 36 },
   { NO_LED, NO_LED, 37, 38, 39 },
   // 40, 41, 42, 43 are underneath
  },
  {
   // LED Index to Physical Position

   // very rough approximation
   { 10, 10 }, { 60, 10 }, { 110, 10 }, { 160, 10 }, { 210, 10 },
   { 10, 60 }, { 60, 60 }, { 110, 60 }, { 160, 60 }, { 210, 60 },
   { 10, 110 }, { 60, 110 }, { 110, 110 }, { 160, 110 }, { 210, 110 },
   { 110, 160 }, { 160, 160 }, { 210, 160 },
   { 190, 190 }, { 30, 190 }, { 30, 60 }, { 190, 60 },

   { 10, 10 }, { 60, 10 }, { 110, 10 }, { 160, 10 }, { 210, 10 },
   { 10, 60 }, { 60, 60 }, { 110, 60 }, { 160, 60 }, { 210, 60 },
   { 10, 110 }, { 60, 110 }, { 110, 110 }, { 160, 110 }, { 210, 110 },
   { 110, 160 }, { 160, 160 }, { 210, 160 },
   { 190, 190 }, { 30, 190 }, { 30, 60 }, { 190, 60 }
  },
  {
   // LED Index to Flag
   4, 4, 4, 4, 4,
   4, 4, 4, 4, 4,
   4, 4, 4, 4, 4,
   1, 1, 1,
   2, 2, 2,
   
   4, 4, 4, 4, 4,
   4, 4, 4, 4, 4,
   4, 4, 4, 4, 4,
   1, 1, 1,
   2, 2, 2
  }
};
#endif
