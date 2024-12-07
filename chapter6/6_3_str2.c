#include <stdio.h>

int main(void){
    char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\n'};
    //printf("%s\n", c_array);

    char c_array2[10] = {'c', 'o', 'd', 'i', 'n', 'g'};
    for(int i = 0 ; i < sizeof(c_array2); i++){
        printf("%c\n", c_array2[i]);
    }


    return 0;
}