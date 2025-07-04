# include <stdlib.h>
# include "factorial.h"

/**
* @brief функция для вычисления факториала
* @param value: число для которого требуется вернуть число факториала
* @return: число факториала
*/
long factorial(int value){
    int return_value = 1; 
for (int i = 1; i < value; i++){
    return_value *= i;
}
return return_value;
}

/* gcc -c factorial.c -o factorial.o*/