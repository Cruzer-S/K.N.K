#include <stdio.h>
#include <math.h>

double calc_interest(double t, double r, double p)
{
	return p * exp( (r * 0.01) * t );
}

int main(void)
{
	double year, interest, origin;

	fputs("Enter origin amount deposited: ", stdout);
	scanf("%lf", &origin);

	fputs("Enter interest rate: ", stdout);
	scanf("%lf", &interest);

	fputs("Enter number of year: ", stdout);
	scanf("%lf", &year);

	printf("Result: %.2f \n", calc_interest(year, interest, origin));

	return 0;
}
