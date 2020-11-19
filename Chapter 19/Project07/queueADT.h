#ifndef QUEUE_H__ 
#define QUEUE_H__

#include <stddef.h> //size_t
#include <stdbool.h> //bool

typedef struct queue_type *Queue;
typedef int Item;

Queue queue_create(void);

bool queue_insert(Queue , Item);
bool queue_pop(Queue );
Item queue_peek(Queue , bool);
bool queue_is_empty(Queue );

void queue_destroy(Queue );

#endif
