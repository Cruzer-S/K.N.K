#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stype contents[STACK_SIZE];
int top;

void stack_overflow(void)
{
	printf("%s \n", STACK_OVERFLOW_MESSAGE);
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("%s \n", STACK_UNDERFLOW_MESSAGE);
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
