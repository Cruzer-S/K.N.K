#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int stricmp(char *p, char *q)
{
	while (*p != '\0' && *q != '\0' && toupper(*p) == toupper(*q)) p++,q++;
	return (*p == '\0' && *q == '\0') ? 0 : (*p - *q);
}

int main(int argc, char *argv[])
{
	char *planets[] = {
		"Mercury", "Venus", "Earth", 
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto"
	};

	for (int i = 1, check = 0; i < argc; i++, check = 0) {
		for (int j = 0; j < NUM_PLANETS; j++) {
			if (stricmp(argv[i], planets[j]) == 0) {
				printf("%s is planet %d \n", argv[i], j + 1);
				check = 1;
				break;
			}
		}

		if (check == 0)
			printf("%s is not a planet \n", argv[i]);
	}

	return 0;
}
