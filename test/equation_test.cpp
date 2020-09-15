#include <iostream>
#include <gtest/gtest.h>
#include <exception>

#include "../src/equation.h"

TEST(isZero, test1) {
  ASSERT_TRUE(isZero(0.0));
  ASSERT_TRUE(isZero(-0.0));
  ASSERT_TRUE(isZero(123.1234567 - 123.1234567));

  ASSERT_FALSE(isZero(0.001));
  ASSERT_FALSE(isZero(0.1, 0.1));

  ASSERT_TRUE(isZero(0.099, 0.1));
}

TEST(calculateParabolaXVertex, test1) {
  double x = calculateParabolaXVertex(0.5, 1); // x = -1;
  ASSERT_TRUE(isZero(x + 1));

  x = calculateParabolaXVertex(2, 0);
  ASSERT_TRUE(isZero(x));

  x = calculateParabolaXVertex(4.5, -3.378);
  ASSERT_TRUE(isZero(x - 0.375, 0.01));
  ASSERT_FALSE(isZero(x - 0.375));
}

TEST(calculateDiscriminant, test1) {
  double discriminant = calculateDiscriminant(2, 4, 2);
  ASSERT_TRUE(isZero(discriminant));

  discriminant = calculateDiscriminant(5.667, 0.789, 2.89);
  ASSERT_FALSE(isZero(discriminant + 64.89));
  ASSERT_TRUE(isZero(discriminant + 64.89, 0.01));
}

TEST(solveLinearEquation, test1) {
  double roots[2] = {};
  char nRoots = solveLinearEquation(-13.7, 2.223, roots);

  ASSERT_EQ(1, nRoots);
  ASSERT_TRUE(isZero(roots[0] - 0.162, 0.001));

  nRoots = solveLinearEquation(0.956, -0.456, roots);

  ASSERT_EQ(1, nRoots);
  ASSERT_TRUE(isZero(roots[0] - 0.47695, 0.00005));

  ASSERT_EQ(LEADING_COEFFICIENT_IS_ZERO, solveLinearEquation(0, 2, roots));
  ASSERT_EQ(LEADING_COEFFICIENT_IS_ZERO, solveLinearEquation(0.9, 2, roots, 1));
}

TEST(solveQuadraticEquation, test1) {
  double roots[2] = {};

  double a = 2;
  double b = 5;
  double c = 3;

  ASSERT_EQ(1, calculateDiscriminant(a, b, c));
  ASSERT_EQ(-1.25, calculateParabolaXVertex(a, b));

  char nRoots = solveQuadraticEquation(a, b, c, roots);
  ASSERT_EQ(2, nRoots);
  ASSERT_EQ(-1.5, roots[0]);
  ASSERT_EQ(-1, roots[1]);

  nRoots = solveQuadraticEquation(a, b, c, roots, 1.1);
  ASSERT_EQ(1, nRoots);
  ASSERT_EQ(-1.25, roots[0]);

  a = 4;
  b = 4;
  c = 4;
  nRoots = solveQuadraticEquation(a, b, c, roots, 1);
  ASSERT_EQ(0, nRoots);

  a = 0;
  nRoots = solveQuadraticEquation(a, b, c, roots, 1);
  ASSERT_EQ(LEADING_COEFFICIENT_IS_ZERO, nRoots);
}

TEST(solveUpToQuadraticEquation, test1) {
  double roots[2] = {};

  double a = 2;
  double b = 5;
  double c = 3;

  char nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  ASSERT_EQ(2, nRoots);
  ASSERT_EQ(-1.5, roots[0]);
  ASSERT_EQ(-1, roots[1]);

  a = 0;
  b = -13.7;
  c = 2.223;
  double root = 0.162;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  ASSERT_EQ(1, nRoots);
  ASSERT_TRUE(isZero(roots[0] - root, 0.001));

  a = 0;
  b = 0;
  c = 1;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  ASSERT_EQ(0, nRoots);

  c = 0;
  nRoots = solveUpToQuadraticEquation(a, b, c, roots);
  ASSERT_EQ(INF_ROOTS, nRoots);
}

