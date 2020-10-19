#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_OVERFLOW_MESSAGE ("Expression is too complex")
#define STACK_UNDERFLOW_MESSAGE ("Not enough operands in expression")

#define STACK_SIZE (10)

typedef int stype;

void stack_overflow(void);
void stack_underflow(void);

void make_empty(void);
bool is_empty(void);
bool is_full(void);

void push(stype i);
stype pop(void);

#endif
