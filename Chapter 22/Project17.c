#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

#define PHONE_NUMBER_LENGTH 10

#define NUMBER_STRING "0123456789"

void print_phone_number(const char *);

int main(int argc, char *argv[])
{
	FILE *fp;
	char phone_number[PHONE_NUMBER_LENGTH];

	if (argc != 2)
		ERROR_HANDLING("usage: %s <filename>", argv[0]);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		ERROR_HANDLING("failed to open file %s \n", argv[1]);

	for (int count = 0, ch;;)
	{
		if ((ch = fgetc(fp)) == EOF) break;
		else if (!isdigit(ch))	   continue;

		phone_number[count++] = ch;
		if (count == 10) {
			print_phone_number(phone_number);
			putchar('\n');
			count = 0;
		}
	}

	fclose(fp);

	return 0;
}

void print_phone_number(const char *phone)
{
	for (int i = 0; i < 10; i++)
	{
		switch (i) {
		case 0: fputc('(', stdout);
				break;
		case 3: fputc(')', stdout);
				fputc(' ', stdout);
				break;
		case 6: fputc('-', stdout);
				break;
		}
		fputc(phone[i], stdout);
	}
}
