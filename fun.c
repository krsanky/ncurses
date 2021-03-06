#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#include "statw.h"

/*
 *               The screen (stdscr)
 * (0,0)*----------------------------------* (0, COLS-1)
 *         |                                  |
 *         |                                  |
 *         |    (y0,x0)                       |
 *         |      ---------------             |
 *         |      |             |             |
 *         |      |             |             |
 *         |      |     win     |nlines       |
 *         |      |             |             |
 *         |      |             |             |
 *         |      |             |             |
 *         |      ---------------             |
 *         |          ncols                   |
 *         |                                  |
 *         *----------------------------------*
 * (LINES-1, 0)                              (LINES-1, COLS-1) 
 */

void
main_stuff() {
	int		max_x, max_y;

	getmaxyx(stdscr, max_y, max_x);

	show_status("asdasd123");
	refresh();
	sleep(2);

	int		x, y = 0;
	for (x = 0; x < max_x; x++) {
		mvaddch(y, x, '*');
		y += 1;
		usleep(1000);
		refresh();
	}
}

int
main()
{
	WINDOW		*my_statw;
	int			ch;
	int			height, width;
	int			starty, startx;

	height = 3;
	width = 10;

	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	initscr();
	cbreak();
	/*noecho();*/
	keypad(stdscr, TRUE);
	/*clear();*/


	printw("Press F1 to exit");
	refresh();
	my_statw = statw_create(height, width, starty, startx);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
		case KEY_LEFT:
			statw_delete(my_statw);
			my_statw = statw_create(height, width, starty, --startx);
			break;
		case KEY_RIGHT:
			statw_delete(my_statw);
			my_statw = statw_create(height, width, starty, ++startx);
			break;
		case KEY_UP:
			statw_delete(my_statw);
			my_statw = statw_create(height, width, --starty, startx);
			break;
		case KEY_DOWN:
			statw_delete(my_statw);
			my_statw = statw_create(height, width, ++starty, startx);
			break;
		}
	}

/*	main_stuff();*/

	endwin();
	return EXIT_SUCCESS;
}
