#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
	fputs("That's all!, ", stdout);
}

void func2(void)
{
	fputs("folks!\n", stdout);
}

int main(void)
{
	atexit(func2);
	atexit(func1);

	return 0;
}
