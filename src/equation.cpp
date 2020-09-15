#include <assert.h>
#include <cmath>

#include "equation.h"

char solveUpToQuadraticEquation(double a, double b, double c, double *roots,
                                double epsilon) {

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

char solveQuadraticEquation(double a, double b, double c, double *roots,
                            double epsilon) {
  assert(roots != nullptr);
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(c));

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

char solveLinearEquation(double a, double b, double *roots, double epsilon) {
  assert(roots != nullptr);
  assert(std::isfinite(a));
  assert(std::isfinite(b));

  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  roots[0] = -b / a;
  return 1;
}

double calculateDiscriminant(double a, double b, double c) {
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(c));
  return pow(b, 2) - (4 * a * c);
}

double calculateParabolaXVertex(double a, double b) {
  assert(std::isfinite(a));
  assert(std ::isfinite(b));

  return -b / (2 * a);
}

bool isZero(double value, double epsilon) {
  assert(std::isfinite(value));
  return fabs(value) < epsilon;
}
