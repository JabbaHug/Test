#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 /**
 * @brief проверяет введенное занчение
 * @return возвращает значение переменной value
 */
int getNValue();

/**
 * @brief проверяет введенное занчение
 * @return возвращает значение переменной value
 */
double getEValue();

/**
 * @brief Вычисляет факториал числа
 * @param k значение переменной k
 * @return значение k!
 */
double factorial(int k);

/**
 * @brief Вычисляет k-й член ряда
 * @param k значение переменной k
 * @return значение члена ряда по формуле (-1)^k / (k! * (k + 1)!)
 */
double getTerm(int k);

/**
 * @brief Вычисляет сумму первых n+1 членов ряда
 * @param n количество членов для суммирования (начиная с 0)
 * @return значение суммы первых n+1 членов
 */
double getSumN(int n);

/**
 * @brief Вычисляет сумму членов ряда с точностью до e
 * @param e значение переменной e
 * @return сумму всех членов ряда, пока |term| >= e
 */
double getSumE(double e);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    int n;
    double e;

    printf("Введите n: ");
    n = getNValue();
    printf("Введите e: ");
    e = getEValue();

    printf("\nСумма первых n членов\n");
    double sumN = getSumN(n);

    printf("\nСумма членов, пока term >= e\n");
    double sumE = getSumE(e);

    printf("\nРезультаты:\nСумма n = %.10lf\nСумма e = %.10lf\n", sumN, sumE);
    return 0;
}

int getNValue()
{
    int value;
    if (scanf("%d", &value) != 1 || value < 0)
    {
        printf("Ошибка ввода: n должно быть неотрицательным числом\n");
        exit(1);
    }
    return value;
}

double getEValue()
{
    double value;
    if (scanf("%lf", &value) != 1 || value <= 0)
    {
        printf("Ошибка ввода: e должно быть положительным числом\n");
        exit(1);
    }
    return value;
}

double factorial(int k)
{
    double result = 1;
    for (int i = 1; i <= k; i = i + 1)
        result *= i;
    return result;
}

double getTerm(int k)
{
    return pow(-1, k) / (factorial(k) * factorial(k + 1));
}

double getSumN(int n)
{
    double sum = 0;
    for (int k = 0; k <= n; k = k + 1)
    {
        double term = getTerm(k);
        sum += term;
        printf("k = %d  term = %.10lf  sum = %.10lf\n", k, term, sum);
    }
    return sum;
}

double getSumE(double e)
{
    double sum = 0;
    int k = 0;
    while (1)
    {
        double term = getTerm(k);
        if (fabs(term) < e)
            break;
        sum += term;
        printf("k = %d  term = %.10lf  sum = %.10lf\n", k, term, sum);
        k++;
    }
    return sum;
}
