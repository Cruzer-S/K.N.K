#include <stdio.h>
#include "word.h"

static int read_char(FILE *fp)
{
	int ch = fgetc(fp);

	if (ch == '\n' || ch == '\t')
		return ' ';

	return ch;
}

int read_word(FILE *fp, char *word, int len)
{
	int ch, pos = 0;

	while ((ch = read_char(fp)) == ' ') ;

	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char(fp);
	}

	if (pos == len)
		word[pos++] = '*';

	word[pos] = '\0';

	return pos;
} 
