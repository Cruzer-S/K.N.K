#include <stdio.h>
#include <ctype.h>

#define MAX_SENTENCE 1024

int compute_vowel_count(const char *sentence);

int main(void)
{
	char sentence[MAX_SENTENCE + 1];

	fputs("Enter a sentence: ", stdout);
	fgets(sentence, MAX_SENTENCE, stdin);

	printf("Your sentence contains %d vowels \n", compute_vowel_count(sentence));
	
	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int counts = 0;

	while ( *sentence != '\0') {
		switch ( toupper(*sentence++) ) {
		case 'A': case 'E': case 'I':
		case 'O': case 'U': counts++;
		}
	}

	return counts;
}
