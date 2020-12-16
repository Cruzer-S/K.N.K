#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include <wchar.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define PRINT(X) printf(#X " = %d \n", X);

int main(int argc, char *argv[])
{
	char *locale;
	printf("argc: %d \n", argc);

	switch (argc) {
	case 1: locale = setlocale(LC_ALL, "ko_KR.UTF-8");
			break;
	case 2: locale = setlocale(LC_ALL, "ko_KR.euckr");
			break;
	case 3: locale = setlocale(LC_ALL, "C");
			break;
	} printf("locale: %s \n", locale);

	printf("\xc3\xb4 ""\uc3b4 \n");
	fprintf (stdout, "%C %C \n", 0xc3b4, L'척');
	fwprintf(stderr, L"%C %C \n", 0xc3b4, L'척');

	//https://r12a.github.io/app-encodings/

	return 0;
}
