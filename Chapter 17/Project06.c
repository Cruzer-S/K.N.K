#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define INIT_SIZE 5

int compare_string(const void *p, const void *q)
{
	return strcmp(*(char **)p, *(char **)q);
}

int main(void)
{
	char **list;
	int list_size, lpos;

	list_size = INIT_SIZE;
	list = malloc(sizeof(char *) * list_size);
	if (list == NULL) {
		fputs("failed to create list \n", stderr);
		exit(EXIT_FAILURE);
	} else {
		for (int i = 0; i < list_size; i++) {
			list[i] = malloc(MAX_WORD_LEN + 1);
			if (list[i] == NULL) {
				fputs("failed to create word memory \n", stderr);
				exit(EXIT_FAILURE);
			}
		}
	}

	for (lpos = 0;;) {
		fputs("Enter word: ", stdout);
		fgets(list[lpos], MAX_WORD_LEN, stdin);
		list[lpos][MAX_WORD_LEN] = '\0';

		if (list[lpos][0] == '\n') break;
		else list[lpos][strlen(list[lpos]) - 1] = '\0';

		if (++lpos >= list_size) {
			list_size *= 2;
			list = realloc(list, sizeof(char *) * list_size);
			if (list == NULL) {
				fputs("failed to extend list size \n", stderr);
				exit(EXIT_FAILURE);
			}

			for (int i = lpos; i < list_size; i++) {
				list[i] = malloc(sizeof(MAX_WORD_LEN + 1));
				if (list[i] == NULL) {
					fputs("failed to create word memory \n", stderr);
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	qsort(list, lpos, sizeof(char *), compare_string);

	fputs("In sorted order: ", stdout);
	for (int i = 0; i < lpos; i++)
		printf("%s ", list[i]);	

	for (int i = 0; i < list_size; i++)
		free(list[i]);
	free(list);

	return 0;
}
