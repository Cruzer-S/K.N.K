#include <stdio.h>
#include <time.h>

#define DSEC (60 * 60 * 24)

struct tm get_date(void)
{
	struct tm t;

	printf("Month: "); scanf("%d", &t.tm_mon);
	printf("Day  : "); scanf("%d", &t.tm_mday);
	printf("Year : "); scanf("%d", &t.tm_year);
	t.tm_sec = 0, t.tm_min = 0, t.tm_hour = 0, t.tm_isdst = -1;
	t.tm_mon--, t.tm_year -= 1900;

	return t;
}

int main(void)
{
	struct tm t1, t2;
	char time_str[22];

	t1 = get_date();
	t2 = get_date();

	printf("Day difference: %d \n", 
	(int)difftime(mktime(&t1), mktime(&t2)) / DSEC);

	return 0;
}
