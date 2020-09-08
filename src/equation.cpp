#include <cmath>
#include <assert.h>
#include <float.h>

#include "equation.h"

char solveUpToQuadraticEquation(double a,
                                double b,
                                double c,
                                double *roots,
                                double epsilon = 2 * DBL_EPSILON) {

  assert(roots != nullptr);
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(c));

  if (!isZero(a, epsilon)) {
    return solveQuadraticEquation(a, b, c, roots, epsilon);
  }

  if (!isZero(b, epsilon)) {
    return solveLinearEquation(b, c, roots, epsilon);
  }

  if (!isZero(c, epsilon)) {
    return 0;
  }

  return INF_ROOTS;
}

char solveQuadraticEquation(double a, double b, double c, double *roots, double epsilon = 2 * DBL_EPSILON) {
  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  double discriminant = calculateDiscriminant(a, b, c);

  if (isZero(discriminant, epsilon)) {
    roots[0] = calculateParabolaXVertex(a, b);
    return 1;
  }

  if (discriminant < 0) {
    return 0;
  }

  double sqrtDiscriminant = sqrt(discriminant);
  roots[0] = (-b - sqrtDiscriminant) / (2 * a);
  roots[1] = (-b + sqrtDiscriminant) / (2 * a);
  return 2;
}

char solveLinearEquation(double a, double b, double *roots, double epsilon = 2 * DBL_EPSILON) {
  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  roots[0] = -b / a;
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
