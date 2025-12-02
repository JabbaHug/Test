#include <stdio.h>
#include <stdlib.h>
#include <time.h> //используется в main для генерации сида

/**
 * @brief Проверяет успешность выделения памяти
 * @param pointer Указатель на выделенную память
 */
void checkMemory(const void* pointer); 

/**
 * @brief Считывает целое число с клавиатуры
 * @return Введённое пользователем число
 */
int checkValue();

/**
 * @brief Считывает целое число с клавиатуры и проверяет, что оно положительно
 * @return Введённое пользователем число
 */
int checkValuePositive();

/**
 * @brief Заполняет массив вручную
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillManual(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными значениями [-15; 15]
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, const size_t size, const int start, const int end);


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
int productEven(const int* arr, const size_t size);

/**
 * @brief Заменяет элементы с нечётными индексами на квадраты индексов
 * @param arr Массив
 * @param size Размер массива
 */
void replaceOddIdx(int* arr, const size_t size);

/**
 * @brief Ищет положительные элементы, делящиеся на k с остатком 2
 * @param arr Массив
 * @param size Размер массива
 * @param k Делитель
 * @return 1 если есть такие элементы, иначе 0
 */
void findPositiveMod2(const int* arr, const size_t size, const int k);

/**
 * @brief Печатает массив
 * @param arr Массив
 * @param size Размер массива
 */
void printArray(const int* arr, const size_t size);

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
    int start = 0;
    int end = 0;
    srand((unsigned)time(NULL));

    printf("Enter array size: "); // Введите размер массива:
    size_t size = checkValuePositive();

    int* arr = malloc(size * sizeof(int));
    checkMemory(arr);

    printf("Choose fill method (%d random, %d manual): ", RANDOM, MANUAL);
    // Выберите метод заполнения (1 случайно, 2 вручную):

    int choice = checkValuePositive();

    switch (choice)
    {
        case RANDOM:
            printf("Enter START and END for numbers\n");
            start = checkValue();
            end = checkValue();
            fillRandom(arr, size, start, end);
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

    int p = productEven(copy, size);
    printf("Product of even-valued elements: %d\n", p);
    // Произведение чётных элементов

    replaceOddIdx(copy, size);
    printf("Array after replacing odd indices: "); // Массив после замены нечётных индексов:
    printArray(copy, size);

    printf("Enter k: ");
    int k = checkValuePositive();
    findPositiveMod2(copy, size, k);

    free(arr);
    free(copy);

    return 0;
}

int checkValue()
{
    int value = 0;
    if (!scanf("%d",&value))
    {
        printf("Invalid input\n");
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

int checkValuePositive()
{
    int x = 0;
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input. Enter integer: "); // Неверный ввод. Введите целое число.
        exit(1);
    }
    else if (x <= 0)
    {
        printf("Value has to be positive");
        exit(1);
    } 
    return x;
}

void fillManual(int* arr, const size_t size)
{
    printf("Enter %zu integers: ", size); // Введите N чисел (%zu - подходит и для 64 и для 32 бита(универсальное))
    for (size_t i = 0; i < size; i++)
        arr[i] = checkValue();
}

void fillRandom(int* arr, const size_t size, const int start, const int end)
{
    for (size_t i = 0; i < size; i++)
        arr[i] = start + rand() % (end - start + 1);
}

int* copyArray(const int* arr, const size_t size)
{
    int* newArr = malloc(size * sizeof(int));
    checkMemory(newArr);

    for (size_t i = 0; i < size; i++)
        newArr[i] = arr[i];

    return newArr;
}

int productEven(const int* arr, const size_t size) // тут int достаточно, если что поменять на long long
{
    int res = 1; // --||--
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

void replaceOddIdx(int* arr, const size_t size)
{
    for (size_t i = 1; i < size; i += 2)
        arr[i] = (int)(i * i);
}

void findPositiveMod2(const int* arr, const size_t size, const int k)
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
}

void printArray(const int* arr, const size_t size)
{
    printf("Array: ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
