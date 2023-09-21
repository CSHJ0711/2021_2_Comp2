#include <stdio.h>

void getBoundaries(int* a, int* b) {
    int Min, Max;
    do {
        do {
            printf("Please enter the Lower boundary(between 1 and 50000):");//최소값 판별
            scanf("%d", &Min);
            if (Min > 0 && Min < 50001)
            {
                *a = Min;
                break;
            }
        } while (1);
        do {
            printf("Please enter the Upper boundary(between 1 and 50000):");//최대값 판별
            scanf("%d", &Max);
            if (Max > 0 && Max < 50001)
            {
                *b = Max;
                break;
            }
        } while (1);
        if (Max > Min) //최대값이 최솟값이 크면 탈출
        {
            break;
        }
        else
        {
            printf("your upper boundary cannont be smaller than your lower boundary\n");//아니면 반복
        }
    } while (1);
}

void ProcessSieve(int* a, int* b, int* primes)
{
    int i = 0, j = 0, c = 0;
    for (i = 2; i <= *b; i++) //2 ~ Max 초기화
    {
        primes[i] = 1;
    }
    for (i = 2; i <= *b; i++)
    {
        if (primes[i] != 0) //초기화된 값이 0이 아니라면
        {
            for (j = i * 2; j <= *b; j += i) //j = i * 2
            {
                primes[j] = 0; // 0 -> 소수 X
            }
        }
    }
    for (c = *a; c <= *b; c++) // c = min
    {
        if (primes[c] == 1) //c 가 1이면
        {
            if (primes[1] ==1)
            {
                primes[1] = 0;
            }
            primes[c] = c;
        }
    }
}
void showprimes(int* a, int* b, int* arr)
{
    int c = 0, i = 0;
    printf("\nHere are all of the sexy prime pairs in the range %d to %d:\n", *a, *b);
    for (i = *a; i <= *b; i++) {
        if (arr[i] + 6 == arr[i + 6]) {
            printf("%d and %d\n", arr[i], arr[i + 6]);
            c++;
        }
    }printf("There were %d sexy prime pairs displayed between %d and %d\n", c, *a, *b);
}

int main()
{
    int Max = 0, Min = 0;
    int primes[50001] = { 0 };
    getBoundaries(&Min, &Max);
    ProcessSieve(&Min, &Max, primes);
    showprimes(&Min, &Max, primes);
}
