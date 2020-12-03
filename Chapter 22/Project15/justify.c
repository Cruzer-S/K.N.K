#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

int main(int argc, char *argv[])
{
	FILE *orgn, *dest;
	char word[MAX_WORD_LEN + 2];
	int word_len;

	if (argc != 3)
		ERROR_HANDLING("usage: %s <origin> <destination>", argv[0]);

	orgn = fopen(argv[1], "r");
	if (orgn == NULL)
		ERROR_HANDLING("failed to open file %s", argv[1]);

	dest = fopen(argv[2], "w");
	if (dest == NULL)
		ERROR_HANDLING("failed to create file %s", argv[2]);

	clear_line();
	for (;;) {
		word_len = read_word(orgn, word, MAX_WORD_LEN + 1);
		
		if (word_len == 0) {
			flush_line(dest);
			break;
		}

		if (word_len + 1 > space_remaining()) {
			write_line(dest);
			clear_line();
		}

		add_word(word);
	}

	fclose(orgn); fclose(dest);

	return 0;
}
