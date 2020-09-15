#include "cmath"
#include <cstdio>
#include <float.h>

#include "../src/equation.h"

void printTestFailure(int atLine) {
  fprintf(stderr, "Line %d.  Test failed\n", atLine);
}

void assertTrue(bool condition, int line) {
  if (!condition) {
    printTestFailure(line);
  }
}

void assertFalse(bool condition, int line) { assertTrue(!condition, line); }

void assertEquals(double expected, double present, int line,
                  double epsilon = 2 * DBL_EPSILON) {
  if (fabs(present - expected) >= epsilon) {
    printTestFailure(line);
    fprintf(stderr, "expected : %f, given : %f, epsilon : %f\n", expected,
            present, epsilon);
  }
}

int main() {
  /**
   * isZero Tests
   */
  assertTrue(isZero(0.0), __LINE__);
  assertTrue(isZero(-0.0), __LINE__);
  assertTrue(isZero(123.1234567 - 123.1234567), __LINE__);

  assertFalse(isZero(0.001), __LINE__);
  assertFalse(isZero(0.1, 0.1), __LINE__);

  assertTrue(isZero(0.099, 0.1), __LINE__);

  /**
   * calculateParabolaXVertex Tests
   */
  double x = calculateParabolaXVertex(0.5, 1); // x = -1;
  assertTrue(isZero(x + 1), __LINE__);

  x = calculateParabolaXVertex(2, 0);
  assertTrue(isZero(x), __LINE__);

  x = calculateParabolaXVertex(4.5, -3.378);
  assertTrue(isZero(x - 0.375, 0.01), __LINE__);
  assertFalse(isZero(x - 0.375), __LINE__);

  /**
   * calculateDiscriminant
   */
  double discriminant = calculateDiscriminant(2, 4, 2);
  assertTrue(isZero(discriminant), __LINE__);

  discriminant = calculateDiscriminant(5.667, 0.789, 2.89);
  assertFalse(isZero(discriminant + 64.89), __LINE__);
  assertTrue(isZero(discriminant + 64.89, 0.01), __LINE__);

  /**
   * solveLinearEquation
   */
  double roots[2] = {};
  char nRoots = solveLinearEquation(-13.7, 2.223, roots);

  assertEquals(1, nRoots, __LINE__);
  assertTrue(isZero(roots[0] - 0.162, 0.001), __LINE__);

  nRoots = solveLinearEquation(0.956, -0.456, roots);

  assertEquals(1, nRoots, __LINE__);
  assertTrue(isZero(roots[0] - 0.47695, 0.00005), __LINE__);

  assertEquals(LEADING_COEFFICIENT_IS_ZERO, solveLinearEquation(0, 2, roots),
               __LINE__);
  assertEquals(LEADING_COEFFICIENT_IS_ZERO,
               solveLinearEquation(0.9, 2, roots, 1), __LINE__);

  /**
   * solveQuadraticEquation
   */
  double a = 2;
  double b = 5;
  double c = 3;

  assertEquals(1, calculateDiscriminant(a, b, c), __LINE__);
  assertEquals(-1.25, calculateParabolaXVertex(a, b), __LINE__);

  nRoots = solveQuadraticEquation(a, b, c, roots);
  assertEquals(2, nRoots, __LINE__);
  assertEquals(-1.5, roots[0], __LINE__);
  assertEquals(-1, roots[1], __LINE__);

  nRoots = solveQuadraticEquation(a, b, c, roots, 1.1);
  assertEquals(1, nRoots, __LINE__);
  assertEquals(-1.25, roots[0], __LINE__);

  a = 4;
  b = 4;
  c = 4;
  nRoots = solveQuadraticEquation(a, b, c, roots, 1);
  assertEquals(0, nRoots, __LINE__);

  a = 0;
  nRoots = solveQuadraticEquation(a, b, c, roots, 1);
  assertEquals(LEADING_COEFFICIENT_IS_ZERO, nRoots, __LINE__);

  /**
   * solveUpToQuadraticEquation
   */

  a = 2;
  b = 5;
  c = 3;

  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  assertEquals(2, nRoots, __LINE__);
  assertEquals(-1.5, roots[0], __LINE__);
  assertEquals(-1, roots[1], __LINE__);

  a = 0;
  b = -13.7;
  c = 2.223;
  double root = 0.162;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  assertEquals(1, nRoots, __LINE__);
  assertTrue(isZero(roots[0] - root, 0.001), __LINE__);

  a = 0;
  b = 0;
  c = 1;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  assertEquals(0, nRoots, __LINE__);

  c = 0;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  assertEquals(INF_ROOTS, nRoots, __LINE__);
}
