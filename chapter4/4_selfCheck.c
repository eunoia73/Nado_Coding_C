#include <stdio.h>

int main(void){
    int coffee_c = 0;
    int sand_c = 0;
    
    printf("커피 개수 : ");
    scanf("%d", &coffee_c);
    printf("샌드위치 개수 : ");
    scanf("%d", &sand_c);

    int total = 0;  //총 금액
    //커피 1잔의 가격 : 4500
    //샌드위치 1개 가격 : 6000
    //샌드위치 구매시 커피 잔당 3500원
    if(sand_c > 0){
        total = sand_c * 6000 + coffee_c * 3500;
    }else{
        total = coffee_c * 4500;
    }

    //교재 코드
    // if(sand_c > 0 && coffee_c > 0){
    //     total = (sand_c * 6000) + (coffee_c * 3500);
    // } else {
    //     total = (sand_c * 6000) + (coffee_c * 4500);
    // }
    printf("주문하신 메뉴의 총 금액은 %d원입니다.", total);

    return 0;
}