#include <stdio.h>

int main(void){
    // for(int i = 1; i <= 3; i++){
    //     printf("첫 번재 반복문 : %d\n", i);
    //     for(int j = 1; j <= 5; j++){
    //         printf("    두 번째 반복문 : %d\n", j);
    //     }
    // }

    //실습 1 : 구구단 출력하기
    // for(int i = 2; i <= 9; i++){
    //     printf("\n%d단 출력\n", i);
    //     for(int j = 1; j <= 9; j++){
    //         printf("%d X %d = %d\n", i, j, i*j);
    //     }
    // }

    //실습 2 : 별표 출력하기
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j <= i; j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    //실습 3 : 오른쪽 정렬로 별표 출력하기
    //내가 짠 코드
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4 - i; j++){
            printf("S");
        }
        for(int k = 0; k <= i; k++){
            printf("*");
        }
        printf("\n");
    }

    // 교재에 나온 코드 
    // for(int i = 0; i < 5; i++){
    //     for(int j = i; j < 5-1; j++){
    //         printf("S");
    //     }
    //     for(int k = 0; k <= i; k++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    //


    return 0;
}