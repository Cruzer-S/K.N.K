#include <stdio.h>
#include <ctype.h>

int main(void)
{
	for (int ch = fgetc(stdin), swc = 0; 
			 ch != EOF        ;
			 ch = fgetc(stdin)) 
	{
		if (isalpha(ch) && swc == 0) {
			fputc(toupper(ch), stdout);
			swc = 1;
			continue;
		} else if (isspace(ch)) swc = 0;

		fputc(ch, stdout);
	}

	return 0;
}
