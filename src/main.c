
#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

void switch_on(int, int);
void switch_off(int, int);
int count_neighbors();
int compute_next_state();

int main()
{

	// load world from external file
	// create a structure for the grid
		// create a sub-structure for the cells
	// world = ...

	initall();
	curs_set(0); // hide cursor

	for(int i=0;i<100;i++) // while(1) // main loop
	{
		refresh();
		clear();
		
		// loop over each cell to update world

		/* example of cells on - please decrease your console font size */
		switch_on(10,10);
		switch_on(10,11);
		switch_on(10,12);

		switch_on(20,10);
		switch_on(21,10);
		switch_on(22,10);
		switch_on(22,11);
		switch_on(20,11);
		switch_on(20,12);
		switch_on(21,12);

		switch_on(10,100);
		switch_on(11,101);
		switch_on(12,101);
		switch_on(12,100);
		switch_on(12,99);

		refresh();
	}
	
	getch();
	enditall();
}

void switch_on(int x, int y)
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