# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "matrix.h"

int main(){
    srand(time(NULL));
   
    // переменная, хранящая длину матрицы
    unsigned int n = 0;

    puts("Введите порядок матрицы A и B - "); scanf("%u", &n);
    

    float  **matr_a = NULL, **matr_b = NULL;

    matr_a = init_matr(n, n);
    matr_b = init_matr(n, n);

    matrix_random(matr_a, n, n);
    matrix_random(matr_b, n, n);
   
   puts("Ваша матрица А: "); print_matr(matr_a, n, n);
   puts("Ваша матрица B: "); print_matr(matr_b, n, n);

    matr_free(matr_a, n);
    matr_free(matr_b, n); 
    matr_a = NULL; matr_b = NULL;

    return 0;
}