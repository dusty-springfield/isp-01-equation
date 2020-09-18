#include <assert.h>
#include <cmath>

#include "equation.h"

static bool isValidCoefficientsAndPointers(double a, double b, double c,
                                           const double *roots,
                                           double epsilon) {

  return std::isfinite(a) && std::isfinite(b) && std::isfinite(c) &&
         std::isfinite(epsilon) && roots != nullptr;
}

char solveUpToQuadraticEquation(double a, double b, double c, double *roots,
                                double epsilon) {
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(epsilon));
  assert(roots != nullptr);

  if (!isValidCoefficientsAndPointers(a, b, c, roots, epsilon)) {
    return INVALID_ARGUMENTS;
  }

  if (!isZero(a, epsilon)) {
    return solveQuadraticEquation(a, b, c, roots, epsilon, true);
  }

  if (!isZero(b, epsilon)) {
    return solveLinearEquation(b, c, roots, epsilon, true);
  }

  if (!isZero(c, epsilon)) {
    return 0;
  }

  return INF_ROOTS;
}

char solveQuadraticEquation(double a, double b, double c, double *roots,
                            double epsilon, bool checked) {
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(epsilon));
  assert(roots != nullptr);

  if (!checked && isValidCoefficientsAndPointers(a, b, c, roots, epsilon)) {
    return INVALID_ARGUMENTS;
  }

  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  double discriminant = calculateDiscriminant(a, b, c);
  if (!std::isfinite(discriminant)) {
    return FAILURE;
  }

  if (isZero(discriminant, epsilon)) {
    roots[0] = calculateParabolaXVertex(a, b);
    if (std::isfinite(roots[0])) {
      return 1;
    }

    return FAILURE;
  }

  if (discriminant < 0) {
    return 0;
  }

  double sqrtDiscriminant = sqrt(discriminant);
  roots[0] = (-b - sqrtDiscriminant) / (2 * a);
  roots[1] = (-b + sqrtDiscriminant) / (2 * a);
  if (std::isfinite(roots[0]) && std::isfinite(roots[1])) {
    return 2;
  }
  return FAILURE;
}

char solveLinearEquation(double a, double b, double *roots, double epsilon,
                         bool checked) {
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(epsilon));
  assert(roots != nullptr);

  if (!checked && isValidCoefficientsAndPointers(0, a, b, roots, epsilon)) {
    return INVALID_ARGUMENTS;
  }

  if (isZero(a, epsilon)) {
    return LEADING_COEFFICIENT_IS_ZERO;
  }

  roots[0] = -b / a;
  if (std::isfinite(roots[0])) {
    return 1;
  }

  return FAILURE;
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
  assert(std::isfinite(epsilon));

  return fabs(value) < epsilon;
}
