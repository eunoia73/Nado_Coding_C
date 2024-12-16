#include <stdio.h>
void swap(int a, int b);  //함수 선언
void swap_addr(int *a, int *b);  //매개변수가 포인터 변수

//포인터로 두 변수의 값 교환하기
int main(void){
    int a = 10;
    int b = 20;
    printf("a의 주소 : %p\n", &a);
    printf("b의 주소 : %p\n", &b);
    printf("swap() 함수 호출 전 => a : %d, b : %d\n", a, b);  //교환 전
    swap(a, b); // 값에 의한 호출
    printf("swap() 함수 호출 후 => a : %d, b : %d\n", a, b);  //교환 후

    printf("swap_addr() 함수 호출 전 => a : %d, b : %d\n", a, b);  //교환 전
    swap_addr(&a, &b);  //주소 전달 참조에 의한 호출
    printf("swap_addr() 함수 호출 후 => a : %d, b : %d\n", a, b);  //교환 후


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

void swap_addr(int *a, int *b){
    int temp = *a;  //포인터 변수 a에 담긴 주소의 실제 값 저장
    *a = *b;
    *b = temp;
    printf("swap_addr() 함수 안 => a : %d, b : %d\n", *a, *b);
} 