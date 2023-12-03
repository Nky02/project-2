/*THis program calculates the parking fare for the
    customers who park their cars in a parking lot
  Written by: Nicky Shane Estrada
  Date: November 25, 2023*/

#include <stdio.h>

void getInfo(char *vehType, int *hrTimeIn, int *minTimeIn, int *hrTimeOut, int *minTimeOut);
void calcParkingTime(char vehType, int hrTimeIn, int minTimeIn, int hrTimeOut, int minTimeOut, int *hoursParked, int *minutesParked, int *parkedTime);
float calcParkingFare(char vehType, int parkedTime);
void printCharge(char vehType, int hrTimeIn, int minTimeIn, int hrTimeOut, int minTimeOut, int hoursParked, int minutesParked, float fare);

int main()
{
  // local declaration
  int hrTimeIn, hrTimeOut, minTimeIn, minTimeOut, parkedTime, hoursParked, minutesParked;
  float fare;
  char vehType;

  // input
  getInfo(&vehType, &hrTimeIn, &minTimeIn, &hrTimeOut, &minTimeOut);

  // process
  calcParkingTime(vehType, hrTimeIn, minTimeIn, hrTimeOut, minTimeOut, &hoursParked, &minutesParked, &parkedTime);

  fare = calcParkingFare(vehType, parkedTime);

  // output
  printCharge(vehType, hrTimeIn, minTimeIn, hrTimeOut, minTimeOut, hoursParked, minutesParked, fare);

  return 0;
}

void getInfo(char *vehType, int *hrTimeIn, int *minTimeIn, int *hrTimeOut, int *minTimeOut)
{
  printf("To ensure a seamless parking experience, please provide the following details: \n\n");
  printf("Type of Vehicle            (car(C), bus(B), truck(T))?: \n");
  scanf(" %c", vehType); // Added a space before %c to consume the newline character.
  printf("Hour vehicle entered lot   (0-24)?\n");
  scanf("%d", hrTimeIn);
  printf("Minute vehicle entered lot (0-60)?\n");
  scanf("%d", minTimeIn);
  printf("Hour vehicle left lot      (0-24)?\n");
  scanf("%d", hrTimeOut);
  printf("Minute left entered lot    (0-60)?\n");
  scanf("%d", minTimeOut);
}

void calcParkingTime(char vehType, int hrTimeIn, int minTimeIn, int hrTimeOut, int minTimeOut, int *hoursParked, int *minutesParked, int *parkedTime)
{
  if (minTimeIn > minTimeOut)
  {
    minTimeOut += 60;
    hrTimeOut -= 1;
  }

  *hoursParked = hrTimeOut - hrTimeIn;
  *minutesParked = minTimeOut - minTimeIn;

  if (*minutesParked < 0)
  {
    *minutesParked += 60;
    (*hoursParked)--;
  }

  *parkedTime = *hoursParked * 60 + *minutesParked;
}

float calcParkingFare(char vehType, int parkedTime)
{
  float fare;

  switch (vehType)
  {
  case 'C':
    if (parkedTime < 180) // 3 hours in minutes
    {
      fare = 0.00;
    }
    else
    {
      fare = parkedTime * 1.50;
    }
    break;

  case 'T':

    if (parkedTime < 120) // 2 hours in minutes
    {
      fare = 1.00;
    }
    else
    {
      fare = parkedTime * 2.30;
    }
    break;

  case 'B':

    if (parkedTime < 60) // 1 hour in minutes
    {
      fare = 2.00;
    }
    else
    {
      fare = parkedTime * 3.70;
    }
    break;

  default:
    printf("Invalid vehicle type.\n");
    fare = 0.0; // for invalid INPUT
  }

  return fare;
}

void printCharge(char vehType, int hrTimeIn, int minTimeIn, int hrTimeOut, int minTimeOut, int hoursParked, int minutesParked, float fare)
{
  printf("\t\tPARKING LOT CHARGE\t\t\n");
  printf("\nType of vehicle: %c", vehType);
  printf("\nTIME-IN:               %d : %d", hrTimeIn, minTimeIn);
  printf("\nTIME-out:              %d : %d", hrTimeOut, minTimeOut);
  printf("\n                      --------");
  printf("\nPARKING TIME           %.2d:%.2d", hoursParked, minutesParked);
  printf("\nROUNDED TOTAL            %d", hoursParked);
  printf("\n                      --------");
  printf("\nTOTAL CHARGE             $%.2f", fare);
  printf("\n");
}
