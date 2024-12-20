#include <stdio.h>
#include <stdlib.h>
//구조체 선언
struct book{
    int id;
    char * title;
    int available; //0:대출중, 1:대출가능
};

struct book books[4];  // 구조체 배열 선언
void bookInit();
void printBook();

int main(void){
    bookInit();

    while(1){

        printBook();
        printf("대출/반납할 책 번호를 입력하세요.(종료 : -1) : ");
        int input;  //입력값
        scanf("%d", &input);
        
        if(input == -1){
            printf("프로그램을 종료합니다.");
            exit(0);
        }else if(!(1 <= input && input <= 5)){
            printf("잘못된 입력입니다.");
        }else{
            if(books[input - 1].available == 0){
                printf("'%s' 대출이 완료됐습니다.", books[input - 1].title);
                books[input - 1].available = 1;
            }else{
                printf("'%s' 반납이 완료됐습니다.", books[input - 1].title);
                books[input - 1].available = 0;
            }
        }
    }

    return 0;
}

void bookInit(){
    books[0].id = 1;
    books[0].title = "C 입문편";

    books[1].id = 2;
    books[1].title = "파이썬 기본편";

    books[2].id = 3;
    books[2].title = "자바 기본편";

    books[3].id = 4;
    books[3].title = "파이썬 중급편";
}

void printBook(){
    printf("\n\n==============책장===============\n");
    for(int i = 0; i < 4; i++){
        printf("%d. %-16s", books[i].id, books[i].title);
        if(books[i].available == 0){
            printf("%16s\n", "[대출 가능]");
        }else{
            printf("%s\n", "[대출 중]");
        }
    }
    printf("==================================\n");
}