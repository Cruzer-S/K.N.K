#include <stdio.h>

#define MAX_SIZE (100)

void create_magic_square(int n, char magic_square[n][n]);
void print_array(int n, char magic_square[n][n]);

int main(void)
{
	int size;
	
	printf("This program creates a magic square of a specified size. \n");
		printf("The size must be an odd number between 1 and 99. \n");
	do {
		printf("Enter size of magic square: ");
		scanf("%d", &size);
	} while ( (size < MAX_SIZE) && !(size % 2) );
		
	char map[size][size];

	create_magic_square(size, map);
	print_array(size, map);

	return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
	int pos_x, pos_y,
		target_x, target_y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		magic_square[i][j] = 0;
	
	pos_x = (n / 2);
	pos_y = 0;
	
	for (int k = 0; k < n * n; k++) {
		magic_square[pos_y][pos_x] = (k + 1);
		
		if ( (pos_y - 1) < 0)       target_y = n - 1;
		else                        target_y = pos_y - 1;
		if ( (pos_x + 1) >= n)		target_x = 0;
		else                        target_x = pos_x + 1;
			
		if ( magic_square[target_y][target_x] != 0 )
			pos_x = pos_x + 0, pos_y = pos_y + 1;
		else
			pos_x = target_x, pos_y = target_y;
	}
}

void print_array(int n, char magic_square[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", magic_square[i][j]);
		
		putchar('\n');
	}
}
