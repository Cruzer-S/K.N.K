#ifndef QUEUE_H__ 
#define QUEUE_H__

#define QUEUE_SIZE 100

#include <stdbool.h> //bool
#include <stddef.h> //size_t

typedef int qdata;

typedef struct {
	 qdata[QUEUE_SIZE];
	size_t top;
} *Queue;

Queue queue_create(void);

void queue_insert(Queue , qdata);
qdata queue_pop(Queue *);
qdata queue_peek(Queue *, bool);
bool queue_is_empty(Queue *);

void queue_destroy(Queue *);

#endif
