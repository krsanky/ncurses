#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

void
draw_trunk()
{
	move(LINES, (COLS/2)-10);
}

void
draw_top()
{

}

void
draw_tree()
{
	draw_trunk();
	draw_top();
}

int
main()
{
	int		ch;

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	clear();


	printw("Press F1 to exit");
	refresh();

	while ((ch = getch()) != KEY_F(1)) {
		draw_tree();
	}


	endwin();
	return EXIT_SUCCESS;
}
