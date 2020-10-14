#include <stdio.h>

int main(void)
{
	const char *month_str[] = {
		"January", "Feburary", "March",
		"April", "May", "June",
		"July", "August", "September", 
		"October", "November", "December"
	};
	int day, month, year;

	fputs("Enter a date (mm/dd/yyyy): ", stdout);
	scanf("%d/%d/%d", &month, &day, &year);

	printf("You entered the date %s %d, %d \n",
			month_str[month - 1], day, year);

	return 0;
}
