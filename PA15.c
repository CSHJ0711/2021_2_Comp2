/*        Max_Alphabet 
          Mississipi -> ?
          zZa -> Z
          Z -> Z
          baaa -> A         */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char max_alphabet(char string[])
{
    int arr[26] = { 0, }; //알파벳 저장
    int i = 0; //for문 i
    unsigned long size = strlen(string); //string의 크기저장
    int many = 0; //알파벳 개수 최대값
    char c = '\0'; //가장 많이 사용된 알파벳을 저장
    
    for(i = 0; i<size; i++)
    {
        /*      -- ASCII --
                A~Z : 65~90
                a~z : 97~122        */
        
        if(string[i]<=90) //대문자일때
        {
            arr[string[i]-65]++;
        }
        else if(string[i]>=97) //소문자일때
        {
            arr[string[i]-97]++;
        }
    }

    for(i = 0; i<26; i++)
    {
        if(arr[i] !=0 && many < arr[i]) //가장 많이 사용된 알파벳 찾기
        {
            many = arr[i];
            c = i+65;
        }
    }
    
    for(i = 0; i<26; i++)
    {
        if(arr[i]!=0 && many == arr[i] && i!=c-65) //사용된 횟수가 같은 알파벳 찾기
        {
            c = '?';
            break;
        }
    }
    return c;
}

int main(void)
{
    char str[255];
    char found;
    
    printf("Enter a word: ");
    gets(str);
    
    found = max_alphabet(str);
    printf("%c\n", found);
}
