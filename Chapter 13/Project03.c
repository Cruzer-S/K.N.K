#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD (1024)

#define NUM_SUITS 4
#define NUM_RANKS 13

char *capitalize(const char* word) 
{
	static char cap_word[MAX_WORD];
	strcpy(cap_word, word);
	*cap_word = toupper(*cap_word);
	return cap_word;
}

int main(void)
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = { false };
	int num_cards, rank, suit;
	const char *rank_code[] = {
		"two", "three", "four", 
		"five", "six", "seven", 
		"eight", "nine", "ten", 
		"jack", "queen", "king", "ace"
	},		   *suit_code[] = {
		"clubs", "diamonds", "hearts", "spades"
	};

	srand((unsigned)time(NULL));

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);

	fputs("Your hand: \n", stdout);
	while (num_cards > 0) {
		suit = rand() % NUM_SUITS;
		rank = rand() % NUM_RANKS;
		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%s of %s\n", capitalize(rank_code[rank]), suit_code[suit]);
		}
	}
	putchar('\n');

	return 0;
}
