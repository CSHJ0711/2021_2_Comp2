#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int floorinput(void)
{
    int n = 0;
    do{
        n = 0;
        printf(" How many steps do you want: ");
        scanf("%d", &n);
        if(n > 0) //계단 범위 내의 경우
            break;
        else
            printf(" The number of stairs must be larger than 0.\nYour input value is %d\n",n); //계단 범위 외의 경우
    }while(1);
    return n;
}

void step(char *Steps, char LastFoot, int n) //포인터,문자,정수 메인함수 에서 입력 받은값 {NULL,S/L/R,3}
{
            /* LastFoot : 마지막으로 오른 발 (왼발(L)/오른발(R)) */
    int i;//for문 횟수
    char *NextStep;//다음에 올라가야할 계단수
    if (n==0) //다 올라간 경우
    {
        printf("%s\n", Steps);//문자열출력
    }
    if (n<0) //0이하로 작아지는경우 (0도 포함)
    return;
    
    NextStep = (char*)malloc(strlen(Steps)+4); //NextStep 에 char형의 동적메모리 할당
    if(NextStep != NULL) //메모리 할당의 성공유무 파악
    {
        if (LastFoot != 'L') //만약 마지막으로 오른 발이 왼발이 아니라면 (오른발이라면)
            for (i=3; i>=1; i--) //왼발은 3번 오를 수 있으므로
            {
                /* sprintf : (str,"문자열"); -> "문자열" 을 str에 저장 */
                sprintf(NextStep,"%s %dL", Steps, i); //Steps : 원래 있던 값, i 새로 오른 발
                step(NextStep, 'L', n-i); //재귀함수(step함수를 다시 부름) , (현재 오른 발의 수, 계단을 오른 발(왼발), n(계단수) - i)
            }
        if (LastFoot != 'R') //만약 마지막으로 오른 발이 오른발이 아니라면 (왼발이라면)
            for (i=1; i<2; i++) //오른발은 1번 오를 수 있으므로
            {
                sprintf(NextStep,"%s %dR", Steps, i); //Steps : 원래 있던 값, i 새로 오른 발
                step(NextStep, 'R', n-i); //재귀함수(step함수를 다시 부름) , (현재 오른 발의 수, 계단을 오른 발(오른발), n(계단수) - i)
            }
            free(NextStep); //메모리할당 해제
    }
    else //메모리 할당 실패시
    {
        printf("\n\n!!!!Memory allocation failed.!!!!\n\n"); //메모리 할당 실패 출력
        exit(1);
    }
}
int main() {
    int n = floorinput();
    step("", 'S', n);//문자열 , 문자 , 정수({NULL,S,n값})
}