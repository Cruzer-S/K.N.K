#ifndef ARRAY_STACK_H__
#define ARRAY_STACK_H__ 

#include <stdbool.h>

#define STACK_SIZE 100

typedef int sdata;

struct stack;

void make_empty(struct stack *);
bool is_empty(const struct stack *);
bool is_full(const struct stack *);
bool push(struct stack *, sdata );
sdata pop(struct stack *s);

#endif
