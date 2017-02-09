#ifndef GAMEMATRIX
#define GAMEMATRIX

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void createMatrix(int, int, int ***);
void lodData(int **);
void saveResult(int **, int, int);
void showWorld(int **, int, int);
void deleteMatrix(int ***, int);
void resizeMatrix(int ***, int ***, int *, int *);
void insert(int **);
void at(int **);

#endif // GAMEMATRIX
