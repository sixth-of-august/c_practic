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
* @brief функция вычитания матриц
* @param matr_1: первая матрица
* @param matr_2: вторая матрица
* @param rows: количество строк
* @return сумма матриц
*/
float** matr_minus(float **matr_1, float **matr_2, size_t rows){
    
    // создаём указатель на матрицу
    float **matr_minus = NULL;
    
    // инициализируем матрицу
    matr_minus = init_matr(rows, rows);

    // суммируем матрицы
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
          matr_minus[i][j] =  matr_1[i][j] - matr_2[i][j];
        }

    // возвращаем результат и очищаем память
    } return matr_minus; matr_free(matr_minus, rows);
}

/**
* @brief функция умножения матриц
* @param matr_1: первая матрица
* @param matr_2: вторая матрица
* @param rows: количество строк
* @return: результат умножения
*/
float** matr_multiply(float **matr_1, float **matr_2, size_t rows){
    
    // создаём указатель на матрицу
    float **matr_mult = NULL;
    
    // инициализируем матрицу
    matr_mult = init_matr(rows, rows);

    // перемножаем матрицы
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){

            // инициализируем первый элемент
            matr_mult[i][j] = 0;
            for (int k = 0; k < rows; k++){

                // умножаем строку на каждый элемент столбца и суммируем их
             matr_mult[i][j] += matr_1[i][k] * matr_2[k][j]; 
            }
        } // возвращаем результат и очищаем память
    } return matr_mult; matr_free(matr_mult, rows);
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