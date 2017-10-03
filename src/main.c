
#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int main()
{

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
	{
		refresh();
		clear();

		// loop over each cell to update world

		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				if(world[i][j])
					{
						switch_on(i, j);
					}
			}
		}		

		refresh();
	}
	
	getch();
	enditall();
}