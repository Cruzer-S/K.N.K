#include <stdio.h>
#include "stackADT3.h"

int main(void)
{
	Stack s1, s2;
	Item n;

	s1 = create();
	s2 = create();

	push(s1, "Hello ");
	push(s1, "world!");

	n = pop(s1);
	printf("Popped %s from s1 \n", n);

	push(s2, n);
	n = pop(s1);
	printf("Popped %s from s1 \n", n);
	push(s2, n);

	destroy(s1);

	while (!is_empty(s2))
		printf("Popped %s from s2 \n", pop(s2));
	
	push(s2, "empty ");	
	make_empty(s2);
	if (is_empty(s2))
		printf("s2 is empty \n");
	else
		printf("s2 is not empty \n");

	destroy(s2);

	return 0;
}
