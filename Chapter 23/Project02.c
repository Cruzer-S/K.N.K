#include <stdio.h>
#include <ctype.h>

#define WHITE_SPACE " \t"

int main(void)
{
	int ch;

	do {
		scanf("%*[" WHITE_SPACE  "]");

		ch = fgetc(stdin);
		if (ch == EOF) break;
		if (ch == '\n') continue;
		ungetc(ch, stdin);

		/*************************/
		for (ch = fgetc(stdin);/**/
		/***/ch != EOF;/**********/
		/***/ch = fgetc(stdin))/**/
		/*************************/
		{ 
			fputc(ch, stdout);
			if (ch == '\n') break;
		}
	} while ( ch != EOF );
	
	return 0;
}
