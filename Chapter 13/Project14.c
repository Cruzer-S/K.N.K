#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WORD_LEN 20

int ltoi(char alpha)
{
	const char *origin = "abcdefghijklnmopqrstuvwxyz"
						 "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
	return (strchr(origin, alpha) - origin);
}

bool are_anagrams(const char *word1, const char *word2)
{
	int count[26] = { 0, };

	for (const char *p = word1, *q = word2; *p && *q; p++, q++)
		count[ltoi(tolower(*p))]++, --count[ltoi(tolower(*q))];

	for (int i = 0; i < 26; i++)
		if (count[i]) return false;

	return true;
}

int main(void)
{
	char word1[WORD_LEN], word2[WORD_LEN];

	fputs("Enter first word: ", stdout);
	scanf("%s", word1);

	fputs("Enter second word: ", stdout);
	scanf("%s", word2);

	printf("Thw words are %s anagrams. \n", are_anagrams(word1, word2) ? "\b" : "not");

	return 0;
}
