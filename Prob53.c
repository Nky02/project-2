/*THis program calculates and determines a  student's grade by reading three test scores
  Written by: Nicky Shane Estrada
  Date: November 22, 2023*/

#include <stdio.h>
// function declaration
double scoreInput(double score1, double score2, double score3);
char calcGrade(double score1, double score2, double score3);
void printRes(char calcGrade);

int main()
{
  // local declarartion
  double score1, score2, score3, average;
  char grade;

  // input
  scoreInput(score1, score2, score3);

  // process
  grade = calcGrade(score1, score2, score3);

  // Output
  printRes(calcGrade);

  return 0;
}

double scoreInput(double score1, double score2, double score3)
{
  double score1, score2, score3, scoreInput;

  printf("Enter three test score separated by spaces(1-100): ");
  scanf("%lf %lf %lf", &score1, &score2, score3);

  return score1, score2, score3;
}

char calcGrade(double score1, double score2, double score3)
{
  double score1, score2, score3, totalScore, calcAverage, average;
  char grade;

  totalScore = score1 + score2 + score3;
  calcAverage = (totalScore / 3) / 100;
  average = calcAverage * 100;

  if (average >= 0.90)
  {
    grade = 'A';
  }

  else if (average >= 70 && average < 90)
  {
    if (score3 > 90)
    {
      grade = 'A';
    }
    else
    {
      grade = 'B';
    }
  }
  else if (average >= 50 && average < 70)
  {
  }

  return grade;
}

/* if (average >= 90) {
        return 'A';
    } else if (average >= 70) {
        if (thirdScore > 90) {
            return 'A';
        } else {
            return 'B';
        }
    } else if (average >= 50) {
        float avgSecondThird = (secondScore + thirdScore) / 2;
        if (avgSecondThird >= 70) {
            return 'C';
        } else {
            return 'D';
        }
    } else {
        return 'F';
    }
}
*/