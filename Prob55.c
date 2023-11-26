/*THis program determines a quadrant given a user-input angle
  Written by: Nicky Shane Estrada
  Date: November 22, 2023*/

#include <stdio.h>

void getAngle(double *angle);
const char *validateAngle(double angle);

int main()
{
    // local declaration
    double angle;
    const char *quadrantNum;

    // function calls
    getAngle(&angle);

    quadrantNum = validateAngle(angle);

    // output
    if (quadrantNum != NULL)
    {
        printf("The given angle is in  %s\n", quadrantNum);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}

void getAngle(double *angle)
{
    // user-input angle
    printf("Give an angle: ");
    scanf("%lf", angle);
}

const char *validateAngle(double givenAngle)
{
    const char *quadrantNum;

    if (givenAngle == 0)
    {
        quadrantNum = "Positive X-axis";
    }
    else if (givenAngle == 90)
    {
        quadrantNum = "Positive Y-axis";
    }
    else if (givenAngle == 180)
    {
        quadrantNum = "Negative X-axis";
    }
    else if (givenAngle == 270)
    {
        quadrantNum = "Negative Y-axis";
    }
    else if (givenAngle > 0 && givenAngle < 90)
    {
        quadrantNum = "quadrant number I";
    }
    else if (givenAngle > 90 && givenAngle < 180)
    {
        quadrantNum = "quadrant number II";
    }
    else if (givenAngle > 180 && givenAngle < 270)
    {
        quadrantNum = "quadrant number III";
    }
    else if (givenAngle > 270 && givenAngle < 360)
    {
        quadrantNum = "quadrant number IV";
    }
    else
    {
        quadrantNum = "Invalid";
    }

    return quadrantNum;
}
