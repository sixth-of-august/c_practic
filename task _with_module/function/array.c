// модуль array с исполняемым кодом 

// включённые модули программы
# include <stdio.h>

// заголовочный файл
# include "array.h"

/**
* @brief функция поиска максимального значения в массиве
* @param arr: динамический массив
* @param length: длина массива
* @return: максимальное значение в массиве
*/
int max_in_arr(int *arr, int length){
    int max = arr[0];
    for(int i = 1; i < length; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }  return max;
}

/**
* @brief процедура ввода элементов массива
* @param arr: динамический массив
* @param length: длина массива
*/
void scan_arr(int *arr, int length){
   for(int i = 0; i < length; i++){
    printf("Введите элемент[%d]: ", i + 1);
    scanf("%d", &arr[i]);
   }
}

/**
* @brief процедура вывода элементов массива
* @param arr: динамический массив
* @param length: длина массива
*/
void print_arr(int *arr, int length){
   for(int i = 0; i < length; i++){
    printf("%d ", arr[i]);
   } printf("\n"); 
}

/* действия в компиляторе 

содание объектного файла из исполняемого
gcc -c array.c -o array.o*/