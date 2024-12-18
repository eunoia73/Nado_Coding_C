#include <stdio.h>
//구조체 선언
struct GameInfo{
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;  //구조체 포인터
};

int main(void){
    struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2022;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";
    struct GameInfo gameInfo2 = {"너도게임", 2022, 100, "너도회사"};

    gameInfo1.friendGame = &gameInfo2;  //gameInfo1의 구조체 포인터에 gameInfo2의 주소 넣기

    printf("-- 다른 회사의 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", gameInfo1.friendGame->name);
    printf("발매 연도 : %d\n", gameInfo1.friendGame->year);
    printf("게임 가격 : %d\n", gameInfo1.friendGame->price);
    printf("제작 회사 : %s\n", gameInfo1.friendGame->company);




    return 0;
}