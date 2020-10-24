#include <stdio.h>

#define FORMAT ("%d/%d/%d")

struct date {
	int year;
	int month;
	int day;
};

struct date get_date(const char *format)
{
	struct date ret;

	scanf(format, &ret.month, &ret.day, &ret.year);

	return  ret;
}

int compare_date(struct date d1, struct date d2)
{
	int date1, date2;

	date1 = d1.year * 400 + d1.month * 40 + d1.day;
	date2 = d2.year * 400 + d2.month * 40 + d2.day;

	return date1 - date2;
}

int main(void)
{
	int result;

	struct date first, second;

	fputs("Enter first date (mm/dd/yy): ", stdout);
	first = get_date(FORMAT);

	fputs("Enter second date (mm/dd/yy): ", stdout);
	second = get_date(FORMAT);

	result = compare_date(first, second);

	if (result == 0) {
		fputs("Same date \n", stdout);
	} else {
		if (result > 0) {
			struct date temp = first;
			first = second;
			second = temp;
		}

		printf("%d/%d/%02d is earlier than %d/%d/%02d \n",
		    first.month , first.day , first.year,
			second.month, second.day, second.year);
	}

	return 0;
}
