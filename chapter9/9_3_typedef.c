#include <stdio.h>
//구조체 선언
struct GameInfo{
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;
};

// 구조체 선언과 동시에 별명 붙이기
typedef struct {
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;
} GAME_INFO;  


int main(void){
    typedef struct GameInfo 게임정보;  //별명붙이기 
    게임정보 game1;
    game1.name = "한글 게임";
    game1.year = 2022;

    GAME_INFO game2;  //선언
    game2.name = "한글 게임2";
    game2.year = 2023;

    //출력
    printf("-- 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", game1.name);
    printf("발매 연도 : %d\n", game1.year);
    printf("게임 이름 : %s\n", game2.name);
    printf("발매 연도 : %d\n", game2.year);

    return 0;
}