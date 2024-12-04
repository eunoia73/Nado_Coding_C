#include <stdio.h>
#include <time.h>  //time
#include <stdlib.h>  //random

int main(void){
    //난수 초기화
    srand(time(NULL)); 

    //1~100사이의 난수
    int num = rand() % 100 + 1;
    printf("정답 : %d\n", num);

    int answer = 0; //사용자 입력 값
    int chance = 5; //가능한 답변 횟수

    while(chance > 0){  

        printf("남은 기회 %d번\n", chance--);  //답변 기회 차감
        printf("숫자를 맞혀 보세요.(1~100) : ");
        scanf("%d", &answer);
        if(num == answer){
            printf("정답입니다!");
            break;
        } else if(num < answer){
            printf("DOWN ↓\n\n");
        } else if(num > answer){
            printf("UP ↑\n\n");
        } else {
            printf("알 수 없는 오류가 발생했어요.\n\n");  //예외 상황 대비
        }
        if(chance == 0){
            printf("모든 기회를 사용했어요. 아쉽게도 실패했습니다.\n");
            break;
        }
    }

    return 0;
}
