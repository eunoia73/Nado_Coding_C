#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    /**
     * 1. 랜덤값으로 4개 약병 중 발모제 하나 선택하기(정답)
     * 2. 조합할 약병 개수 랜덤 값으로 선택하기(한 번에 2~3개 조합) - 3번 반복
     * 3. 정답 입력받기
     * 4. 정답여부 알려주기
    */

    // 랜덤값 초기화
    srand(time(NULL));
    int treatment = rand() % 4; //0~3 중 하나
    printf("\n\n=== 자라나라 머리카락 게임 시작! ====\n\n");
    
    int cntShowBottle  = 0;
    int prevShowBottle = 0;
    
    for(int i = 1; i <= 3; i++){  //총 3번 진행
        int isIncluded = 0;

        int bottle[4] = {0, 0, 0, 0};  //매 회 선택하는 약병이 다르니까 0으로 초기화

        //2_1. 섞을 발모제 개수 정하기 
        do{
            cntShowBottle = rand() % 2 + 2;  //2~3 중 하나
        } while (cntShowBottle == prevShowBottle);
        prevShowBottle = cntShowBottle;

        printf(">> %d번째 테스트\n", i);

        //2_2. 조합할 약병 선택하기
        for(int j = 0; j < cntShowBottle; j++){
            int randBottle = rand() % 4;  //약병 번호 뽑기
            if(bottle[randBottle] == 0){
                bottle[randBottle] = 1;  //값 변경
                if(randBottle == treatment){
                    isIncluded = 1;
                }
            }else{  //이미 선택된 약병이면 중복이므로 다시 선택
                j--; //반복 횟수 조정
            }
        }

        //사용자에게 테스트 결과 표시
        for(int k = 0; k < 4; k++){
            if(bottle[k] == 1){
                printf("%d ", k + 1);
            }
        }
        printf("번 물약을 머리에 바릅니다.\n\n");

        if(isIncluded == 1){
            printf(">> 성공!! 머리카락이 났어요 ");
        }else{
            printf(">> 실패.. 머리카락이 나지 않았어요 ");
        }
        printf("\n 계속하려면 Enter를 누르세요. \n");
        getchar();

    }

    printf("\n\n 발모제는 몇 번 일까요? ");
    int answer;
    scanf("%d", &answer);
    if(answer == treatment + 1){
        printf("정답입니다!");
    }else{
        printf("틀렸어요! 정답은 %d번입니다.\n", treatment + 1);
    }
    






    return 0;
}