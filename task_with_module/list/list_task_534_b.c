/* Автор - Лесков Никита
 
   Задание - Даны натуральное число n, действительные числа а1,..., an
    Вычислить: б) a1a2n + a2a2n-1 +...+ anan+1; 
 */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <locale.h>

// пользовательский модуль
# include "list.h"

int main() {
// рандомайзер
srand(time(NULL));

int length = 0; // переменная длины списка
double sum = 0.0; // переменная суммы

// ввод количества элементов списка
puts("Введите длину списка: ");
scanf("%d", &length);
length *= 2;

// заполнение списка вещественными значениями
Node *head = create_random_list(length);

// вывод списка
puts("Ваш список: ");
print_list(head);

// процес вычислений
sum = list_calc(head, length);

// вывод результата
printf("Результат вычислений по формуле = %.3f\n", sum);

// очистка памяти списка
list_clear(head);

// помечаем указатель свободным
head = NULL;
}
/*
создаём исполняемый файл, связаный с модулем
gcc list.c  list_task_534_b.c -o list_task_2

запускаем исполняемый файл
./list_task_2
*/