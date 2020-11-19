#include "list_stack.h"

#include <stdlib.h>

struct node {
	sdata data;
	struct node *next;
};

struct stack {
	struct node *top;
};

void make_empty(struct stack *ADT)
{
	while ( !is_empty(ADT) )
		pop(ADT);

	ADT->top = NULL;
}

bool is_empty(const struct stack *ADT)
{
	return ADT->top ? false : true;
}

bool is_full(const struct stack *ADT)
{
	return false;
}

bool push(struct stack *ADT, sdata data)
{
	struct node *new_node = malloc(sizeof(struct node));
	if ( !new_node ) return false;

	new_node->data = data;
	new_node->next = NULL;

	if ( ADT->top == NULL ) {
		ADT->top = new_node;
	} else {
		new_node->next = ADT->top;
		ADT->top = new_node;
	}
}

sdata pop(struct stack *ADT)
{
	sdata save_data = ADT->top->data;
	struct node *save_node = ADT->top->next;

	free(ADT->top);

	ADT->top = save_node;

	return save_data;
}
