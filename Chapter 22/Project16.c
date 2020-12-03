#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

int main(int argc, char *argv[])
{
	char block[BLOCK_SIZE];
	FILE *orgn, *dest;

	if (argc != 3)
		ERROR_HANDLING("usage: %s <origin> <destination>", argv[0]);

	orgn = fopen(argv[1], "rb");
	if (orgn == NULL)
		ERROR_HANDLING("failed to open file %s", argv[1]);

	dest = fopen(argv[2], "wb");
	if (dest == NULL) {
		fclose(orgn);
		ERROR_HANDLING("failed to create file %s", argv[2]);
	}

	for (int count;
		(count = fread(block, sizeof(char), 
				       BLOCK_SIZE / sizeof(char), orgn)) != 0
		/* empty increment expression */ ;)
	{
		printf("Count: %d \n", count);
		if (fwrite(block, sizeof(char), 
				   count / sizeof(char), dest) == 0) {
			fclose(orgn); fclose(dest);
			remove(argv[2]);
			ERROR_HANDLING("failed to write file %s", argv[1]);
		}
	}

	fclose(orgn); fclose(dest);

	return 0;
}
