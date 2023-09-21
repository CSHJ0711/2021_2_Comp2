#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81
void Enter_N(int *a)
{
    do{
        printf("Enter N :");
        scanf("%d",a);
        if(*a>0){
            break;
        }else
        printf("Enter a Positive number\n");
    }while(1);
}
int get_score(char *input_string[MAX]){
            int i;int z=0;int c=0;
            char arr[MAX];
            strcpy(arr,input_string);
            for(i=0;i<strlen(arr);i++){
                if(arr[i]=='O'){
                    z++;
                    c+=z;
                }
                if(arr[i]=='X'){
                    z=0;
                }
            }
    return c;
}
void inputstring(int a){
    int i=0;
    int z=0;
    int total=0;
    char arr[a][MAX];
    for(i=0;i<a;i++){
    scanf("%s",arr[i]);
    }
    printf("\n");
    for(z=0;z<a;z++){
        total=get_score(arr[z]);
        printf("%d\n",total);
    }
    
}
int main(){
    int a;
    Enter_N(&a);
    inputstring(a);
}