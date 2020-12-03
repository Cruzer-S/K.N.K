#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const char *month_string[12] = {
		"January", "Feburary", "March", 
		"April", "May", "June", "July", 
		"August", "September", "October", 
		"November", "December"
	};
	int month, day, year;

	if (argc != 2) {
		fprintf(stderr, "usage: <month-day-year> or <month/day/year> \n");

		exit(EXIT_FAILURE);
	}

	if      (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3) ;
	else if (sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3) ;
	else {
		fprintf(stderr, "invalid date form; can't extract date \n");
		exit(EXIT_FAILURE);
	}

	if (month < 1 || month > 12
	||  day   < 1 || day   > 31) 
	{
		fprintf(stderr, "invalid date form; can't extract date \n");
		exit(EXIT_FAILURE);
	}

	printf("%s %d, %d \n", month_string[month - 1], day, year);

	return 0;
}
