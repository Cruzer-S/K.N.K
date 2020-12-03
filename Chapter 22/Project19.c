#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR_HANDLING(MSG, ...) do {			\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
} while (false)

#define SIZEOF(X) (sizeof(X) / sizeof((X)[0])

#define UNIX 0
#define Windows 1

int main(int argc, char *argv[])
{
	int type;
	FILE *orgn, *dest;

	if (argc != 4)
		ERROR_HANDLING("usage: <type> <origin> <destination>");

	if (strcmp(argv[1], "UNIX") && strcmp(argv[1], "Windows")) {
		ERROR_HANDLING("invalid type name %s", argv[1]);
		exit(EXIT_FAILURE);
	} else type = (int)(bool)strcmp(argv[1], "UNIX");

	orgn = fopen(argv[2], "rb");
	if (orgn == NULL)
		ERROR_HANDLING("failed to open file %s", argv[2]);

	dest = fopen(argv[3], "wb");
	if (dest == NULL)
		ERROR_HANDLING("failed to create file %s", argv[3]);

	for (int ch = fgetc(orgn); ch != EOF; ch = fgetc(orgn)) 
	{
		if (type == UNIX && ch == '\x0d') {
			int temp = fgetc(orgn);
			if (temp == '\x0a') {
				fputc('\x0a', dest);
				continue;
			}

			fputc(ch, dest); fputc(temp, dest);

			printf("Convert 2\n");
		} else if (type == Windows && ch == '\x0a') {
			fputc('\x0d', dest);
			fputc('\x0a', dest);

			printf("Convert 1\n");
		} else fputc(ch, dest);
	}

	fclose(orgn); fclose(dest);

	return 0;
}
