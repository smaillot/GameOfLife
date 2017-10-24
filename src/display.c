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

void display_interface()
{
	// coder 3
	// the interface function to display
	initall();
  printw("Please press number 1-5 to choose a map to display");	// Print instruction
	printw("Map 1 The R-pentomino");	// map infomation
	printw("Map 2 Diehard");
	printw("Map 3 Acorn");
	printw("Map 4 ");
	printw("Map 5 ");

	int in = getch();			// Wait for user input
	        if(ch == 49)  //49 is the ASCII code of ´1´
	        {  // here the map is The R-pentomino
						draw_shape(1, 2, 2, &twopoints, &map);
						draw_shape(2, 1, 2, &twopoints, &map);
						draw_shape(3, 2, 1, &onepoint, &map);
	        }
	        else if(ch == 50) // here we choose map2
	        {
						draw_shape(2, 1, 3, &angle3, &map);
						draw_shape(1, 7, 1, &onepoint, &map);
						draw_shape(3, 6, 3, &blinker, &map);
	        }
	        else if(ch == 51)
	        {  //Acorn
						draw_shape(1, 2, 1, &onepoint, &map);
						draw_shape(2, 4, 1, &onepoint, &map);
						draw_shape(3, 1, 2, &twopoints, &map);
						draw_shape(3, 5, 3, &blinker, &map);
	        }
	        else if(ch == 52)
	        {  //  !!!!!     this shape was in main
						draw_shape(5, 5, 36, &canon, &map);
						draw_shape_180(65, 95, 36, &canon, &map);
						draw_shape(40, 15, 48, &galaxy, &map);
						draw_shape(5, 80, 28, &cross, &map); 
	        }
					else if(ch == 53)
					{ // beacon
						draw_shape(1, 1, 3, &angle3, &map);
						draw_shape_180(3, 4, 3, &angle3, &map);
					}
	        setTicker(20);
	    }
	printw("please Press number 1-5 from keboard to choose the map");


  refresh();			// refresh it on to the real screen
  mvaddch(10,10,'X');
  refresh();			// print the map on the real screen


  enditall();
   usleep(1000000/freq); // wait for 1/freq seconds
}
