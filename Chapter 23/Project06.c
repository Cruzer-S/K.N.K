#include <stdio.h>
#include <ctype.h>

int main(void)
{
	for (int ch = fgetc(stdin);
			 ch != EOF;
			 ch = fgetc(stdin))
	{
		if (iscntrl(ch) && ch != '\n')
			fputc('?', stdout);
		else
			fputc(ch, stdout);
	}

	return 0;
}
