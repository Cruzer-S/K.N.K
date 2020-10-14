#include <stdio.h>

void reduce(int numerator, int denominator,
			int *reduced_numerator, int *reduced_denominator);

int main(void)
{
	int num1, num2;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &num2);

	reduce(num1, num2, &num1, &num2);

	printf("In lowest terms: %d/%d \n", num1, num2);

	return 0;
}

void reduce(int numerator, int denominator,
			int *reduced_numerator, int *reduced_denominator)
{
	int remainder;

	*reduced_numerator = numerator;
	*reduced_denominator = denominator;

	for (;;) {
		remainder = numerator % denominator;
		numerator = denominator;
		denominator = remainder;

		if (denominator <= 1)
			break;
	} 

	if (denominator == 1) return ;

	*reduced_numerator /= numerator;
	*reduced_denominator /= numerator;
}
