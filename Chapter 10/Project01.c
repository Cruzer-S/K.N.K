#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE (100)

typedef char stype;

stype contents[STACK_SIZE];
int top;

void stack_overflow(void)
{
	printf("stack overflow occured! \n");

	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("stack underflow occured! \n");

	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return (top == 0);
}

bool is_full(void)
{
	return (top == STACK_SIZE);
}

void push(stype i)
{
	if ( is_full() )
		stack_overflow();

	contents[top++] = i;	
}

stype pop(void)
{
	if ( is_empty() )
		stack_underflow();
	
	return contents[--top];
}

int main(void)
{
	bool is_match;
	char ch;

	printf("Enter parenthese and/or braces: ");
	
	is_match = true;
	do {
		ch = getchar();
		if (ch == '(' || ch == '{') {
			if ( is_full() ) {
				printf("stack is full! \n");
				exit(EXIT_SUCCESS);
			}
			push(ch);
		} else if (ch == ')') {
			if ( is_empty() ) {
				is_match = false;
				break;
			}

			if (pop() != '(') {
				is_match = false;
				break;
			}
		} else if (ch == '}') {
			if ( is_empty() ) {
				is_match = false;
				break;
			}

			if (pop() != '{') {
				is_match = false;
				break;
			}
		}
	} while (ch != '\n');
	
	printf("Parentheses/braces %s nested properly \n",
			(is_match ? "are" : "are not"));
	
	return 0;
}
