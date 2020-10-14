#include <stdio.h>

int compute_polynomial(int x);


int main(void)
{
	int x;

	scanf("%d", &x);

	printf("Input: ");

	printf("Result: %d \n", compute_polynomial(x));

	return 0;
}

int compute_polynomial(int x)
{
	return (((
		((3 * x + 2) 
			* x - 5) 
			* x - 1)
			* x + 7)
			* x - 6);
}
