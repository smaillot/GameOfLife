
#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int main()
{
	initall();
	printw("Hello World ! ");
	refresh();
	mvaddch(10, 10, 'X');
	refresh();
	
	getch();
	enditall();
}
