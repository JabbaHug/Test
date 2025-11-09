#include <stdio.h>
#include <math.h>

/**
 * @brief - Расчет силы тяжести по формуле
 * @param m значение переменной m
 * @param g значение константы g
 * @return - рассчитанное значение
 */
double getF(const double m, const double g);

/**
 * @brief - Расчет веса по формуле
 * @param m значение переменной m
 * @param g значение константы g
 * @return - рассчитанное значение
 */
double getP(const double m, const double g);

/**
 * @brief - Точка входа в программу
 * @return - вызвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double m = 0;
    const double g = 9.80665;
    
    printf("Введите массу мешка с картошкой\n");
    scanf("%lf", &m);

    printf("Сила тяжести: %.2lf\n", getF(m, g));
    printf("Вес картошки: %.2lf\n", getP(m, g));

    return 0;
}

double getF(const double m, const double g)
{
    return m * g;
}

double getP(const double m, const double g)
{
    return m * g;
}
