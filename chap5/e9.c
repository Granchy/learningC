#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char isLeapYear(int year) {
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}

int day_of_year(int year, int month, int day) {
    char *ptr;
    
    ptr = isLeapYear(year) ? daytab[1] + 1: daytab[0] + 1;
    for(; month > 1; month--) {
        day += *ptr;
        ptr++;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i = 1;
    char *ptr;

    ptr = isLeapYear(year) ? daytab[1] + 1: daytab[0] + 1;
    char *start;
    start = ptr;
    while(yearday > *ptr) {
         yearday -= *ptr++;
         
    }
       
    
    *pmonth = 1 + (ptr - start);
    *pday = yearday;
}

int main(int argc, char const *argv[])
{
    int pmonth;
    int pday;

    
    printf("%d", day_of_year(2024,2, 29));

    month_day(2024, 60, &pmonth, &pday);
    printf("%d, %d", pmonth, pday);

    return 0;
}

/* make sure you allocate memory for the pointer to point to before accessing its value
writing
int *p;
*p = 1; is not valid as *p does not point to a valid memory address to begin with.

On the other hand we can do

int x;
and then pass &x to a function to manipulate the value at the memory address of x.
*/ 
