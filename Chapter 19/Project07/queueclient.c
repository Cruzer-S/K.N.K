#include <stdio.h>
#include "queueADT.h"

int main(void)
{
	Queue q1, q2;
	int n;

	q1 = queue_create();
	q2 = queue_create();

	queue_insert(q1, 1);
	queue_insert(q1, 2);

	n = queue_peek(q1, true);
	printf("Peeked %d from q1\n", n);
	queue_insert(q2, n);
	queue_pop(q1);

	n = queue_peek(q1, true);
	printf("Peeked %d from q1\n", n);
	queue_insert(q2, n);
	queue_pop(q1);

	queue_destroy(q1);

	while ( !queue_is_empty(q2) ) {
		n = queue_peek(q2, true);
		printf("Peeked %d from q2\n", n);
		queue_pop(q2);
	}
	
	queue_destroy(q2);
}
