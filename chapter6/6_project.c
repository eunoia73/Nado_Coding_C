// 자라나라 머리카락
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));  //난수 초기화
    int treatment = rand() % 4;  //약병 4개 중 하나 선택 (0~3)
    printf("\n\n === 자라나라 머리카락 게임 === \n\n");

    int cntShowBottle = 0;  //이번 회차 약병 조합 횟수
    int prevCntShowBottle = 0;  //이전 회차 약병 조합 횟수

    //3회 테스트
    for(int i = 1; i <= 3; i++){
        int bottle[4] = {0, 0, 0, 0};  //약병 4개의 배열
        do{
            cntShowBottle = rand() % 2 + 2;  //2 or 3
        } while(cntShowBottle == prevCntShowBottle);
        prevCntShowBottle = cntShowBottle;  //이번 회차의 약병 개수 저장
        printf(" > %d번째 테스트 : ", i);  // 회차 정보 출력

        int isIncluded = 0;  //진짜 발모제인지 확인하는 용
        for(int j = 0; j < cntShowBottle; j++){  //조합할 약병 번호 선택
            int randBottle = rand() % 4; // 약병 번호 뽑기(0~3)
            if(bottle[randBottle] == 0){  //아직 선택되지 않은 약병이면
                bottle[randBottle] = 1;   // 0 -> 1
                if(randBottle == treatment){
                    isIncluded = 1;  //진짜 발모제 포함됨
                }
            }else{  //선택된 약병이면 다시 선택
                    j--;  //반복 횟수 조정
                }
            }
        

        //사용자에게 테스트 결과 표시
        for(int k = 0; k < 4; k++){
            if(bottle[k] == 1){
                printf("%d ", k + 1);  //인덱스 + 1
            }
        }
        printf("번 물약을 머리에 바릅니다.\n\n");
        if(isIncluded == 1){
            printf(">> 성공! 머리카락이 났어요!\n");
        }else{
            printf(">> 실패! 머리카락이 나지 않았어요.\n");
        }
        printf("\n 계속하려면 Enter를 누르세요. \n");
        getchar();  //enter를 입력받아 다음 테스트 회차로 넘어간다
    }
    
        //사용자 입력받기
        printf("\n\n발모제는 몇 번일까요? ");
        int answer;
        scanf("%d", &answer);  //입력받기
        if(answer == treatment + 1){
            printf("\n>> 정답입니다!\n");
        }else{
            printf("\n>> 틀렸어요. 정답은 %d번입니다.\n", treatment + 1);
        }




        return 0;
    
}