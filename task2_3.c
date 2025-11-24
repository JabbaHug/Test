#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Проверяет корректность ввода положительного числа
 * @param x сторона кирпича
 * @param y сторона кирпича
 * @param z сторона кирпича
 * @param r сторона отверстия
 * @param s сторона отверстия
 * @return возвращает введённое корректное значение
 */
double getValue();

/**
 * @brief Определяет, пройдет ли кирпич через отверстие
 * @param x сторона кирпича
 * @param y сторона кирпича
 * @param z сторона кирпича
 * @param r сторона отверстия
 * @param s сторона отверстия
 * @return 1 — если кирпич проходит, 0 — если не проходит
 */
int checkBrick(double x, double y, double z, double r, double s);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    double x;
    double y;
    double z;
    double r;
    double s;

    printf("Введите стороны кирпича (x, y, z):\n");
    x = getValue();
    y = getValue();
    z = getValue();

    printf("Введите стороны отверстия (r, s):\n");
    r = getValue();
    s = getValue();

    if (checkBrick(x, y, z, r, s))
        printf("Кирпич ПРОЙДЁТ через отверстие.\n");
    else
        printf("Кирпич НЕ пройдёт через отверстие.\n");

    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка ввода. Значение должно быть числом\n");
        exit(1);
    }
    else if (value < 0)
    {
        printf("Ошибка ввода. Значение должно положительным\n");
        exit(1);
    }
    return value;
}

int checkBrick(const double x, const double y, const double z, const double r, const double s)
{
    double minH = (r < s) ? r : s;
    double maxH = (r < s) ? s : r;

    double a_min, a_max;

    a_min = (x < y) ? x : y;
    a_max = (x < y) ? y : x;
    if (a_min <= minH && a_max <= maxH)
        return 1;

    a_min = (x < z) ? x : z;
    a_max = (x < z) ? z : x;
    if (a_min <= minH && a_max <= maxH)
        return 1;

    a_min = (y < z) ? y : z;
    a_max = (y < z) ? z : y;
    if (a_min <= minH && a_max <= maxH)
        return 1;

    return 0;
}
