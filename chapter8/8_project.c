#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//카드 초기화하기

int arrayAnimal[4][5];
char * strAnimal[10];  //동물 이름 배열  // char형 포인터 배열은 한 번 선언하면 변경 불가능
int failCount = 0;  // 총 실패 횟수 저장할 변수

void initAnimalArray();  //배열 초기화 함수 
void initAnimalName();  //동물 이름 배열 초기화 함수
void shuffleAnimal();  //카드 섞기
int getEmptyPosition();  //빈 공간 찾는 함수
int conv_pos_x(int x);  //x좌표 반환 함수 선언
int conv_pos_y(int y);  //y좌표 반환 함수 선언
void printAnimals();
void printQuestion();
int checkAnimal[4][5];
int foundAllAnimals();  // 게임 종료 확인 함수 선언

int main(void){
    //난수 초기화
    srand(time(NULL));

    initAnimalArray();  //배열 초기화
    initAnimalName(); //동물 이름 배열 초기화 
    shuffleAnimal();
    while (1){
        int select1 = 0;
        int select2 = 0;
        printAnimals();  //카드 지도 출력 함수
        printQuestion();  //문제 출력 함수

        printf("\n뒤집을 카드 2장을 고르세요.(예: 12 4) -> ");
        scanf("%d %d", &select1, &select2);
        if(select1 == select2){  //같은 카드 선택시 무효처리
            continue;
        }

        //입력받은 카드 번호를 x, y 좌표로 변환
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);
        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        if((checkAnimal[firstSelect_x][firstSelect_y] == 0
        && checkAnimal[secondSelect_x][secondSelect_y] == 0)
        && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])){  //두 카드가 같은 동물, 뒷면
        printf("\n\n빙고!! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
        checkAnimal[firstSelect_x][firstSelect_y] = 1;
        checkAnimal[secondSelect_x][secondSelect_y] = 1;
        } else{
            printf("\n\n땡!! 서로 다른 동물 카드이거나 이미 뒤집힌 카드입니다.\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n");
            failCount++;
        }

        if(foundAllAnimals() == 1){
            printf("\n\n 축하축하! 모든 동물을 찾았습니다.\n");
            printf("총 %d번 실패했습니다. \n", failCount);
            break;
        }

    }
    

    return 0;
}

// 배열 초기화 함수
void initAnimalArray(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            arrayAnimal[i][j] = -1;  //카드 뒷면 설정

        }
    }
}

//동물 이름 배열 초기화 함수
void initAnimalName(){
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal(){
    for(int i = 0; i < 10; i++){  //이름 수 만큼
        for(int j = 0; j < 2; j++){  //같은 동물 2번
            int pos = getEmptyPosition();  //빈 공간 찾기 함수 호출
            int x = conv_pos_x(pos);  // 카드 번호를 x좌표로 변환하는 함수 호출
            int y = conv_pos_y(pos);  // 카드 번호를 y좌표로 변환하는 함수 호출
            arrayAnimal[x][y] = i;
        }
    }
}

// 빈 공간 찾는 함수(빈 공간 없을 때까지 작동 -> 무한 반복문)
int getEmptyPosition(){
    while (1){
        int randPos = rand() % 20;  // 0~19
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if(arrayAnimal[x][y] == -1){  // 찾은 공간 비었으면 카드 번호 반환
            return randPos;
        }
    }
    return 0;  // 빈 공간 없으면 0 반환
    
}

//x좌표 반환 함수 
int conv_pos_x(int x){
    return x / 5;
}

//y좌표 반환 함수 
int conv_pos_y(int y){
    return y % 5;
}

//동물 위치 출력 함수
void printAnimals(){
    printf("\n========= 동물 위치를 보여 줍니다. =========\n\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("%8s ", strAnimal[arrayAnimal[i][j]]);  //카드 지도 좌표로 동물 이름 출력하기
        }
        printf("\n");
    }
    printf("\n=======================================\n");
}

//카드 지도 출력 함수 정의
void printQuestion(){
    printf("\n(문제)\n\n");
    int seq = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(checkAnimal[i][j] != 0){
                printf("%8s ", strAnimal[arrayAnimal[i][j]]);  //동물 이름 출력
            } else{
                printf("%8d ", seq);  //카드 번호 출력
            }
            seq++;  //다음 카드로 넘어가기
        }
        printf("\n");
    }
}

//게임 종료 확인 함수 정의
int foundAllAnimals(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(checkAnimal[i][j] == 0){
                return 0;  //뒤집지 않은 카드가 있음
            }
        }
    }
    return 1;  //모든 카드 뒤집음
}