#include <cstdio>
#include <math.h>

#include "equation.h"
#define NUMBER_OF_COEFFICIENTS 3


static bool readInput(double *a, double *b, double *c) {
  printf("Enter coefficients (a, b, c) to the equation ax^2 + bx + c = 0:\n");
  return scanf("%lf %lf %lf", a, b, c) == NUMBER_OF_COEFFICIENTS;
}

static void outputRoots(char nRoots, double *roots) {
  if(nRoots == INVALID_ARGUMENTS){
    printf("Invalid arguments provided\n");

  }else if(nRoots == FAILURE){
    printf("Computation failure. Probably caused by double overflow\n");

  }else if (nRoots == INF_ROOTS) {
    printf("Number of roots is infinite\n");

  } else {
    printf("Number of roots : %d\n", nRoots);

    if (nRoots > 0) {
      printf("They are : ");
      for (int i = 0; i < nRoots; ++i) {
        printf("%.3f; ", roots[i]);
      }
    }
  }
}

int main() {
  double a = NAN;
  double b = NAN;
  double c = NAN;

  if (!readInput(&a, &b, &c)) {
    fprintf(stderr, "Incorrect input\n");
    return -1;
  }

  double roots[2] = {};
  char nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  outputRoots(nRoots, roots);
  return 0;
}