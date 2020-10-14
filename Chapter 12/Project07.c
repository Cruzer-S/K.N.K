#include <stdio.h>

#define N 10

void max_min(int *a, int n, int *max, int *min);

int main(void)
{
	int b[N], big, small;
	
	printf("Enter %d numbers: ", N);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);

	max_min(b, N, &big, &small);

	printf("Largest: %d\n"
		   "Smallest: %d\n", big, small);

	return 0;
}

void max_min(int *a, int n, int *max, int *min)
{
	int *smax, *smin;

	smax = smin = a;
	for (int *p = a; p < a + n; p++) {
		if (*p > *smax) smax = p;
		if (*p < *smin) smin = p;
	}

	*max = *smax;
	*min = *smin;
}
