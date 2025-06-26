# include <stdio.h> 
# include <locale.h>
# include <stdlib.h>
# include <math.h>

int main(){
int vertical = 0, diagonal = 0, field_v = 0, field_g = 0;

setlocale(LC_ALL, "");

puts("Введите номер вертикали поля: "); scanf("%d", &vertical);
puts("Введите номер горизонтали поля: "); scanf("%d", &diagonal);

puts("Введите номер вертикали поля (для сравнения): "); scanf("%d", &field_v);
puts("Введите номер горизонтали поля (для сравнения): "); scanf("%d", &field_g);

if (vertical < 1 || vertical > 8 
&& diagonal < 1 || vertical > 8){
 puts("Выбранное поле не существует");
 exit;

} else if (field_v < 1 || field_v > 8 
&& field_g < 1 || field_g > 8){
 puts("Поле для сравнения не существует");
 exit; 
}

if (vertical % 2 == 0 && diagonal % 2 != 0
&& field_v % 2 == 0 && field_g % 2 != 0){
 puts("Выбранные поля чёрного цвета");

} else if (vertical % 2 != 0 && diagonal % 2 == 0
&& field_v % 2 != 0 && field_g % 2 == 0) {
 puts("Выбранные поля белого цвета");

} else {
 puts("Поля различного цвета"); }

return(0);
}