#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * @brief Проверяет успешность выделения памяти
 * @param pointer Указатель на выделенную память
 */
void checkMemory(const void* pointer);

/**
 * @brief Считывает целое число
 * @return Введённое пользователем число
 */
int checkValue();

/**
 * @brief Считывает положительное целое число
 * @return Положительное целое число
 */
int checkValuePositive();

/**
 * @brief Заполняет массив вручную
 * @param arr Массив
 * @param size Размер массива
 */
void fillManual(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными значениями в диапазоне [start; end]
 * @param arr Массив
 * @param size Размер массива
 * @param start Левая граница
 * @param end Правая граница
 */
void fillRandom(int* arr, const size_t size, const int start, const int end);

/**
 * @brief Выводит массив на экран
 * @param arr Массив
 * @param size Размер массива
 */
void printArrayInt(const int* arr, const size_t size);

/**
 * @brief Выводит массив на экран
 * @param arr Массив
 * @param size Размер массива
 */
void printArrayDbl(const double* arr, const size_t size);

/**
 * @brief Проверяет, заканчивается ли число x цифрой k
 * @param x Число
 * @param k Цифра (0–9)
 * @return 1 если заканчивается, иначе 0
 */
int endWithK(const int x, const int k);

/**
 * @brief Заменяет предпоследний элемент массива на максимальный по модулю
 * @param arr Массив
 * @param size Размер массива
 */
void replacePreLast(int* arr, const size_t size);

/**
 * @brief Вставляет элементы K до и после всех чисел, оканчивающихся на K
 * @param arr Массив
 * @param size Размер массива
 * @param k Значение для вставки
 * @return Указатель на новый массив (старый освобождается)
 */
int* insertAroundK(const int* arr, const size_t size, const int k);

/**
 * @brief Формирует массив A по заданному правилу из массива D
 * @param D Исходный массив
 * @param size Размер массива
 * @return Указатель на массив A
 */
double* buildA(const int* D, const size_t size);

/**
 * @param RANDOM - 1: случайное заполнение
 * @param MANUAL - 2: ручной ввод
 */
enum { RANDOM = 1, MANUAL = 2 };

int main()
{
    srand((unsigned)time(NULL));

    printf("Enter array size: ");
    size_t size = checkValuePositive();

    int* arr = malloc(size * sizeof(int));
    checkMemory(arr);

    printf("Choose fill method (%d random, %d manual): ", RANDOM, MANUAL);
    int choice = checkValuePositive();

    switch (choice)
    {
        case RANDOM:
        {
            printf("Enter START and END for numbers: ");
            int start = checkValue();
            int end = checkValue();
            fillRandom(arr, size, start, end);
            break;
        }
        case MANUAL:
            fillManual(arr, size);
            break;
        default:
            printf("Invalid choice\n");
            free(arr);
            return 1;
    }

    printArrayInt(arr, size);

    replacePreLast(arr, size);
    printf("After replacing pre-last with max abs: ");
    printArrayInt(arr, size);

    printf("Enter K: ");
    int k = checkValue();

    int* arr2 = insertAroundK(arr, size, k);
    printf("After inserting around K: ");
    printArrayInt(arr2, size + (int)((endWithK(arr[0],k))?2:0)); // просто size не подходит, при добавлении новых переменных (по заданию)  



    free(arr2); // временный массив освобождается

    double* A = buildA(arr, size);
    printf("Array A: ");
    printArrDbl(A, size);

    free(arr);
    free(A);

    return 0;
}

int checkValue()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input\n");
        exit(1);
    }
    return value;
}

int checkValuePositive()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input\n");
        exit(1);
    }
    if (value <= 0)
    {
        printf("Value has to be positive\n");
        exit(1);
    }
    return value;
}

void checkMemory(const void* pointer)
{
    if (pointer == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
}

void fillManual(int* arr, const size_t size)
{
    printf("Enter %zu integers: ", size);
    for (size_t i = 0; i < size; i++)
        arr[i] = checkValue();
}

void fillRandom(int* arr, const size_t size, const int start, const int end)
{
    for (size_t i = 0; i < size; i++)
        arr[i] = start + rand() % (end - start + 1);
}

void printArrayInt(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printArrayDbl(const double* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%lf ", arr[i]);
    printf("\n");
}

int endWithK(int x, int k)
{
    return abs(x) % 10 == abs(k) % 10;
}

void replacePreLast(int* arr, const size_t size)
{
    if (size < 2)
    {
        printf("Array too small\n");
        exit(1);
    }

    int maxAbs = abs(arr[0]);
    int maxVal = arr[0];

    for (size_t i = 1; i < size; i++)
    {
        if (abs(arr[i]) > maxAbs)
        {
            maxAbs = abs(arr[i]);
            maxVal = arr[i];
        }
    }

    arr[size - 2] = maxVal;
}

int* insertAroundK(const int* arr, size_t size, const int k)
{
    size_t extra = 0;

    for (size_t i = 0; i < size; i++)
        if (endWithK(arr[i], k))
            extra += 2;

    int* newArr = malloc((size + extra) * sizeof(int));
    checkMemory(newArr);

    size_t pos = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (endWithK(arr[i], k))
        {
            newArr[pos++] = k;
            newArr[pos++] = arr[i];
            newArr[pos++] = k;
        }
        else
        {
            newArr[pos++] = arr[i];
        }
    }

    return newArr;
}

double* buildA(const int* D, const size_t size)
{
    double* A = malloc(size * sizeof(double));
    checkMemory(A);

    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            A[i] = (double)(i * D[i] * D[i]);
        }
        else
        {
            if (i == 1)
                A[i] = D[i];
            else
                A[i] = (double)D[i] / (i - 1);
        }
    }

    return A;
}
