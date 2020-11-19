#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stackADT2.h"

int main(void)
{
	Stack stack;
	bool is_match;
	char ch;

	stack = create(100);

	printf("Enter parenthese and/or braces: ");	
	is_match = true;
	do {
		ch = getchar();
		if (ch == '(' || ch == '{') {
			if ( is_full(stack) ) {
				printf("stack is full! \n");
				exit(EXIT_SUCCESS);
			}
			push(stack, ch);
		} else if (ch == ')') {
			if ( is_empty(stack) ) {
				is_match = false;
				break;
			}

			if (pop(stack) != '(') {
				is_match = false;
				break;
			}
		} else if (ch == '}') {
			if ( is_empty(stack) ) {
				is_match = false;
				break;
			}

			if (pop(stack) != '{') {
				is_match = false;
				break;
			}
		}
	} while (ch != '\n');
	
	printf("Parentheses/braces %s nested properly \n",
			(is_match ? "are" : "are not"));

	destroy(stack);

	return 0;
}
