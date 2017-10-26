#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int count_neighbors (struct Cell *c, struct Map *m) {
	// coder 2
    // Count the number of neighbors of a given cell
    
    // This function take the adresses of a cell and its current map.
    // It extract the coordinates x and y of the cell and check line by line
    // if one of his neighboor is live or dead.

    int num_live=0;
    int x=c->x;
    int y=c->y;
    
    for (int k=-1; k<2; k++ )
    {
        for (int j=-1; j<2; j++)
        {
            if (j==0 && k==0){
            } // This condition is here to avoid to take the life of the cell studied into account
            else {
                if (m->world[x+k][y+j])
                    // the map has 2 possible values in one position True or False,
                    // here it is equivalent to write if (True)
                {
                    num_live++;
                }
            }
        }
    }
    return num_live;
}

bool compute_next_state (bool alive, int num_live) {
	//coder 2
    // Given the current state and the # of neighbors of a cell, apply the rules to compute the next step

    // The rules only need to now if a cell is alive or not and its number of neighbor
	bool state;
    if (alive && num_live<=3 && num_live>=2)
    {
        state=true;        
    }
    else if (alive && (num_live>3 || num_live<2))
             {
                 state=false;
             }
    else if (!alive && num_live==3)
             {
                 state=true;
             }
    return state;
}

bool get_next_state (struct Cell *c, struct Map *m)
{
	// coder 2
    // Return the next state given the cell structure and the current world map
    
	bool alive = c->alive;
	int num_live = count_neighbors(c, m);

	return compute_next_state(alive, num_live);
}