#include <stdlib.h> //malloc, free
#include <string.h> //memcpy
#include "queue.h"

#define MAX_QUEUE_DATA 100

struct qdata {
	void *data;
	size_t size;
	bool deep_copied;
};

struct queue {
	struct qdata node[MAX_QUEUE_DATA];
	size_t first, last;
	size_t count;
} ;

struct queue *queue_create(void)
{
	struct queue *new_queue;
	
	new_queue = malloc(sizeof(struct queue));
	if (new_queue == NULL)
		return NULL;

	new_queue->first = new_queue->last = 0;
	new_queue->count = 0;

	return new_queue;
}

bool queue_insert(struct queue *ADT, void *data, size_t size, bool is_deep_copy) 
{
	struct qdata new_node;

	if (ADT->count == MAX_QUEUE_DATA)
		return false;

	if (is_deep_copy) {
		void *new_data = malloc(size);
		if (new_data == NULL)
			return false;

		memcpy(new_data, data, size);

		new_node = (struct qdata) {
			.data = new_data, .size = size, .deep_copied = true
		};
	} else {
		new_node = (struct qdata) {
			.data = data, .size = size, .deep_copied = false
		};
	}

	ADT->node[ADT->last++] = new_node;
	ADT->count++;

	if (ADT->last == MAX_QUEUE_DATA)
		ADT->last = 0;

	return true;
}

bool queue_erase(struct queue *ADT)
{
	if (ADT->count == 0)
		return false;

	if (ADT->node[ADT->first].deep_copied)
		free(ADT->node[ADT->first].data);

	ADT->first++, ADT->count--;
	if (ADT->first == MAX_QUEUE_DATA)
		ADT->first = 0;

	return true;
}

qdata queue_peek(struct queue *ADT, bool is_first)
{
	if (is_first)
		return ADT->node[ADT->first].data;
	else
		return ADT->node[ADT->last == 0 ? MAX_QUEUE_DATA - 1 : ADT->last - 1].data;
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
