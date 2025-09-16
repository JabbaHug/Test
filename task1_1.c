#include <stdio.h>
#include <math.h>

/**
 *@brief Рассчитывает значение функции A
 *@param x значение параметра x
 *@param y значение параметра y
 *@param z значение параметра z
 *@return рассчитывает значение
 */
double defA (double x, double y, double z);
/**
 *@brief Рассчитывает значение функции B
 *@param x значение параметра x
 *@param y значение параметра y
 *@param z значение параметра z
 *@return рассчитывает значение
 */
double defB (double x, double y, double z);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    /*объявляем именно константы*/
    const double x = 0.78;
    const double y = 1.24;
    const double z = 0.5;

    /*вывод с нужной точностью*/
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.1f\n\n", z);

    printf("A = %.6f\n", defA(x, y, z));
    printf("B = %.6f\n", defB(x, y, z)); 

    return 0; 
}
double defA(double x, double y, double z)
{
    return (2 * pow(z, x))/(sqrt(pow(y, x)* pow(cos(x + y), 2)) - 3 * z);
}
double defB(double x, double y, double z)
{
    return x * exp(sqrt(z))*cos((pow(x,2))/(y*z));
}
