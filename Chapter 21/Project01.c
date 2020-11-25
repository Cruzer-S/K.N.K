#include <stdio.h>
#include <stddef.h>

struct s {
	char a;
	int b[2];
	float c;
} ;

int main(void)
{
	struct s s1;

	printf("size of struct s : %d \n", sizeof(struct s));
	printf("offset of struct's member variables... \n");
	printf(".a : %zu \n", offsetof(struct s, a));
	printf(".b : %zu \n", offsetof(struct s, b));
	printf(".c : %zu \n", offsetof(struct s, c));

	printf("holes of struct s \n");
	printf("between .a and .b : %zu \n", 
			offsetof(struct s, b) - offsetof(struct s, a) - sizeof(s1.a));
	printf("between .b and .c : %zu \n", 
			offsetof(struct s, c) - offsetof(struct s, b) - sizeof(s1.b));


	return 0;
}
