#include <stdio.h>

#define SIZEOF(X) (sizeof(X) / sizeof(X[0]))

typedef struct  {
	char *country;
	int code;
} dialing_code;

const dialing_code country_codes[] = {
	{"Argentina",			 54}, {"Bangladesh",			880},
	{"Brazil",				 55}, {"Burma (Myanmar)",		 95},
	{"China",				 86}, {"Colombia",				 57},
	{"Congo, Dem. Rep. of", 243}, {"Egypt",					 20},
	{"Ethiopia",			251}, {"France",				 33},
	{"Germany",				 49}, {"India",					 91},
	{"Indonesia",			 62}, {"Iran",					 98},
	{"Italy",				 39}, {"Japan",					 81},
	{"Mexico",				 52}, {"Nigeria",				234},
	{"Pakistan",			 92}, {"Philippines",			 63},
	{"Poland",				 48}, {"Russia",				  7},
	{"South Africa",		 27}, {"South Korea",			 82},
	{"Spain",				 34}, {"Sudan",					249},
	{"Thailand",			 66}, {"Turkey",				 90},
	{"Ukraine",				380}, {"United Kingdom",		 44},
	{"United States",		  1}, {"Vietnam",				 84}
};

const char *country_code_to_name(int code)
{
	for (int k = 0; k < SIZEOF(country_codes); k++)
		if (country_codes[k].code == code)
			return country_codes[k].country;

	return "Not founded";
}

int main(void)
{
	int code;

	fputs("Enter country code: ", stdout);
	scanf("%d", &code);

	printf("country name: %s \n", country_code_to_name(code));

	return 0;
}
