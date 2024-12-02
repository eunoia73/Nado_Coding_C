#include <stdio.h>
int main(void){
    for(int i = 1; i <= 30; i++){
        
        //continue문 - 이번 반복만 종료한 후, 다음 반복으로 넘어감
        if(i == 4){
            printf("%d번 학생은 결석입니다.\n", i);
            continue;
        }
        
        //break 문
        if(i >= 6){
            printf("나머지 학생은 집에 가세요.\n");
            break;
        }
        printf("%d번 학생은 조별 발표를 준비하세요.\n", i);
    }

    return 0;
}