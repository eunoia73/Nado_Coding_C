#include <stdio.h>
void p(int num);  //함수 선언
int apple(int total, int ate);  //함수 선언

int main(void){
    int num = 2;
    p(num);
    num = num + 3;
    p(num);

    //apple 함수 호출
    int ret = apple(5, 2);
    printf("사과 5개 중에서 2개를 먹으면 %d개가 남습니다.\n", ret);
    printf("사과 %d개 중에서 %d개를 먹으면 %d개가 남습니다.", 10, 4, apple(10, 4));
    return 0;
}

void p(int nun){
    printf("num은 %d입니다.\n", nun);
}

//apple 함수 정의
int apple(int total, int ate){
    printf("전달값과 반환값이 있는 함수입니다.\n");
    return total - ate;
}

