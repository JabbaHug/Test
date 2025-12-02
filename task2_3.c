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
double getValuePositive();

/**
 * @brief Проверяет, поместится ли пара сторон (a,b) в отверстие (minH,maxH)
 * @param a первая сторона
 * @param b вторая сторона
 * @param minH меньшая сторона отверстия
 * @param maxH большая сторона отверстия
 * @return 1 — если помещается, 0 — нет
 */
int fitsPair(const double a, const double b, const double minH, const double maxH);

/**
 * @brief Определяет, пройдет ли кирпич через отверстие
 * @param x сторона кирпича
 * @param y сторона кирпича
 * @param z сторона кирпича
 * @param r сторона отверстия
 * @param s сторона отверстия
 * @return 1 — если кирпич проходит, 0 — если не проходит
 */
int checkBrick(const double x,const double y,const double z,const double r,const double s);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите стороны кирпича (x, y, z):\n");
    double x = getValuePositive();
    double y = getValuePositive();
    double z = getValuePositive();

    printf("Введите стороны отверстия (r, s):\n");
    double r = getValuePositive();
    double s = getValuePositive();

    if (checkBrick(x, y, z, r, s))
        printf("Кирпич ПРОЙДЁТ через отверстие.\n");
    else
        printf("Кирпич НЕ пройдёт через отверстие.\n");

    return 0;
}

double getValuePositive()
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

int fitsPair(const double a, const double b, const double minH, const double maxH)
{
    double amin = (a < b) ? a : b;
    double amax = (a < b) ? b : a;

    return (amin <= minH && amax <= maxH);
}

int checkBrick(const double x, const double y, const double z, const double r, const double s)
{
    double minH = (r < s) ? r : s;
    double maxH = (r < s) ? s : r;

    if (fitsPair(x, y, minH, maxH)) return 1;
    if (fitsPair(x, z, minH, maxH)) return 1;
    if (fitsPair(y, z, minH, maxH)) return 1;

    return 0;
}
