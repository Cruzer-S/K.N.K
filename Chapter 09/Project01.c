#include <stdio.h>

#define MAX_SIZE (10)

void selection_sort(int array[], int size);

int main(void)
{
	int array[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
		scanf("%d", &array[i]);

	selection_sort(array, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%-3d", array[i]);
	putchar('\n');
	
	return 0;
}

void selection_sort(int array[], int size)
{
	int point, temp; 
	
	if (size <= 1)
		return ;

	point = 0; 
	for (int i = 1; i < size; i++)
		if (array[point] < array[i])
			point = i;

	temp = array[size - 1];
	array[size - 1] = array[point];
	array[point] = temp;

	selection_sort(array, size - 1);
}
