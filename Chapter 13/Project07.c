#include <stdio.h>

void number_string(int number)
{
	const char *ty[] = {
		"twenty", "thirty", "forty", "fifty",
			"sixty", "seventy", "eighty", "ninety"
	},         *teen[] = {
		"ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen",
			"seventeen", "eighteen", "nineteen"
	},		   *digits[] = {
		"one", "two", "three", 
		"four", "five", "six", 
		"seven", "eight", "nine"
	};
	
	fputs( (number / 10 < 2) ? "" : ty[number / 10 - 2], stdout);	
	if (number / 10 == 1) {
		fputs(teen[number % 10], stdout);
	} else if (number % 10 != 0) {
		if (number > 10) putchar('-');
			fputs(digits[number % 10 - 1], stdout);
	} else if (number == 0) {
		fputs("zero", stdout);
	} putchar('\n');
}

int main(void)
{
	int number;
	
	fputs("Enter a two-digit number: ", stdout);
	scanf("%d", &number);
	
	//for (int i = 0; i < number; i++)
	//	number_string(i);
	number_string(number);
	
	return 0;
}
