#include <stdio.h>
#include <stdlib.h>

#define ERROR_HANDLING(MSG, ...) {			\
	fprintf(stderr, MSG "\n", __VA_ARGS__);	\
	exit(EXIT_FAILURE);						\
}

void show_item(FILE * );

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
		ERROR_HANDLING("usage: %s <filename>", argv[0]);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		ERROR_HANDLING("Failed to open file %s", argv[1]);

	show_item(fp);

	fclose(fp);
	return 0;
}

void show_item(FILE *fp)
{
	int item; float price;
	int month, day, year;

	printf("%-15s"		"%-15s"		"%s"	"\n", 
			"Item",		"Unit",		"Purchase");
	printf("%-15s"		"%-15s"		"%s"	"\n",
			"",			"Price",	"Date");

	while ( fscanf(fp, "%d,%f,%d/%d/%d", 
			&item, &price, &month, &day, &year) == 5 ) 
	{
		printf("%-15d"		"$%7.2f"	"%7s",
				item,		price,		""   ); 	

		printf("%d/%d/%d \n", month,day,year);
	} 
}
