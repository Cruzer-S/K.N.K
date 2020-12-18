#include <stdio.h>
#include <time.h>

int main(void)
{
	char time_str[22];
	struct tm t;
	int n;

	printf("Month: "); scanf("%d", &t.tm_mon);
	printf("Day  : "); scanf("%d", &t.tm_mday);
	printf("Year : "); scanf("%d", &t.tm_year);
	t.tm_sec = 0, t.tm_min = 0, t.tm_hour = 0, t.tm_isdst = -1;
	t.tm_mon--, t.tm_year -= 1900;

	printf("After the day: "); scanf("%d", &n);
	t.tm_mday += n;

	mktime(&t);

	strftime(time_str, sizeof(time_str), "Result: %F", &t);
	puts(time_str);

	return 0;
}
