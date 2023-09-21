/*        Anagram
//input
          3
          blather reblath
          maryland landam
          bizarre brazier
          
//output
          blather & reblath are anagrams.
          maryland & landam are NOT anagrams.
          bizarre & brazier are anagrams.       */

#include <stdio.h>

int inputn()
{
	int n = 0;
	scanf("%d", &n);
    while( n < 0 || n > 100 ) //테스트 케이스 범위가 아닐경우
    {
        printf("test case must be between 0 and 100. \n Your input value is %d\n",n);
        scanf("%d", &n);
    }
}
int cntCmp(int* arr1A, int* arr2A)
{
    int i=0;
    for ( i = 0; i < 26; i++) //a~z 26개
    {
        if (arr1A[i] != arr2A[i]) //하나라도 다른게 있으면
            return 0; //0 return
    }
    return 1; //모두 다 같으면 1 return
}

int main()
{
    int i = 0, n = 0;
    n = inputn();

    char Tarr[n][250];
    for ( i = 0; i < n; i++)
    {
        char arr1[101] = { 0, } , arr2[101] = { 0, }; //단어를 받기위한 배열
        scanf("%s %s", arr1, arr2); //단어 입력
        int result = 0 , check = 0;
        int arr1A[26] = { 0, } , arr2A[26] = { 0, }; //알파벳 개수를 세기 위한 배열
        /*      -- ASCII --
                a~z : 97~122        */
        while (arr1[check] != '\0') //arr1의 배열 검사
        {
            arr1A[(int)arr1[check] - 97]++; //해당하는 알파벳 위치에 1 더함
            check++; //다음 알파벳을 검사하기 위해 더함
        }
        check=0;
        while(arr2[check]!='\0') //arr2의 배열 검사
        {
            arr2A[(int)arr2[check] - 97]++; //해당하는 알파벳 위치에 1 더함
            check++; //다음 알파벳을 검사하기 위해 더함
        }
        result = cntCmp(arr1A, arr2A); //알파벳 개수 비교를 위한 함수호출
        if(result == 0) //anagram이 아니면
            sprintf(Tarr[i],"%s & %s are NOT anagrams.",arr1,arr2);
        if(result == 1) //anagram이면
            sprintf(Tarr[i],"%s & %s are anagrams.",arr1,arr2);
    }
    puts("");
    for(i = 0; i < n; i++) //테스트 케이스 만큼 반복
    {
        puts(Tarr[i]); //입력되던 배열을 모두 출력
    }
}