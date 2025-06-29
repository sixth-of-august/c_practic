// модуль matrix с исполняемым кодом 

// включённые модули программы
# include <stdio.h>
# include <stdlib.h>

// заголовочный файл
# include "matrix.h"


/**
* @brief функция инициализации матрицы
* @param rows: количество строк
* @param cols: количество столбцов
* @return: инициализированная матрица
*/
float** init_matr(int  rows, int cols){

    // выделение памяти под первую строку
     float **matr = malloc(rows * sizeof(float*));
    
     // выделение памяти под столбцы матрицы
    for (size_t i = 0; i < rows; i++){
     matr[i] = malloc(cols * sizeof(float));
    } 

    // возвращение инициализированной матрицы
    return matr;
}

/**
* @brief функция заполнения матрицы случайными значениями
* @param matr: вещественная матрица
* @param rows: количество строк
* @param cols: количество столбцов
*/
void matrix_random(float **matr, size_t rows, size_t cols){
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
        matr[i][j] = rand() % 10;
        }       
    }
}

/**
* @brief функция вывода матрицы на экран
* @param matr: вещественная матрица
* @param rows: количество строк
* @param cols: количество столбцов
*/
void print_matr(float **matr, size_t rows, size_t cols){
   for (int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
    printf("%.2f ", matr[i][j]);
        }
        // переход но новую строку после вывода
        printf("\n");

      // переход на новую строку после вывода матрицы
    } printf("\n");
}

/**
* @brief функция очистки памяти, занятой динамической матрицей
* @param matr: вещественная матрица
* @param rows: количество строк
*/
void matr_free(float **matr, size_t rows){
    for (size_t i = 0; i < rows; i++){
        // освобождаем память кажого столбца
        free(matr[i]);
    }
// освобождаем память строки    
free(matr);
}

/* Действия в консоли :

связываем файл с кодом модуля с заголовочным файлом
-c matrix.c -o matrix.o
*/