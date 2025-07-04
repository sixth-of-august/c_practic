# include <stdio.h>
# include <stdlib.h>
# include "list.h"

/**
* @brief структура списка
* @param data: данные списка
* @param next: указатель на следующий узел
* @param prev: указатель на предыдущий узел
*/
struct Node{
    float data; // значение
    struct Node *next; // ссылка на следующий узел
    struct Node *prev; // ссылка на предыдущий узел
};

// даём структуре имя, чтобы обращаться к нему
typedef struct Node Node;

/**
* @brief функция создания списка
* @param data: данные списка
* @return инициализированный список
*/
Node* create_node(float data){

    // выделение размера под запись
    Node *node = malloc(sizeof(Node));

    // создание нового списка
    node -> data = data;
    node -> next = NULL;
    node -> prev = NULL;

    // возвращаем список
    return node;
}

/**
* @brief функция добавление узла в список
* @param head: указатель на голову списка
* @param data: данные списка
*/
void add_node(Node* head,float data){
    Node *new_node = create_node(data);

    if (head == NULL){
        head  = new_node;
        exit;
    } else {
    Node *current = head;

    while(current -> next != 0){
    current = current -> next;
    }

    // запись нового элемента в список
    current -> next = new_node;
    new_node -> prev = current;
} }

/**
* @brief функция вывода списка на экран
* @param head: указатель на голову списка
*/
void print_list(Node * first){

    // проверка на нулевой список
    if(first == NULL){ return;}

    // запись - текущяя, создаём и инициализириуем
    Node *cur = first;

    // пока раобтает счётчик, добавляем узлы
    while(cur != NULL){
        printf("%.3f ", cur->data);

        // переходим к следующему узлу
        cur = cur -> next;
    }

    printf("\n");
}

/**
* @brief создаёт список со случайными значениями
* @param n: размер списка
* @return: случайно-заполненный список
*/
Node* create_random_list(size_t n){

    // если размер списка = 0, то завершаем программу
    if (n == 0) return NULL;

    // инициализация списка со случайным значением
    Node *first = create_node(rand() % 100);
    Node *last = first;
     n--;

    // пока не дойдём до конца списка - заполняем его значениями
    while(n != 0){
    
        Node *new_node = create_node(rand() % 100);
        new_node -> prev = last;
        last -> next = new_node;
    
     last = new_node;

    // уменьшаем счётчик
         n--;}
    return first;
}

/**
* @brief функция вычислений (по  заданию)
* @param head: указатель на голову списка
* @param n: размер списка
*/
void list_factor_plus(Node *head, int n){

    Node *cur = head;
    int factorial = 1;

    for (int i = 1; i <= n; i++){
        factorial *= i;

        // записываем изменённое значение
         cur -> data += factorial; 
        cur = cur -> next; }
}

/**
* @brief функция вычислений (по  заданию 534)
* @param head: указатель на голову списка
* @param n: размер списка
* @return: сумма по формуле
*/
double list_calc(Node *head, int n) {
    // инициализируем первый и последний узел
    Node *last = head;
    Node *first = head;

    // инициализируем переменную суммы
    double sum = 0.0;

    // присваиваем last значение последнего узла
    while (last->next != NULL) {
        last = last->next;
    }

    int i = 0; n--;
    // считаем сумму
    do{
        sum += (first->data) * (last->data);

        // переходим на следующие элементы
        first = first->next;
        last = last->prev; 
        i++; n--;
    } while(i < n);
    
    return sum;
}

/**
* @brief функция очистки листа
* @param head: указатель на голову списка
*/
void list_clear(Node *head){

    // узел для перехода по списку
    Node *next_node;

    // пока не дойдём до конца
    while(head != NULL){
    
    // очистка по переходу на следующее значение
        next_node = head -> next;
        free(head);
        head = next_node;
    } }

    /*
    действия в компиляторе - 

    // создаём обьектный файл
    gcc -c list.c -o list.o 
    */