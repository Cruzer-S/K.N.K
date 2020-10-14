#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sum = 0;

	while(*++argv != NULL)
		sum += atoi(*argv);

	printf("Total: %d \n", sum);

	return 0;
}
