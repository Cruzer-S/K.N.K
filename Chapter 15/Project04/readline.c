#include <stdio.h>
#include "readline.h"

int read_line(char *str, int n)
{
	const char *origin = str;
	int ch;

	while ( (*str = getchar()) != '\n' && (str++ - origin) < n ) ;
	*str = '\0';

	return str - origin;
}
