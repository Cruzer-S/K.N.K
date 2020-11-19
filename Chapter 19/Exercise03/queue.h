#ifndef QUEUE_H__ 
#define QUEUE_H__

#include <stdbool.h> //bool
#include <stddef.h> //size_t

struct queue;
typedef void *qdata;

struct queue *queue_create(void);

bool queue_insert(struct queue *, void *, size_t, bool );
bool queue_erase(struct queue *);
qdata queue_peek(struct queue *, bool);
bool queue_is_empty(struct queue *);

void queue_destroy(struct queue *);

#endif
