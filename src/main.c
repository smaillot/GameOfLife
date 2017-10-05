#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int main()
{

<<<<<<< HEAD
	// load world from external file
	int rows = 5;
	int cols = 10;
	bool world[5][10] = {{false}}; // need a malloc
	world[1][1] = true;
	world[1][2] = true;
	world[1][3] = true;

	initall();
	curs_set(0); // hide cursor

	for(int k=0;k<1;k++) // while(1) // main loop
=======
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
>>>>>>> function_law
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

<<<<<<< HEAD
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(world[i][j])
					{
						switch_on(i, j);
					}
=======
		for (int i=0; i<map.rows; i++)
		{
			for (int j=0; j<map.cols; j++)
			{
				map.world[i][j] = map.next_world[i][j];
>>>>>>> function_law
			}
		}		

		if (k!=0) getchar();		
		refresh();

	}
	
	getch();
	enditall();
}