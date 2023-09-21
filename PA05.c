#include <stdio.h>

void seat(int *buf, int n, int c)
{
    int tmp;
    int l;
    int k = 0;
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(buf[j] > buf[j+1]){
                tmp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = tmp;
            }
        }
    }
    
    
    
    for(int i=0; i < c; i++){
        for(l=0; l < c; l++){
            printf("%d ", buf[k]);
            k++;
        }
        printf("\n");
        l = 0;
    }
}

int main(void)
{
    int buf[100];
    int n, c, i = 0;

    puts("(학생수) (자리수)");
    scanf("%d %d", &n, &c);
    puts("학생들의 키를 입력 (띄어쓰기로 구분)");
    for (i = 0; i < n; i++){
        scanf("%d", &buf[i]);
    }
    
    seat(buf, n, c);
}