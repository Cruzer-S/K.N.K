#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include <wchar.h>

#define PRINT(X) printf(#X "= %d \n", X);

int mbcheck(const char *s)
{
	for (int n = mblen(NULL, 0); ; s += n) {
		if ((n = mblen(s, MB_CUR_MAX)) <= 0) {
			printf("n: %d \n", n);
			return n;
		} else printf("n: %d \n", n);
	}
}

int main(void)
{
	char *sjis[] = {
		"\x05\x87\x80\x36\xed\xaa",
		"\x20\x12"
	};

	if (setlocale(LC_ALL, "") == NULL)
		abort();
	else printf("setlocale: %s \n", setlocale(LC_ALL, NULL));

	PRINT(mbcheck(sjis[0]));

	return 0;
}
