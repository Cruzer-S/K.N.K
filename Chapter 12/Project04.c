#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_MSG (1024)

int main(void)
{
	char message[MAX_MSG];
	char *p, *q = message;

	bool isPalindrome;

	printf("Enter a message: ");
	for (p = message; ( p < (message + MAX_MSG))
				   && ( *p++ = getchar() != '\n');) ;

	while (q < p) {
		if ( !isalpha(*p) ) { p--; continue; }
		if ( !isalpha(*q) ) { q++; continue; }
		if ( toupper(*p--) == toupper(*q++) ) continue; 
		isPalindrome = false; break; 
	}

	printf(	"%s \n", (isPalindrome) ? 
	("Palindrome") : ("Not a palindrome"));

	return 0;
} 
