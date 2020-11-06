#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define STACK_UNDERFLOW_MESSAGE ("There\'s no entity to pop \n")

struct node {
	stype data;
	struct node *next;
} *top = NULL;

void stack_underflow(void)
{
	fputs(STACK_UNDERFLOW_MESSAGE, stderr);
	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	while ( !is_empty() )
		pop();
}

bool is_empty(void)
{
	if ( top == NULL )
		return true;
	
	return false;
}

bool push(stype i)
{
	struct node *new_top = malloc(sizeof(struct node));

	if (new_top == NULL) return false;

	new_top->data = i;
	new_top->next = top;
	top = new_top;

	return true;
}

stype pop(void)
{
	struct node *node_to_remove;
	stype data;

	if ( is_empty() )
		stack_underflow();

	data = top->data;
	node_to_remove = top;
	top = top->next;

	free(node_to_remove);

	return data;
}
