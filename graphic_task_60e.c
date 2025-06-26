# include <stdio.h>
# include <locale.h>
# include <math.h>

int main () {
   
    double x = 0.0, y = 0.0, result = 0.0;
    
    setlocale(LC_ALL, "");

    puts("Введите действительное число Х: ");  scanf("%lf", &x);
    puts("Введите действительное число Y: ");  scanf("%lf", &y);
   
   if (y > 0 && y < 1  
   && y < exp(x) 
   && y < exp(-x)
   && y >= pow(x, 2))
   { 
     result = x + y;
     printf("Точка находится в окрашенной зоне, (результат x + y) %.4lf", result); 
   
    } else {
     result = x - y;
     printf("Точка не находится в окрашенной зоне, (результат  x - y) %.4lf", result);
   }
    return 0;
}