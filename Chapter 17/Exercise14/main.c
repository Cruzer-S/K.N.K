#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

struct node *insert_into_ordered_list(
		struct node *list,
		struct node *new_node) 
{
	struct node *cur, *prev;

	if (list == NULL)
		return new_node;

	for (prev = NULL, cur = list;
		 (cur != NULL) && (cur->value <= new_node->value);
		 prev = cur, cur = cur->next) ;

	if (prev != NULL) {
		prev->next = new_node;
		new_node->next = cur;
	} else {
		new_node->next = cur;
		list = new_node;
	} 

	return list;
}

void delete_from_list(struct node **list, int n)
{
	struct node *cur, *prev;

	for (cur = *list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next);

	if (cur == NULL)
		return ;

	if (prev == NULL)
		*list = (*list)->next;
	else
		prev->next = cur->next;

	free(cur);
}

int main(void)
{
	struct node *list, *new_node, *copy;
	int n;

	list = NULL;
	while (true) {
		scanf("%d", &n);
		if (n <= 0) break;

		new_node = malloc(sizeof(struct node));
		if (new_node == NULL) exit(EXIT_FAILURE);
		new_node->value = n;

		list = insert_into_ordered_list(list, new_node);
	}
	
	copy = list;
	while (copy != NULL) {
		if ((copy->value % 2) == 0) {
			delete_from_list(&list, copy->value);
			copy = list;

			continue;
		}

		copy = copy->next;
	}

	copy = list;
	while (copy != NULL) {
		printf("%d ", copy->value);
		copy = copy->next;
	} putchar('\n');

	return 0;
}
