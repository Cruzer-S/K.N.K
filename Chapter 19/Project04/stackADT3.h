#ifndef STACK_ADT_2_H__
#define STACK_ADT_2_H__

#include <stdbool.h>

typedef void *Item;

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
