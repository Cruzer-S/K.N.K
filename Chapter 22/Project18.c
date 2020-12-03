#include <stdio.h>
#include <stdlib.h>

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

#define MAX_NUMBER 10000

int comp(const void *, const void *);

int main(int argc, char *argv[])
{
	int number[MAX_NUMBER];
	FILE *fp;

	if (argc < 2) 
		ERROR_HANDLING("usage: %s <file1> <file2> ... ", argv[0]);

	for (int k; *++argv != NULL; )
	{
		fp = fopen(*argv, "r");
		if (fp == NULL) {
			ERROR_HANDLING("failed to open file %s", *argv) ;
		} else {
			printf("file: %s \n", *argv);
		}

		for (k = 0; k < MAX_NUMBER; k++)
		{
			int ret = fscanf(fp, "%d", &number[k]);
			if (ret != 1 || ret == EOF) break;
		}

		if (k == 0) {
			printf("There's no number \n\n");
			continue;
		}

		qsort(number, k, sizeof(int), comp);


		printf("Smallest: %d \n", number[0]);
		printf("Largest : %d \n", number[k - 1]);
		printf("Median  : %d \n\n", (k % 2 == 1) ? number[k / 2] :
			   (number[k / 2 - 1] + number[k / 2]) / 2);

		fclose(fp);
	}

	return 0;
}

int comp(const void *n1, const void *n2)
{
	if ( *(int *)n1 < *(int *)n2 )
		return -1;
	else
		return 1;
}
