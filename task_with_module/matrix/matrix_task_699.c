/*
автор Лесков Н. Г.

задание - даны квадратные матрицы А и В порядка n. Получить матрицу АВ-ВА
*/

// используемые модули программы
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <time.h>

// пользовательский модуль с действиями в матрице
# include "matrix.h"

int main(){
    // рандомайзер
    srand(time(NULL));

    // устанавливаем локаль для корректного отображения русских символов
    setlocale(LC_ALL, "");
   
    // переменная, хранящая длину матрицы
    unsigned int n = 0;
   
    // вывод сообщения - введите размерность матрицы
    puts("Введите порядок матрицы A и B - "); scanf("%u", &n);
    
    // инициализируем указатели на матрицы
    float  **matr_a = NULL, **matr_b = NULL, **matr_c = NULL, **matr_d = NULL;

    // инициализируем матрицы
    matr_a = init_matr(n, n);
    matr_b = init_matr(n, n);
    matr_c = init_matr(n, n);

    // заполняем матрицы случайными значениями
    matrix_random(matr_a, n, n);
    matrix_random(matr_b, n, n);
   
    // выводим матрицы на экран 
    puts("Ваша матрица А: "); print_matr(matr_a, n, n);
    puts("Ваша матрица B: "); print_matr(matr_b, n, n);

    // считаем результат операций
    matr_c = matr_minus(matr_multiply(matr_a, matr_b, n), matr_multiply(matr_b, matr_a, n), n);
    
    // выводим полученный результат
    puts("Полученная матрица: "); print_matr(matr_c, n, n);

    // освобождаем память от матрицы
    matr_free(matr_a, n);
    matr_free(matr_b, n); 
    matr_free(matr_c, n); 

    // помечаем указатели как свободные
    matr_a = NULL; 
    matr_b = NULL;
    matr_c = NULL;

    return 0;
}

/* действия в консоли

связываем код программы и модуль в приложение
gcc matrix.c matrix_task_699.c -o matrix_task

запускаем приложение
.\matrix_task

*/