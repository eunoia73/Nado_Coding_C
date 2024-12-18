#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//전역변수
int level; //레벨 
int arrayFish[6];//어항
int * cursor; //어항 배열에 접근할 포인터 변수

void initData();  //게임 초기화 함수 선언
void printFishes();  //어항 물 높이 출력 함수
void decreaseWater(long elapsedTime);  //어항 물 증발 함수
int checkFishAlive();  //모든 물고기가 죽었는지 확인하는 함수 선언

int main(void){
    long startTime = 0;  //게임 시작 시간 담을 변수
    int num; //물 줄 어항 번호
    long totalElapsedTime = 0;  //총 경과시간
    long prevElapsedTime = 0;  //직전에 물 준 시간(물 준 시간 간격)
    initData();  //게임 초기화 함수 호출
    startTime = clock();  //프로그램 수행 시작 시점부터 현재까지 흐른 시간을 시작 시간으로 저장
    cursor = arrayFish;  //포인터 배열에 어항 배열의 시작 주소 넣기

    
    while (1){  //어항 물 주기 무한 반복
        printFishes(); //물 높이 출력

        //물 줄 어항 선택하기
        printf("몇 번 어항에 물을 줄까요?(1~6) ");
        scanf("%d", &num);
        if(num < 1 || num > 6){
            printf("\n 입력값이 잘못됐습니다. \n");
            continue;
        }
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;  //총 경과 시간(현재시간 - 시작시간)
        printf("총 경과 시간 : %ld초\n", totalElapsedTime);
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld초\n", prevElapsedTime);

        decreaseWater(prevElapsedTime);  // 증발 함수 호출

        //선택한 어항에 물 주기
        //1. 어항의 물 높이가 0이하면 물 주지 않음
        if(cursor[num - 1] <= 0){
            printf("%d번 어항의 물고기는 이미 죽었으므로 물을 주지 않습니다.\n", num);
        }
        //2. 어항의 물 높이가 0초과하면 100을 넘지 않는지 확인하고 물 주기
        else if(cursor[num - 1] + 1 <= 100){
            printf("%d번 어항에 물을 줍니다.\n\n", num);
            //물 주면 -> 물 높이 + 1(cursor[num-1] = cursor[num-1]+1)
            cursor[num - 1] += 1;
        }

        //레벨 관리
        //20초마다 체크 후 물고기 살아있으면 레벨업
        if(totalElapsedTime / 20 > level - 1){
            level++;
            printf("*** 축하축하! %d레벨에서 %d레벨로 올랐습니당. ***\n\n", level - 1, level);
            if (level == 5){
                printf("\n\n축하축하합니다! 최고 레벨을 달성했습니다. 게임을 종료합니당~\n\n");
                exit(0);  //프로그램 종료
            }
        }

        //모든 물고기가 죽었는지 확인
        if(checkFishAlive() == 0){
            printf("모든 물고기가 죽었습니다..ㅠ\n\n");
            exit(0);
        }else{
            printf("물고기가 아직 살아 있어요!\n\n");
        }
        prevElapsedTime = totalElapsedTime;
            
        }
    return 0;
}


//초기화
void initData(){
    level = 1;
    for(int i = 0; i < 6; i++){
        arrayFish[i] = 100;  //처음 물 높이는 모두 100
    }
}

//어항 물 높이 출력
void printFishes(){
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for(int i = 0; i < 6; i++){
        printf("  %3d ", arrayFish[i]);  //출력 결과 정렬
    }
    printf("\n\n");

}

//어항 물 증발 함수
void decreaseWater(long elapsedTime){
    for(int i = 0; i < 6; i++){
        //물의 양은 레벨이 클수록 더 빨리 줄어든다. 기본 증발 양은 3
        arrayFish[i] -= (level * 3 * (int)elapsedTime);  //증발하는 물의 양 계산
        if(arrayFish[i] < 0){
            arrayFish[i] = 0;
        }
    }
}  

// 모든 물고기 죽었는지 확인하는 함수 정의
int checkFishAlive(){
    for(int i = 0; i < 6; i++){
        if (arrayFish[i] > 0) {
            return 1;  //true
        }
    }
    return 0;
}

