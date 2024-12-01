#include <stdio.h>

int main(void){
//피라미드를 쌓아라

    printf("몇 층으로 쌓겠습니까?(5~100) ");
    int floor; //층수
    scanf("%d", &floor);  //층 입력받기

    for(int i = 0; i < floor; i++){
        for(int j = i; j < floor - 1; j++){
            printf(" ");
        }
        for(int k = 0; k < i * 2 + 1; k++){
             printf("*");
         }
        printf("\n");
    }



    return 0;    
}