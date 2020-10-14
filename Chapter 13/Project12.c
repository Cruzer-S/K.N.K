#include <stdio.h>
#include <ctype.h>

#define MAX_WORD 30
#define WORD_LEN 20

int main(void)
{
	int count_word = 0;
	char punct;
	char sentence[MAX_WORD][WORD_LEN + 1];

	fputs("Enter a sentence: ", stdout);
	for (int i = 0; i < MAX_WORD; i++) {
		for (char ch, *p = sentence[i]; ; p++) {
			if ( !isspace(ch = getchar()) ) {
				*p = ch;
			} else { 
				if ( ch  == '\n' ) {
					*p--;
					punct = *p;
					*p = '\0';
					count_word = i + 1;
					i = MAX_WORD;
				}
				*p = '\0';
				break;
			}
		}
	}

	for (int k = count_word - 1; k > 0; k--, putchar(' '))
		fputs(sentence[k], stdout);

	printf("%s%c\n", *sentence, punct);

	return 0;
}
