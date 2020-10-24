#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

#define UPDATE_PRICE	1
#define UPDATE_QUANTITY	0

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	int price;
} ;

int num_parts = 0;

int find_part(struct part *inventory, int number);
void insert(struct part *inventory);
void search(struct part *inventory);
void update(struct part *inventory, int type);
void print(struct part *inventory);

int main(void)
{
	struct part inventory[MAX_PARTS];

	char code;

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n');

		switch (code) {
		case 'i': insert(inventory);
				  break;
		case 's': search(inventory);
				  break;
		case 'u': update(inventory, UPDATE_QUANTITY);
				  break;
		case 'c': update(inventory, UPDATE_PRICE);
				  break;
		case 'p': print(inventory);
				  break;
		case 'q': return 0;
		default: printf("Illegal code \n");
		}
		printf("\n");
	}
}

int find_part(struct part *inventory, int number)
{
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;

	return -1;
}

void insert(struct part *inventory)
{
	struct part new_part;

	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts. \n");
		return ;
	}

	printf("Enter part number: ");
	scanf("%d", &new_part.number);

	if (find_part(inventory, new_part.number) >= 0) {
		printf("Part already exists. \n");
		return ;
	}

	printf("Enter part price: ");
	scanf("%d", &new_part.price);

	printf("Enter part name: ");
	read_line(new_part.name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_part.on_hand);

	int offset;
	for ( offset = 0; offset < num_parts; offset++) 
		if (inventory[offset].number > new_part.number) break;

	for (int k = num_parts; k > offset; k--)
		inventory[k] = inventory[k - 1];

	inventory[offset] = new_part;

	num_parts++;
}

void search(struct part *inventory)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, number);

	if (i >= 0) {
		printf("Part number: %s \n", inventory[i].name);
		printf("Quantity on hand: %d \n", inventory[i].on_hand);
		printf("Part price: %d \n", inventory[i].price);
	} else {
		printf("Part not found. \n");
	}
}

void update(struct part *inventory, int type)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(inventory, number);
	if (i >= 0) {
		switch (type) {
		case UPDATE_QUANTITY:
			printf("Enter change in quantity on hand: ");
			scanf("%d", &change);
			inventory[i].on_hand += change;
			break;

		case UPDATE_PRICE:
			printf("Enter change price: ");
			scanf("%d", &change);
			inventory[i].price = change;
			break;
		}
	} else {
		printf("Part not found. \n");
	}
}

void print(struct part *inventory)
{
	printf("Part Number    Part Name      Price          "
		   "Quantity on Hand\n");

	for (int i = 0; i < num_parts; i++)
		printf("%7d        %-15s%-15d%d\n",
				inventory[i].number,
				inventory[i].name,
				inventory[i].price,
				inventory[i].on_hand);
}
