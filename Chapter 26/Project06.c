#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
	time_t current = time(NULL);
	struct tm *ptr = localtime(&current);
	char date_str[100];

	// Sunday, June 3, 2007   05:48p
	strftime(date_str, sizeof(date_str),
			 "%A, %B %d, %Y\t%I:%M", ptr);
	strcat(date_str, (ptr->tm_hour > 11) ? "p" : "a");
	puts(date_str);

	// Sun, 3 Jun 07  17:48
	strftime(date_str, sizeof(date_str),
			"%a, %d %b %C\t%R", ptr);
	puts(date_str);

	// 06/03/07  5:47:34 PM
	strftime(date_str, sizeof(date_str),
		     "%x\t%X %p", ptr);
	puts(date_str);

	return 0;
}
