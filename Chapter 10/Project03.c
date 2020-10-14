#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS (13)
#define NUM_SHAPE (4)
#define NUM_CARDS (5)

#define RANKS_IDX (0)
#define SHAPE_IDX (1)

bool straight, flush, four, three;
int pairs;

bool read_cards(int in_hand[NUM_CARDS][2]);
void analyze_hand(int in_hand[NUM_CARDS][2]);
void print_result(void);

int main(void)
{
	int in_hand[NUM_CARDS][2];

	for (;;) {
		if ( !read_cards(in_hand) )
			break;

		analyze_hand(in_hand);
		print_result();
	}

	return 0;
}

bool read_cards(int in_hand[NUM_CARDS][2])
{
	int ch;
	int rank, shape;

	for (int read_card = 0; read_card < NUM_CARDS; read_card++) {
		printf("Enter a card: ");

		ch = getchar();
		switch (ch) {
		case '2': rank = 0; break;
		case '3': rank = 1;	break;
		case '4': rank = 2; break;
		case '5': rank = 3;	break;
		case '6': rank = 4;	break;
		case '7': rank = 5;	break;
		case '8': rank = 6;	break;
		case '9': rank = 7;	break;
		case 't': case 'T': rank = 8; break;
		case 'j': case 'J': rank = 9; break;
		case 'q': case 'Q': rank = 10; break;
		case 'k': case 'K': rank = 11; break;
		case 'a': case 'A': rank = 12; break;

		case '0': return false;
		default: 
			printf("Bad card; ignored. \n"), read_card--;
			goto END_OF_LOOP;
		}

		ch = getchar();
		switch (ch) {
		case 's': case 'S': 
			shape = 0; break;
		case 'c': case 'C': 
			shape = 1; break;
		case 'h': case 'H': 
			shape = 2; break;
		case 'd': case 'D': 
			shape = 3; break;
		default:
			printf("Bad card; ignored. \n"), read_card--;
			goto END_OF_LOOP;
		}

		for (int k = 0; k < read_card; k++) {
			if (in_hand[k][RANKS_IDX] == rank
			&&  in_hand[k][SHAPE_IDX] == shape) {
				rank = shape = -1;
				break;
			}
		}

		if (shape == -1 || rank == -1) {
			printf("Duplicate card; ignored. \n"), read_card--;
			goto END_OF_LOOP;
		}

		in_hand[read_card][RANKS_IDX] = rank;
		in_hand[read_card][SHAPE_IDX] = shape;

END_OF_LOOP: while ( getchar() != '\n' ) ;
	}

	return true;
}

void analyze_hand(int in_hand[NUM_CARDS][2])
{
	/* check whether is straight or not */ {
		int check;

		check = in_hand[0][RANKS_IDX];
		for (int k = 1; k < NUM_CARDS; k++)
			if (in_hand[k][RANKS_IDX] < check)
				check = in_hand[k][RANKS_IDX];

		for (int i = 1; i < NUM_CARDS; i++) {
			straight = false;
			for (int k = 0; k < NUM_CARDS; k++)
				if ( (check + 1) == in_hand[k][RANKS_IDX] ) {
					check = in_hand[k][RANKS_IDX];
					straight = true;
					break;
				}

			if ( !straight )
				break;
		}		
	}

	/* check whethr is flush or not */
	flush = true;
	for (int k = 1; k < NUM_CARDS; k++) {
		if ( (in_hand[k - 1][SHAPE_IDX]) != (in_hand[k][SHAPE_IDX]) ) {
			flush = false;
			break;
		}
	}

	/* check pair, three of a kind, four of a kind  */ {
		int check[NUM_RANKS];

		for (int k = 0; k < NUM_RANKS; k++)
			check[k] = 0;

		for (int k = 0; k < NUM_CARDS; k++)
			check[ in_hand[k][RANKS_IDX] ]++;

		four = three = pairs = false;
		for (int k = 0; k < NUM_RANKS; k++) {
			if (check[k] == 4) four = true;
			if (check[k] == 3) three = true;
			if (check[k] == 2) pairs++;
		}
	}
}

void print_result(void)
{
	if (straight && flush) printf("Straight flush");
	else if (four)		   printf("Four of a kind");
	else if (three &&
			 pairs == 1)   printf("Full house");
	else if (flush)        printf("Flush");
	else if (straight)     printf("Straight");
	else if (three)        printf("Three of a kind");
	else if (pairs == 2)   printf("Two pairs");
	else if (pairs == 1)   printf("Pairs");
	else                   printf("High card");

	printf("\n\n");
}
