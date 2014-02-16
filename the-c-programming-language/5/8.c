#include <stdio.h>
#define YEARLENGTH 365

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(void)
{
    int month, day;
    month_day(1997, 139, &month, &day);
    printf("19.05.1997 was %dth day of year\n", day_of_year(1997, 5, 19));
    printf("139 day of 1997 was %d.0%d", day, month);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    if (month < 0 || month > 0 || daytab[leap][month] < day)
        return 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (yearday > YEARLENGTH + leap) {
        pmonth = NULL;
        pday = NULL;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
