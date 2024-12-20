#include <stdio.h>
void square(int * ptr);

int main(void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++){
        square(&arr[i]);
    }


    for(int j = 0; j < 10; j++){
        printf("%d", arr[j]);
        if(j + 1 < 10) printf(", ");
    }

    return 0;
}

void square(int * ptr){
    if(*ptr % 2 == 0){
        *ptr = (*ptr) * (*ptr);
    }
}