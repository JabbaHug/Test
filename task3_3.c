#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

/**
 * @brief Проверяет корректность ввода числа типа double.
 * @return Введённое корректное значение.
 */
double checkValue();

/**
 * @brief Проверяет корректность шага и диапазона.
 * @param start Начальное значение диапазона.
 * @param end   Конечное значение диапазона.
 * @param step  Шаг итерации.
 */
void checkStep(const double start,const double end,const double step);

/**
 * @brief Вычисляет точное значение функции sin(x).
 * @param x Аргумент функции.
 * @return Значение sin(x).
 */
double f_exact(const double x);

/**
 * @brief Вычисляет значение sin(x) с помощью функционального ряда с заданной точностью по рекуррентной формуле.
 * @param x Аргумент функции.
 * @return Приближённое значение sin(x).
 */
double f_series(const double x, const double ebs);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите точность:");
    double ebs = checkValue();

    printf("Введите начальное значение: ");
    double start = checkValue();

    printf("Введите конечное значение: ");
    double end = checkValue();

    printf("Введите шаг: ");
    double step = checkValue();

    checkStep(start, end, step);

    for (double x = start; x <= end + DBL_EPSILON; x += step)
    {
        double exact = f_exact(x);
        double approx = f_series(x, ebs);
        printf("x=%.4lf  sin(x)=%.6lf  S=%.6lf\n", x, exact, approx);
    }

    return 0;
}

double checkValue()
{
    double value;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода\n");
        exit(1);
    }
    return value;
}

void checkStep(const double start, const double end, const double step)
{
    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным\n");
        exit(1);
    }
    if (start > end)
    {
        printf("Ошибка: начало больше конца\n");
        exit(1);
    }
}

double f_exact(const double x)
{
    return sin(x);
}

double f_series(const double x, const double ebs)
{
    double term = x;     // первый член 
    double sum = term;

    for (int n = 0; n < fabs(f_exact(x) - sum ) < ebs; n++)
    {
        double next = -term * x * x / ((2*n + 2)*(2*n + 3));

        sum += next;
        term = next;
    }

    return sum;
}
