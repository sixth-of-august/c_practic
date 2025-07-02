// модуль matrix с исполняемым кодом 

// включённые модули программы
# include <stdio.h>
# include <stdlib.h>

// заголовочный файл
# include "matrix.h"

// обьявляем структуру
struct RowsCols{
// поля структуры
short rows;

// столбец
short cols; };

// даём структуре имя, чтобы обращаться к нему
typedef struct RowCols RowCols;

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
        } } }

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
* @brief функция поиска адресса ячейки с мин.значением
* @param matrix: первая матрица
* @param rows: строки
* @param cows: столбец
* @return: результат поиска
*/
struct RowsCols min_matrix_RC(float** matrix, int  rows, int cols){

// инициализируем локальную переменную
float min_value = 0;
struct RowsCols rows_cols;
        min_value = matrix[0][0];

        // проходимся циклом по элементам матрицы
      for (int i = 0; i < rows; i++){  
        for (int j = 1; j < cols; j++){
            if (min_value > matrix[i][j]){

                // заменяем минимальное значение 
                // записываем ячейку
                min_value = matrix[i][j];
                rows_cols.rows = i;
                rows_cols.cols = j;
            }    }    }     
        return rows_cols;
        };

/**
* @brief функция перестановки значений
* @param matrix: матрица со значениями
* @param rows_1: строка с ячейкой для замены
* @param rows_1: строка куда заменить
* @param cols_1: столбец с ячейкой для замены
* @param cols_2: столбец куда заменить
* @return: результат поиска
*/
float** element_change(float** matrix, int  rows_1, int cols_1, int rows_2, int cols_2){
    
    float* temp; *temp = 0.0;

    // переставляем переменные
    *temp = matrix[rows_1][cols_1];
    matrix[rows_1][cols_1] = matrix[rows_2][cols_2];
    matrix[rows_2][cols_2] = *temp;

    free(temp); temp = NULL;

    return matrix;
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