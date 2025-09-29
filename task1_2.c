#include <stdio.h>
#include <math.h>

/**
 * @brief - Расчет площади по формуле
 * @param x значение переменной x
 * @return - рассчитанное значение
 */
double getS(const double x);

/**
 * @brief - Расчет площади полной поверхности по формуле
 * @param x значение переменной x
 * @return - рассчитанное значение
 */
double getSP(const double x);

/**
 * @brief - Расчет объема по формуле
 * @param x значение переменной x
 * @return - рассчитанное значение
 */
double getV(const double x);

/**
 * @brief - Точка входа в программу
 * @return - вызвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double x = 0;
    printf("Введите длину ребра куба\n");

    scanf("%lf", &x);

    printf("Площадь грани: %.2lf\n", getS(x));
    printf("Площадь полной поверхности: %.2lf\n", getSP(x));
    printf("Объем куба: %.2lf\n", getV(x));

    return 0;
}

double getS(const double x)
{
    return x * x;
}

double getSP(const double x)
{
    return 6 * x * x;
}

double getV(const double x)
{
    return x * x * x;
}
