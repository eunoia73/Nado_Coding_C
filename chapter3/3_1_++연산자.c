#include <stdio.h>

int main(void){

    // ++연산자
    int a = 10;
    printf("a는 %d\n", a);  //10
    a++;     //a = a + 1;
    printf("a는 %d\n", a);  //11
    a++;     
    printf("a는 %d\n", a);  //12

    int b = 20;
    printf("b는 %d\n", ++b);   //21
    printf("b는 %d\n", b++);   //21
    printf("b는 %d\n", b);     //22


    return 0;
}