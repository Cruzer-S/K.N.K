#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void)
{
	struct queue *my_queue, *your_queue;

	my_queue = queue_create(), your_queue = queue_create();
	if ( !my_queue || !your_queue ) exit(EXIT_FAILURE);


	printf("================ Your Queue ============= \n");
	for (int i = 0; i < 100; i++) {
		if (queue_insert(my_queue, 
			&i, sizeof(int), true) == false) break;

		if( i % 2 )
			if (queue_insert(your_queue,
				&i, sizeof(int), true) == false) break;

		if ( !queue_is_empty(your_queue) )
			printf("%d ", *(int *)queue_peek(your_queue, false));
	} putchar('\n');

	printf("========== Move Your to My Queue ======== \n");
	while ( !queue_is_empty(your_queue) ) {
		if (!queue_insert(my_queue,
			queue_peek(your_queue, true), sizeof(int), true)) 
		{
			queue_erase(my_queue);
		} else {
			printf("%d ", *(int *)queue_peek(your_queue, true));
			queue_erase(your_queue);
		}
	} putchar('\n');

	printf("================ My Queue =============== \n");
	while ( !queue_is_empty(my_queue) ) {
		printf("%d ", *(int *)queue_peek(my_queue, true));		
		queue_erase(my_queue);
	} putchar('\n');

	queue_destroy(my_queue);
	queue_destroy(your_queue);
}
