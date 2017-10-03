//
//  part_of_homework.c
//  
//
//  Created by Théo Desquins on 03/10/2017.
//
//

#include <stdio.h>

struct cell {
    int alive;
    int position_x;
    int position_y;
};

struct grid {
    struct cell cell;
};

int row=3;
int column=3;


int laws (struct cell *c, struct grid m[row][column]);
             

int main(void)
{
    
    struct cell c1;
    c1.alive=1;
    c1.position_x=0;
    c1.position_y=0;
    
    struct cell c2;
    c2.alive=0;
    c2.position_x=0;
    c2.position_y=1;
    
    struct cell c3;
    c3.alive=0;
    c3.position_x=0;
    c3.position_y=2;
    
    struct cell c4;
    c4.alive=0;
    c4.position_x=1;
    c4.position_y=0;
    
    struct cell c5;
    c5.alive=1;
    c5.position_x=1;
    c5.position_y=1;
    
    struct cell c6;
    c6.alive=1;
    c6.position_x=1;
    c6.position_y=2;
    
    struct cell c7;
    c7.alive=0;
    c7.position_x=2;
    c7.position_y=0;
    
    struct cell c8;
    c8.alive=1;
    c8.position_x=2;
    c8.position_y=1;
    
    struct cell c9;
    c9.alive=0;
    c9.position_x=2;
    c9.position_y=2;
    
    struct grid map[3][3];
    map[0][0].cell=c1;
    map[0][1].cell=c2;
    map[0][2].cell=c3;
    map[1][0].cell=c4;
    map[1][1].cell=c5;
    map[1][2].cell=c6;
    map[2][0].cell=c7;
    map[2][1].cell=c8;
    map[2][2].cell=c9;
    
//    printf("%d",map[0][0].alive);
  //  printf("%d",map[0][0].position_x);
//    printf("%d",map[0][0].position_y);
  //  printf("%d",map[0][1].alive);
//    printf("%d\n",map[0][1].cell.position_x);
  //  printf("%d\n",map[0][1].cell.position_y);
    //printf("Everything goes fine till now\n");
    
    
    // We fill the map with the cells and their properties
    laws (&c5, map);
    printf("\n");
    printf("\n");
    printf("%d",c5.alive);
    printf("\n");
    printf("\n");
    return 0;
}

// Then for each cell we apply the following law
int laws (struct cell *c, struct grid m[row][column]) {
    int num_live=0;
    int x=(*c).position_x;
    int y=(*c).position_y;
    for (int k=-1; k<2; k++ )
    {
        for (int j=-1; j<2; j++)
        {
            if (j==0 && k==0){
            }
            else {
                if (m[y+k][x+j].cell.alive==1)
                {
                    num_live++;
                    printf("\n");
                    printf("%d", num_live);
                    printf("\n");
                }
            }
        }
    }
    if (c->alive==1 && num_live<=3 && num_live>=2)
    {
        c->alive=1;
        printf("\n");
        printf("Ha ! Ha ! Ha ! Ha ! Stayin'alive Stayin'alive ");
        
    }
    else if (c->alive==1 && (num_live>3 || num_live<2))
             {
                 c->alive=0;
                 printf("\n");
                 printf("I'll be back.");
             }
    else if (c->alive==0 && num_live==3)
             {
                 c->alive=1;
                 printf("\n");
                 printf("I live !");
             }
    return 0;
};


