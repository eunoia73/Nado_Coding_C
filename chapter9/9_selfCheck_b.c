#include <stdio.h>
#include <stdlib.h>

//구조체 선언
struct book{
    int id;
    char * title;
    int available; //0:대출중, 1:대출가능
};

void print_book(struct book * books);  //함수 선언

int main(void){
    struct book books[4] = {
        {1, "C 입문편", 1},
        {2, "파이썬 기본편", 1},
        {3, "자바 기본편", 1},
        {4, "파이썬 중급편", 1}
    };

    int input;  //사용자 입력 저장 변수
    while(1){
        print_book(books);  //전체 도서 정보 출력 함수 호출
        printf("대출/반납할 책 번호를 입력하세요.(종료 : -1) : ");
        scanf("%d", &input);  //사용자 입력 받기
        if(input == -1){
            printf("프로그램을 종료합니다.\n\n");
            break;
        }
        if(input < 1 || input > 4){
            printf("잘못된 입력입니다.\n\n");
            continue;
        }
        input -= 1;
        if(books[input].available == 0){
            printf("'%s' 반납이 완료됐습니다.\n\n", books[input].title);
            books[input].available = 1;
        }else{
            printf("'%s' 대출이 완료됐습니다.\n\n", books[input].title);
            books[input].available = 0;
        }
    }
    return 0;
}

// 전체 도서 정보 출력, books 배열은 구조체 포인터로 처리
void print_book(struct book * books){
    char * available = "대출 가능";
    char * unavailable = "대출 중";
    printf("전체 도서 목록입니다.\n");
    printf("================================\n");
    for(int i = 0; i < 4; i++){
        printf("%d. %-16s ", books[i].id, books[i].title);  //도서 번호, 도서 제목
        //대출 여부 출력
        if(books[i].available){
            printf("[%s]\n", available);
        }else{
            printf("[%s]\n", unavailable);
        }
    }
    printf("=================================\n");
}