/**
 * @file equation.h
* @brief Библиотека для решения уравнений до второй степени включительно
 */

#ifndef INC_01_EQUATION_LIBRARY_H
#define INC_01_EQUATION_LIBRARY_H

#include <float.h>

/**
 * @brief Бесконечное количество решений
 */
#define INF_ROOTS -1

/**
 * @brief Неверная классификация уравнения в виду равества 0-ю старшего члена
 */
#define LEADING_COEFFICIENT_IS_ZERO -2

/**
 * @brief Неверные входные данные. Возможные ошибки:
 *
 * <ul>
 * <li>передан указатель на NULL</li>
 * <li>в качестве коэффициента передан NaN</li>
 * </ul>
 */
#define INVALID_ARGUMENTS -3

/**
 * @brief Переполнение double при вычислениях
 */
#define FAILURE -4

/**
 * @brief Решение уравнений вплоть до второй степени вида ax<sup>2</sup> + bx + c = 0.
 * Для a, b, c допустимо равенство нулю
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @param[out] roots корни уравнения (минимальный размер массива - 2)
 * @param[in] epsilon точность вычислений
 * @return количество корней уравнения
 */
char solveUpToQuadraticEquation(double a, double b, double c, double *roots,
                                double epsilon = 2 * DBL_EPSILON);

/**
 * @brief Решение квадратного уравнения вида ax<sup>2</sup> + bx + c = 0, a&ne;0
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @param[out] roots корни уравнения (минимальный размер массива - 2)
 * @param[in] epsilon точность вычислений
 * @param[in] checked проводилась ли уже проверка аргументов на валидность
 * @return количество корней уравнения
 */
char solveQuadraticEquation(double a, double b, double c, double *roots,
                            double epsilon = 2 * DBL_EPSILON,
                            bool checked = false);

/**
 * @brief Решение линейного уравнения вида ax + b = 0, a&ne;0
 *
 * @param[in] a коэффициент при x
 * @param[in] b свободный член
 * @param[out] roots корни уравнения (минимальный размер массива - 1)
 * @param[in] epsilon точность вычислений
 * @param[in] checked проводилась ли уже проверка аргументов на валидность
 * @return количество корней уравнения
 */
char solveLinearEquation(double a, double b, double *roots,
                         double epsilon = 2 * DBL_EPSILON,
                         bool checked = false);

/**
 * @brief Вычисление дискриминанта для уравнения  ax<sup>2</sup> + bx + c = 0
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @param[in] c свободный член
 * @return дискриминант
 */
double calculateDiscriminant(double a, double b, double c);

/**
 * @brief Вычиление x вершины параболы ax<sup>2</sup> + bx + c
 *
 * @param[in] a коэффициент при x<sup>2</sup>
 * @param[in] b коэффициент при x
 * @return x вершина
 */
double calculateParabolaXVertex(double a, double b);

/**
 * @brief Проверка числа на равенство нулю
 *
 * @param[in] value Сравниваемое значение
 * @param[in] epsilon точность вычислений
 */
bool isZero(double value, double epsilon = 2 * DBL_EPSILON);

#endif // INC_01_EQUATION_LIBRARY_H