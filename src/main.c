#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "conway.h"


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

	// draw on the map

	draw_shape(5, 5, 36, &canon, &map);
	draw_shape_180(65, 95, 36, &canon, &map);
	draw_shape(40, 15, 48, &galaxy, &map);
	draw_shape(5, 80, 28, &cross, &map);


    //
    ///////// map.world[][] is now initialized
    
    initall();

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

		animate(20);		

	}
	
	getch();
	enditall();
}
