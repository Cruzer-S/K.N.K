#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2) {
		fprintf(stderr, "usgae: %s <filename> \n", *argv);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (int ch = fgetc(fp); ch != EOF; ch = fgetc(fp)) {
		if (isalpha(ch))
			fputc(toupper(ch), stdout);
		else
			fputc(ch, stdout);
	}

	fclose(fp);

	return 0;
}
