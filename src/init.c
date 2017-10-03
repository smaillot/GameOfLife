#include <stdio.h>
#include <ncurses.h>


int initall(void)
{
	/* Start curses mode* */
	initscr();
	return 0;
}

int enditall(void)
{
	/* Endcurses mode */
	endwin();
	return 0;
}

void switch_on(int x, int y) // coder 1
{
	/* one cell is represented by 2 characters in order to make a square pixel */
	mvaddch(x, 2*y, (char)0x2588); // solid block ascii code
	mvaddch(x, 2*y+1, (char)0x2588);
}

int count_neighbors()
{
	return 0;
}

int compute_next_state()
{
	return 0;
}