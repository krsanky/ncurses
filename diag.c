#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

/*
				The screen (stdscr)
(0,0)*----------------------------------* (0, COLUMNS-1)
	 |                                  |
	 |                                  |
	 |    (y0,x0)                       |
	 |      ---------------             |
	 |      |             |             |
	 |      |             |             |
	 |      |     win     |nlines       |
	 |      |             |             |
	 |      |             |             |
	 |      |             |             |
	 |      ---------------             |
	 |          ncols                   |
	 |                                  |
	 *----------------------------------*
(LINES-1, 0)                              (LINES-1, COLUMNS-1) 
*/


void
show_status(char *s)
{
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

int
main()
{
	int		max_y, max_x;

	initscr();
	//cbreak();
	noecho();
	curs_set(FALSE);

	getmaxyx(stdscr, max_y, max_x);

	//clear();
	mvprintw(0, 0, "Heloow asdqw");
	show_status("asdasd123");
	refresh();
	sleep(2);

/*
To move the cursor to a new position on a window, use the function
int wmove(WINDOW *win, int y, int x)
    wmove(win, y, x);
where (x, y) are the coordinates of the new position in the window.
If the window has nlines lines and ncolumns columns, then
	0 <= y < nlines 
	0 <= x < ncolumns
Refresh.  The actual cursor motion is not shown on the screen untill
you do a wrefresh(win).

move(y, x) is equivalent to the wmove(stdscr, y, x).

then addch(ch);
*/







	endwin();

	return EXIT_SUCCESS;
}

