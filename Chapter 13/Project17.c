#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_LEN 1024

bool is_palindrome(const char *message);

int main(void)
{
	char message[MSG_LEN + 1];

	fputs("Enter message: ", stdout);
	fgets(message, MSG_LEN, stdin);

	printf("%s \n", is_palindrome(message) ? 
			"Palindrome" : "Not a palindrome");

	return 0;
}

bool is_palindrome(const char *m)
{
	const char *q = m + strlen(m);
	while (m < q) {
		if (!isalpha(*m)) { m++; continue; }
		if (!isalpha(*q)) { --q; continue; }
		if (*m++ != *q--) return false;
	}
	return true;
}
