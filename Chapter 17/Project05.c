#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 20

struct node {
	char word[MAX_WORD_LEN + 1];
	struct node *next;
} *list = NULL;

int main(void)
{
	int word_len;
	struct node *new_node, *cur, *prev;
	
	while (true)
	{
		new_node = malloc(sizeof(struct node));
		if (new_node == NULL) {
			fputs("failed to create new node! \n", stderr);
			exit(EXIT_FAILURE);
		}

		fputs("Enter word: ", stdout);
		fgets(new_node->word, MAX_WORD_LEN, stdin);	
		new_node->word[MAX_WORD_LEN] = '\0';

		if (new_node->word[0] == '\n')	break;
		else new_node->word[strlen(new_node->word) - 1] = '\0';

		if (list == NULL) {
			list = new_node;
			continue;
		}

		for (cur = list, prev = NULL;
			 cur != NULL && strcmp(cur->word, new_node->word) < 0;
			 prev = cur, cur = cur->next);

		if (prev == NULL) {
			new_node->next = cur;
			list = new_node;
		} else {
			prev->next = new_node;
			new_node->next = cur;
		}
	}

	fputs("In sorted order: ", stdout);
	for (struct node *cur = list, *prev = NULL;
		 cur != NULL; prev = cur, cur = cur->next) 
	{
		fputs(cur->word, stdout);
		putchar(' ');
	} putchar('\n');

	while (true) {
		if (list == NULL) break;

		new_node = list->next;
		free(list);
		list = new_node;
	}

	return 0;
}
