#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет введенное занчение
 * @param x значение проверяемой переменной
 */
void getValue(double *x);

/**
 * @brief рассчитывает значение y по формуле
 * @param a значение константы a
 * @param x значение переменной x
 * @return возвращает значение y
 */
double getY(const double a, double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    const double a = 2;
    double x;
    double y; 

    printf("Введите значение параметра X\n");
    getValue(&x);
    y = getY(a, x);
    printf("y = %.2f\n", y);
    return 0;
}

void getValue(double *x)
{
    if (!scanf("%lf", x))
    {
        printf("Ошибка ввода\n");
        exit(1);
    }
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
