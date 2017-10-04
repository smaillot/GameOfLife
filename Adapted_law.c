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


void laws (bool matrix[rows][cols], int x, int y);

int main(void)
{
    world[1][0] = true;
    world[0][1] = true;
    world[1][2] = true;
    world[2][2] = true;
    world[1][1] = true;
    // We fill the map with the cells and their properties
    laws (world, 1, 1);
    printf("\n");
    printf("\n");
    printf("And now the result:\n");
    printf("%d %d %d \n",world[0][0],world[0][1],world[0][2]);
    printf("%d %d %d \n",world[1][0],world[1][1],world[1][2]);
    printf("%d %d %d \n",world[2][0],world[2][1],world[2][2]);
    printf("\n");
    printf("\n");
    return 0;
}

// Then for each cell we apply the following law
void laws (bool matrix[rows][cols], int x, int y) {
    int num_live=0;
    bool st_cell=matrix[x][y];
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
                    printf("\n");
                    printf("%d", num_live);
                    printf("\n");
                }
            }
        }
    }
    if (st_cell && num_live<=3 && num_live>=2)
    {
        matrix[x][y]=true;
        printf("\n");
        printf("Ha ! Ha ! Ha ! Ha ! Stayin'alive Stayin'alive ");
        
    }
    else if (st_cell && (num_live>3 || num_live<2))
    {
        matrix[x][y]=false;
        printf("\n");
        printf("I'll be back.");
    }
    else if (!st_cell && num_live==3)
    {
        matrix[x][y]=true;
        printf("\n");
        printf("I live !");
    }
};


