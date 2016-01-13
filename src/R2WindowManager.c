/* This is the source code of Artoo Editor.
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "R2WindowManager.h"
#include "R2Window.h"

#define PARENT stdscr
#define R2WindowManager_getParentWindowMaxYX(_y, _x) getmaxyx(PARENT, _y, _x)
#define R2WindowManager_updateAllWindows() doupdate()
#define SIZE_ROWS_TERMINAL 3

static void R2WindowManager_init();
static void R2WindowManager_deinit();

void R2WindowManager_run()
{
  R2WindowManager_init();

  int parent_win_x = 0;
  int parent_win_y = 0;
  int new_x = 0;
  int new_y = 0;
  
  R2WindowManager_getParentWindowMaxYX(parent_win_y, parent_win_x);
  R2Window *editorWin = R2Window_new(parent_win_y - SIZE_ROWS_TERMINAL, parent_win_x, 0, 0, BT_DASHED);
  R2Window *terminalWin = R2Window_new(SIZE_ROWS_TERMINAL, parent_win_x, parent_win_y - SIZE_ROWS_TERMINAL, 0, BT_DASHED);

  while(1)  
  { 
    R2WindowManager_getParentWindowMaxYX(new_y, new_x);
    if (new_y != parent_win_y || new_x != parent_win_x)
    {
      parent_win_y = new_y;
      parent_win_x = new_x;

      R2Window_resize(editorWin, new_y - SIZE_ROWS_TERMINAL, new_x);
      R2Window_resizeAndGotoYX(terminalWin, SIZE_ROWS_TERMINAL, new_x, new_y - SIZE_ROWS_TERMINAL, 0);
    }
    
    R2WindowManager_updateAllWindows();
  }  

  R2Window_release(editorWin);
  R2Window_release(terminalWin);
  R2WindowManager_deinit();
}

static void R2WindowManager_init()
{
  initscr();
  cbreak();
  noecho();
  curs_set(TRUE);
}

static void R2WindowManager_deinit()
{
  endwin();
}

void R2WindowManager_stop()
{
}