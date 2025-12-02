#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет корректность ввода целого числа
 * @return возвращает значение
 */
int getValueNonNegative();

/**
 * @brief проверяет корректность ввода вещественного числа
 * @return возвращает значение
 */
double getValuePositive();

/**
 * @brief вычисляет коэффициент рекуррентного выражения
 * @param k индекс текущего члена
 * @return коэффициент (-1)/((k+1)(k+2))
 */
double getRecurent(int k);

/**
 * @brief вычисляет k-й член ряда рекуррентно
 * @param k индекс члена
 * @return значение члена
 */
double getTerm(const int k);

/**
 * @brief сумма первых n+1 членов ряда
 * @param n верхний предел
 * @return сумма
 */
double getSumN(const int n);

/**
 * @brief сумма членов ряда, пока |term| >= e
 * @param e точность
 * @return сумма
 */
double getSumE(const double e);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    int n;
    double e;

    printf("Введите n: ");
    n = getValueNonNegative();

    printf("Введите e: ");
    e = getValuePositive();

    printf("\nСумма первых n членов\n");
    double sumN = getSumN(n);

    printf("\nСумма членов, пока term >= e\n");
    double sumE = getSumE(e);

    printf("\nРезультаты:\nСумма n = %.10lf\nСумма e = %.10lf\n",
           sumN, sumE);
    return 0;
}

int getValueNonNegative()
{
    int value;
    if (scanf("%d", &value) != 1 || value < 0)
    {
        printf("Ошибка ввода\n");
        exit(1);
    }
    return value;
}

double getValuePositive()
{
    double value;
    if (scanf("%lf", &value) != 1 || value <= 0)
    {
        printf("Ошибка ввода\n");
        exit(1);
    }
    return value;
}

double getRecurent(const int k)
{
    return -1.0 / ((k + 1.0) * (k + 2.0));
}

double getTerm(const int k)
{
    if (k == 0)
        return -1.0;

    double term = -1.0;
    for (int i = 0; i < k; i++)
        term *= getRecurent(i);

    return term;
}

double getSumN(const int n)
{
    double term = -1.0;
    double sum = term;

    printf("k = 0  term = %.10lf  sum = %.10lf\n", term, sum);

    for (int k = 1; k <= n; k++)
    {
        term *= getRecurent(k - 1);
        sum += term;
        printf("k = %d  term = %.10lf  sum = %.10lf\n", k, term, sum);
    }
    return sum;
}

double getSumE(const double e)
{
    double term = -1.0;
    double sum = 0.0;
    int k = 0;

    while (fabs(term) >= e)
    {
        sum += term;
        printf("k = %d  term = %.10lf  sum = %.10lf\n", k, term, sum);

        term *= getRecurent(k);
        k++;
    }
    return sum;
}
