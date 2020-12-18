#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// srand((unsigned int)time(NULL));
	for (int i = 0; i < 1000; i++)
		fputc((rand() % 2) ? '1' : '0', stdout);

	return 0;
}

/*************************************************** 
 * Answer of question (b)                          *
 * Use higher order bit not using lower order bit. *
 **************************************************/
