#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int count = 0;

	for (int ch = fgetc(stdin);
			 ch != EOF;
			 ch = fgetc(stdin))
	{
		if (strchr(".,?!", ch)) {
			int check = fgetc(stdin);
			if (isspace(check))
				count++;
			else
				ungetc(check, stdin);
		}
	}

	printf("sentence(s): %d \n", count);

	return 0;
}
