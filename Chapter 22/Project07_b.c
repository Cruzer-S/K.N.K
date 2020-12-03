#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *orgn, *dest;
	if (argc != 2) {
		fputs("usage: <filename> \n", stderr);
		exit(EXIT_FAILURE);
	}

	orgn = fopen(argv[1], "rb");
	if (orgn == NULL) {
		fprintf(stderr, "failed to open %s file \n", argv[1]);
		exit(EXIT_FAILURE);
	} else {
		char temp[FILENAME_MAX], *ptr;


		strcpy(temp, argv[1]);
		if ( (ptr = strstr(argv[1], ".rle")) != NULL) {
			temp[ptr - argv[1]] = '\0';
		}

		if ( (dest = fopen(temp, "wb")) == NULL) {
			fprintf(stderr, "failed to create %s file \n", temp);
			fclose(orgn);
			exit(EXIT_FAILURE);
		}
	}

	for (int count = fgetc(orgn), ch = fgetc(orgn); 
			 count != EOF && ch != EOF;
			 count = fgetc(orgn), ch = fgetc(orgn))	
	{
		for (int k = 0; k < count; k++)
			fputc(ch, dest);	
	}

	fclose(orgn);
	fclose(dest);

	return 0;
}
