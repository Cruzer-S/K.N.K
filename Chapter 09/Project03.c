#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_X (10)
#define MAP_SIZE_Y (10)

#define INIT_POS_X (0)
#define INIT_POS_Y (0)

void generate_random_walk(char walk[MAP_SIZE_Y][MAP_SIZE_X]);
void print_array(char walk[MAP_SIZE_Y][MAP_SIZE_X]);

int main(void)
{
	char map[MAP_SIZE_Y][MAP_SIZE_X] = { 0, };

	generate_random_walk(map);
	print_array(map);

	return 0;
}

void generate_random_walk(char walk[MAP_SIZE_Y][MAP_SIZE_X])
{
	int position_x, position_y;
	int check_x, check_y;
	
	const int dtox[4] = {
		-1, 0, 1, 0
	},        dtoy[4] = {
		0, -1, 0, 1
	};
	
	srand((unsigned int)time(NULL));
	
	position_x = INIT_POS_X, position_y = INIT_POS_Y;
	
	walk[position_y][position_x] = 1;
	for (int step = 1; step < 26; step++) {
		for (int i = 0, dir = (rand() % 4); i < 4; i++, dir++) {
			if (dir >= 4) dir = 0;
				
			check_x = position_x + dtox[dir],
			check_y = position_y + dtoy[dir];
			
			if (check_x < 0 || check_y < 0
				||  check_x >= MAP_SIZE_X
			||  check_y >= MAP_SIZE_Y)          continue;
			if (walk[ check_y ][ check_x ] != 0) continue;
				
			position_x = check_x,
			position_y = check_y;
			
			walk[ position_y ][ position_x ] = (step + 1);
			
			break;
		}
		
		if ( walk[ position_y ][position_x ] == (step - 1) )
			break;
	}
}

void print_array(char walk[10][10])
{
	for (int i = 0; i < MAP_SIZE_Y; i++) {
		for (int j = 0; j < MAP_SIZE_X; j++) {
			switch ( walk[i][j] ) {
				case 0: putchar('.'); break;
				case 1: putchar('A'); break;
				case 2: putchar('B'); break;
				case 3: putchar('C'); break;
				case 4: putchar('D'); break;
				case 5: putchar('E'); break;
				case 6: putchar('F'); break;
				case 7: putchar('G'); break;
				case 8: putchar('H'); break;
				case 9: putchar('I'); break;
				case 10: putchar('J'); break;
				case 11: putchar('K'); break;
				case 12: putchar('L'); break;
				case 13: putchar('M'); break;
				case 14: putchar('N'); break;
				case 15: putchar('O'); break;
				case 16: putchar('P'); break;
				case 17: putchar('Q'); break;
				case 18: putchar('R'); break;
				case 19: putchar('S'); break;
				case 20: putchar('T'); break;
				case 21: putchar('U'); break;
				case 22: putchar('V'); break;
				case 23: putchar('W'); break;
				case 24: putchar('X'); break;
				case 25: putchar('Y'); break;
				case 26: putchar('Z'); break;
			} putchar(' ');
		} putchar('\n');
	}
}
