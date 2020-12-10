#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#undef BUFSIZ
#define BUFSIZ 3

char *read_gradually(int len)
{
	int cur = 0;
	char *str = malloc(sizeof(len));

	for (char *ptr = str;
			  fgets(ptr, len - cur, stdin);
			  cur = ptr - str)
	{
		if (strchr(ptr, '\n')) break;

		do {
			char *new_ptr = realloc(str, len *= 2);
			if (new_ptr == NULL) {
				free(str);
				return NULL;
			} else str = new_ptr;
		} while (false);
		
		ptr = strchr(str + cur, '\0');
	}

	return (char *)str;
}

void recursive(char *str)
{
	char *ptr;

	ptr = strtok(str, " ");

	if (ptr == NULL) return ;

	recursive(NULL);

	printf("%s ", ptr);
}

int main(void)
{
	char *buffer;

	buffer = read_gradually(BUFSIZ);
	if (buffer == NULL) {
		fputs("failed to read data \n", stderr);
		exit(EXIT_FAILURE);
	} else {
		buffer[strlen(buffer) - 1] = '\0';
	}

	printf("buffer: %s \n", buffer);

	recursive(buffer);
	fputc('\n', stdout);

	free(buffer);
	
	return 0;
}
