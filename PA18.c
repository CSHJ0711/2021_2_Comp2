#include <stdio.h>
#include <string.h> //strlen
#include <ctype.h>  //tolower
#include <stdbool.h> //bool

void inputrc(int *row, int *col)
{
    scanf("%d %d", row, col);
}
void inputarr(int row, int *word_num, char (*grid)[100], char (*word_array)[100])
{
    int i = 0;
    char arr[100];
    //무작위 단어입력------------
    for(i =1; i <= row; i++)
    {
        scanf("%s", arr); //배열에 입력
        strcpy(grid[i],arr);
    }
    scanf("%d", word_num); //몇개 찾을지 입력
    // 찾을 단어입력-----------
    for(i=1; i<=*word_num; i++)
    {
        scanf("%s", arr); //찾을 단어 배열에 입력
        strcpy(word_array[i],arr);
    }
}
int main()
{
    int col = 0, row = 0;
    int word_num = 0;
    int aa = 0;
    int c = 0, x = 0, i = 0;
    char grid[100][100]; //무작위 단어 입력 배열
    char word_array[100][100];
    inputrc(&row,&col);
    inputarr(row,&word_num,grid,word_array);

    for(i=1; i<=word_num; i++)
    {
        for(x =1; x <= row; x++)
        {
            char row_string[100];
            strcpy(row_string, grid[x]); //row_string과 grid 복사
            char word_copy[100];
            strcpy(word_copy, word_array[i]); //word_copy
            for(c = 0; c <= col-1; c++)
            {
                if(tolower(word_copy[0]) == tolower(row_string[c])) // 알파벳 겹치는거 찾기
                { //찾았으면

                    int current_wl = strlen(word_copy) - 1; //문자열 길이 -1 (시작은 찾고 들어가기 때문에 제외하기 위함)
                    int a = 0;
                    int b = 0;
                    
                    bool flag = true;
                    
                    a = (x-current_wl); //찾은 열에서 단어수 -1만큼 빼기 (위로 올라가도 괜찮은지)
                    if( a > 0) //위로 충분히 올라갈 수 있으면
                    { // Path 1: top //위를 검사
                        for(aa = 1; aa <= current_wl; aa++)
                        {
                            char col_string[100];
                            strcpy(col_string, grid[x-aa]); //올라가며 복사
                            if(tolower(word_copy[aa]) != tolower(col_string[c])) //다르면
                                flag = false; //false로 변경
                            if(aa == current_wl) //모두 똑같은걸 찾으면
                            {
                                if(flag == true) //true면
                                    printf("%d %d\n",x,c+1); //프린트
                            }
                        }
                    }
                    
                    flag = true;
                    a = (x-current_wl); //찾은 열에서 단어수-1만큼 빼기 (올라가도 괜찮은지)
                    b = (c+1+current_wl); //찾은 행에서 단어수만큼 (오른쪽으로 가도 괜찮은지)

                    if( a > 0 && b <= col) //가도 괜찮으면
                    { // Path 2: top-right
                        for(aa = 1; aa <= current_wl; aa++)
                        {
                            char col_string[100];
                            strcpy(col_string, grid[x-aa]);
                            if(tolower(word_copy[aa]) != tolower(col_string[c+aa]))
                                flag = false;
                            if(aa == current_wl){
                                if(flag == true)
                                    printf("%d %d\n",x,c+1);
                            }
                        }
                    }
                    
                    flag = true;
                    a = (x+current_wl); //찾은 열에서 단어수만큼 더하기 (내려가도 괜찮은지)
                    if( a <= row) //내려가도 괜찮으면
                    { // Path 3: down
                        for(aa = 1; aa <= current_wl; aa++){
                            char col_string[100];
                            strcpy(col_string, grid[x+aa]);

                            if(tolower(word_copy[aa]) != tolower(col_string[c]))
                                flag = false;

                            if(aa == current_wl)
                            {
                                if(flag == true)
                                    printf("%d %d\n",x,c+1);
                            }
                        }
                    }
                    
                    flag = true;
                    a = (x+current_wl); //찾은 열에서 단어수만큼 더하기(내려가도 괜찮은지)
                    b = (c+1+current_wl); //찾은 행에서 단어수만큼 더하기 (오른쪽으로 가도 괜찮은지)
                    if( a <= row && b <= col)
                    { // Path 4: down-right
                        for(aa = 1; aa <= current_wl; aa++)
                        {
                            char col_string[100];
                            strcpy(col_string, grid[x+aa]);
                            if(tolower(word_copy[aa]) != tolower(col_string[c+aa]))
                                flag = false;

                            if(aa == current_wl){
                                if(flag == true)
                                    printf("%d %d\n",x,c+1);
                            }
                        }
                    }
                    
                    flag = true;
                    a = (c-current_wl+1); //찾은 행에서 단어수만큼 빼기 (왼쪽으로 가도 괜찮은지)
                    if( a > 0)
                    { // Path 5: left
                        for(aa = 1; aa <= current_wl; aa++)
                        {
                            
                            if(tolower(word_copy[aa]) != tolower(row_string[c-aa]))
                                flag = false;

                            if(aa == current_wl){
                                if(flag == true)
                                    printf("%d %d\n",x,c+1);
                            }
                        }
                    }
                    
                    flag = true;
                    a = (c+1-current_wl); //찾은 행에서 단어수만큼 빼기 (왼쪽으로 가도 괜찮은지)
                    b = (x+current_wl); //찾은 열에서 단어수만큼 더하기(내려가도 괜찮은지)
                    if( a > 0 && b <= row)
                    { // Path 6: down-left
                        for(aa = 1; aa <= current_wl; aa++)
                        {
                            char col_string[100];
                            strcpy(col_string, grid[x+aa]);
                            if(tolower(word_copy[aa]) != tolower(col_string[c-aa]))
                                flag = false;

                            if(aa == current_wl){
                                if(flag == true)
                                    printf("%d %d\n",x,c+1);
                            }
                        }
                    }
                    
                    flag = true;
                    a = (c+1+current_wl); //찾은 행에서 단어수만큼 더하기 (오른쪽으로 가도 괜찮은지)
                    if(a <= col)
                    { // Path 7: right
                          for(aa = 1; aa <= current_wl; aa++)
                          {
                              if(tolower(word_copy[aa]) != tolower(row_string[c+aa]))
                                  flag = false;

                              if(aa == current_wl)
                              {
                                  if(flag == true)
                                      printf("%d %d\n",x,c+1);
                              }
                          }
                      }

                      flag = true;
                      a = (x-current_wl); //찾은 열에서 단어수만큼 빼기(올라가도 괜찮은지)
                      b = (c+1-current_wl); //찾은 행에서 단어수만큼 빼기 (왼쪽으로 가도 괜찮은지)
                      if( a > 0 && b > 0)
                      { // Path 8: top-left
                          for(aa = 1; aa <= current_wl; aa++)
                          {
                              char col_string[100];
                              strcpy(col_string, grid[x-aa]);

                              if(tolower(word_copy[aa]) != tolower(col_string[c-aa]))
                                  flag = false;

                              if(aa == current_wl)
                              {
                                  if(flag == true)
                                      printf("%d %d\n",x,c+1);
                              }
                          }
                      }
                      break;
                  }
              }
          }
      }
  }

/*
 
8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
 

 https://drive.google.com/drive/folders/18QZzOh4hQTD8wroXJeV9VKiOiySE_Ht0?usp=sharing
 
 
 */
 