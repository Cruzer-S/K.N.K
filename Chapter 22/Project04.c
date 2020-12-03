#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*operation_function)(FILE *);

typedef enum {
	CHAR, WORD, LINE
} operation_code;

int count_char(FILE *);
int count_word(FILE *);
int count_line(FILE *);

int main(int argc, char *argv[])
{
	const char *opstring[] = {
		"char", "word", "line"
	};

	const operation_function opfunc[] = {
		count_char, count_word, count_line
	};

	operation_code opcode;
	FILE *fp;

	if (argc != 3) {
		fputs("usage: <operation> <filename> \n", stderr);
		exit(EXIT_FAILURE);
	}

	do {
		const int count = sizeof(opstring) 
						/ sizeof(opstring[0]);

		for (opcode = 0; opcode < count; opcode++)
			if ( !strcmp(opstring[opcode], argv[1]) )
				break;

		if ( opcode == count ) {
			fprintf(stderr, "invalid opstring %s \n", argv[1]);

			fputs("opstring list... \n", stderr);
			for (int i = 0; i < count; i++)
				fprintf(stderr, (i != (count - 1)) ? 
						"%s, " : "%s\n", opstring[i] );

			exit(EXIT_FAILURE);
		} 
	} while (false);

	fp = fopen(argv[2], "r");
	if (fp == NULL) {
		fprintf(stderr, "failed to open file %s \n", argv[2]);
		exit(EXIT_FAILURE);
	}

	printf("result: %d \n", (opfunc[opcode])(fp));

	fclose(fp);

	return 0;
}

int count_char(FILE *fp)
{
	int count = 0;

	printf("count character \n");

	for (int ch = fgetc(fp); ch != EOF; ch = fgetc(fp))
		count++;

	return count;
}

int count_word(FILE *fp)
{
	int count = 0;

	for (int check = 0; 
		     fscanf(fp, "%*s%n", &check) != EOF; 
			 count += (bool)check) ;

	return count;
}

int count_line(FILE *fp)
{
	int count = 0;

	for (int check = 0;
			 fscanf(fp, "%*[^\n]%*c%n", &check) != EOF;
			 count++, check = 0) {
		if (check == 0) fgetc(fp);
	}

	return count;
}
