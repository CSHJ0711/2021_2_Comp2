#include <stdio.h>

int is_palindrome(int *r) // 회문 판단 함수
{
    if(1000 < *r )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int reverse(unsigned int n) // n값을 뒤집는 함수
{
    int result = 0;
    int i = 0, p = 0; // i -> n, p : 
    for( i = n ; i > 0; i /= 10 ) // i를 10으로 나눈 몫
    {
        p = i % 10; // i의 나머지
        result = (result * 10) + p;
    }
    return result;
}

void add(int n) //더하는 함수
{
    int r = 0;
    unsigned int result = reverse(n);
    int i = 0;
    for( i = n ; 1000 >= r && i != result; )
    {
        i += result;
        result = reverse(i);
        ++r;
    }
    
    //결과값 출력

    int totval = is_palindrome(&r);
    if(totval == 0)
    {
        puts("There is no palindrome.");
    }
    else
    {
        printf("%d %d\n", r,result);
    }
}


int main()
{
    unsigned int n = 0;
    printf("Please enter a number: ");
    scanf("%d", &n);

    add(n);

}

