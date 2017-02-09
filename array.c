#include"array.h"

void at(int **world)
{
    int x, y;
    printf("Write x and y of the position you want to check :");
    scanf("%d", &x);
    scanf("%d", &y);
    if(world[x][y] == 1)
        printf("The position is alive(1)");
    else
        printf("The position is dead(0)");
    getch();
}

void insert(int **world)
{
    int x, y, new_elem;
    printf("Write position x, position y and the new element(0 or 1) :\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &new_elem);
    world[x][y] = new_elem;
}

void resizeMatrix(int ***world, int ***world2, int *row, int *col)
{
    int **temp;
    int i, j, newrow, newcol;

    printf("Write new dimensions : \n");
    scanf("%d %d", &newrow, &newcol);
    createMatrix(newrow, newcol, &temp);
    deleteMatrix(world2, *row);
    *world2 = temp;

    createMatrix(newrow, newcol, &temp);
    for(i = 0; i <(*row < newrow ? *row : newrow) ; i++)
        for(j = 0; j <(*col < newcol ? *col : newcol); j++)
            temp[i][j] =(*world)[i][j];
    deleteMatrix(world, *row);

    *world = temp;
    *row = newrow;
    *col = newcol;
}

void createMatrix(int row, int col, int ***world)
{
    int i, j;
    int ** tab = NULL;

    tab = (int**)malloc(row * sizeof(*tab));
    if(tab == NULL)
       printf("Memory Error");
    for(i=0; i < row; i++)
    {
        tab[i] =(int*)malloc(col * sizeof(**tab));
        if(tab[i] == NULL)
            printf("Memory Error");
    }

    for(i=0; i < row; i++)
        for(j=0; j < col; j++)
            tab[i][j] = 0;
    *world=tab;
}

void lodData(int **world)
{
    FILE * data;
    if((data = fopen("danewej.txt", "r")) == NULL)
        printf("I can't open the file");
    int x, y;
    while(fscanf(data, "%d", &x) != EOF)
    {
        fscanf(data, "%d", &y);
        world[x][y] = 1;
    }
    fclose(data);
}

void saveResult(int **world, int row, int col)
{
    int i, j;
    FILE * data;
    data = fopen("danewyj.txt", "a");
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            if(world[i][j] == 1)
                fprintf(data, "%d %d \n", i, j);
    fclose(data);
}

void showWorld(int ** world, int row, int col)
{
    int i, j;


    for(i=0; i < row; i++)
    {
        if(i > 0)
            printf("\n");
        for(j = 0; j < col; j++)
            printf(" %d", world[i][j]);
    }
}

void deleteMatrix(int ***world, int row)
{
    int i;
    for(i = 0; i < row; i++)
    {
        free((*world)[i]);
       (*world)[i] = NULL;
    }
    free(*world);
    *world = NULL;
}

