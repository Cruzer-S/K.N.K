#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2) {
		fputs("usage: canopen <filename> \n", stderr);
		exit(EXIT_FAILURE);
	}

	for (argv++; *argv != NULL; argv++) {
		fp = fopen(*argv, "r");
		if (fp == NULL) {
			printf("%s can't be opened \n", *argv);
			continue;
		}

		printf("%s can be opened \n", *argv);
		fclose(fp);
	}

	return 0;
}
