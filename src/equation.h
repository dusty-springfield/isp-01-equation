#ifndef INC_01_EQUATION_LIBRARY_H
#define INC_01_EQUATION_LIBRARY_H

/**
 * Бесконечное количество решений
 */
char const INF_ROOTS = -1;

/**
 * Неверная классификация уравнения в виду равества 0-ю старшего члена
 */
char const LEADING_COEFFICIENT_IS_ZERO = -2;

/**
 * Решение уравнений вплоть до второй степени вида ax<sup>2</sup> + bx + c = 0.
 * Для a, b, c допустимо равенство нулю
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @param[out] x1 первый корень уравнения (если есть)
 * @param[out] x2 второй корень уравнения (если есть)
 * @param[in] epsilon точность вычислений
 * @return количество корней уравнения
 */
char solveUpToQuadraticEquation(double a, double b, double c, double *x1, double *x2, double epsilon);

/**
 * Решение квадратного уравнения вида ax<sup>2</sup> + bx + c = 0, a&#8800;0
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @param[out] x1 первый корень уравнения (если есть)
 * @param[out] x2 второй корень уравнения (если есть)
 * @param[in] epsilon точность вычислений
 * @return количество корней уравнения
 */
char solveQuadraticEquation(double a, double b, double c, double *x1, double *x2, double epsilon);

/**
 * Решение линейного уравнения вида ax + b = 0, a&#8800;0
 *
 * @param[in] a коэффициент при x
 * @param[in] b свободный член
 * @param[out] x корень уравнения (если есть)
 * @param[in] epsilon точность вычислений
 * @return количество корней уравнения
 */
char solveLinearEquation(double a, double b, double *x, double epsilon);

/**
 * Вычисление дискриминанта для уравнения  ax<sup>2</sup> + bx + c = 0
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @return дискриминант
 */
double calculateDiscriminant(double a, double b, double c);

/**
 * Вычиление x вершины параболы ax<sup>2</sup> + bx + c
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @return x вершина
 */
double calculateParabolaXVertex(double a, double b);

/**
 * Проверка числа на равенство нулю
 * @param[in] value Сравниваемое значение
 * @param[in] epsilon точность вычислений
 */
bool isZero(double value, double epsilon);

#endif //INC_01_EQUATION_LIBRARY_H