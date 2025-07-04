// 472_a 507_b

# include <stdio.h>
# include <wchar.h>

int main(){

// задаём файловый тип
FILE *open_file;

// задаём переменную для хранения макс. значения
float max;
char max_1;

// оъявляем имя файловой перменной
char file_name[] = "open_file.txt";

// открываем файл по имени в режиме для чтения
*open_file = *fopen(file_name, "w+");

fgets(max_1, 4, open_file);

for (int i = 0; i < eof(*open_file); i++){
    fgets(max_1, 4, open_file);

}

// закрываем файл после работы с ним
fclose(open_file);

return 0;
}