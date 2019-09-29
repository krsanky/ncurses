#include <stdlib.h>
#include <ncurses.h>

int
main(int argc, char **argv)
{
	initscr();
	printw("hello curses...\n");
	printw("LINES:%d COLS:%d\n", LINES, COLS);
	printw("random:%ld\n", random());
	printw("random3:%ld\n", random()%3);
	printw("random COLS:%ld\n", random()%COLS);
	printw("random LINES:%ld\n", random()%LINES);
	refresh();
	getch();
	endwin();

	return EXIT_SUCCESS;
}

