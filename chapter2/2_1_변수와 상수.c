#include <stdio.h>

int main(void){
    // 변수
    
    //정수형
    int age = 20;
    printf("%d\n", age);
    age = 21;
    printf("%d\n", age);


    //실수형
    float f = 46.5f;
    printf("%.2f\n", f);

    double d = 4.428;
    printf("%.2lf\n", d);

    float f = 2121.1020f;
    printf("%.3f\n", f); 


    // 상수

    const int YEAR = 1972;  //상수
    printf("C 언어가 발표된 연도 : %d\n", YEAR);
    //YEAR = 1973; 상수는 변경 불가

    return 0;
}