#include "lifegame.h"

void lifeFieldUpdate (unsigned int(&field)[fieldSize][fieldSize])
{
    unsigned int fieldCopy[fieldSize][fieldSize];

    for (int i=0; i<fieldSize; i++)
    {
        for (int j=0; j<fieldSize; j++)
        {
            fieldCopy[i][j]=field[i][j];
        }
    }


    for (int i=0; i<fieldSize; i++)
    {
        for (int j=0; j<fieldSize; j++)
        {
            int neighbourSum = 0;
            if (i==0)                                   //periodic boundary conditions handling and computation of number of alive neighbours
            {
                if (j==0)
                {
                    neighbourSum = fieldCopy[fieldSize-1][j]+fieldCopy[i+1][j]+fieldCopy[fieldSize-1][fieldSize-1]+fieldCopy[i+1][fieldSize-1]+fieldCopy[fieldSize-1][j+1]+fieldCopy[i+1][j+1]+fieldCopy[i][fieldSize-1]+fieldCopy[i][j+1];
                }
                else if (j==fieldSize-1)
                {
                    neighbourSum = fieldCopy[fieldSize-1][j]+fieldCopy[i+1][j]+fieldCopy[fieldSize-1][j-1]+fieldCopy[i+1][j-1]+fieldCopy[fieldSize-1][0]+fieldCopy[i+1][0]+fieldCopy[i][j-1]+fieldCopy[i][0];
                }
                else
                {
                    neighbourSum = fieldCopy[fieldSize-1][j]+fieldCopy[i+1][j]+fieldCopy[fieldSize-1][j-1]+fieldCopy[i+1][j-1]+fieldCopy[fieldSize-1][j+1]+fieldCopy[i+1][j+1]+fieldCopy[i][j-1]+fieldCopy[i][j+1];
                }
            }
            else if (i==fieldSize-1)
            {
                if (j==0)
                {
                    neighbourSum = fieldCopy[i-1][j]+fieldCopy[0][j]+fieldCopy[i-1][fieldSize-1]+fieldCopy[0][fieldSize-1]+fieldCopy[i-1][j+1]+fieldCopy[0][j+1]+fieldCopy[i][fieldSize-1]+fieldCopy[i][j+1];
                }
                else if (j==fieldSize-1)
                {
                    neighbourSum = fieldCopy[i-1][j]+fieldCopy[0][j]+fieldCopy[i-1][j-1]+fieldCopy[0][j-1]+fieldCopy[i-1][0]+fieldCopy[0][0]+fieldCopy[i][j-1]+fieldCopy[i][0];
                }
                else
                {
                  neighbourSum = fieldCopy[i-1][j]+fieldCopy[0][j]+fieldCopy[i-1][j-1]+fieldCopy[0][j-1]+fieldCopy[i-1][j+1]+fieldCopy[0][j+1]+fieldCopy[i][j-1]+fieldCopy[i][j+1];
                }
            }
            else if (j==0)
            {
            neighbourSum = fieldCopy[i-1][j]+fieldCopy[i+1][j]+fieldCopy[i-1][fieldSize-1]+fieldCopy[i+1][fieldSize-1]+fieldCopy[i-1][j+1]+fieldCopy[i+1][j+1]+fieldCopy[i][fieldSize-1]+fieldCopy[i][j+1];
            }
            else if (j==fieldSize-1)
            {
            neighbourSum = fieldCopy[i-1][j]+fieldCopy[i+1][j]+fieldCopy[i-1][j-1]+fieldCopy[i+1][j-1]+fieldCopy[i-1][0]+fieldCopy[i+1][0]+fieldCopy[i][j-1]+fieldCopy[i][0];
            }
            else
            {
              neighbourSum = fieldCopy[i-1][j]+fieldCopy[i+1][j]+fieldCopy[i-1][j-1]+fieldCopy[i+1][j-1]+fieldCopy[i-1][j+1]+fieldCopy[i+1][j+1]+fieldCopy[i][j-1]+fieldCopy[i][j+1];
            }


            switch (neighbourSum)
            {
              case 2:;
                break;
              case 3:
                if (fieldCopy[i][j]==0)
                {
                    field[i][j] = 1;
                }
                break;
              default: field[i][j] = 0;
                break;
             }

            }
        }
}

