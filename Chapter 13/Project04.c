#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int k = argc - 1; k > 0; k--)
		printf("%s ", argv[k]);
	putchar('\n');

	return 0;
}
