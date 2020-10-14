#include <stdio.h>

#define MAX_MSG (1024)

int main(void)
{
	char message[MAX_MSG + 1];
	char ch, *p;

	printf("Enter a message: ");
	for ( p = message; (ch = getchar()) != '\n' && (p - message) < MAX_MSG; *p++ = ch) ;

	printf("Recersal is: ");
	for ( ; p >= message; putchar(*p--)) ;
	putchar('\n');

	return 0;
}
