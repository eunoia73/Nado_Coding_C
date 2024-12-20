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

> `rand() % 뽑고 싶은 숫자의 범위` <br>
ex. `rand() % 10` -> 0-9 중 숫자 하나 뽑아줘! <br>
1-10 범위 설정 하고 싶다면 -> `rand() % 10 + 1`

> `srand(time(NULL));` : 난수 초기화
난수 초기화를 하지 않으면 실행할 때마다 같은 랜덤 결과가 나온다.

### 5. 문자열

C언어에서 문자열은 `char 배열`에 저장한다.

#### 1) 문자열 끝에 null문자 포함 (배열크기 = 글자 수 + 1) 

`char str[6] = "coding";` 마지막 null값의 자리를 포함하지 않고 배열을 만들면, 아래와 같이 이상한 문자가 붙어서 출력된다.

<img src="https://velog.velcdn.com/images/eunoia73/post/ba972d66-d360-4484-8b61-f5bf7829b2a2/image.png" width="30%" height="50%">


```c
//문자열
#include <stdio.h>

int main(void){
    char str[7] = "coding";  //길이에 마지막 null값 포함해야함
    printf("%s\n", str);
    return 0;
}
```
* 문자열을 한 번에 저장하든, 하나씩 저장하든 마지막에는 null이 들어감!

```c
#include <stdio.h>

int main(void){
    char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\n'};
    printf("%s\n", c_array);

    return 0;
}
```


#### 2) sizeof() 사용하여 문자열 출력하기

```c
#include <stdio.h>

int main(void){
   
    //sizeof()
    char str2[] = "coding";
    printf("%s\n", str);	//coding
    printf("%d\n", sizeof(str));  //7(null포함한 값)
    
    for(int i = 0; i < sizeof(str); i++){
        printf("%c\n", str[i]);  //값이 한 글자이므로 %c로 받기
    }    


    return 0;
}

```

* 출력 결과

<img src="https://velog.velcdn.com/images/eunoia73/post/e05d630b-c03a-4951-9853-a60cc1e0cdc6/image.png" width="20%" height="50%">

* 배열 크기를 문자열보다 크게 선언하면, 문자열을 저장한 공간 외에 나머지는 null로 채워짐

```c
#include <stdio.h>

int main(void){

    char c_array2[10] = {'c', 'o', 'd', 'i', 'n', 'g'};
    for(int i = 0 ; i < sizeof(c_array2); i++){
        printf("%c\n", c_array2[i]);
    }

    return 0;
}
```
<img src="https://velog.velcdn.com/images/eunoia73/post/299fe804-e300-41aa-b3c4-572fdfeb77bd/image.png" width="20%" height="50%">

### 6. 포인터

> `&변수명` : 변수의 주소 <br>
`자료형 * 변수명;` : 포인터 변수 선언 <br>
`*포인터변수명` : 포인터 변수가 가리키는 주소의 값 <br>

``` c
#include <stdio.h>
int main(void){
    int arr[3] = {5, 10, 15};
    for(int i = 0; i < 3; i++){
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    }

    int* ptr = arr;  //포인터변수에 배열 넣기 -> 배열의 첫 번째 요소의 주소를 가리키게 됨
    for(int i = 0; i < 3; i++){
        //두 표현은 같은 표현
        //printf("포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
        printf("포인터 변수 ptr[%d]의 값 : %d\n", i, *(ptr + i));  //배열 첫 번째 요소의 주소로부터 i번째에 해당하는 요소의 값을 가져온다.
    }

    //값 넣기
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    for(int i = 0; i < 3; i++){
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
    }

    //arr자체의 값과 arr배열 첫 요소의 주소는 같다. arr = &arr[0]
    printf("arr 자체의 값 : %p\n", arr);
    printf("arr[0]의 주소 : %p\n", &arr[0]);

    //arr[0] = *(arr + 0)
    printf("arr 자체의 값인 주소의 실제 값 : %d\n", *arr);
    printf("arr[0]의 실제 값 : %d\n", *&arr[0]);  //*와 &를 같이 사용하면 둘은 상쇄돼서 아무것도 안 붙인 것과 같다.


    return 0;
}
```

>    `int* ptr = arr;`  <br>
포인터변수에 배열 넣기 -> 배열의 첫 번째 요소의 주소를 가리키게 됨 <br>
`*(ptr + i)` : `ptr[i]`와 같은 표현. 배열 첫 번째 요소의 주소로부터 i번째에 해당하는 요소의 값을 가져온다. `arr[0] = *(arr + 0)` <br>
`arr = &arr[0]` : arr자체의 값과 arr배열 첫 요소의 주소는 같다.  <br>
`*&arr[0]` : *와 &를 같이 사용하면 둘은 상쇄돼서 아무것도 안 붙인 것과 같다. <br>


### 7. 구조체
#### 1) 구조체 선언과 사용
> `구조체 (structure)` : 서로 다른 자료형을 가진 자료들의 모임을 하나의 자료형으로 정의하여 사용. 사용자 정의 자료형
``` c
struct 구조체명{
	자료형1 변수명1;
    자료형2 변수명2;
    ..
};
```
일반적으로 전역 위치에 정의한다. <br>
`struct 구조체명 변수명;` -> 구조체 변수 선언 방식 <br>
`변수명.멤버명 = 값;` -> 값 저장 방식 <br>

```c
#include <stdio.h>

struct  GameInfo{  //구조체 정의
    char * name;
    int year;
    int price;
    char * company;
};

int main(void){
    struct GameInfo gameInfo1;  //구조체 변수 선언
    //구조체 멤버 저장
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2022;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";

    struct GameInfo gameInfo2 = {"너도게임", 2022, 100, "너도회사"};

    //구조체 멤버 출력
    printf("-- 게임 출시 정보 -- \n");
    printf("게임 이름 : %s\n", gameInfo1.name);
    printf("발매 연도 : %d\n", gameInfo1.year);
    printf("게임 가격 : %d\n", gameInfo1.price);
    printf("제작 회사 : %s\n", gameInfo1.company);

    printf("\n-- 또 다른 게임 출시 정보 -- \n");
    printf("게임 이름 : %s\n", gameInfo2.name);
    printf("발매 연도 : %d\n", gameInfo2.year);
    printf("게임 가격 : %d\n", gameInfo2.price);
    printf("제작 회사 : %s\n", gameInfo2.company);

    return 0;
}

```
#### 2) 구조체 배열
`struct 구조체명 배열명[배열크기];` -> 선언방식
```c
struct GameInfo gameArray[2] = {
        {"나도게임", 2022, 50, "나도회사"},
        {"너도게임", 2022, 100, "너도회사"}
    };
```

#### 3) 구조체 포인터 사용하기
```c
	//구조체 포인터 사용하기
    struct GameInfo * gamePtr;
    gamePtr = &gameInfo1; //gameInfo1의 주소 넣기
    
    //구조체 포인터가 가리키는 구조체 변수의 값 나타내기
    printf("\n-- 미션맨의 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", (*gamePtr).name);
    printf("발매 연도 : %d\n", (*gamePtr).year);
    printf("게임 가격 : %d\n", gamePtr->price);  //간접 멤버 참조 연산자(->)사용
    printf("제작 회사 : %s\n", gamePtr->company);

```

#### 4) 구조체 안의 구조체
```c
#include <stdio.h>
//구조체 선언
struct GameInfo{
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;  //구조체 포인터
};

int main(void){
    struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2022;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";
    struct GameInfo gameInfo2 = {"너도게임", 2022, 100, "너도회사"};

    gameInfo1.friendGame = &gameInfo2;  //gameInfo1의 구조체 포인터에 gameInfo2의 주소 넣기

    printf("-- 다른 회사의 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", gameInfo1.friendGame->name); //너도게임
    printf("발매 연도 : %d\n", gameInfo1.friendGame->year); //2022
    printf("게임 가격 : %d\n", gameInfo1.friendGame->price); //100
    printf("제작 회사 : %s\n", gameInfo1.friendGame->company); //너도회사


    return 0;
}
```

<img src="https://velog.velcdn.com/images/eunoia73/post/524351ba-d0c9-4260-8a3a-3cd046b0183b/image.jpeg" width="80%" height="50%">

#### 5) typedef로 구조체 선언하기

```c
#include <stdio.h>
//구조체 선언
struct GameInfo{
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;
};

// 구조체 선언과 동시에 별명 붙이기
typedef struct {
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;
} GAME_INFO;  


int main(void){
    typedef struct GameInfo 게임정보;  //별명붙이기 
    게임정보 game1;
    game1.name = "한글 게임";
    game1.year = 2022;

    GAME_INFO game2;  //선언
    game2.name = "한글 게임2";
    game2.year = 2023;

    //출력
    printf("-- 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", game1.name);
    printf("발매 연도 : %d\n", game1.year);
    printf("게임 이름 : %s\n", game2.name);
    printf("발매 연도 : %d\n", game2.year);

    return 0;
}
```
i) 구조체 변수 선언시 typedef사용
```c
typedef struct GameInfo 게임정보;  //별명붙이기 
게임정보 game1;  //변수 선언
```
ii) 구조체 선언시 typedef사용
```c
typedef struct {
    char * name;
    int year;
    int price;
    char * company;
    struct GameInfo * friendGame;
} GAME_INFO;  
```

### 8. 파일 입출력
#### 1) fopen(), fputs(), fclose()

> `FILE * 포인터명 = fopen(파일명, 파일모드);` : 파일 열어서 파일 포인터 얻기<br>`fopen()` : 파일 여는 함수<br> 
- 파일 포인터 : 커서가 깜빡이는 위치를 담은 것(무슨 파일 열었는지, 어디까지 열었는지, 파일 끝에 도달했는지 등의 정보를 담는다) <br>
- 파일모드 : 파일을 여는 방식<br>
> 
`fputs(문자열, 파일포인터);` : 파일에 데이터를 문자열 단위로 저장 <br>
`fclose(파일포인터);` : 데이터 손실을 방지하기 위해 fopen()후 fclose()사용 필요 <br>

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
	// 파일 생성 및 파일 포인터 생성 
    FILE * file = fopen("/Users/[사용자계정]/Documents/Nado_Coding_C/test1.txt", "wb"); 
    //wb -> 바이너리 데이터를 쓰는 목적으로 새 파일 생성하겠다.

  // 파일 포인터 얻었는지 확인하기 
  if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    fputs("fputs() 함수로 글을 써 볼게요.\n", file);
    fputs("잘 써지는지 확인해 주세요.\n", file);

    fclose(file);

    return 0;
}
```
<img src="https://velog.velcdn.com/images/eunoia73/post/0b659aba-ebd3-4475-a5d8-594e25c55c82/image.png" width="70%" height="50%">



|파일모드|기능|설명|
|:---:|:---:|:---:|
|r|읽기 전용|파일이 있어야 함|
|w|쓰기 전용|새 파일 생성. 기존 파일이 있으면 덮어 씀|
|a|추가|파일을 열어 기존 파일 끝에 이어쓰기. 파일 없으면 새로 생성|
|r+|읽기/쓰기|파일이 있어야 함. 없으면 NULL 반환|
|w+|읽기/쓰기|파일 없으면 새로 생성, 있으면 덮어씀|
|a+|추가(읽기/쓰기)|파일을 열어 기존 파일 끝에 이어쓰기, 파일 없으면 새로 생성,<br> 읽기는 파일의 모든 구간에서, 쓰기는 파일 끝에서만 가능함
|t|텍스트모드|파일을 읽고 쓸 떄 줄바꿈 문자 \n과 \r\n을 서로 변환함<br>^Z를 파일 끝으로 인식하므로 ^Z까지만 파일을 읽음|
|b|바이너리 모드|파일 내용을 그대로 읽고 씀|



#### 2) fgets() 함수로 파일 읽기

>`fgets(변수명, 문자열최대크기, 파일포인터)` : 파일에 저장된 내용을 문자열 단위로 읽는다. 줄바꿈 문자(\n)를 읽으면 읽기를 중단.

```c
#include <stdio.h>
#define MAX 10000  //매크로 정의

int main(void){
    char line[MAX]; //char line[1000]; 파일에서 읽어오는 문자열 저장 배열 선언

    //파일 모드 rb로 설정 
    FILE * file = fopen("/Users/[사용자계정]/Documents/Nado_Coding_C/test1.txt", "rb");

    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    while(fgets(line, MAX, file) != NULL){  //fgets()로 파일 읽기
        printf("%s", line); //출력
    }
    fclose(file);


    return 0;
}

/**
 * 출력 결과
 * 
 * fputs() 함수로 글을 써 볼게요.
 * 잘 써지는지 확인해 주세요.
*/
```

#### 3) 형식을 지정해 파일 입출력하기(fprintf(), fscanf())

> `fprintf(파일포인터, "서식지정자", 값);` : 파일에 데이터 저장하기 <br>
`fscanf(파일포인터, "서식지정자", &변수명);` : 파일에서 데이터 읽어오기

```c
#include <stdio.h>
int main(void){
    //파일 생성 후 포인터 얻기
    FILE * file = fopen("/Users/sookyung/Documents/Nado_Coding_C/test2.txt", "wb");

    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1, 2, 3, 4, 5, 6);

    fprintf(file, "%s %d\n", "보너스번호", 7);
    fclose(file);


    return 0;
}

```
<img src="https://velog.velcdn.com/images/eunoia73/post/e10492a7-b0d0-419b-80b2-16e11e939af3/image.png" width="70%" height="50%">

```c
#include <stdio.h>
#define MAX 10000

int main(void){
    char str1[MAX];
    char str2[MAX];
    int num[6] = {0, 0, 0, 0, 0, 0};
    int bonus = 0;

    FILE * file = fopen("/Users/sookyung/Documents/Nado_Coding_C/test2.txt", "rb");  //파일 포인터 얻기
    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    //fscanf() 함수로 파일 읽기
    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    //추첨번호 출력
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

    //fscanf() 함수로 파일 읽기
    fscanf(file, "%s %d", str2, &bonus);
    //보너스번호 출력
    printf("%s %d\n", str2, bonus);
    
    fclose(file);

    return 0;
}

/**
 * 출력 결과
 * 
 * 추첨번호 1 2 3 4 5 6
 * 보너스번호 7
*/
```


** 2024.11.25 ~ 2024.12.22 
나도코딩 C언어 코딩자율학습단을 진행하며 작성한 공부기록입니다.


