/*This program displays the digits 10, 20, 30, ..., 100  using for loop
    Written by: Nicky Shane EStrada
    Date: December 13, 2023*/

#include <stdio.h>

int main()
{
    for (int i = 10; i <= 100; i += 10)
    {
        printf("%d\n", i);
    }

    return 0;
}