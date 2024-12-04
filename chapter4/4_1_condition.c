#include <stdio.h>

int main(void){
    // int age = 25;
    // if(age >= 20){
    //     printf("성년입니다.\n");
    // }else{
    //     printf("청소년입니다.\n");
    // }


    //if문
    // int age = 25;
    // if(age >= 8 && age <= 13){
    //     printf("초등학생입니다.\n");
    // }else if(age >= 14 && age <= 16){
    //     printf("중학생입니다.\n");
    // }else if(age >= 17 && age <= 19){
    //     printf("고등학생입니다.\n");
    // }else{
    //     printf("청소년이 아닙니다.\n");
    // }

    //swich문
    int age = 8;

    switch (age){
    case 8:         //break문 없으므로 계속 아래 case로 내려감
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        printf("초등학생입니다.\n");
        break;
    case 14:
    case 15:
    case 16:
        printf("중학생입니다.\n");
        break;
    case 17:
    case 18:
    case 19:
        printf("고등학생입니다.\n");
        break;

    default:
        printf("청소년이 아닙니다.\n");
    }


    return 0;
}