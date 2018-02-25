#include <stdio.h>
//Works Cited: Professor Hong's GitHub 

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day of year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;
    if(year < 1 || month > 12 || month < 1 || day < 1)
	    return -1;

    leap = year%4 == year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

// month_day: set month, day from day of year
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if(yearday < 1)
    {
	    return -1;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if((leap && yearday > 366) || (!leap && yearday > 365))
 {
		    return -1;
}
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int day;
    day = day_of_year(2018, 2, 15);
    printf("day=%d\n", day);

    int pmonth, pday;
    month_day(2018, 46, &pmonth, &pday);
    printf("pmonth=%d, pday=%d\n", pmonth, pday);

    int day2;
    day2 = day_of_year(5-6, 2, 15);
    printf("day=%d\n", day2);

    int pmonth2,pday2;
    month_day(2018, 370, pmonth, pday);
    printf("pmonth=%d, pday=%d\n", pmonth2, pday2);


    return 0;
}
