#include <curses.h>

#include "statw.h"

WINDOW	       *
statw_create(int height, int width, int starty, int startx)
{
	WINDOW	*local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);  /* 0, 0 gives default characters 
                             * for the vertical and horizontal
                             * lines   */
	wrefresh(local_win);  /* Show that box */

	return local_win;
}

void
statw_delete(WINDOW * local_win)
{
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
  	 * 2. ls: character to be used for the left side of the window 
  	 * 3. rs: character to be used for the right side of the window 
  	 * 4. ts: character to be used for the top side of the window 
  	 * 5. bs: character to be used for the bottom side of the window 
  	 * 6. tl: character to be used for the top left corner of the window 
  	 * 7. tr: character to be used for the top right corner of the window 
  	 * 8. bl: character to be used for the bottom left corner of the window 
  	 * 9. br: character to be used for the bottom right corner of the window
  	 */
	wrefresh(local_win);
	delwin(local_win);
}

void
show_status(char *s)
{
	/* show a color rainbow decay for how hot the updates are */

	int		x, y;
	int		max_x, max_y;

	getyx(stdscr, y, x);
	getmaxyx(stdscr, max_y, max_x);
	move(3, 10);
	printw("COLUMNS:%d LINES:%d", max_x, max_y);
	move(4, 10);
	printw("status: %s", s);
	move(y, x);
}
