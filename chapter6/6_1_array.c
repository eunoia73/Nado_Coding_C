#include <stdio.h>

int main(void){
    int subway_array[3];
    subway_array[0] = 30;
    subway_array[1] = 40;
    subway_array[2] = 50;

    for(int i = 0; i < 3; i++){
        printf("지하철 %d호차에 %d명이 타고 있습니다.\n", i+1, subway_array[i]);
    }

    //배열 일부만 초기화
    int arr[10] = {1, 2}; //일부 값 초기화
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    //배열 일부만 초기화하면 나머지 값은 모두 0이 된다.


    //배열 초기화X => 이상한 쓰레기 값이 들어감
    int arr2[10];
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr2[i]);
    }

    return 0;
}