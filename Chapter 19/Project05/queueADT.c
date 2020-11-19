#include "queueADT.h"
#include <stdlib.h>
#include <stddef.h> //size_t

#define QUEUE_SIZE 100

struct queue_type {
	Item item[QUEUE_SIZE];
	size_t first, last;
	size_t count;
};

Queue queue_create(void)
{
	Queue new_queue = malloc(sizeof(struct queue_type));
	if (new_queue == NULL)
		return NULL;

	new_queue->first = new_queue->last = 0;
	new_queue->count = 0;

	return new_queue;
}

bool queue_insert(Queue ADT, Item item)
{
	if (ADT->count >= QUEUE_SIZE)
		return false;

	ADT->item[ADT->last++] = item;
	if (ADT->last >= QUEUE_SIZE)
		ADT->last = 0;

	ADT->count++;

	return true;
}

bool queue_pop(Queue ADT)
{
	if (ADT->count <= 0)
		return false;

	ADT->first++;
	if (ADT->first >= QUEUE_SIZE)
		ADT->first = 0;

	ADT->count--;

	return true;
}

Item queue_peek(Queue ADT, bool is_first)
{
	if (is_first)
		return ADT->item[ADT->first];
	else
		return ADT->item[ ADT->last == 0 ? QUEUE_SIZE - 1 : ADT->last - 1];
}

bool queue_is_empty(Queue ADT)
{
	return ADT->count == 0 ? true : false;
}

void queue_destroy(Queue ADT)
{
	free(ADT);
}
