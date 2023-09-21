/*        Alphabet Couple 
          N : 7
          xxyyzz
          yc
          aaaab
          bca
          qqzqq
          qnwerrewmq
          aaa

          Good
          cy
          b
          abc
          z
          mn
          a            */
          
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void is_couple(char (*input_string)[101],int n)
{
    int i = 0, j = 0, cnt = 0;
    char arr[n][101];
    for(i=0;i<n;i++)
        strcpy(arr[i],input_string[i]); //배열 복사
    for(i=0;i<n;i++)
    {
        for(j=0;j<strlen(arr[i]);j++)
        {
            if(arr[i][j]==arr[i][j+1]) //만일 다음것과 같으면
            {
               arr[i][j]='1'; //앞에거 1으로 수정
               arr[i][j+1]='1'; //뒤에거 1으로 수정
            }
        }
    }
    puts("");
    for(i=0;i<n;i++) //n이 될때까지
    {
        cnt=0;
        for(j=0;j<strlen(arr[i]);j++)
        {
            if(arr[i][j]=='1') //만일 1이면
            {
                cnt++; //cnt에 1더함
                continue;
            }
            else
                printf("%c",arr[i][j]);
        }
        if(cnt==strlen(arr[i])) //cnt의 길이가 배열의 길이와 같다면
            printf("GOOD"); //출력
        printf("\n");
    }
}
void inputstring(int n) //string 입력함수
{
    int i = 0, j = 0, z = 0;
    char k = 0;
    char arr[n][101]; //string을 입력받는 2차원 배열. 문자열의 길이는 1~100이므로.
    for(i=0;i<n;i++)
        scanf("%s",arr[i]); //n번만큼 입력받아 2차원 배열에 저장
    for(i=0;i<n;i++)
    {
        for(z=0;z<strlen(arr[i])-1;z++) //정렬
        {
            for(j=0;j<strlen(arr[i])-1-z;j++)
            {
                if(arr[i][j]>arr[i][j+1])
                {
                    k=arr[i][j];
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=k;
                }
            }
        }
    }
    is_couple(arr,n); //배열값 알파벳순으로 수정후 넘김
}
void Enter_N(void) //n값 입력 함수
{
    int n = 0;
    do
    {
        printf("Enter N : "); //n값 입력
        scanf("%d",&n);
        if(n>0) //0보다 클경우 탈출
        {
            break;
        }
        else //n보다 작을경우
        printf("Enter a Positive number\n"); //경고문
    }while(1);
    inputstring(n);
}
int main(void)
{
    Enter_N();
}
