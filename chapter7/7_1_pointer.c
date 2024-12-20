#include <stdio.h>
int main(void){
    int 철수 = 1; 
    int 영희 = 2;
    int 민수 = 3;

    //변수의 주소 출력 -> &변수명
    printf("철수네 주소 : %p, 암호 : %d\n", &철수, 철수);
    printf("영희네 주소 : %p, 암호 : %d\n", &영희, 영희);
    printf("민수네 주소 : %p, 암호 : %d\n", &민수, 민수);

    //포인터 변수 선언과 값 출력
    int * 미션맨;  //포인터 변수 선언
    미션맨 = &철수; 
    // 포인터 변수의 서식 지정자 : %p , 포인터 변수가 가리키는 주소의 값 : *포인터변수명
    printf("미션맨이 방문한 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);


    //포인터 변수로 바꾼 값 출력
    미션맨 = &철수;
    *미션맨 = *미션맨 * 3;
    printf("미션맨이 암호를 바꾼 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);

    //포인터 변수를 추가해 값 바꾸기
    printf("\n>> 스파이가 미션을 수행하는 중 <<\n");
    int * 스파이 = 미션맨;
    *스파이 = *스파이 - 1;  //철수 = 철수 - 1;
    printf("스파이가 방문한 곳의 주소 : %p, 암호 : %d\n\n", 스파이, *스파이);

    미션맨 = &영희;
    printf("미션맨이 방문한 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);
    *미션맨 = *미션맨 * 3;
    printf("미션맨이 암호를 바꾼 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);

    //포인터 변수를 추가해 값 바꾸기
    printf("\n>> 스파이가 미션을 수행하는 중 <<\n");
    스파이 = 미션맨;
    *스파이 = *스파이 - 1;
    printf("스파이가 방문한 곳의 주소 : %p, 암호 : %d\n\n", 스파이, *스파이);

    미션맨 = &민수;
    printf("미션맨이 방문한 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);
    *미션맨 = *미션맨 * 3;
    printf("미션맨이 암호를 바꾼 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);

    //포인터 변수를 추가해 값 바꾸기
    printf("\n>> 스파이가 미션을 수행하는 중 <<\n");
    스파이 = 미션맨;
    *스파이 = *스파이 - 1;
    printf("스파이가 방문한 곳의 주소 : %p, 암호 : %d\n\n", 스파이, *스파이);

    //결과
    printf("\n>> 철수, 영희, 민수가 집에 와서 바뀐 암호를 보고 놀람 << \n");
    printf("철수네 주소 : %p, 암호 : %d\n", &철수, 철수);
    printf("영희네 주소 : %p, 암호 : %d\n", &영희, 영희);
    printf("민수네 주소 : %p, 암호 : %d\n", &민수, 민수);

    printf("미션맨의 주소 : %p\n", &미션맨);
    printf("스파이의 주소 : %p\n", &스파이);

    return 0;
}