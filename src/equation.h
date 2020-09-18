#ifndef INC_01_EQUATION_LIBRARY_H
#define INC_01_EQUATION_LIBRARY_H

#include <float.h>

/**
 * Бесконечное количество решений
 */
#define INF_ROOTS  -1

/**
 * Неверная классификация уравнения в виду равества 0-ю старшего члена
 */
#define LEADING_COEFFICIENT_IS_ZERO -2

/**
 * Неверные входные данные. Возможные ошибки:
 * <ul>
 * <li>Передан указатель на NULL</li>
 * <li>В качестве коэффициента передан NaN</li>
 * </ul>
 */
#define INVALID_ARGUMENTS -3

/**
 * Переполнение double при вычислениях
 */
#define FAILURE -4

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
char solveUpToQuadraticEquation(double a, double b, double c, double *roots,
                                double epsilon = 2 * DBL_EPSILON);

/**
 * Решение квадратного уравнения вида ax<sup>2</sup> + bx + c = 0, a&#8800;0
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @param[out] x1 первый корень уравнения (если есть)
 * @param[out] x2 второй корень уравнения (если есть)
 * @param[in] epsilon точность вычислений
 * @param[in] checked проводилась ли уже проверка аргументов на валидность
 * @return количество корней уравнения
 */
char solveQuadraticEquation(double a, double b, double c, double *roots,
                            double epsilon = 2 * DBL_EPSILON,
                            bool checked = false);

/**
 * Решение линейного уравнения вида ax + b = 0, a&#8800;0
 *
 * @param[in] a коэффициент при x
 * @param[in] b свободный член
 * @param[out] x корень уравнения (если есть)
 * @param[in] epsilon точность вычислений
 * @param[in] checked проводилась ли уже проверка аргументов на валидность
 * @return количество корней уравнения
 */
char solveLinearEquation(double a, double b, double *roots,
                         double epsilon = 2 * DBL_EPSILON,
                         bool checked = false);

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
bool isZero(double value, double epsilon = 2 * DBL_EPSILON);

#endif // INC_01_EQUATION_LIBRARY_H