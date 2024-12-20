#include <stdio.h>
#define MAX 10000  //매크로 정의

int main(void){
    char line[MAX]; //char line[1000]; 파일에서 읽어오는 문자열 저장 배열 선언

    //파일 모드 rb로 설정 
    FILE * file = fopen("/Users/sookyung/Documents/Nado_Coding_C/test1.txt", "rb");

    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    while(fgets(line, MAX, file) != NULL){  //fgets()로 파일 읽기
        printf("%s", line); //출력
    }
    fclose(file);


    return 0;
}

/**
 * 출력 결과
 * 
 * fputs() 함수로 글을 써 볼게요.
 * 잘 써지는지 확인해 주세요.
*/