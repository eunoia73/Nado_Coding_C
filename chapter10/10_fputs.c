//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
	// 파일 생성 및 파일 포인터 생성 
    FILE * file = fopen("/Users/sookyung/Documents/Nado_Coding_C/test1.txt", "wb");
    //wb -> 바이너리 데이터를 쓰는 목적으로 새 파일 생성하겠다.

  // 파일 포인터 얻었는지 확인하기 
    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    fputs("fputs() 함수로 글을 써 볼게요.\n", file);
    fputs("잘 써지는지 확인해 주세요.\n", file);

    fclose(file);

    return 0;
}