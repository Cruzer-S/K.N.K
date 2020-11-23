#include <stdio.h>

union IEEE754 {
	float origin;
	struct {
		unsigned int fraction:23;
		unsigned int exponent:8;
		unsigned int sign:1;
	};
};

int main(void)
{
	union IEEE754 number;

	number.fraction = 0;
	number.exponent = 128;
	number.sign = 1;

	printf("Result: %.1f \n", number.origin);

	return 0;
}
