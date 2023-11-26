/* This program computes the real roots of a quadratic equation
   Written by: Nicky Shane Estrada
   Date: November 25, 2023*/

#include <stdio.h>
#include <math.h>

void getConstants(int *a, int *b, int *c);
void calcRoots(int a, int b, int c);

int main()
{
    int a, b, c;

    // Input
    getConstants(&a, &b, &c);

    // Process and Output
    calcRoots(a, b, c);

    return 0;
}

void getConstants(int *a, int *b, int *c)
{
    printf("\nEnter the value of constant (a):  ");
    scanf("%d", a);

    printf("\nEnter the value of  constant (b): ");
    scanf("%d", b);

    printf("\nEnter the value of  constant (c): ");
    scanf("%d", c);
}

void calcRoots(int a, int b, int c)
{
    float root1, root2;
    double d;

    if (a == 0 && b == 0)
    {
        printf("There is no solution.\n");
    }
    else if (a == 0)
    {
        root1 = (float)-c / b;
        printf("The root of the equation is %.2f\n", root1);
    }
    else
    {
        d = b * b - (4 * a * c);

        if (d < 0)
        {
            printf("There are no real roots.\n");
        }
        else
        {
            root1 = (-b + sqrt(d)) / (2 * a);
            root2 = (-b - sqrt(d)) / (2 * a);

            printf("The two roots of the equation are %.2f and %.2f\n", root1, root2);
        }
    }
}
