#include <stdio.h>

 int main(void){

    // printf()
    int add = 3 + 7;
    printf("3 + 7 = %d\n", add);
    printf("%d + %d = %d\n", 30, 79, 30 + 79);
    printf("%d * %d = %d\n", 30, 79, 30 * 79);


    //scanf()
    int input;
    printf("값을 입력하세요 : ");
    scanf("%d", &input);
    printf("입력값 : %d\n", input);


    int one, two, three;
    printf("정수 세 개를 입력하세요 : ");
    scanf("%d %d %d", &one, &two, &three);
    printf("첫 번째 값 : %d\n", one);
    printf("두 번째 값 : %d\n", two);
    printf("세 번째 값 : %d\n", three);


    //문자열

    char c = 'A';
    printf("%c\n", c);


    char str[256];
    scanf("%s", str);
    //scanf_s로 문자열을 입력받기 위해서는 크기를 명시해야 함
    printf("%s\n", str);


    //1분 퀴즈
    char str1[256], str2[256];
    printf("첫 번째 문자열을 입력하세요 : ");
    scanf("%s", str1);

    printf("두 번째 문자열을 입력하세요 : ");
    scanf("%s", str2);

    printf("%s\n", str1);
    printf("%s\n", str2);

    
    return 0;
}