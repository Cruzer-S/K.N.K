#include <stdio.h>
#include <string.h>

#define MSG_LEN 1024

#define SWAP(p, q) {	\
	char temp = p;		\
	p = q;				\
	q = temp;			\
}

void reverse(char *message);

int main(void)
{
	char message[MSG_LEN + 1];

	fputs("Enter message: ", stdout);
	fgets(message, MSG_LEN, stdin);
	message[strlen(message) - 1] = '\0';

	reverse(message);

	printf("Reversed message: %s \n", message);

	return 0;
}

void reverse(char *m)
{
	for (char *q = m + strlen(m) - 1; m <= q; m++,--q) 
		SWAP(*m, *q);
}
