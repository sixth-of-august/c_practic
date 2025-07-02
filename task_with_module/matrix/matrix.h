# pragma once
// директива, которая запрещает множественное копирование модулей
// это заголовочный файл модуля с исполняемым кодом matrix.c

/**
*@todo: модуль для работы с матрицами
*/

// подключённые библиотеки
# include <stdio.h>
# include <stdlib.h>

// структура хранящая номер строки и столбец
struct RowsCols;

// даём структуре имя, чтобы обращаться к нему
typedef struct RowsCols RowsCols;

/**
* @brief функция инициализации матрицы
* @param rows: количество строк
* @param cols: количество столбцов
* @return: инициализированная матрица
*/
float** init_matr(int  rows, int cols);

/**
* @brief функция заполнения матрицы случайными значениями
* @param matr: вещественная матрица
* @param rows: количество строк
* @param cols: количество столбцов
*/
void matrix_random(float **matr, size_t rows, size_t cols);

/**
* @brief функция вывода матрицы на экран
* @param matr: вещественная матрица
* @param rows: количество строк
* @param cols: количество столбцов
*/
void print_matr(float **matr, size_t rows, size_t cols);

/**
* @brief функция вычитания матриц
* @param matr_1: первая матрица
* @param matr_2: вторая матрица
* @param rows: количество строк
* @return сумма матриц
*/
float** matr_minus(float **matr_1, float **matr_2, size_t rows);

/**
* @brief функция умножения матриц
* @param matr_1: первая матрица
* @param matr_2: вторая матрица
* @param rows: количество строк
* @return: результат умножения
*/
float** matr_multiply(float **matr_1, float **matr_2, size_t rows);

/**
* @brief функция поиска адресса ячейки с мин.значением
* @param matrix: первая матрица
* @param rows: строки
* @param cows: столбец
* @return: результат поиска
*/
struct RowsCols min_matrix_RC(float** matrix, int  rows, int cols);

/**
* @brief функция перестановки значений
* @param matrix: матрица со значениями
* @param rows_1: строка с ячейкой для замены
* @param rows_1: строка куда заменить
* @param cols_1: столбец с ячейкой для замены
* @param cols_2: столбец куда заменить
* @return: результат поиска
*/
float** element_change(float** matrix, int  rows_1, int cols_1, int rows_2, int cols_2);

/**
* @brief функция очистки памяти, занятой динамической матрицей
* @param matr: вещественная матрица
* @param rows: количество строк
*/
void matr_free(float **matr, size_t rows);