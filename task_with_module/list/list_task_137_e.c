/* Автор - Лесков Никита
 
   Задание - Даны натуральное число n, действительные числа а1,..., an
    Вычислить: е) a1 + 1!, a2 + 2!, ..., an + n!. 
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

// переменная длины списка
int length = 0;

// ввод количества элементов списка
puts("Введите длину списка: ");
scanf("%d", &length);

// заполнение списка вещественными значениями
Node *head = create_random_list(length);

// вывод списка
puts("Ваш список: ");
print_list(head);

// процес вычислений
list_factor_plus(head, length);

// вывод списка
puts("Ваш список (после операций): ");
print_list(head);

// очистка памяти списка
list_clear(head);

// помечаем указатель свободным
head = NULL;
}
/*
создаём исполняемый файл, связаный с модулем
gcc list.c list_task_137_e.c -o list_task

запускаем исполняемый файл
./list_task
*/