#include <stdio.h>

int testPerfect(int *n)
{
    int sum = 0;
    int input = 0;
    int i = 0;
    int cnt = 0;
    
    input = *n;
    
    for(i;i<input; i++)
    {
        if(input % i == 0) //나머지 0이면
        {
            sum += i;
            cnt++;
        }
    }
    if(input == sum) //맞으면
        return 1;
        
    else
        return 0; //아니면
}

void printFactors(int *n)
{
    int i = 0;
    int sum;
    int input;
    int carr[25];
    int cnt = 0;
        
    input = *n;
    for(i;i<input; i++)
    {
        if(input % i == 0)
        {
            carr[cnt] = i;
            cnt++;
        }

    }
    cnt = cnt - 1;
    //printf("craft : ");
    for(cnt; cnt >= 0; cnt--)
    {
        printf("%d", carr[cnt]);
        printf(" ");
    }
    puts("");
    //약수출력
}


int main(void)
{
    int i = 0; // 횟수카운트
    int n = 0;
    int perfect;
    
    do
    {
        printf("How many numbers would you like to test? : "); scanf("%d",&i); //반복
        if(i > 0)
            break; // 제대로된값 입력받으면 통과
    }while(1);
    
    
    for(int cnt = 0 ; cnt < i ; cnt++) // 횟수반복
    {
        printf("Please enter a possible perfect number : "); scanf("%d",&n);
        perfect = testPerfect(&n);
        
        if(perfect == 0) // 아니면
            printf("%d : NOT PERFECT\n", n);
        if(perfect == 1) // 맞으면
        {
            printf("%d : PERFECT : ", n);
            printFactors(&n);
        }
    }
    
    
    return 0;
}


//6
//28
//496
//33,550,336

