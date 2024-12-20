#include <stdio.h>
#define MAX 10000

int main(void){
    char str1[MAX];
    char str2[MAX];
    int num[6] = {0, 0, 0, 0, 0, 0};
    int bonus = 0;

    FILE * file = fopen("/Users/sookyung/Documents/Nado_Coding_C/test2.txt", "rb");  //파일 포인터 얻기
    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    //fscanf() 함수로 파일 읽기
    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    //추첨번호 출력
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

    //fscanf() 함수로 파일 읽기
    fscanf(file, "%s %d", str2, &bonus);
    //보너스번호 출력
    printf("%s %d\n", str2, bonus);
    
    fclose(file);

    return 0;
}

/**
 * 출력 결과
 * 
 * 추첨번호 1 2 3 4 5 6
 * 보너스번호 7
*/