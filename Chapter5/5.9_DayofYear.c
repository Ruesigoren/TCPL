#include <stdio.h>

static char daytab[2][13] = {
	{ 0,31,28,31,30,31,30,31,31,30,31,30,31 },
	{ 0,31,29,31,30,31,30,31,31,30,31,30,31 },
};

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

main()
{
	int day;
	int pm, pd;

	day = day_of_year(2019, 4, 29);
	printf("%d\n", day);
	month_day(2019, day, &pm, &pd);
	printf("month:%d	day:%d\n", pm, pd);
}

int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	if (month > 12 || month < 1) {
		printf("Month Illegal\n");
		return -1;
	}
	if (day < 1 || day > daytab[leap][month]) {
		printf("Month day of month\n");
		return -1;
	}
	p = daytab[leap];
	while (--month) {
		day += *++p;
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	if (yearday < 1 || yearday > 365 + leap) {
		printf("Error days of year\n");
		*pmonth = -1;
		*pday = -1;
	}
	p = daytab[leap];
	while (yearday > *++p) {
		yearday -= *p;
	}
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}
