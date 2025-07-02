# pragma once

# include <stdio.h>
# include <stdlib.h>

/**
* @brief структура списка
* @param data: данные списка
* @param next: указатель на следующий узел
* @param prev: указатель на предыдущий узел
*/
struct Node;

// даём структуре имя, чтобы обращаться к нему
typedef struct Node Node;

/**
* @brief функция создания списка
* @param data: данные списка
* @return инициализированный список
*/
Node* create_node(float data);

/**
* @brief функция добавление узла в список
* @param head: указатель на голову списка
* @param data: данные списка
*/
void add_node(Node* head,float data);

/**
* @brief функция вывода списка на экран
* @param head: указатель на голову списка
*/
void print_list(Node * first);

/**
* @brief создаёт список со случайными значениями
* @param n: размер списка
* @return: случайно-заполненный список
*/
Node* create_random_list(size_t n);

/**
* @brief функция вычислений (по  заданию)
* @param head: указатель на голову списка
* @param n: размер списка
*/
void list_factor_plus(Node *head, int n);

/**
* @brief функция вычислений (по  заданию 534)
* @param head: указатель на голову списка
* @param n: размер списка
* @return: сумма по формуле
*/
double list_calc(Node *head, int n);

/**
* @brief функция очистки листа
* @param head: указатель на голову списка
*/
void list_clear(Node *head);