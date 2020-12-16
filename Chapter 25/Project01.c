#include <stdio.h>
#include <locale.h>

int main(void)
{
	char *native, *begin;

	begin  = setlocale(LC_ALL, NULL);
	native = setlocale(LC_ALL, "");

	printf("At the beginning of the prgoram: %s \n", begin);
	printf("After setlocal(LC_ALL, "") is called: %s \n", native);

	return 0;
}
