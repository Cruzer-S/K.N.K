#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 20

int main(void)
{
	char word[MAX_WORD + 1], small[MAX_WORD + 1], large[MAX_WORD + 1];

	*small = *large = '\0';

	do {
		fputs("Enter word: ", stdout);
		scanf("%s", word);

		if (*small == '\0' && *large == '\0') {
			strcpy(large, strcpy(small, word));
			continue;
		}

		if (strcmp(word, small) < 0)
			strcpy(small, word);	
		if (strcmp(word, large) > 0) 
			strcpy(large, word);
	} while (strlen(word) != 4);

	printf("Smallest word: %s \n", small);
	printf("Largest word: %s \n", large);

	return 0;
}
