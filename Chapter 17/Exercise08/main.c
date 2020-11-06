#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void)
{
	printf("is_empty: %d \n", is_empty());

	for (int i = 0; i < 10; i++)
		push(i);

	printf("is_empty: %d \n", is_empty());

	while ( !is_empty() )
		printf("%d ", pop());

	return 0;
}
