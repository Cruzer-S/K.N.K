#include <stdio.h>
#include "word.h"

int read_char(void)
{
	int ch = getchar();

	if (ch == '\n' || ch == '\t')
		return ' ';

	return ch;
}

int read_word(char *word, int len)
{
	int ch, pos = 0;

	while ((ch = read_char()) == ' ') ;

	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char();
	}

	if (pos == len)
		word[pos++] = '*';

	word[pos] = '\0';

	return pos;
} 
