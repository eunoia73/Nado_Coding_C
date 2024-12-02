#include <stdio.h>

int main(void){
    int a = 10;
    int b = 10;
    int c = 12;
    int d = 13;

    //and 연산자
    // if(a == b && c == d){
    //     printf("a와 b가 같고 c와 d도 같습니다.\n");
    // }else{
    //     printf("값이 서로 다릅니다.\n");
    // }

    //or 연산자
    if(a == b || c == d){
        printf("a와 b 또는 c와 d의 값이 같습니다.\n");
    }


    return 0;
}