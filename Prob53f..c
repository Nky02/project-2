/* This program calculates and determines a student's grade by reading three test scores
   Written by: Nicky Shane Estrada
   Date: November 22, 2023*/

#include <stdio.h>

// function declaration
void scoreInput(double *score1, double *score2, double *score3);
char calcGrade(double score1, double score2, double score3);
void printRes(char grade);

int main()
{
  // local declaration
  double score1, score2, score3;
  char grade;

  // input
  scoreInput(&score1, &score2, &score3);

  // process
  grade = calcGrade(score1, score2, score3);

  // Output
  printRes(grade);

  return 0;
}

// function definition of input
void scoreInput(double *score1, double *score2, double *score3)
{
  printf("Enter three test scores separated by spaces (1-100): ");
  scanf("%lf %lf %lf", score1, score2, score3);
}

// function definition of calculation and process
char calcGrade(double score1, double score2, double score3)
{
  double totalScore = score1 + score2 + score3;
  double average = totalScore / 3;
  char grade;

  if (average >= 90)
    grade = 'A';
  else if (average >= 70 && average < 90)
  {
    if (score3 > 90)
      grade = 'A';
    else
      grade = 'B';
  }
  else if (average >= 50 && average < 70)
  {
    double avgScore2andScore3 = (score2 + score3) / 2;
    if (avgScore2andScore3 > 70)
      grade = 'C';
    else
      grade = 'D';
  }
  else if (average < 50)
    grade = 'F';

  return grade;
}

// function definition of  Output
void printRes(char grade)
{
  printf("The student's grade based on the three test scores is %c\n", grade);
}
