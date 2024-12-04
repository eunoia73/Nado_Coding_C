#include <stdio.h>
void p(int num);  //함수 선언

int main(void){
    int num = 2;
    p(num);
    num = num + 3;
    p(num);

    return 0;
}

void p(int nun){
    printf("num은 %d입니다.\n", nun);
}