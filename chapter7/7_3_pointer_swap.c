#include <stdio.h>
void swap(int a, int b);  //함수 선언
//포인터로 두 변수의 값 교환하기
int main(void){
    int a = 10;
    int b = 20;
    printf("a의 주소 : %p\n", &a);
    printf("b의 주소 : %p\n", &b);
    printf("swap() 함수 호출 전 => a : %d, b : %d\n", a, b);  //교환 전
    swap(a, b);
    printf("swap() 함수 호출 후 => a : %d, b : %d\n", a, b);  //교환 후


    return 0;
}

void swap(int a, int b){
    printf("swap()함수 안에서의 a의 주소 : %p\n", &a);
    printf("swap()함수 안에서의 b의 주소 : %p\n", &b);
    int temp = a;
    a = b;
    b = temp;
    printf("swap() 함수 안 => a : %d, b : %d\n", a, b);
}