#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет введенное занчение
 * @return возвращает значение переменной value
 */
double getValue();

/**
 * @brief проверяет, что шаг положительный
 * @param step значение переменной step
 * @param end значение переменной end
 */
void checkStep(const double step, const double end);

/**
 * @brief рассчитывает значение функции
 * @param x значение переменной x
 * @return возвращает значение y
 */
double getY(const double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите начальное значение: ");
    double start = getValue();

    printf("Введите конечное значение: ");
    double end = getValue();

    printf("Введите шаг: ");
    double step = getValue();

    checkStep(step, end);

    double x = start;

    while (x <= end)
    {
        printf("x = %.2lf, y = %.4lf\n", x, getY(x));
        x += step;
    }

    return 0;
}

double getValue()
{
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return value;
}

void checkStep(const double step, const double end)
{
    if (step <= end)
    {
        printf("Ошибка: шаг должен быть положительным\n");
        abort();
    }
}

double getY(const double x)
{
    return 0.29 * pow(x, 3) + x - 1.2502;
}
