// модуль для  работы с файлами
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

// заголовочный файл модуля
# include "files.h"

// структура - ученик
struct student{
    // имя ученика
    char name[20];

    // фамилия ученика
    char surname[30];

    // номер класса
    int number;

    // буква класса
    char letter[2];
};

// даём структуре имя, чтобы обращаться к нему
typedef struct student student;

/**
 * @brief функция для заполнения переменной
 * @param: файл для открытия
 * @param file_name: имя файла
 * @return заполненная переменная
 */
student get_student(FILE *open_file, char file_name[]){

// задаём переменную для возврата
student s;

// сканируем значения в структуру
fscanf(open_file, "%s %s %d %s", s.name, s.surname, &s.number, s.letter);

// возвращаем заполненную переменную
return s;
}

/**
 * @brief процедура поиска однофамильцев с разных паралелей
 * @param file_name: имя открываемого файла
 */
void surname_search(char file_name[]){

// обьявление файловыъ переменных
FILE *first_open, *second_open;

// открываем файлы для чтения
first_open = fopen(file_name, "r");
second_open = fopen(file_name, "r");

// переменные для хранений данных для студентов
student s1, s2;

// проходим дор конца цикла
while(feof(first_open) == 0){

    // записываем данные второго студента
    s1 = get_student(first_open, file_name);
    
    // запоминаем позицию после сравнения, чтобы избежать повторений 
    long pos = ftell(first_open);

    // после прохода до конца второго файла, возвращаем курсор после проверенной переменной
    // SEEK_SET - это константа, показывающая откуда нужно сместить курсор (с начала файла)
    fseek(second_open, pos, SEEK_SET);

    // цикл идёт до конца файла
    while(feof(second_open) == 0){

        // запись значений второго студента
        s2 = get_student(second_open, file_name);
        
        // проверка на условия
        if (strcmp(s1.surname, s2.surname) == 0 && 
            strcmp(s1.letter, s2.letter) != 0 &&
            s1.number == s2.number){

            // вывод сообщения на экран
            printf("Ученики %s и %s носят одну фамилию - %s, в паралелях %d-ого класса \n", s1.name, s2.name, s1.surname, s1.number);
        } } 

// закрываем файлы после работы
} fclose(first_open); fclose(second_open);

}

/**
 * @brief функция поиска максимального вещественного значения в файле
 * @param file_name: имя файла
 * @return: максимальное вещественное число
 */
float max_in_file(char file_name[]){

// инциализируем переменную, которая будет хранить мак.знач
// и временную переменную 
float max = 0.0, temp = 0.0;

// инициализируем файловую переменную
FILE* open_file;

// открываем файл по имени в режиме для чтения
open_file = fopen(file_name, "r");

// считываем первую переменную
fscanf(open_file, "%f", &max);  

// проходимся до конца файла
while (feof(open_file) == 0){
    
    // сканируем число во временную переменную
    fscanf(open_file, "%f", &temp);

    // проверяем, больше ли эта переменная макс.значения
       if (temp > max) {max = temp; }   
    
    // возвращаем максимальное значение
    // закрываем файл
    } return max; fclose(open_file); }

/**
 * @brief функция для записи значений в файл
 * @param file_name: имя файла
 * @param n: количество чисел
 */
void f_write_real(char file_name[], int n){

// обьявляем фаловую переменную
FILE *rewrite_file;

// рандомайзер
srand(time(NULL));

// временная переменная для хранения значений
double temp = 0.0;

// открываем файл для записи
rewrite_file = fopen(file_name, "w");

// записываем переменные в файл с форматированием
for (int i = 0; i < n; i++){
    temp = rand() % 125;
    fprintf(rewrite_file, "%.3f\n", temp);
}

// закрываем файл после завершения работы
fclose(rewrite_file);

}