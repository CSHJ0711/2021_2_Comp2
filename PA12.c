#include <stdio.h>
#include <math.h> //floor 함수 사용을 위함

void countstudent(int *n) //학생수 구하기
{
    do{
        printf("Enter The number of Student: ");
        scanf("%d",n);
        if(*n > 0 && *n < 1000) //학생수 범위내의경우
            break;
        else
            printf("The number of students ranges from 0 to 1,000\nYour input value is %d\n",*n); //학생수 범위 외의 경우
    }while(1);
}

void collectexpenses(int *n, float *arr) //학생수 , 배열
{
    int i = 0;
    float t = 0;
    
    puts("Enter the student's expenses");
    for(i = 0; i < *n; i++) //학생수만큼 반복
    {
        do{
            scanf("%f",&t); //t 변수에 입력
            if(t > 10000 || t < 0) //금액 범위 외
            {
                printf("Students don't spend more than $10,000.00\nYour input value is %.2f\n",t); //오류문 출력
                continue;
            }
            else
            {
                arr[i] = floorf(t * 100) / 100; //t 변수에 100을 곱한후 나머지 값들을 버림. 후 100을 나눔
                break;
            }
        }while(1);
            
    }
}

float sum_average(int *n, float *arr)
{
    int i = 0;
    float sum = 0, average = 0;
    
    for(i = 0; i < *n; i++)
    {
        sum += arr[i]; //배열 하나하나 sum 함수에 더함
    }
    average = sum / *n; //sum 함수를 n으로 나눠 평균 계산
    return average; //평균값 return
}

void difference(int *n, float *arr, float average)
{
    float diffarr[*n]; //차이값을 저장할 배열 생성 (n명만큼의 배열)
    int i = 0;
    float sum = 0;
    float tmp = 0;
    
    
    for(i=0; i < *n; i++)
    {
        tmp = 0;
        diffarr[i] = arr[i] - average; //각 학생이 지불한 금액에 평균값을 빼서 평균과의 값 비교
        tmp = diffarr[i]; //tmp에 배열 저장
        diffarr[i] = floorf(tmp * 100) / 100; //차이값을 소수점 2자리까지 구하고 나머지 버림
        
        if(diffarr[i] > 0 ) //차이가 0보다 큰 값만
            sum += diffarr[i]; //sum 함수에 저장
    }
    printf("$%.2f\n",sum);
}
int main(void)
{
    int n = 0;
    float average = 0;
    
    countstudent(&n);
    float arr[n]; //학생수 만큼의 float 배열 생성
    collectexpenses(&n, arr);
    average = sum_average(&n, arr);
    difference(&n, arr, average);
}
