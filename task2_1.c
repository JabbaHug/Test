#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает гепотенузу по теореме Пифагора
 * @param kat1 первый катет треугольника
 * @param kat2 второй катет треугольника
 * @return возвращает рассчитанной гепотенузы
 */
double getH(const double kat1, const double kat2);
/**
 * @brief рассчитывает периметр треугольника
 * @param kat1 первый катет треугольника
 * @param kat2 второй катет треугольника
 * @param hyp гипотенуза треугольника
 * @return возвращает рассчитанный периметр
 */
double getP(const double kat1, const double kat2, const double hyp);
/**
 * @brief рассчитывает площадь треугольника
 * @param kat1 первый катет треугольника
 * @param kat2 второй катет треугольника
 * @return возвращает рассчитанную площадь
 */
double getS(const double kat1, const double kat2);
/**
 * @brief считывает значение, введенное с клавиатуры, с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);
/**
@brief PERIMETR - периметр прямоугольника
@brief SQUARE - площадь прямоугольника
*/
enum {PERIMETR = 1, SQUARE};
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите стороны треугольника: ");
    double kat1 = getValue();
    checkValue(kat1);
    double kat2 = getValue();
    checkValue(kat2);
    double hyp = getH(kat1,kat2);
    printf("Выберите нужный расчет: %d - периметр, %d - площадь\n", PERIMETR, SQUARE);
    int choice = (int)getValue();
    switch (choice)
    {
    case PERIMETR:
        printf("Периметр равен %.2lf",getP(kat1, kat2, hyp));
        break;
    case SQUARE:
        printf("Площадь равна %.2lf",getS(kat1, kat2));
        break;
    default:
        printf("Неправильный выбор. Выберите 1 или 2\n");
        return 1;
    }
    return 0;
}
/*теорема пифагора*/
double getH(const double kat1, const double kat2)
{
    return sqrt(pow(kat1, 2) + pow(kat2, 2));
}
double getP(const double kat1, const double kat2, const double hyp)
{
    return kat1 + kat2 + hyp;
}
double getS(const double kat1, const double kat2)
{
    return 0.5 * kat1 * kat2;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return value;
}
void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Значение должно быть положительным\n");
        abort();
    }
}
