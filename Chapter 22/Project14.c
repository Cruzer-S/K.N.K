#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

#define SHFT(C) (islower(C) ? 'a' : 'A')

int main(void)
{
	FILE *orgn, *dest;
	char filename[FILENAME_MAX];
	int shift;

	printf("Enter name of file to encrypted: ");
	scanf("%s", filename);

	orgn = fopen(filename, "r");
	if (orgn == NULL)
		ERROR_HANDLING("failed to open file %s", filename);

	dest = fopen(strcat(filename, ".enc"), "w");
	if (dest == NULL) {
		fclose(orgn);
		ERROR_HANDLING("failed to create file %s", filename);
	}

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	for (int ch = fgetc(orgn); ch != EOF; ch = fgetc(orgn)) 
	{	
		if (fputc(!isalpha(ch) ? ch :
			((ch - SHFT(ch)) + shift) % 26 + SHFT(ch), dest) == EOF)
		{
			fclose(orgn);
			fclose(dest);
			remove(filename);

			ERROR_HANDLING("failed to write file");
		}
	}

	fclose(orgn);
	fclose(dest);

	return 0;
}
