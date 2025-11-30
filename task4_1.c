#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Считывает целое число с клавиатуры
 * @return Введённое пользователем число
 */
int readInt();

/**
 * @brief Считывает положительный размер массива
 * @param msg Сообщение для вывода
 * @return Размер массива > 0
 */
size_t readSize(const char* msg);

/**
 * @brief Заполняет массив вручную
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillManual(int* arr, size_t size);

/**
 * @brief Заполняет массив случайными значениями [-15; 15]
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, size_t size);


/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param size Размер массива
 * @return Указатель на новый массив
 */
int* copyArray(const int* arr, size_t size);

/**
 * @brief Вычисляет произведение элементов, имеющих чётное значение
 * @param arr Массив
 * @param size Размер массива
 * @return Произведение или 0, если чётных нет
 */
long long productEven(const int* arr, size_t size);

/**
 * @brief Заменяет элементы с нечётными индексами на квадраты индексов
 * @param arr Массив
 * @param size Размер массива
 */
void replaceOddIdx(int* arr, size_t size);

/**
 * @brief Ищет положительные элементы, делящиеся на k с остатком 2
 * @param arr Массив
 * @param size Размер массива
 * @param k Делитель
 * @return 1 если есть такие элементы, иначе 0
 */
int findPositiveMod2(const int* arr, size_t size, int k);

/**
 * @brief Печатает массив
 * @param arr Массив
 * @param size Размер массива
 */
void printArray(const int* arr, size_t size);

/**
* @param RANDOM - значение 1, случайное заполнение числами в заданном диапазоне
* @param MANUAL - значение 2, ручной ввод элементов массива с клавиатуры
*/
enum { RANDOM = 1, MANUAL = 2 };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    srand((unsigned)time(NULL));

    size_t size = readSize("Enter array size: "); 
    // Введите размер массива:

    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation error"); // Ошибка выделения памяти
        exit(1);
    }

    printf("Choose fill method (%d random, %d manual): ", RANDOM, MANUAL);
    // Выберите метод заполнения (1 случайно, 2 вручную):

    int choice = readInt();

    switch (choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;

        case MANUAL:
            fillManual(arr, size);
            break;

        default:
            printf("Invalid choice\n");
            free(arr);
            return 1;
    }

    printArray(arr, size);

    int* copy = copyArray(arr, size);

    long long p = productEven(copy, size);
    printf("Product of even-valued elements: %lld\n", p);
    // Произведение чётных элементов

    replaceOddIdx(copy, size);
    printf("Array after replacing odd indices: "); // Массив после замены нечётных индексов:
    printArray(copy, size);

    printf("Enter k: ");
    int k = readInt();
    findPositiveMod2(copy, size, k);

    free(arr);
    free(copy);

    return 0;
}

int readInt()
{
    int x;
    while (scanf("%d", &x) != 1)
    {
        printf("Invalid input. Enter integer: "); // Неверный ввод. Введите целое число.
        while (getchar() != '\n');
    }
    return x;
}

size_t readSize(const char* msg)
{
    printf("%s", msg);
    int x;
    while ((scanf("%d", &x) != 1) || x <= 0)
    {
        printf("Size must be > 0. Enter again: "); // Размер должен быть > 0. Введите снова.
        while (getchar() != '\n');
    }
    return (size_t)x;
}

void fillManual(int* arr, size_t size)
{
    printf("Enter %zu integers: ", size); // Введите N чисел:
    for (size_t i = 0; i < size; i++)
        arr[i] = readInt();
}

void fillRandom(int* arr, size_t size)
{
    const int START = -15;
    const int END   = 15;

    for (size_t i = 0; i < size; i++)
        arr[i] = START + rand() % (END - START + 1);
}

int* copyArray(const int* arr, size_t size)
{
    int* newArr = malloc(size * sizeof(int));
    if (newArr == NULL)
    {
        printf("Memory allocation error"); // Ошибка выделения памяти
        exit(1);
    }

    for (size_t i = 0; i < size; i++)
        newArr[i] = arr[i];

    return newArr;
}

long long productEven(const int* arr, size_t size)
{
    long long res = 1;
    int found = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            res *= arr[i];
            found = 1;
        }
    }

    return found ? res : 0;
}

void replaceOddIdx(int* arr, size_t size)
{
    for (size_t i = 1; i < size; i += 2)
        arr[i] = (int)(i * i);
}

int findPositiveMod2(const int* arr, size_t size, int k)
{
    int found = 0;

    printf("Elements divisible by %d with remainder 2: ", k); 
    // Элементы делящиеся на k с остатком 2:

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] % k == 2)
        {
            printf("%d ", arr[i]);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
    return found;
}

void printArray(const int* arr, size_t size)
{
    printf("Array: "); // Массив:
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
