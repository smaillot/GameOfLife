//
//  Adapted_law.c
//
//
//  Created by Théo Desquins on 04/10/2017.
//
// Coder 3

#include <stdio.h>
#include <stdbool.h>

const int rows=3;
const int cols=3;

bool world[rows][cols] = {false}; // need a malloc
bool new_world[rows][cols] = {false};

int neighboor_count (bool matrix[rows][cols], int x, int y);
void actualize_State (bool matrix[rows][cols], bool new_matrix[rows][cols], int x, int y, int num_live);

int main(void)
{
    world[1][0] = true;
    world[0][1] = true;
    
    world[2][2] = true;
    world[1][1] = true;
    
    new_world[1][0] = true;
    new_world[0][1] = true;
    new_world[2][2] = true;
    new_world[1][1] = true;
    // We fill the map with the cells and their properties
    int numl= neighboor_count (world, 1, 1);
    actualize_State (world, new_world, 1, 1, numl);
    
    printf("\n");
    printf("\n");
    printf("And now the result:\n");
    printf("%d %d %d \n",new_world[0][0],new_world[0][1],new_world[0][2]);
    printf("%d %d %d \n",new_world[1][0],new_world[1][1],new_world[1][2]);
    printf("%d %d %d \n",new_world[2][0],new_world[2][1],new_world[2][2]);
    printf("\n");
    printf("\n");
    return 0;
}

// Then for each cell we apply the following law
int neighboor_count (bool matrix[rows][cols], int x, int y) {
    int num_live=0;
    for (int k=-1; k<2; k++ )
    {
        for (int j=-1; j<2; j++)
        {
            if (j==0 && k==0){
            }
            else {
                if (matrix[y+k][x+j])
                {
                    num_live++;
                }
            }
        }
    }
    return num_live;
}

void actualize_State (bool matrix[rows][cols], bool new_matrix[rows][cols], int x, int y, int num_live) {
    bool st_cell=matrix[x][y];
    if (st_cell && num_live<=3 && num_live>=2)
    {
        new_matrix[x][y]=true;
        matrix[x][y]=true;
    }
    else if (st_cell && (num_live>3 || num_live<2))
    {
        new_matrix[x][y]=false;
        matrix[x][y]=false;
    }
    else if (!st_cell && num_live==3)
    {
        new_matrix[x][y]=true;
        matrix[x][y]=true;
    }
};

