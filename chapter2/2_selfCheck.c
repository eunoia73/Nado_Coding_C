// 신발 쇼핑몰의 회원 가입 프로그램 
#include <stdio.h>
int main(void){
    //이름
    printf("이름을 입력하세요 : ");
    char name[256];
    scanf("%s", name);  //name 배열에 저장

    //아이디
    printf("아이디를 입력하세요 : ");
    char id[256];
    scanf("%s", id);

    //나이
    printf("나이를 숫자로 입력하세요 : ");
    int age;
    scanf("%d", &age);

    //생일
    printf("생일을 입력하세요(ex: 0703) : ");
    char birth[256];
    scanf("%s", birth);

    //신발 크기
    printf("신발 크기를 입력하세요 : ");
    int size;
    scanf("%d", &size);


    //출력
    printf("\n--- 회원 정보 ---\n");
    printf("이름      : %s\n", name);
    printf("아이디    : %s\n", id);
    printf("나이      : %d\n", age);
    printf("생일      : %s\n", birth);
    printf("신발 크기 : %d\n", size);
    return 0;
}


