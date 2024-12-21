#include <stdio.h>
#include <string.h>
#define MAX 10000  //매크로 정의

int main(void){
    char password[20];
    char c;
    int i = 0; 
    char line[MAX];  //파일에서 읽어온 내용 저장
    char contents[MAX] = "";  //일기장에 입력한 내용을 저장할 변수(빈 값으로 초기화)

    printf("비밀 일기에 오신 것으르 환영합니다.\n");
    printf("비밀번호를 입력하세요(최대 20자리) : ");
    while(1){ //비밀번호 입력받기
        c = getchar();  
        //_getch() : 키를 입력하면 바로 작동(Windows 환경 Visual Studio에서 사용) 
        //getchar() : 키 입력 후 Enter 눌러야 작동
        if(c == 10 || c == 13){  //13은 아스키코드로 Enter //10은 LF (Line Feed)
            password[i] = '\0';  //비밀번호 입력 종료
            break;
        }else{
            printf("*");
            password[i] = c;
        }
        i++;  //배열 인덱스 증가
    }

    printf("\n\n === 비밀번호 확인 중 === \n\n");
    if(strcmp(password, "skehzheld") == 0){
        printf("=== 비밀번호 확인 완료 ===\n\n");
        char * fileName = "/Users/sookyung/Documents/Nado_Coding_C/secretdiary.txt";  //파일 이름 포인터 변수에 저장
        //파일 포인터 얻기
        FILE * file = fopen(fileName, "a+b");  // a+ : 읽기, 쓰기 모두 가능
        if(fileName == NULL){
            printf("파일 열기 실패");
            return 1;
        }
        while(fgets(line, MAX, file) != NULL){ //파일 읽어오기
            printf("%s", line);  //파일에서 읽어온 내용 출력
        }
        printf("\n\n 내용을 계속 작성하세요. 종료하려면 EXIT를 입력하세요.\n\n");
        while(1){
            scanf("%[^\n]", contents);  //줄바꿈문자 전까지 한 문장씩 읽어오기
            getchar();
            if(strcmp(contents, "EXIT") == 0){
                printf("비밀 일기 입력을 종료합니다.\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);
        }
        fclose(file);
    }else{
        printf("=== 비밀번호가 틀렸어요. ===");
    }
    


    return 0;
}