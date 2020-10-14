#include <stdio.h>
#include <ctype.h>

#define MAX_NAME 1024

void reverse_name(char *name);

int main(void)
{
	char name[MAX_NAME + 1];

	fputs("Enter a first and last name: ", stdout);
	fgets(name, MAX_NAME, stdin);

	reverse_name(name);

	fputs(name, stdout);
	putchar('\n');

	return 0;
}

void reverse_name(char *name)
{
	char *origin = name;
	char last_name[MAX_NAME / 2];
	char first_name;

	//skip white-space
	while ( isspace(*name) ) name++;

	//get first-name
	first_name = toupper(*name);

	//skip first-name, and then white-space
	while ( isalpha(*name) ) name++;
	while ( isspace(*name) ) name++;

	//get last-name
	for (char *p = last_name; isalpha(*name); *p++ = *name++, *p = '\0') ;

	//concate last and first name
	sprintf(origin, "%s, %c.", last_name, first_name);
}
