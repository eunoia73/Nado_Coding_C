#### -  C언어를 이용한 프로그램 완성 과정
코딩(소스파일) -> 컴파일 (소스 -> 목적파일) -> 링킹 linking (목적파일 -> 실행파일)

### 1. 선행처리기(preprocessor) 
컴파일에 앞서 프로그램 선두에 선언된 지시자들을 미리 처리하는 역할 수행
* 전처리기 지시문 - 컴파일에 필요한 정보를 컴파일러에게 알려주는 역할
`#include <stdio.h>`


| <center>선행처리기</center> |  <center>기능</center> |   <center>예시</center> |
| :---: | :---: |  :---: |
| <center>#include</center> | <center>파일 포함</center> | <center> #include <stdio.h> </center> |
| <center>#define</center> | <center>매크로 정의</center> | <center> #define PI 3.141592 </center>|
| <center>#if #else #elif #endif </center> | <center>조건부 컴파일</center> | <center>  </center>|
* 매크로(macro) - 선행처리기 #define을 사용하여 단순 치환되는 자료
프로그램 작성 시 명령이나 수식, 상수 값이 자주 사용될 때, 대표하는 이름을 붙여 사용하는 대상

### 2. 표준 입출력 함수
`stdio.h` (Standard Input Output) - 표준 입출력 헤더파일
#### * 표준 출력 함수 printf()
```c
#include <stdio.h>
  
int main(void){
	int add = 3 + 7;
  	printf("3 + 7 = %d\n", add);
  	return 0;
  }
//3 + 7 = 10
```
  
#### * 표준 입력 함수 scanf()
``` c
#include <stdio.h>
  
int main(void){
	int one, two, three;
  	printf("정수 3개를 입력하세요 : ");
  	scanf("%d %d %d", &one, &two, &three);
  	printf("첫 번째 값 : %d\n", one);
    printf("두 번째 값 : %d\n", two);
  	printf("세 번째 값 : %d\n", three);

  	return 0;
  }
```
 ``` c
  char 변수명[길이];  // 문자열 생성 
  scaf_s("서식지정자", 변수명, sizeof(변수명)); //값이 문자열일때
 ```
 
 &(ampersand)는 메모리 주소를 나타낼 때 사용
 &one은 one변수가 할당된 메모리의 주소. 입력받을 값을 넣으라는 뜻
 

### 3. 서식 지정자
| <center>자료형</center> |  <center>서식 지정자</center> |   <center>설명</center> |
| :---: | :---: | :---: |
| <center>int</center> | <center>%d</center> | <center> 정수 </center> |
| <center>float</center> | <center>%.nf</center> | <center> 실수 (n+1 자리에서 반올림) </center>|
| <center>double </center> | <center>%.nlf</center> | <center> 실수 (n+1 자리에서 반올림) </center>|
| <center>char </center> | <center>%c</center><center>%s</center> | <center> 문자 </center>  <center> 문자열 </center>|

### 4. 난수 생성하기
```c
#include <stdio.h>
#include <time.h>  //시간 관련 함수
#include <stdlib.h>  //난수생성, 문자열 변환 등 함수

int main(void){

    printf("난수 초기화 이전...\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", rand() % 10);
    }
    //난수 초기화를 하지 않으면 여러 번 실행해도 같은 랜덤 숫자가 나온다. 

    srand(time(NULL));  //난수 초기화
    printf("\n\n난수 초기화 이후...\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", rand() % 10);
    }    

    return 0;
}
```

> `rand() % 뽑고 싶은 숫자의 범위` 
ex. `rand() % 10` -> 0~9 중 숫자 하나 뽑아줘!
1~10 범위 설정 하고 싶다면 -> `rand() % 10 + 1`

> `srand(time(NULL));` : 난수 초기화
난수 초기화를 하지 않으면 실행할 때마다 같은 랜덤 결과가 나온다.
