# pragma once
// директива, которая запрещает множественное копирование модулей
// это заголовочный файл модуля с исполняемым кодом array.c

/**
* @todo: модуль для работы с массивами
*/

// подключённые библиотеки
# include <stdio.h>

/**
* @brief функция поиска максимального значения в массиве
* @param arr: динамический массив
* @param length: длина массива
* @return: максимальное значение в массиве
*/
int max_in_arr(float *arr, int length);

/**
* @brief процедура ввода элементов массива
* @param arr: динамический массив
* @param length: длина массива
*/
void scan_arr(float *arr, int length);

/**
* @brief процедура вывода элементов массива
* @param arr: динамический массив
* @param length: длина массива
*/
void print_arr(float *arr, int length);
