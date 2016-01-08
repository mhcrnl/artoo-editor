/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */


#include <stdbool.h>

#define CREATE_COLOR(A, B) init_pair(A, B, COLOR_BLACK)
#define R2_BACKSPACE 127

typedef struct
{
  int x;
  int y;
}R2Point;


bool R2_SHOULD_NOT_USE_COLORS = true;
