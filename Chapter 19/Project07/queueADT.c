#include "queueADT.h"
#include <stdlib.h>
#include <stddef.h> //size_t

#define QUEUE_SIZE 100

struct node {
	Item item;
	struct node *next;
};

struct queue_type {
	struct node *first, *last;
	size_t count;
};

Queue queue_create(void)
{
	Queue new_queue = malloc(sizeof(struct queue_type));
	if (new_queue == NULL)
		return NULL;

	new_queue->first = new_queue->last = NULL;
	new_queue->count = 0;

	return new_queue;
}

bool queue_insert(Queue ADT, Item item)
{
	struct node *new_node;
	if (ADT->count >= QUEUE_SIZE)
		return false;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		return false;

	new_node->item = item;
	new_node->next = NULL;

	if (ADT->count == 0) {
		ADT->first = ADT->last = new_node;
	} else {
		ADT->last->next = new_node;
		ADT->last = new_node;
	}

	ADT->count++;

	return true;
}

bool queue_pop(Queue ADT)
{
	struct node *save_node;
	if (ADT->count == 0)
		return false;

	save_node = ADT->first->next;
	free(ADT->first);
	ADT->first = save_node;

	ADT->count--;

	return true;
}

Item queue_peek(Queue ADT, bool is_first)
{
	if (is_first)
		return ADT->first->item;
	else
		return ADT->last->item;
}

bool queue_is_empty(Queue ADT)
{
	return (ADT->count == 0) ? true : false;
}

void queue_destroy(Queue ADT)
{
	free(ADT);
}
