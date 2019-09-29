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
	// show a color rainbow decay for how hot the updates are

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
	int		max_x, max_y;
	
	initscr();
	getmaxyx(stdscr, max_y, max_x);
	//cbreak();
	noecho();
	//curs_set(FALSE);

	//clear();
	//mvprintw(0, 0, "Heloow asdqw");
	show_status("asdasd123");
	refresh();
	sleep(2);

	int		x, y = 0;  
	for (x=0 ;x<max_x; x++) {
		mvaddch(y, x, '*');
		y += 1;
		usleep(1000);
		refresh();
		
	}



	endwin();
	return EXIT_SUCCESS;
}

