#include <stdio.h>

int main(void){
    //문자
    char c = 'A';
    printf("%c\n", c);

    //문자열
    char str[7] = "coding";  //길이에 마지막 null값 포함해야함
    printf("%s\n", str);

    //sizeof()
    char str2[] = "coding";
    printf("%s\n", str);
    printf("%d\n", sizeof(str));
    for(int i = 0; i < sizeof(str); i++){
        printf("%c\n", str[i]);
    }    

    //한글 저장하기
    char kor[] = "나도코딩";
    printf("%s\n", kor);
    printf("%d\n", sizeof(kor));  //13



    return 0;
}
