#include <stdio.h>

long long int power(int x, int n);

int main(void)
{
	int x, n;

	printf("Input: ");
	scanf("%d %d", &x, &n);

	printf("result of %d power of %d: %lld \n", x, n, power(x, n));

	return 0;
}

long long int power(int x, int n)
{
	if (n <= 1)
		return x;
	else {
		if (n / 2 == 0)
			return power(x, n / 2) * power(x, n / 2);
		else
			return x * power(x, n - 1);
	}
}
