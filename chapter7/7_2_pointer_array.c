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