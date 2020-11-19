#ifndef QUEUE_H__ 
#define QUEUE_H__

#include <stdbool.h> //bool
#include <stddef.h> //size_t

struct queue;
struct qdata {
	void *data;
	size_t size;
};

struct queue *queue_create(void);

void queue_insert(struct queue *, struct qdata);
struct qdata queue_pop(struct queue *);
struct qdata queue_peek(struct queue *, bool);
bool queue_is_empty(struct queue *);

void queue_destroy(struct queue *);

#endif
