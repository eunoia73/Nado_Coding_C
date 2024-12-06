#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//비밀번호 마스터

//함수 선언
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();


int main(void){
    srand(time(NULL));  // 난수 초기화
    int count = 0;   //맞힌 문제 개수

    //문제 출제 x * y = ?
    for(int i = 1; i <=5; i++){
        int num1 = getRandomNumber(i);  //함수 호출로 난수 생성
        int num2 = getRandomNumber(i);  //함수 호출로 난수 생성
        showQuestion(i, num1, num2); //문제 출력
        int answer = -1;
        scanf("%d", &answer); //답 입력
        if(answer == -1){
            printf("\n프로그램을 종료합니다.\n");
            //break;
            exit(0);  //현재 실행중인 프로그램 종료 
        }else if(answer == num1 * num2){
            success();
            count++;  //맞힌 문제 개수 증가
        }else{
            fail();
        }
    }

    printf("\n\n비밀번호 %d개를 맞혔습니다.\n", count);

    return 0;
}

//함수 정의
//레벨에 따라 다른 난이도
int getRandomNumber(int level){
    return rand() % (level * 9) + 1;
}

//문제 출력
void showQuestion(int level, int num1, int num2){
    printf("\n\n\n########## %d번째 비밀번호 ########\n", level);
    printf("\n\t%d * %d = ?\n\n", num1, num2);
    printf("##################################\n");
    printf("\n비밀번호를 입력하세요.(종료를 원하면 -1 입력) >> ");
}

void success(){
    printf("\n >> 정답입니다!\n");
}

void fail(){
    printf("\n >> 틀렸습니다.\n");
}