#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int
main()
{
	initscr();
	//cbreak();
	noecho();
	curs_set(FALSE);

	//clear();
	mvprintw(0, 0, "Heloow asdqw");
	refresh();
	sleep(2);


	endwin();

	return EXIT_SUCCESS;
}

