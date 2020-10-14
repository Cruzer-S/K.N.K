#include <stdio.h>
#include <ctype.h>

#define MAX_MSG 1024

int main(void)
{
	char *end;

	char message[MAX_MSG], punct;
	printf("Enter a sentence: ");

	for (char ch, *p = message; (p - message) < MAX_MSG; p++) {
		ch = getchar();
		if ( ch == '!' || ch == '.' || ch == '?' ) {
			punct = ch;
			end = p;
			break;
		}

		*p = ch;
	}

	for (char *last = end, *first = last; first >= message; first--) {
		if (first != message)
			if (*first != ' ') continue;

		for (char *p = first + (first != message); p <= last; p++)
			putchar(*p);
		if (first != message)
			putchar(' ');

		last = first - 1;
	} printf("%c\n", punct);

	return 0;
}
