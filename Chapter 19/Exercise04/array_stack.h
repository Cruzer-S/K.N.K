#ifndef ARRAY_STACK_H__
#define ARRAY_STACK_H__ 

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
	int contents[STACK_SIZE];
	int top;
} Stack;

void make_empty(Stack *);
bool is_empty(const Stack *);
bool is_empty(const Stack *);
void push(Stack *, int );
int pop(Stack *s);

#endif
