#include <windows.h>
#include "game.h"

int main()
{
    int **world = NULL, **world2 = NULL;
    int number;
    int row = 10, col = 10;
    int i = 0;

    createMatrix(row, col, &world);
    createMatrix(row, col, &world2);
    lodData(world);

    while(1)
    {
        printf("Created world %d x %d : \n", row, col);
        showWorld(world, row, col);
        printf("\nIf you want to resize world, press 1\n"
                "If you want to insert new element, press 2\n"
                "If you want to check specified position, press 3\n"
                "If you want to start the game, press 4\n"
                "During the game, you can exit by clicking k\n");

        if((scanf("%d", &number)) == 1)
            switch(number)
            {
                case 1 : resizeMatrix(&world, &world2, &row, &col);
                break;
                case 2 : insert(world);
                break;
                case 3 : at(world);
                break;
                case 4 : goto Jump;
                default: printf("Enter other number\n");
            }
            system("cls");
    }

    Jump:
    system("cls");
    printf("World at the beginning :\n");
    showWorld(world, row, col);
    Sleep(4000);

    while(1)
    {
        system("cls");
        if(kbhit())
        {
            int button;
            button = getch();
            if(button == 'k' || button == 'K')
                break;
        }
        printf(" Day %d\n", i++);
        play(row, col, &world, &world2);
        Sleep(200);
    }
    printf("World in the end :\n");
    showWorld(world, row, col);
    saveResult(world, row, col);
    deleteMatrix(&world, row);

    return 0;
}



