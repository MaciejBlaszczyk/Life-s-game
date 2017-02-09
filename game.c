#include"game.h"


int countNeighbours(int row, int col, int posx ,int posy , int ** world)
{
    int counter, x, y;
    counter = 0;
    for(x = -1; x < 2; x++)
        for(y = -1; y < 2; y++)
            if(x != 0 || y != 0)
                if(posx + x >= 0 && posy + y >= 0 && posx + x < row && posy + y < col)
                    if(world[posx + x][posy + y] == 1)
                        counter++;
    return counter;
}

void play(int row, int col, int ***world, int ***world2)
{
    int i, j, quantity;
    int **temp = NULL;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
        {
            quantity = countNeighbours(row, col, i, j, *world);
            if((*world)[i][j] == 1)
            {
                if(quantity == 2 || quantity == 3)
                   (*world2)[i][j] = 1;
                else
                   (*world2)[i][j] = 0;
            }
            if((*world)[i][j] == 0)
            {
                if(quantity == 3)
                   (*world2)[i][j] = 1;
                else
                   (*world2)[i][j] = 0;
            }
        }
    showWorld(*world, row, col);
    printf("\n");
    temp = *world;
    *world = *world2;
    *world2 = temp;
}

