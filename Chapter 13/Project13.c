#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MSG_LEN 1024

int ltoi(char alphabet);
char itol(int sequence);

void encrypt(char *message, int shift);

int main(void)
{
	int shift;
	char message[MSG_LEN + 1];

	fputs("Enter message to be encrypted: ", stdout);
	fgets(message, MSG_LEN, stdin);
	message[strlen(message)] = '\0';

	fputs("Enter shift amount (1-25): ", stdout);
	scanf("%d", &shift);

	encrypt(message, shift);

	printf("Encrypted message: %s \n", message);

	return 0;
}

int ltoi(char alpha)
{
	const char *origin = "abcdefghijklnmopqrstuvwxyz"
						 "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
	return (strchr(origin, alpha) - origin);
}

char itol(int seq)
{
	return "abcdefghijklnmopqrstuvwxyz"
		   "ABCDEFGHIJKLNMOPQRSTUVWXYZ"[seq];
}

void encrypt(char *m, int s)
{
	for (bool check = isupper(*m); *m; check = isupper(*++m)) 
		if(isalpha(*m))
			*m = itol( (ltoi(*m) + s) % 26 + (check * 26) );
}
