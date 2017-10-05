#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int main()
{

	/* remaining work:
		- interface
		- modify grid size with a variable
		- choose the initial states ingame
		- choose speed (use sleep instead of getchar() )
	*/


	
	struct Map map;
	map.rows = 10;
	map.cols = 10;
	for (int i=0; i<map.rows; i++)
	{
		for (int j=0; j<map.cols; j++)
		{
			map.world[i][j] = false;
			map.next_world[i][j] = false;
		}
	}

	for (int i=1; i<map.rows-1; i++) //draw an initial figure
	{
		for (int j=1; j<map.cols-1; j++)
		{
			if ((i+j)%2)
			{
				map.world[i][j] = true;
			}
		}
	}

	initall();
	curs_set(0); // hide cursor
	
	for(int k=0;k<100;k++) // while(1) // main loop
	{
		refresh();
		clear();

		// loop over each cell to update world
		for (int i=1; i<map.rows-1; i++)
		{
			for (int j=1; j<map.cols-1; j++)
			{
				struct Cell current_cell = {i, j, map.world[i][j]};
				display(&current_cell);
				map.next_world[i][j] = (bool*) get_next_state(&current_cell, &map);
			}
		}

		for (int i=0; i<map.rows; i++)
		{
			for (int j=0; j<map.cols; j++)
			{
				map.world[i][j] = map.next_world[i][j];
			}
		}		

		if (k!=0) getchar();		
		refresh();

	}
	
	getch();
	enditall();
}