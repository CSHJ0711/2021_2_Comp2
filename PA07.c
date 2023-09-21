#include <stdio.h>

void get_date(char* birthday) //생년월일 정보 입력
{
    printf("Enter the birth date (mm/dd/yyyy) : ");
    gets(birthday); // 7 / 23 / 1981
}

int validate_date(int year, int month, int day) // 기간제한, 날짜확인, 덧셈
{
    int rt = 0;
    
    if(year <= 1880 || year >= 2280) //year가 정해진 값이 아닐때
    {
        printf("Bad year : %d ( 1880 <= year <= 2280 )\n", year);
        return 0;
    }
    else if(month >= 12 || month <= 0) //month가 정해진 값이 아닐때
    {
        printf("Bad month : %d ( 1 <= month <= 12 )\n", month);
        return 0;
    }
    else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12)&& (day > 31 || day <= 0)) //0 <= day < 31
    {
        printf("Bad day for %d / %d : %d \n", month, year, day);
        return 0;
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11)&& (day > 30 || day <= 0)) //0 <= day < 30
    {
        printf("Bad day for %d / %d : %d \n", month, year, day);
        return 0;
    }
    else if(month == 2 && year % 4 == 0 && (day > 29 || day <= 0)) //2월 0 <= day < 29 윤년
    {
        printf("Bad day for %d / %d : %d \n", month, year, day);
        return 0;
    }
    else if(month == 2 && year % 4 != 0 && (day > 28 || day <= 0)) //2월 0 <= day < 28 윤년아님
    {
        printf("Bad day for %d / %d : %d \n", month, year, day);
        return 0;
    }
    else
    {
        rt = year + month + day;
        return rt;
    }
}

int crunch_date(int number) //한자리숫자로 쪼갬
{
    int save1 = 0, save2 = 0, tmp = 0;
    int i;
    
    for(i = number ; i > 0; i /= 10) //하나씩 나눠서 더하기
    {
        tmp = i % 10;
        save1 += tmp;
    }
    if(save1 >= 10) //나눴음에도 10보다 큰 경우
    {
        for(i = save1 ; i > 0; i /= 10)
        {
            tmp = i % 10;
            save2 += tmp;

        }
    }
    else
        save2 = save1;
    return save2;
}

void show_numerology(int number) //운세출력
{
    if(number == 1)
        puts(":1: Neither give cherries to pigs nor advice to a fool.");
    if(number == 2)
        puts(":2: Expect harmony and balance.");
    if(number == 3)
        puts(":3: Your dearest dream is coming true.");
    if(number == 4)
        puts(":4: Take a leap of faith.");
    if(number == 5)
        puts(":5: Your sweetheart may be too beautiful for words, but not for arguments.");
    if(number == 6)
        puts(":6: Rid your life of negative energy.");
    if(number == 7)
        puts(":7: Prepare for a spiritual awakening.");
    if(number == 8)
        puts(":8: You are almost there.");
    if(number == 9)
        puts(":9: Share your wisdom with the world.");
    if(number == 0)
        puts(":0: You are on the right path.");
    
}

int main(void)
{
    char birthday[1024]; // 생일받는 변수
    int year, month, day; //년 월 일
    int number[14]; //숫자별로 나눔
    int i = 0; //for문 i
    int rt = 0, sum = 0;
        
    
    do{
        year = 0; month = 0; day = 0;
        get_date(birthday); //생일값 넘겨줌
        for(i = 0; i < 14; i++) //number 배열
        {
            number[i] = birthday[i] - '0'; //char의 int화
            
            if(number[i] == -3) // - 를 썼을 때 오류띄우기
            {
                puts("Use forward slashes between mm/dd/yyyy!");
                return 0;
            }
            else if(number[i] < 0)
                number[i] = -1; //그 외의 경우 -1로 모두 변경
        }
        for(i = 0; i < 2; i++) //월
        {
            if(number[i] == -1)
                continue;
            else
                month = (month*10) + number[i]; // -1인경우 무시, 값이 있는경우 month에 저장
        }
        for(i = 4; i < 7; i++) //일
        {
            if(number[i] == -1)
                continue;
            else
                day = (day*10) + number[i]; // -1인경우 무시, 값이 있는경우 day에 저장
        }
        for(i = 8; i < 14; i++) // 년
        {
            if(number[i] == -1)
                continue;
            else
                year = (year*10) + number[i]; // -1인경우 무시, 값이 있는경우 year에 저장
        }
        rt = validate_date(year, month, day);
        if(rt != 0) // rt가 0이 아닌경우
        {
            sum = crunch_date(rt);
            printf("Welcome to the numerology report for %d/%d/%d :\n",month,day,year);
            show_numerology(sum);
        }
    }while(1);
}
