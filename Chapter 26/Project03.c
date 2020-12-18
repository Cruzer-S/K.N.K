#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int comp(const void *f, const void *l)
{
	return *(int *)f > *(int *)l;
}

int main(void)
{
	clock_t start, end;
	int size;
	int *arr;

	printf("size: ");
	scanf("%d", &size);

	arr = malloc(size * sizeof(int));
	if (arr == NULL) abort();

	for (int i = 0; i < size; i++) 
		arr[i] = size - i;

	start = clock();
	qsort(arr, size, sizeof(int), comp);
	end   = clock();

	free(arr);

	printf("result: %g \n", (end - start) / (double)CLOCKS_PER_SEC);

	return 0;
}
