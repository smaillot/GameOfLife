#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

// Contains all the function related to ncurses display of the world and interfaces

void initall()
{
	// coder 3

    initscr();  
    noecho();  
    curs_set(0);            // set cursor invisible 
}

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
	// Display the status of a cell on screen assuming it has been cleaned before

	if (c->alive) // if not alive, nothing to display
	{
		int x = c->x;
		int y = c->y;
		/* one cell is represented by 2 characters in order to make a square pixel */
		pixel(x, y, LIVE_SYMBOL);
	}
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
	// Wait between 2 frames according to chosen FPS rate

	if (freq == 0) // 0 freq corresponds to the "press to continue" mode
	{
		getchar();
	}
	else // Otherwise wait for 1/freq seconds
	{
		usleep(1000000/freq); // try Sleep(1000/delay) on windows -> maybe we need to check the current OS to take into account
	}
}

int display_interface(struct Map* map)
{
	// coder 3
	// the interface function to display
	
	printw("-----------------------------------------------------------------------------------------------\n");
	printw("GAME OF LIFE - PLEASE ZOOM OUT AFTER SELECTION TO REDUCE PIXELS SIZE AND DISPLAY THE ENTIRE MAP\n");
	printw("-----------------------------------------------------------------------------------------------\n\n");
  	printw("SELECT a map number (press the correspounding key number) :\n\n");	// Print instruction
	printw("Map 1 - The R-pentomino\n");	// map infomation
	printw("Map 2 - Diehard\n");
	printw("Map 3 - Acorn\n");
	printw("Map 4 - Canons\n");
	printw("Map 5 - Oscillators\n");
	printw("Map 6 - Half pulsar\n");

    char ch = getch();			// Wait for user input
    if(ch == 49)  //49 is the ASCII code of ´1´
    {  // here the map is The R-pentomino
		draw_shape(ROWS/2 - 1, COLS/2 - 1, 5, &pentomino, map);
    }
    else if(ch == 50) // here we choose map2
    { // diehard
		draw_shape(ROWS/2 - 1, COLS/2 - 1, 7, &diehard, map);
    }
    else if(ch == 51)
    {  //Acorn
		draw_shape(ROWS/2 - 1, COLS/2 - 1, 7, &acorn, map);
    }
    else if(ch == 52)
    {  // canons
		draw_shape(1, 1, 36, &canon, map);
		draw_shape_180(65, 95, 36, &canon, map);

    }
    else if(ch == 53)
	{ // oscillators

		// beacon
		draw_shape(20, 50, 3, &angle3, map);
		draw_shape_180(23, 53, 3, &angle3, map);

		draw_shape(20, 20, 3, &blinker, map);
		draw_shape(50, 50, 28, &oscillator, map);
		draw_shape(50, 20, 28, &cross, map);
		draw_shape(50, 80, 48, &galaxy, map);

		// pulsar
		draw_shape(20, 80, 14, &pulsar, map);
		draw_shape_flip_h(20, 94, 14, &pulsar, map);
		draw_shape_flip_v(34, 80, 14, &pulsar, map);
		draw_shape_180(34, 94, 14, &pulsar, map);
	}
		else if(ch == 54)
		{ // half pulsars

			draw_shape(ROWS/2 - 15, COLS/2 - 7, 14, &pulsar, map);
			draw_shape_flip_h(ROWS/2 - 15, COLS/2 + 7, 14, &pulsar, map);
			draw_shape_flip_v(ROWS/2 + 15, COLS/2 - 7, 14, &pulsar, map);
			draw_shape_180(ROWS/2 + 15, COLS/2 + 7, 14, &pulsar, map);
		}

	clear();

	printw("--------------------------------------------------------------------\n");
	printw("GAME OF LIFE - PLEASE ZOOM OUT AFTER SELECTION TO REDUCE PIXELS SIZE\n");
	printw("--------------------------------------------------------------------\n\n");
  	printw("SELECT a speed :\n\n");	// Print instruction
	printw("1. Press key to move next frame\n");	// map infomation
	printw("2. Slow (5 fps)\n");
	printw("3. Normal (15 fps)\n");
	printw("4. Fast (30 fps)\n");
	printw("5. Extreme (60 fps)\n");

	ch = getch();			// Wait for user input
    if(ch == 49)  //49 is the ASCII code of ´1´
    {  
    	return 0;
    }
    else if(ch == 50) // here we choose map2
    {
		return 5;
    }
    else if(ch == 51)
    {  
    	return 15;
    }
    else if(ch == 52)
    {  
    	return 30;
    }
			else if(ch == 53)
			{ 
				return 60;
			}
}
