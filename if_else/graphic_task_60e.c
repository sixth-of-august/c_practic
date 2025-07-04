/* автор программы - Лесков. Н. Г.

задание - пусть D - заштрихованная часть плоскости
и пусть U определяется по x и y следующим образом 
(запись(x, y) Є D означает, что точка с координатами x, y принадлежит D)

     { x + y, если (x, y) Є D
U =  { x - y, в противном случае

подключаем библиотеки для работы программы
stdio.h - для ввода и вывода в консоль
locale.h - для отображения кириллицы в консоли
math.h - для математических функций*/
# include <stdio.h>
# include <locale.h>
# include <math.h>

// основное тело программы
int main () {
   
   // создаём переменные для ввода значений и вывода результата
   // записываем в них значение, чтобы инициализировать переменные
    double x = 0.0, y = 0.0, result = 0.0;
    
    // устанавливаем локаль для корректного отображения русских символов
    setlocale(LC_ALL, "");
   
    // выводим сообщение и считываем переменную формата %lf (double), 
    // в scanf делаем адрес на перемнную для записи значения
    puts("Введите действительное число Х: ");  scanf("%lf", &x);
    puts("Введите действительное число Y: ");  scanf("%lf", &y);
   
   // проводим проверку на значение y
   if (y > 0 && y < 1  

  // проводим проверку на положение точки ниже графика exp^x
   && y < exp(x) 

   // проводим проверку на положение точки ниже графика exp^-x
   && y < exp(-x)

   // проводим проверку на положение точки выше графика x^2
   && y >= pow(x, 2))
   { 
    /* счиатем значение и
    выводим соообщение о нахождении точки в закрашенной зоне
    в форматированом виде - 4 точки после запятой */
     result = x + y;
     printf("Точка находится в окрашенной зоне, (результат x + y) %.4lf", result); 
   
    } else {
    /* счиатем значение и
    выводим соообщение о нахождении точки в не закрашенной зоне
    в форматированом виде - 4 точки после запятой*/
     result = x - y;
     printf("Точка не находится в окрашенной зоне, (результат  x - y) %.4lf", result);
   }

    // завершаем программу и возвращаем 0
    return 0;
}

/* действия в консоли -- 
 создаём исполняемый файл и указываем файл для компиляции
  gcc -o graphic_task graphic_task_60e.c
  
  запускаем исполняемый файл
  ./graphic_task                        */ 
