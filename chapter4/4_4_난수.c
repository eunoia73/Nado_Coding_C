#include <stdio.h>
#include <time.h>  //시간 관련 함수
#include <stdlib.h>  //난수생성, 문자열 변환 등 함수

int main(void){

    printf("난수 초기화 이전...\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", rand() % 10);
    }
    //난수 초기화를 하지 않으면 여러 번 실행해도 같은 랜덤 숫자가 나온다. 

    srand(time(NULL));  //난수 초기화
    printf("\n\n난수 초기화 이후...\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", rand() % 10);
    }    

    return 0;
}