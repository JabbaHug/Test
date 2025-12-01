#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет введенное занчение
 * @param x значение проверяемой переменной
 */
double getValue(void);

/**
 * @brief рассчитывает значение y по формуле
 * @param a значение константы a
 * @param x значение переменной x
 * @return возвращает значение y
 */
double getY(const double a, const double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    const double a = 2;
    double x = 0;
    double y = 0; 

    printf("Введите значение параметра X\n");
    x = getValue();
    y = getY(a, x);
    printf("y = %.2f\n", y);
    return 0;
}

double getValue(void)
{
    double x = 0;
    if (scanf("%lf", &x) != 1)
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return x;
}

double getY(const double a, const double x)
{
    if (x < 1)
    {
        return 1;
    }
    else if (x > 2)
    {
        return exp(a * x) * cos(x);
    }
    else
    {
        return a * pow(x, 2 * log(x));
    }
}
