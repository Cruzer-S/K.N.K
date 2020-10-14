#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS		(10)
#define DIGIT_HEIGHT	(4)
#define DIGIT_WIDTH		(4)

void clear_digit(void);
void process_digit(int digit, int position);
void print_digits_array(void);

char digits[DIGIT_HEIGHT][MAX_DIGITS * DIGIT_WIDTH];

const bool segments[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},	// 0
	{0, 1, 1, 0, 0, 0, 0},	// 1
	{1, 1, 0, 1, 1, 0, 1},	// 2
	{1, 1, 1, 1, 0, 0, 1},	// 3
	{0, 1, 1, 0, 0, 1, 1},	// 4
	{1, 0, 1, 1, 0, 1, 1},	// 5
	{1, 0, 1, 1, 1, 1, 1},	// 6
	{1, 1, 1, 0, 0, 0, 0},	// 7
	{1, 1, 1, 1, 1, 1, 1},	// 8
	{1, 1, 1, 1, 0, 1, 1},	// 9
};

int dtoi(int digit)
{
	switch (digit) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}

	return -1;
}

int main(void)
{
	int digit, position, ch;

	clear_digit();

	printf("Enter a number: ");
	for (position = 0;;) {
		ch = getchar();

		if (ch == '\n') break;
		if ( !isdigit(ch) ) continue;

		digit = dtoi(ch);

		process_digit(digit, position++);
	}

	print_digits_array();

	return 0;
}

void clear_digit(void)
{
	for (int i = 0; i < DIGIT_HEIGHT; i++)
		for (int j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++)	
			digits[i][j] = 0;
}

void process_digit(int digit, int position)
{
	if (position < 0 || position > MAX_DIGITS - 1)
		return ;

	for (int k = 0; k < 7; k++) {
		if ( !segments[digit][k] ) continue;

		int offset = position * DIGIT_WIDTH;
		switch (k) {
		case 0:
			digits[0][offset + 0] = '.';
			digits[0][offset + 1] = '-';
			digits[0][offset + 2] = '-';
			digits[0][offset + 3] = '.';
			break;

		case 1:
			digits[0][offset + 3] = '.';
			digits[1][offset + 3] = '|';
			break;

		case 2:
			digits[2][offset + 3] = '|';
			digits[3][offset + 3] = '\'';
			break;

		case 3:
			digits[3][offset + 0] = '\'';
			digits[3][offset + 1] = '-';
			digits[3][offset + 2] = '-';
			digits[3][offset + 3] = '\'';
			break;

		case 4:
			digits[2][offset + 0] = '|';
			digits[3][offset + 0] = '\'';
			break;

		case 5:
			digits[0][offset + 0] = '.';
			digits[1][offset + 0] = '|';
			break;

		case 6:
			digits[1][offset + 1] = '_';
			digits[1][offset + 2] = '_';
			break;

		case 7:
			digits[3][offset + 0] = '\'';
			digits[3][offset + 1] = '-';
			digits[3][offset + 2] = '-';
			digits[3][offset + 3] = '\'';
			break;
		}
	}
}

void print_digits_array(void)
{
	for (int i = 0; i < DIGIT_HEIGHT; i++) {
		for (int j = 0; j < DIGIT_WIDTH * MAX_DIGITS; j++) {
			if (j != 0 && j % DIGIT_WIDTH == 0) putchar(' ');
			if (digits[i][j] == '\0')
				putchar(' ');
			else
				putchar(digits[i][j]);
		} 
		putchar('\n');
	}
}
