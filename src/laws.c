#include <stdio.h>
#include <ncurses.h>

#include "conway.h"

int count_neighbors (struct Cell *c, struct Map *m) {
	// coder 2

    int num_live=0;
    int x=c->x;
    int y=c->y;
    
    for (int k=-1; k<2; k++ )
    {
        for (int j=-1; j<2; j++)
        {
            if (j==0 && k==0){
            }
            else {
                if (m->world[x+k][y+j])
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
	//coder 2
	bool alive = c->alive;
	int num_live = count_neighbors(c, m);

	return compute_next_state(alive, num_live);
}