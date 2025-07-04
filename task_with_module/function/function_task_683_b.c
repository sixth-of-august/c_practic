/*
автор Лесков Н. Г.

задание - Назовем допустимым преобразованием матрицы перестановку двух строк или двух столбцов
Дана действительная квадратная матрица порядка n. С помощью допустимых преобразований добиться того, чтобы

    б) один из элементов матрицы, обладающий наименьшим значением, располагался в левом нижнем углу матрицы. 
*/

// используемые модули программы
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <time.h>
# include <math.h>

// пользовательский модуль с действиями в матрице
# include "matrix.h"

// обьявляем структуру
struct RowsCols{
// поля структуры
short rows;

// столбец
short cols; };

int main(){
    // рандомайзер
    srand(time(NULL));

    // устанавливаем локаль для корректного отображения русских символов
    setlocale(LC_ALL, "");

    // переменная с размером матрицы
    int  length = 10;

    // указатель на динамическую память
    float **matrix;

    struct RowsCols RowsCols1;

    // требуем ввести порядок матрицы
    puts("Введите размер матрицы"); scanf("%d", &length);

    // инициализируем динамическую матрицу
    matrix = init_matr(length, length);

    // заполняем массив случайными значениями с изменением в знаке
    for (int i = 0; i < length; i++){
    for (int j = 0; j < length; j++){
        matrix[i][j] = (rand() % 10 ) * powf(-1, rand() % 2);
    } }

    // выводим на экран начальную матрицу
    puts("Матрица до перестановки: ");
    print_matr(matrix, length, length);

    // записываем ячейку с минимальным значением в память
    RowsCols1 = min_matrix_RC(matrix, length, length);

    // вывод сообщения о том, где находилось минимальное значение
    printf("Минимальное число находилось в ячейке[%hd][%hd]\n", RowsCols1.rows + 1, RowsCols1.cols + 1);

    // меняем ячейки местами
    // matrix = element_change(matrix, RowsCols1.rows, RowsCols1.cols, length - 1, length - 1);

    // выводим матрицу с перестановкой
    puts("Матрица после перестановки: ");
    row_change(matrix, length, RowsCols1.rows, length - 1);
    cols_change(matrix, length, RowsCols1.cols, length - 1);

    print_matr(matrix, length, length);

    // очищаем память динамической матрицы
    matr_free(matrix, length);

    // делаем указатель пустым
    matrix = NULL;
}

/* Действия в компиляторе 

связываем код программы и модуль в приложение
 gcc matrix.c function_task_683_b.c -o function_task_2

запускаем приложение
 .\function_task_2
 */