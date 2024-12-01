#include <stdio.h>
int main(void){
    //*****
    //****
    //***
    //**
    //*

    // 내 코드
    // for(int i = 0; i < 5; i++){
    //     for(int j = 5 - i ; j > 0; j-- ){
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    //교재 코드
    for(int i = 5; i > 0; i--){
        for(int j = i; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}