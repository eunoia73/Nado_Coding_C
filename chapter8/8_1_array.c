#include <stdio.h>

int main(void){

    // 2차원 배열
    int arr[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    arr[3][0] = 9;
    arr[3][1] = 10;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            printf("2챠원 배열 [%d][%d]의 값 : %d\n", i, j, arr[i][j]);
        }
        printf("\n");
    }

    // 3차원 배열
    int arr2[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19}
        },
        {
            {21, 22, 23},
            {24, 25, 26},
            {27, 28, 29}
        }
    };
    
    //출력
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                printf("3차원 배열 [%d][%d][%d]의 값 : %d\n", i, j, k, arr2[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;
}