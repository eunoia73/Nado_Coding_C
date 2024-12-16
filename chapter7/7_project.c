#include <stdio.h>
#include <time.h>

//전역변수
int level; //레벨 
int arrayFish[6];
void initData();  //게임 초기화 함수 선언

int main(void){
    long startTime = 0;  //게임 시작 시간 담을 변수
    initData();  //게임 초기화 함수 호출
    startTime = clock();  //프로그램 수행 시작 시점부터 현재까지 흐른 시간을 시작 시간으로 저장

    while (1){

    if(level == 5) break;
    if()
    }
    

    return 0;
}



void initData(){
    level = 0;
    for(int i = 0; i < 6; i++){
        arrayFish[i] = 100;  //처음 물 높이는 모두 100
    }
}