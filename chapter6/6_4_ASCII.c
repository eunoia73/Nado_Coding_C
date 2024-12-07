#include <stdio.h>

//아스키코드
//사용자가 입력한 문자나 기호를 컴퓨터가 이해할 수 있는 0, 1의 신호로 변환한 것
//null - 0, a - 97, A - 65

int main(void){
    printf("%c\n", 'a'); //a
    printf("%d\n", 'a'); //97
    printf("%c\n", 'b'); //b
    printf("%d\n", 'b'); //98
    printf("%c\n", 'A'); //A
    printf("%d\n", 'A'); //65

    printf("%c\n", '\0'); //
    printf("%d\n", '\0'); //0
    printf("%c\n", '0');  //0
    printf("%d\n", '0');  //48
    printf("%c\n", '1');  //1
    printf("%d\n", '1');  //49

    //아스키코드 값 0~127에 해당하는 문자 확인
    for(int i = 0; i < 128; i++){
        printf("아스키코드 값 %d : %c\n", i, i);
    }
    return 0;
}