#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZOF(X) (sizeof((X)) / sizeof((X)[0]))

int main(int argc, char *argv[])
{
	char blocks[10];
	FILE *fp;

	if (argc != 2) {
		fputs("usage: <filename> \n", stderr);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "failed to open %s file \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("%6s" "  " "%*s%s%*s" "  " "%10s" "\n",
			"offset", 
			12, "", "bytes", 12, "", 
			"characters"); 

	printf("%6s" "  " "%29s" "  " "%10s" "\n",
			"------", "-----------------------------", "----------");

	for (int len, count = 0; ; count += 10)	
	{
		len = fread(blocks, sizeof(char), SIZOF(blocks), fp);
		if (len == 0) break;

		printf("%6d  ", count);
		for (int i = 0; i < 10; i++) {
			if (i < len) printf("%2.2X ", blocks[i]);
			else         printf("   ");
		} putchar(' ');

		for (int i = 0; i < len; i++) {
			if (isprint(blocks[i])) putchar(blocks[i]);
			else                    putchar('.');
		} putchar('\n');
	}

	fclose(fp);

	return 0;
}
