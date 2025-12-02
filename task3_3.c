#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

const double EPS = 1e-4;  // по условию
// DBL_EPSILON существует, но он слишком мал (~1e-16), нам не подходит

double getValue();
void checkInput(double start, double end, double step);
double f_exact(double x);
double f_series(double x);

int main(void)
{
    double start, end, step;

    printf("Введите начальное значение: ");
    start = getValue();

    printf("Введите конечное значение: ");
    end = getValue();

    printf("Введите шаг: ");
    step = getValue();

    checkInput(start, end, step);

    for (double x = start; x <= end + DBL_EPSILON; x += step)
    {
        double exact = f_exact(x);
        double approx = f_series(x);
        printf("x=%.4lf  sin(x)=%.6lf  S=%.6lf\n", x, exact, approx);
    }

    return 0;
}

double getValue()
{
    double v;
    if (scanf("%lf", &v) != 1)
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return v;
}

void checkInput(double start, double end, double step)
{
    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным\n");
        abort();
    }
    if (start > end)
    {
        printf("Ошибка: начало больше конца\n");
        abort();
    }
}

double f_exact(double x)
{
    return sin(x);
}

double f_series(double x)
{
    double term = x;     // первый член 
    double sum = term;

    for (int n = 0; n < INT_MAX; n++)
    {
        double next = -term * x * x / ((2*n + 2)*(2*n + 3));

        if (fabs(next) < EPS)
            break;

        sum += next;
        term = next;
    }

    return sum;
}
