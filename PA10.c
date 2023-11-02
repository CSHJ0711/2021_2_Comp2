//Game Of Life

#include <stdio.h>
#define GRIDSIZE 20
void clearGrid(int(*grid)[GRIDSIZE]) {//grid 이차원 배열 0으로 초기화
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            grid[i][j] = 0;
        }
    }
}
void setup(int(*board)[GRIDSIZE], char which) {

    clearGrid(board);

    if (which == 'q') {
        board[5][1] = 1;
        board[5][2] = 1;
        board[6][3] = 1;
        board[7][4] = 1;
        board[8][4] = 1;
        board[9][4] = 1;
        board[10][3] = 1;
        board[11][2] = 1;
        board[11][1] = 1;
    }
    else {
        board[15][1] = 1;
        board[16][1] = 1;
        board[16][2] = 1;
        board[17][0] = 1;
        board[17][2] = 1;
    }
}

void displayGrid(int(*grid)[GRIDSIZE]) {
    int x, r, c;

    printf("   ");
    for (x = 1; x <= GRIDSIZE; x++) {
        if ((x / 10) != 0)
            printf("%d", x / 10);
        else
            printf(" ");
    }

    printf("\n");
    printf("   ");

    for (x = 1; x <= GRIDSIZE; x++)
        printf("%d", x % 10);
    printf("\n");

    for (r = 0; r < GRIDSIZE; r++) {
        printf("%d", r + 1);

        if (r + 1 < 10)
            printf("  ");
        else
            printf(" ");
        for (c = 0; c < GRIDSIZE; c++) {
            if (grid[r][c] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
int countNeighbors(int(*grid)[GRIDSIZE], int row, int col) {
    int c = 0;
    int i = row;
    int j = col;
    if (grid[i][j] == 1) {//생존 or 죽음
        if (grid[i - 1][j - 1] == 1) {
            c++;
        }
        if (grid[i - 1][j] == 1) {
            c++;
        }
        if (grid[i - 1][j + 1] == 1) {
            c++;
        }
        if (grid[i][j - 1] == 1) {
            c++;
        }
        if (grid[i][j + 1] == 1) {
            c++;
        }
        if (grid[i + 1][j - 1] == 1) {
            c++;
        }
        if (grid[i + 1][j] == 1) {
            c++;
        }
        if (grid[i + 1][j + 1] == 1)
        {
            c++;
        }
        return c;
    }
    if (grid[i][j] == 0) {//탄생
        if (grid[i - 1][j - 1] == 1) {
            c++;
        }
        if (grid[i - 1][j] == 1) {
            c++;
        }
        if (grid[i - 1][j + 1] == 1) {
            c++;
        }
        if (grid[i][j - 1] == 1) {
            c++;
        }
        if (grid[i][j + 1] == 1) {
            c++;
        }
        if (grid[i + 1][j - 1] == 1) {
            c++;
        }
        if (grid[i + 1][j] == 1) {
            c++;
        }
        if (grid[i + 1][j + 1] == 1)
        {
            c++;
        }
        return c;
    }return 0;
}
void genNextGrid(int(*grid)[GRIDSIZE]) {
    int z = 0;
    int APP[GRIDSIZE][GRIDSIZE] = { 0, };//원래 배열을 복사 하기 위해
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (grid[i][j] == 1) {
                z = countNeighbors(grid, i, j);//1에 값에 이웃 확인
                if (z == 2 || z == 3) {//조건 이웃수가 2,3이면 생존
                    APP[i][j] = 1;
                    z = 0;
                }
                else {
                    APP[i][j] = 0;
                    z = 0;
                }
            }if (grid[i][j] == 0) {
                z = countNeighbors(grid, i, j);
                {
                    if (z == 3) {//이웃수가 3이면 탄생
                        APP[i][j] = 1;
                        z = 0;
                    }
                    else {
                        z = 0;
                        continue;
                    }
                }
            }
        }
    }
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            grid[i][j] = APP[i][j];
        }
    }
}
int main(void) {
    int board[GRIDSIZE][GRIDSIZE];
    char choice;
    int x = 1;

    do {
        printf("Start with the (q)ueen bee shuttle or the (g)lider pattern? ");
        scanf("%c", &choice);
    } while (choice != 'q' && choice != 'g');

    setup(board, choice);//초기화했던 값을 넘긴다.

    do {
        printf("Viewing generation #%d:\n\n", x++);
        displayGrid(board);
        genNextGrid(board);
        printf("\n(q)uit or any other key + ENTER to continue: ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice != 'q');
}
