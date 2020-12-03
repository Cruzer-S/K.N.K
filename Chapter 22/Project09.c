#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN  25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int );
int insert_part(struct part *);

int main(int argc, char *argv[])
{
	struct part part1, part2;
	int s1, s2;
	char filename[FILENAME_MAX];
	FILE *src1, *src2;
	FILE *dest;

	if (argc != 2) {
		fputs("usage: <mergefile> \n", stderr);
		exit(EXIT_FAILURE);
	}

	dest = fopen(argv[1], "wb");
	if (dest == NULL) {
		fprintf(stderr, "failed to open %s file \n", filename);
		exit(EXIT_FAILURE);
	}

	printf("Enter first file name: ");
	scanf("%s", filename);
	if ( (src1 = fopen(filename, "rb")) == NULL ) {
		fprintf(stderr, "failed to open %s file \n", filename);

		fclose(dest);
		remove(argv[1]);

		exit(EXIT_FAILURE);
	}

	printf("Enter second file name: ");
	scanf("%s", filename);
	if ( (src2 = fopen(filename, "rb")) == NULL ) {
		fprintf(stderr, "failed to open %s file \n", filename);
		fclose(src1);

		fclose(dest);
		remove(argv[1]);

		exit(EXIT_FAILURE);
	}

	do {
		s1 = fread(&part1, sizeof(struct part), 1, src1);
		s2 = fread(&part2, sizeof(struct part), 1, src2);

		if (s1) if (insert_part(&part1) != 0) goto ERROR;
		if (s2) if (insert_part(&part2) != 0) goto ERROR;
	} while (s1 + s2 > 0);

	if (fwrite(inventory, 
			   sizeof(struct part), num_parts, 
			   dest) != num_parts) goto ERROR;

	fclose(dest);
	fclose(src1); fclose(src2);
	
	return 0;

	ERROR: {
		fprintf(stderr, "failed to merge two file \n");

		fclose(src1); fclose(src2);
		fclose(dest); remove(argv[1]);
		exit(EXIT_FAILURE);
	} 
}

int find_part(int number)
{
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;

	return -1;
}

int insert_part(struct part *new_part)
{
	int check;
	if (num_parts == MAX_PARTS)
		return -1;
	
	if ( (check = find_part(new_part->number)) >= 0) {
		if ( strcmp(inventory[check].name, new_part->name) )
			return -2;

		inventory[check].on_hand += new_part->on_hand;
		return 0;
	}

	int offset;
	for ( offset = 0; offset < num_parts; offset++) 
		if (inventory[offset].number > new_part->number) break;

	for (int k = num_parts; k > offset; k--)
		inventory[k] = inventory[k - 1];

	inventory[offset] = *new_part;

	num_parts++;

	return 0;
}
