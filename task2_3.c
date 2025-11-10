#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Проверяет корректность ввода положительного числа
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
    double x = 0, y = 0, z = 0;
    double r = 0 , s = 0;

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
    else if (value <= 0)
    {
        printf("Ошибка ввода. Значение должно положительным\n");
        exit(1);
    }
    
    return value;
}

int checkBrick(const double x, const double y, const double z, const double r, const double s)
{
    double brick1 = x, brick2 = y, brick3 = z;

    if ((brick1 <= r && brick2 <= s) || (brick1 <= s && brick2 <= r))
        return 1;
    if ((brick1 <= r && brick3 <= s) || (brick1 <= s && brick3 <= r))
        return 1;
    if ((brick2 <= r && brick3 <= s) || (brick2 <= s && brick3 <= r))
        return 1;

    return 0;
}
