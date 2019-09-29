#include <curses.h>

#include "statw.h"

WINDOW	       *
create_statw()
{
	return NULL;
}

void
show_status(char *s)
{
	//show a color rainbow decay for how hot the updates are

	int		x, y;
	int		max_x, max_y;
	getyx
		(stdscr, y, x);
	getmaxyx(stdscr, max_y, max_x);
	move(3, 10);
	printw("COLUMNS:%d LINES:%d", max_x, max_y);
	move(4, 10);
	printw("status: %s", s);
	move(y, x);
}
