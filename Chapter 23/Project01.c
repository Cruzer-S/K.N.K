#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	double a, b, c, x;

	fputs("Enter the value of a, b, c \n", stdout);
	fputs("a: ", stdout); scanf("%lf", &a);
	fputs("b: ", stdout); scanf("%lf", &b);
	fputs("c: ", stdout); scanf("%lf", &c);	
	
	x = b * b - (4 * a * c);
	if (x < 0.0) {
		fputs("Equation in the roots is negative \n", stderr);
		exit(EXIT_FAILURE);
	}

	printf("the value x are either %g and %g \n", 
			(-b + sqrt(x)) / (2 * a),
			(-b - sqrt(x)) / (2 * a));

	return 0;
}
