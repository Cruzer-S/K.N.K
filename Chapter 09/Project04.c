#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHA_SIZE (26)
#define WORD_LEN (100)

void read_word(int counts[ALPHA_SIZE]);
bool equal_array(int counts1[ALPHA_SIZE], int counts2[ALPHA_SIZE]);

int main(void)
{
	int anagram1[ALPHA_SIZE] = { 0, },
		anagram2[ALPHA_SIZE] = { 0, };
	
	int position;
	
	char ch;
	
	printf("Enter first word: ");
	read_word(anagram1);

	printf("Enter seconds word: ");
	read_word(anagram2);
		
	printf("The words %s anagrams. \n", equal_array(anagram1, anagram2) ? "are" : "are not");
	
	return 0;
}

void read_word(int counts[ALPHA_SIZE])
{
	int position;
	char ch;
	
	for (int i = 0; i < WORD_LEN; i++) {
		if ( (ch = getchar()) == '\n' )
			break;
		
		switch ( toupper(ch) ) {
			case 'A': position = 0; break;
			case 'B': position = 1; break;
			case 'C': position = 2; break;
			case 'D': position = 3; break;
			case 'E': position = 4; break;
			case 'F': position = 5; break;
			case 'G': position = 6; break;
			case 'H': position = 7; break;
			case 'I': position = 8; break;
			case 'J': position = 9; break;
			case 'K': position = 10; break;
			case 'L': position = 11; break;
			case 'M': position = 12; break;
			case 'N': position = 13; break;
			case 'O': position = 14; break;
			case 'P': position = 15; break;
			case 'Q': position = 16; break;
			case 'R': position = 17; break;
			case 'S': position = 18; break;
			case 'T': position = 19; break;
			case 'U': position = 20; break;
			case 'V': position = 21; break;
			case 'W': position = 22; break;
			case 'X': position = 23; break;
			case 'Y': position = 24; break;
			case 'Z': position = 25; break;
		}
		
		counts[position]++;
	}
}

bool equal_array(int counts1[ALPHA_SIZE], int counts2[ALPHA_SIZE])
{
	int	position = 1;
	for (int i = 0; i < ALPHA_SIZE; i++) {
		if (counts1[i] != counts2[i])
			return false;
	}
	return true;
}
