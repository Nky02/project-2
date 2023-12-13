/*This program displays the digits 1, 2, 3, 4, 5 in a right triangle format using for loop
    Written by: Nicky Shane EStrada
    Date: December 13, 2023*/

#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d", j);
        }

        printf("\n");
    }

    return 0;
}
