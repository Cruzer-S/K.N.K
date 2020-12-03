#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *orig_fp, *dest_fp;
	int orig_char, new_char;

	if (argc != 3) {
		fputs("usage: <origin> <destination> \n", stderr);
		exit(EXIT_FAILURE);
	}

	orig_fp = fopen(argv[1], "rb");
	if (orig_fp == NULL) {
		fprintf(stderr, "failed to open %s file \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	dest_fp = fopen(argv[2], "wb");
	if (dest_fp == NULL) {
		fprintf(stderr, "failed to open %s file \n", argv[2]);
		exit(EXIT_FAILURE);
	}

	for (int ch = fgetc(orig_fp); ch != EOF; ch = fgetc(orig_fp))
		fputc(ch ^ KEY, dest_fp);

	fclose(orig_fp); fclose(dest_fp);

	return 0;
}
