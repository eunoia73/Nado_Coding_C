#include <stdio.h>
int score[5];


int main(void){
    int score[5] = {76, 84, 80, 92, 96};  //시험점수
    int totalScore = 0;
    float avg = 0.0f;
   
    for(int i = 0; i < 5; i++){
        totalScore += score[i]; 
    }
    avg = totalScore / 5.0f;

    printf("총점은 %d점, 평균은 %.1f점 입니다.", totalScore, avg);

    return 0;
}