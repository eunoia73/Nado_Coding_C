#include <stdio.h>
//영화 상영 시간 정보를 분에서 시간+분으로 변환하는 프로그램

//함수 선언
void convert_time(int minute);


int main(void){
    convert_time(118);
    convert_time(138);
    convert_time(60);
    convert_time(30);
    
    return 0;
}


//함수 정의
void convert_time(int minute){
    int hour = minute / 60;
    int converted_minute = minute % 60;
    printf("%d시간 %d분\n", hour, converted_minute);
}


