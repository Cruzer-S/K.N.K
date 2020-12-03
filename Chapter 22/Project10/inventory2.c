#include <stdio.h>
#include <stdlib.h>

#include "readline.h"

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;

	struct part *next;
} ;

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void erase(void);
void print(void);
void dump(void);
void restore(void);
void erase(void);

int main(void)
{
	char code;

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n');

		switch (code) {
		case 'i': insert();
				  break;
		case 's': search();
				  break;
		case 'u': update();
				  break;
		case 'p': print();
				  break;
		case 'e': erase();
				  break;
		case 'd': dump();
				  break;
		case 'r': restore();
				  break;
		case 'q': return 0;
		default: printf("Illegal code \n");
		}
		printf("\n");
	}
}

struct part *find_part(int number)
{
	struct part *p;
	
	for (p = inventory;
		 p != NULL && number > p->number;
		 p = p->next) ;

	if (p != NULL && number == p->number)
		return p;

	return NULL;
}

void erase(void)
{
	struct part *prev, *cur;
	int parts;

	printf("Enter a parts: ");
	scanf("%d", &parts);

	for (prev = NULL, cur = inventory;
		 cur != NULL; prev = cur, cur = cur->next) {
		if (cur->number == parts) {
			struct part *temp = cur;

			printf("Remove part %d, %s \n",
					cur->number, cur->name);

			if (prev == NULL)	inventory = cur->next;
			else				prev->next = cur->next;

			free(temp);

			return ;
		}
	}

	printf("Failed to find part %d \n", parts);
}

void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full; can't add more parts. \n");
		return ;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for (cur = inventory, prev = NULL;
		 cur != NULL && new_node->number > cur->number;
		 prev = cur, cur = cur->next) ;

	if (cur != NULL && new_node->number == cur->number) {
		printf("Part already exists. \n");
		free(new_node);
		return ;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);

	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s \n", p->name);
		printf("Quantity on hand %d \n", p->on_hand);
	} else {
		printf("Part not found. \n");
	}
}

void update(void)
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);

	if (p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	} else {
		printf("Part not found. \n");
	}
}

void print(void)
{
	struct part *p;

	printf("Part Number		Part Name				"
		   "Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%7d		%-25s%11d\n", 
				p->number, p->name, p->on_hand);
}

void dump(void)
{
	FILE *fp;
	char filename[FILENAME_MAX];

	if (inventory == NULL) {
		printf("There's no part in inventory \n");
		return ;
	}

	printf("Enter name of output file: ");
	scanf("%s", filename);

	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("failed to create file %s \n", filename);
		return ;
	}

	for (struct part *cur = inventory; 
					  cur != NULL; 
					  cur = cur->next) 
	{
		if (fwrite(cur, sizeof(struct part), 1, fp) != 1) {
			printf("failed to write part data \n");
			remove(filename);
			return ;
		}
	}

	fclose(fp);
}

void restore(void)
{
	FILE *fp;
	char filename[FILENAME_MAX];

	printf("Enter name of input file: ");
	scanf("%s", filename);

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("failed to load file %s \n", filename);
		return ;
	}

	for (struct part *cur, *prev, *new_node, load;
			    fread(&load, sizeof(struct part), 1, fp) == 1;)
	{
		for (cur = inventory, prev = NULL;
			 cur != NULL && load.number > cur->number;
			 prev = cur, cur = cur->next) ;

		if (cur != NULL && load.number == cur->number) {
			cur->on_hand += load.on_hand;
			continue;
		}

		new_node = malloc(sizeof(struct part));
		if (new_node == NULL) {
			printf("Database is full; can't load parts data \n");
			return ;
		} else *new_node = load;

		new_node->next = cur;
		if (prev == NULL)
			inventory = new_node;
		else
			prev->next = new_node;
	}

	fclose(fp);
}
