#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

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

int find_part(int number)
{
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;

	return -1;
}

void insert(void)
{
	struct part new_part;

	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts. \n");
		return ;
	}

	printf("Enter part number: ");
	scanf("%d", &new_part.number);

	if (find_part(new_part.number) >= 0) {
		printf("Part already exists. \n");
		return ;
	}

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

void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);

	if (i >= 0) {
		printf("Part number: %s \n", inventory[i].name);
		printf("Quantity on hand: %d \n", inventory[i].on_hand);
	} else {
		printf("Part not found. \n");
	}
}

void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else {
		printf("Part not found. \n");
	}
}

void print(void)
{
	printf("Part Number    Part Name                         "
		   "Quantity on Hand\n");

	for (int i = 0; i < num_parts; i++)
		printf("%7d        %-25s%11d\n",
				inventory[i].number,
				inventory[i].name,
				inventory[i].on_hand);
}

void dump(void)
{
	FILE *fp;
	char filename[FILENAME_MAX];

	printf("Enter name of output file: ");
	scanf("%s", filename);

	fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("failed to create %s file", filename);
		return ;
	}

	if (fwrite(inventory, 
			   sizeof(struct part), num_parts, fp) 
			   != num_parts) {
		printf("failed to write inventory data");
		fclose(fp);
		remove(filename);

		return ;
	}

	fclose(fp);
}

void restore(void)
{
	struct part new_part;
	FILE *fp;
	char filename[FILENAME_MAX];

	printf("Enter name of input file: ");
	scanf("%s", filename);

	fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("failed to open %s file", filename);
		return ;
	}

	num_parts = 0;
	for (num_parts = 0; 
		 fread(&inventory[num_parts], sizeof(struct part), 1, fp);
		 num_parts++);

	if (num_parts == 0) {
		printf("failed to read inventory data");
		fclose(fp);
		return ;
	}
	
	fclose(fp);
}
