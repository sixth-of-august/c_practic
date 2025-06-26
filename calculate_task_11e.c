# include <stdio.h>
# include <locale.h>
# include <math.h>

int main () {
   
    double x = 0.0, y = 0.0, z = 0.0;
    double a = 0.0, b = 0.0; 
    
    setlocale(LC_ALL, "");

    puts("Введите действительное число Х: ");  scanf("%lf", &x);
    puts("Введите действительное число Y: ");  scanf("%lf", &y);
    puts("Введите действительное число Z: ");  scanf("%lf", &z);
   
    double angle = powf(sin(x + y), 2);
    double denominator =  2 + fabs(x - (2 * x / (1 + powf(x, 2) * powf(y, 2))));

    a = (1 + angle) / denominator;
    b = powf(cos(atan(x / z)), 2); 

    printf("Полученное значение a = %.4lf, полученное значение b: %.4lf", a, b); 

    return 0;
}