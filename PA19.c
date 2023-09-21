#include <stdio.h>

typedef struct item {
    int weight;
    int value;
}item;
int max(int a, int b) //a b중에 큰 값을 return하는 함수임
{
    if (a>b)
        return a;
    else
        return b;
}

int choose(int n, int w, item arr[], int k[100][200]) //개수 최대무게, 가방, 아무것도 없는 배열 전달
{
    
    int i, j; //for문
    int select, unselect;

    for (i = 0; i <= n; i++) //물건 개수까지
    {
        for (j = 0; j <= w; j++) //최대무게까지
        {
            if (arr[i].weight>j) //무게가 j보다 크면
                k[i][j] = k[i - 1][j]; //하나 전에있는거 입력
            else //무게가 j보다 작으면
            {
                unselect = k[i - 1][j];
                select = k[i - 1][j - arr[i].weight] + arr[i].value;
                k[i][j] = max(unselect, select); //큰걸 넣음
            }
        }
    }
    return k[n][w];
}
void make_list(int k[100][200], item arr[], int n, int w) //배열, 가방, 개수, 최대무게 전달
{
    int i,j;
    int cnt = 0;
    j = w;
    int list[100] = {0,};
    

    for (i = n - 1; i >= 0; i--)
    {
        if (k[i][j] != k[i - 1][j]) //같지 않으면
        {
            list[cnt] = i; //i를 입력
            j = j - arr[i].weight; //
            cnt++;
        }
        if (j <= 0) //j가 0보다 작아지면 (무게가 0보다 작아지면)
            break;
    }
    for (i = cnt - 1; i >= 0; i--) //출력
        printf("%d ", list[i]);
}

int main()
{
    int i, ans;
    int k[100][200] = { 0, };
    int n = 0, w = 0;

    scanf("%d %d", &n, &w); //물건의 개수 , 넣을 수 있는 최대 무게
    struct item bag[n];
    
    for (i = 0; i<n; i++)
        scanf("%d", &bag[i].value); //물건 가치 입력
    for (i = 0; i<n; i++)
        scanf("%d", &bag[i].weight); //물건 무게 입력

    ans = choose(n, w, bag, k); //개수, 최대무게, 가방, 아무것도 없는 배열 전달
    printf("Max value: %d\n", ans);
    make_list(k, bag, n, w); //배열, 가방, 개수, 최대무게 전달

    printf("\n");
}

/*
 
10 20
2 3 3 4 4 5 7 8 8 9
3 5 7 4 3 9 2 9 5 10
 
 */