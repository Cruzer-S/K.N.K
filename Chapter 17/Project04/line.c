#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "line.h"

#define MAX_WORD_LEN 20
#define MAX_LINE_LEN 60

struct node {
	char word[MAX_WORD_LEN + 1];
	struct node* next;
} *line, *track;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	while (line != NULL) {
		track = line->next;
		free(line);
		line = track;
	}

	line_len = 0;
	num_words = 0;

	line = track = NULL;
}

void add_word(const char *word)
{
	struct node *new_word;

	new_word = malloc(sizeof(struct node));
	if (new_word == NULL) {
		fputs("Failed to create new line! \n", stderr);
		exit(EXIT_FAILURE);
	}

	new_word->next = NULL;

	strcpy(new_word->word, word);
	line_len += strlen(word);
	num_words++;

	if (line == NULL)
		line = new_word;
	else {
		track->next = new_word;
		line_len++;
	}

	track = new_word;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int ext, ins, rem;
	int cnt, add;

	ext = MAX_LINE_LEN - line_len;
	ins = ext / (num_words - 1) + 1;
	ext %= (num_words - 1);

	rem = ext % 2;
	ext /= 2;

	cnt = add = 0;
	for (struct node *p = line; p != NULL; p = p->next) 
	{
		fputs(p->word, stdout);

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
	for (struct node *p = line; line != NULL; line = line->next) 
	{	
		fputs(p->word, stdout);
		putchar(' ');
	} putchar('\n');
}
