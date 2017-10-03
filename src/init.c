#include <stdio.h>
#include <ncurses.h>

int initall(void)
{
	/* Start curses mode* */
	initscr();
	return 0;
};

int enditall(void)
{
	/* Endcurses mode */
	endwin();
	return 0;
};
