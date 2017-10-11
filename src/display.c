#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

// Contains all the function related to ncurses display of the world and interfaces


void enditall(void)
{
	/* Endcurses mode */
	endwin();
}

void pixel(int x, int y, char c)
{
	//coder 1
	// Display a pixel (with 2 chars c) in (x,y) 

	mvaddch(x, 2*y, c);
	mvaddch(x, 2*y+1, c);
}

void display_cell(struct Cell *c)
{
	// coder 1
	// Display the status of a cell on screen assuming it has been cleaned

	if (c->alive) // if not alive, nothing to display
	{
		int x = c->x;
		int y = c->y;
		/* one cell is represented by 2 characters in order to make a square pixel */
		pixel(x, y, LIVE_SYMBOL);
	}
}

void initall()
{
	// coder 3

    initscr();  
    noecho();  
    curs_set(0);            // set cursor invisible 
}

void inimap()  { 
  	// coder 3
  	// Display the map contours and title

  	refresh();
	clear();
   
    int i, j;   
  
    // display the map  
    for(i = 0; i <= ROWS; i++)  
	{   
		pixel(i, LEFT_EDGE, BORDER_SYMBOL);  
		pixel(i, RIGHT_EDGE, BORDER_SYMBOL);  
	}   
    for(j = 0; j <= COLS+1; j++)  
    {    
        pixel(TOP_ROW, j, BORDER_SYMBOL);  
        pixel(BOT_ROW, j, BORDER_SYMBOL);  
    }  
    mvaddstr(BOT_ROW+1, 0, "Game of life");  
    mvaddstr(BOT_ROW+2, 0, "Stéphane Maillot, Théo Desquin, Xiaoxuan Hu");  
    refresh();  
}

void display_map(struct Map *map)
{
	// coder 1
	// Loop over each cell to display its status

	for (int i=1; i<map->rows-1; i++)
	{
		for (int j=1; j<map->cols-1; j++)
		{
			struct Cell current_cell = {i, j, map->world[i][j]};
			display_cell(&current_cell);
		}
	}
	refresh();
}

void animate(int freq)
{
	// coder 1
	// Wait between 2 frames 

	if (freq == 0) // 0 freq corresponds to the "press to continue" mode
	{
		getchar();
	}
	else // Otherwise wait for 1/freq seconds
	{
		usleep(1000000/freq); // try Sleep(1000/delay) on windows -> maybe we need to check the current OS to take into account
	}
}

// Add interface function here