#include <stdio.h>
void changeArray(int* ptr); //함수 선언

int main(void){
    int arr2[3] = {10, 20, 30};
    changeArray(arr2);  //배열의 시작 주소는 배열의 이름이므로 주소 전달시 & 안 붙여도 됨 (&arr2[0]과 같음)
    for(int i = 0; i < 3; i++){
        printf("%d\n", arr2[i]);
    }

    return 0;
}

void changeArray(int* ptr){
    ptr[2] = 50;
}