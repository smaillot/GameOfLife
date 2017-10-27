#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "conway.h"

/*

Team work strategy

Our team work strategy was to create a repo (http://github.com/smaillot/GameOfLife)
so that each member of the team can independantly edit and create his functions 
and check other's work.

We basically splitted the work as follow :

coder 1 created the main structure of the program and display functions
coder 2 focused on game rules for the evolution of world's state between frames
coder 3 realised the game interface and initial maps

*/


int main()
{
	////// coder 1
	//
	
	struct Map map;
	map.rows = ROWS+2;
	map.cols = COLS+2;
	
	
	// The previously created map is set to "all-dead"
	for (int i=0; i<map.rows; i++)
	{ 
		for (int j=0; j<map.cols; j++)
		{
			map.world[i][j] = false;
			map.next_world[i][j] = false;
		}
	}
	
	
    initall();
	// draw the map
	
       // choose the map
	int freq = display_interface(&map);

    // map.world[][] is now initialized
    

	while (1) //for(int k=0;k<1000;k++) // main loop
	{

		inimap(); // draw the map edges and title
		display_map(&map); // display map

		for (int i=1; i<map.rows-1; i++)  // compute next step
		{
			for (int j=1; j<map.cols-1; j++)
			{
				struct Cell current_cell = {i, j, map.world[i][j]};
				map.next_world[i][j] = (bool*) get_next_state(&current_cell, &map);
			}
		}

		for (int i=0; i<map.rows; i++)  // assign next step to current
		{
			for (int j=0; j<map.cols; j++)
			{
				map.world[i][j] = map.next_world[i][j];
			}
		}	

		animate(freq);		

	}
	
	enditall();
}