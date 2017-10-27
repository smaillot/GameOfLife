#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

/*
	This file contains all function related to draw specific patterns on the map structure.
	Unless the actuel world is of size (ROWS+2, COLS+2) and the starting position is (0,0)
	We consider edges as dead cells used to compute neighborhood of inside ones.

	/!\ Important
	Though the only drawable cells grid is starting from (1,1) with size (ROWS,COLS) [from conway.h]
	Do not attempt to draw outside this area.
*/

void draw_cell(int x, int y, struct Map* m)
{
	// coder 1
	// Set the (x,y) Cell

	m->world[x][y] = true;
}

void draw_shape(int x, int y, int n, struct Point* shape, struct Map* m)
{
	// coder 1
	// Draw a specific shape given by an array of Point structures

	for (int i=0; i < n; i++)
	{
		m->world[x+shape[i].x][y+shape[i].y] = true;
	}
}

void draw_shape_180(int x, int y, int n, struct Point* shape, struct Map* m)
{
	// coder 1
	// Draw a specific shape rotated by 180 degrees

	for (int i=0; i < n; i++)
	{
		m->world[x-shape[i].x][y-shape[i].y] = true;
	}
}

void draw_shape_flip_h(int x, int y, int n, struct Point* shape, struct Map* m)
{
	// coder 1
	// Draw a specific shape flipped horizontally 

	for (int i=0; i < n; i++)
	{
		m->world[x+shape[i].x][y-shape[i].y] = true;
	}
}

void draw_shape_flip_v(int x, int y, int n, struct Point* shape, struct Map* m)
{
	// coder 1
	// Draw a specific shape flipped vertically 

	for (int i=0; i < n; i++)
	{
		m->world[x-shape[i].x][y+shape[i].y] = true;
	}
}


// Shapes

	// basics
	struct Point onepoint[1] =  {{0,0}};
	struct Point twopoints[2] =  {{0,0}, {0,1}};
	struct Point angle3[3] = {{0,0}, {0,1}, {1,0}};


	// Oscillators
	struct Point blinker[3] = {{0,0}, {0,1}, {0,2}};
	struct Point oscillator[28] = {{0, 6}, {1, 6}, {2, 4}, {2, 5}, {2, 7}, {2, 8}, {4, 2}, {4, 4}, {4, 8}, {4, 10}, {5, 2}, {5, 10}, {6, 0}, {6, 1}, {6, 11}, {6, 12}, {7, 2}, {7, 10}, {8, 2}, {8, 4}, {8, 8}, {8, 10}, {10, 4}, {10, 5}, {10, 7}, {10, 8}, {11, 6}, {12, 6}};
	struct Point cross[28] = {{0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 5}, {2, 0}, {2, 1}, {2, 2}, {2, 5}, {2, 6}, {2, 7}, {3, 0}, {3, 7}, {4, 0}, {4, 7}, {5, 0}, {5, 1}, {5, 2}, {5, 5}, {5, 6}, {5, 7}, {6, 2}, {6, 5}, {7, 2}, {7, 3}, {7, 4}, {7, 5}};
	struct Point galaxy[48] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {7, 7}, {8, 7}, {3, 8}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, };
	struct Point pulsar[14] = {{0, 4}, {1, 4}, {2, 4}, {2, 5}, {4, 0}, {4, 1}, {4, 2}, {4, 5}, {4, 6}, {5, 2}, {5, 4}, {5, 6}, {6, 4}, {6, 5}};

	// Canons
	struct Point canon[36] = {{4, 0}, {4, 1}, {5, 0}, {5, 1}, {2, 13}, {2, 12}, {3, 11}, {4, 10}, {5, 10}, {6, 10}, {7, 11}, {8, 12}, {8, 13}, {5, 14}, {3, 15}, {4, 16}, {5, 16}, {6, 16}, {5, 17}, {2, 20}, {2, 21}, {3, 20}, {3, 21}, {4, 20}, {4, 21}, {1, 22}, {5, 22}, {0, 24}, {1, 24}, {5, 24}, {6, 24}, {2, 34}, {2, 35}, {3, 34}, {3, 35}};

	// Challenge
	struct Point pentomino[5] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}, {2, 1}};
	struct Point diehard[7] = {{1, 0}, {1, 1}, {2, 1}, {0, 6}, {2, 5}, {2, 6}, {2, 7}};
	struct Point acorn[7] = {{0, 1}, {2, 0}, {2, 1}, {1, 3}, {2, 4}, {2, 5}, {2, 6}};