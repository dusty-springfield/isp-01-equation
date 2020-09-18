#include <cstdio>

#include "../src/equation.h"
#include "my_test.h"

#define EPSILON 0.01

TESTS_BEGIN
  TEST("isZero")
    assertTrue(isZero(0.0))
    assertTrue(isZero(-0.0))
    assertTrue(isZero(123.1234567 - 123.1234567))

    assertFalse(isZero(0.001))
    assertFalse(isZero(0.1, 0.1))
    assertTrue(isZero(0.099, 0.1))
  END

   TEST("calculateParabolaXVertex")
      double x = calculateParabolaXVertex(0.5, 1); // x = -1;
      assertTrue(isZero(x + 1))

      x = calculateParabolaXVertex(2, 0);
      assertTrue(isZero(x))

      x = calculateParabolaXVertex(4.5, -3.378);
      assertTrue(isZero(x - 0.375, 0.01))
      assertFalse(isZero(x - 0.375))
   END

  TEST("calculateDiscriminant")
    double discriminant = calculateDiscriminant(2, 4, 2);
    assertTrue(isZero(discriminant))

    discriminant = calculateDiscriminant(5.667, 0.789, 2.89);
    assertFalse(isZero(discriminant + 64.89))
    assertTrue(isZero(discriminant + 64.89, 0.01))
  END

  TEST("solveLinearEquation")
    double roots[2] = {};
    char nRoots = solveLinearEquation(-13.7, 2.223, roots);

    assertTrue(1 == nRoots)
    assertTrue(isZero(roots[0] - 0.162, 0.001))

    nRoots = solveLinearEquation(0.956, -0.456, roots);

    assertTrue(1 == nRoots)
    assertTrue(isZero(roots[0] - 0.47695, 0.00005))

    assertTrue(LEADING_COEFFICIENT_IS_ZERO == solveLinearEquation(0, 2, roots))
    assertTrue(LEADING_COEFFICIENT_IS_ZERO == solveLinearEquation(0.9, 2, roots, 1))
  END

  TEST("solveQuadraticEquation")
    double a = 2;
    double b = 5;
    double c = 3;

    assertTrue(1 == calculateDiscriminant(a, b, c))
    assertTrue(-1.25 == calculateParabolaXVertex(a, b))

    nRoots = solveQuadraticEquation(a, b, c, roots);
    assertTrue(2 == nRoots)
    assertTrue(-1.5 == roots[0])
    assertTrue(-1 == roots[1])
    
    nRoots = solveQuadraticEquation(a, b, c, roots, 1.1);
    assertTrue(1 ==nRoots)
    assertTrue(isZero(-1.25 - roots[0], EPSILON))
    a = 4;
    b = 4;
    c = 4;
    nRoots = solveQuadraticEquation(a, b, c, roots, 1);
    assertTrue(0 == nRoots)

    a = 0;
    nRoots = solveQuadraticEquation(a, b, c, roots, 1);
    assertTrue(LEADING_COEFFICIENT_IS_ZERO == nRoots)
  END
      
  TEST("solveUpToQuadraticEquation")
    a = 2;
    b = 5;
    c = 3;

    nRoots = solveUpToQuadraticEquation(a, b, c, roots);
    assertTrue(2 == nRoots)
    assertTrue(isZero(-1.5 - roots[0], EPSILON))
    assertTrue(-1 == roots[1])

    a = 0;
    b = -13.7;
    c = 2.223;
    double root = 0.162;
    nRoots = solveUpToQuadraticEquation(a, b, c, roots);
    assertTrue(1 == nRoots)
    assertTrue(isZero(roots[0] - root, 0.001))

    a = 0;
    b = 0;
    c = 1;
    nRoots = solveUpToQuadraticEquation(a, b, c, roots);
    assertTrue(0 == nRoots)

    c = 0;
    nRoots = solveUpToQuadraticEquation(a, b, c, roots);
    assertTrue(INF_ROOTS == nRoots)
  END
TESTS_END
