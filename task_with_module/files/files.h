#pragma once
// директива запрещающее повторное дублирование модулей

# include <stdio.h>
# include <locale.h>

// структура - ученик
struct student;

// даём структуре имя, чтобы обращаться к нему
typedef struct student student;

/**
 * @brief функция для заполнения переменной
 * @param: файл для открытия
 * @param file_name: имя файла
 * @return заполненная переменная
 */
student get_student(FILE *open_file, char file_name[]);

/**
 * @brief процедура поиска однофамильцев с разных паралелей
 * @param file_name: имя открываемого файла
 */
void surname_search(char file_name[]);

/**
 * @brief функция поиска максимального вещественного значения в файле
 * @param file_name: имя файла
 * @return: максимальное вещественное число
 */
float max_in_file(char file_name[]);

/**
 * @brief функция для записи значений в файл
 * @param file_name: имя файла
 * @param n: количество чисел
 */
void f_write_real(char file_name[], int n);