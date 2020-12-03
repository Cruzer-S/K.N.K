#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char buffer[BUFSIZ];
	FILE *fp;

	if (argc < 2) {
		fputs("usage: fcat <filename> \n", stderr);
		exit(EXIT_FAILURE);
	}

	for (argv++; *argv != NULL; argv++) {
		fp = fopen(*argv, "r");
		if (fp == NULL) {
			fprintf(stderr, "%s can't be opened \n", *argv);
			exit(EXIT_FAILURE);
		}

		while ( fgets(buffer, BUFSIZ, fp) != NULL )
			fputs(buffer, stdout);

		fclose(fp);
	}

	return 0;

