#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[++line_len] = '\0';
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int ext, ins, rem;

	ext = MAX_LINE_LEN - line_len;
	ins = ext / (num_words - 1) + 1;
	ext %= (num_words - 1);

	rem = ext % 2;
	ext /= 2;
	
#ifdef DEBUG
	printf("extra : %d \n"
		   "insert: %d \n"
		   "line  : %d \n"
		   "remain: %d \n"
		   "word  : %d \n", ext, ins, line_len, rem, num_words);
#endif	

	for (int k = 0, cnt = 0, add = 0; k < line_len; k++) {
		if (line[k] != ' ') {
			putchar(line[k]);
			continue;
		}

		if (cnt < (ext + rem) || (num_words - ext) <= cnt + 1) 
			add = 1;
	
		for (int k = 0; k < ins + add; k++)
			putchar(' ');

		cnt++, add = 0;
	}

	putchar('\n');
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
