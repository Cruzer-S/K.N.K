#include <stdio.h>
#include <ctype.h>

#define MAX_SENTENCE 1024

double compute_average_word_length(const char *sentence);

int main(void)
{
	char sentence[MAX_SENTENCE + 1];

	fputs("Enter the sentence: ", stdout);
	fgets(sentence, MAX_SENTENCE, stdin);

	printf("Average of word length: %.1f \n", compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
	int count_word, count_alphabet;
	double avg = 0.0;

	// skip first white-space
	while ( isspace(*sentence) ) sentence++;

	count_alphabet = count_word = 0; 
	while (*sentence != '\0') {
		while ( isalpha(*sentence++) ) count_alphabet++;
		count_word++;
		while ( isspace(*sentence) ) sentence++;
	}

	return (double)count_alphabet / count_word;
}
