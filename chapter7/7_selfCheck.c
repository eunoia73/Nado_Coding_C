#include <stdio.h>
void square(int *ptr);  //함수 선언

int main(void){
    int arr[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for(int i = 0; i < 10; i++){
        square(&arr[i]);
    }

    for(int j = 0; j < 10; j++){
        printf("%d ", arr[j]);
        if(j + 1 < 10){  //다음 요소가 남아있는 경우에만 쉼표 출력
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}

void square(int *ptr){
    if(*ptr % 2 == 0){
        *ptr = (*ptr) * (*ptr);
    }


}