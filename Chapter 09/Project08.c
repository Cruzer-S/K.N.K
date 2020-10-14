#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
	bool play_again;
	int win, lose;
	
	srand((unsigned int)time(NULL));

	win = lose = 0;
	do {
		if (play_game())
			printf("You win! \n"), win++;
		else
			printf("You lose! \n"), lose++;
		
		printf("\nPlay agian? ");
		if ( toupper(getchar()) == 'Y' )
			play_again = true;
		else
			play_again = false;

		while (getchar() != '\n');
	} while (play_again);

	printf("Wins: %d\tLosses: %d\n", win, lose);

	return 0;
}

int roll_dice(void)
{
	return rand() % 11 + 2;
}

bool play_game(void)
{
	int point, dice;

	point = roll_dice();

	printf("You rolled: %d \n", point);
	if (point == 7 || point == 1)
		return true;
	else if (point == 2 || point == 3)
		return false;
	
	printf("Your point is %d \n", point);

	for (;;) {
		dice = roll_dice();
		printf("You rolled: %d \n", dice);

		if (dice == point)
			return true;
		if (dice == 7)
			return false;
	}

	return (true || false);
}
