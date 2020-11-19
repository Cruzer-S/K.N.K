#include <stdlib.h> //malloc, free
#include <string.h> //memcpy
#include "queue.h"

struct qnode {
	void *data;
	size_t size;
	bool deep_copied;

	struct qnode *next;
};

struct queue {
	struct qnode *first, *last;
	size_t count;
} ;

struct queue *queue_create(void)
{
	struct queue *new_queue;
	
	new_queue = malloc(sizeof(struct queue));
	if ( !new_queue ) return NULL;

	new_queue->first = new_queue->last = NULL;
	new_queue->count = 0;

	return new_queue;
}

bool queue_insert(struct queue *ADT, void *data, size_t size, bool is_deep_copy) 
{
	struct qnode *new_node;

	new_node = malloc(sizeof(struct qnode));
	if ( !new_node ) return false;

	*new_node = (struct qnode) {
		.size = size, .deep_copied = true, .next = NULL
	};

	if (is_deep_copy) {
		void *new_data = malloc(size);
		if ( !new_data ) return false;

		memcpy(new_data, data, size);
		new_node->data = new_data;
	} else {
		new_node->data = data;
	}

	if ( ADT->count == 0 ) {
		ADT->first = ADT->last = new_node;
	} else {
		ADT->last->next = new_node;
		ADT->last = new_node;
	}

	ADT->count++;

	return true;
}

bool queue_erase(struct queue *ADT)
{
	struct qnode *saved_node;

	if (ADT->count == 0)
		return false;

	if (ADT->first->deep_copied)
		free(ADT->first->data);

	saved_node = ADT->first->next;
	free(ADT->first);
	ADT->first = saved_node;

	ADT->count--;

	return true;
}

qdata queue_peek(struct queue *ADT, bool is_first)
{
	if (is_first)
		return ADT->first->data;
	else
		return ADT->last->data;
}

bool queue_is_empty(struct queue *ADT)
{
	if (ADT->count == 0)
		return true;

	return false;
}

void queue_destroy(struct queue *to_remove)
{
	free(to_remove);
}
