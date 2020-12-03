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
		char temp[FILENAME_MAX];

		dest = fopen( strcat(strcpy(temp, argv[1]), ".rle"), "wb" );
		if (dest == NULL) {
			fprintf(stderr, "failed to create %s file \n", temp);
			fclose(orgn);
			exit(EXIT_FAILURE);
		}
	}

	for (int ch = fgetc(orgn), count = 1, check; 
			 ch != EOF; 
			 ch = fgetc(orgn), count = 1) 
	{
		for (check = fgetc(orgn); 
			 check == ch; 
			 check = fgetc(orgn), count++) ;
		ungetc(check, orgn);

		fputc(count, dest);
		fputc(ch, dest);
	}

	fclose(orgn);
	fclose(dest);

	return 0;
}
