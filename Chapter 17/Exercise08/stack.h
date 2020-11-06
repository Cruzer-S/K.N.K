#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int stype;

void stack_overflow(void);
void stack_underflow(void);

void make_empty(void);
bool is_empty(void);

bool push(stype i);
stype pop(void);

#endif
