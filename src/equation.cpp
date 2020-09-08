#include <cmath>
#include <assert.h>
#include <float.h>

#include "equation.h"

char solveUpToQuadraticEquation(double a,
                                double b,
                                double c,
                                double *x1,
                                double *x2,
                                double epsilon = 2 * DBL_EPSILON) {

  if (!isZero(a, epsilon)) {
    return solveQuadraticEquation(a, b, c, x1, x2, epsilon);
  }

  if (!isZero(b, epsilon)) {
    char nRoots = solveLinearEquation(b, c, x1, epsilon);
    *x2 = *x1;
    return nRoots;
  }

  if (!isZero(c, epsilon)) {
    return 0;
  }

  return INF_ROOTS;
}

char solveQuadraticEquation(double a, double b, double c, double *x1, double *x2, double epsilon = 2 * DBL_EPSILON) {
  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  double discriminant = calculateDiscriminant(a, b, c);

  if (isZero(discriminant, epsilon)) {
    *x1 = calculateParabolaXVertex(a, b);
    *x2 = *x1;
    return 1;
  }

  if (discriminant < 0) {
    return 0;
  }

  double sqrtDiscriminant = sqrt(discriminant);
  *x1 = (-b - sqrtDiscriminant) / (2 * a);
  *x2 = (-b + sqrtDiscriminant) / (2 * a);
  return 2;
}

char solveLinearEquation(double a, double b, double *x, double epsilon = 2 * DBL_EPSILON) {
  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  double root = -b / a;
  *x = root;

  return 1;
}

double calculateDiscriminant(double a, double b, double c) {
  return pow(b, 2) - (4 * a * c);
}

double calculateParabolaXVertex(double a, double b) {
  assert(a != 0);

  return -b / (2 * a);
}

bool isZero(double value, double epsilon = 2 * DBL_EPSILON) {
  return fabs(value) < epsilon;
}
