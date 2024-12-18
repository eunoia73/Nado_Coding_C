#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *item_name[3][4] = {
    {"1.우유", "2.커피", "3.주스", "4.탄산음료"},
    {"5.칸칩", "6.거북칩", "7.감자칩", "8.고구마칩"},
    {"9.안타볼", "10.초코버섯", "11.가재깡", "12.씨리얼"}
};


int main(void){
    
    printf("전체 상품 목록입니다.\n");
    printf("=============================================\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%-14s", item_name[i][j]);
        }
        printf("\n");
    }

    printf("\n==============================================\n");
    printf("몇 번 상품을 구매하시겠습니까?(1~12) : ");
    int input = 0;
    scanf("%d", &input);

    //유효하지 않을 경우
    if(!(1 <= input && input <= 12)){
        printf("유효하지 않은 값입니다.");
        exit(0);
    }

    //0~3
    int x = (input - 1) / 4;
    int y = (input - 1) % 4;

    printf("구매하신 상품은 %s입니다.\n", item_name[x][y]);
    printf("이용해 주셔서 감사합니다.");

    return 0;
}