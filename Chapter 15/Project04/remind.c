#include <stdio.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 3];
	int num_remind;

	for (;;) {
		char daytime_str[15], msg_str[MSG_LEN + 1];
		int month, day, time;

		if (num_remind == MAX_REMIND) {
			fputs("-- No space left -- \n", stdout);
			break;
		}

		fputs("Enter month/day, time and reminder: ", stdout);
		scanf("%d/%d", &month, &day);
		if (month == 0 || day == 0) {
			break;
		} else if ((  day < 0 ||   day > 31)
				&& (month < 1 || month > 12)) {
			fputs("month must be between 1 to 12 and day between 0 to 31! - ignore \n", stdout);
			while ( getchar() != '\n' );
			continue;
		}

		scanf("%d", &time);
		if (time < 0 || time > 24) {
			fputs("time must be between 0 to 24! - ignore \n", stdout);
			while ( getchar() != '\n' );
			continue;
		}
		
		sprintf(daytime_str, "  %2d / %2d   %2d", month, day, time);

		read_line(msg_str, MSG_LEN);

		int i, j;
		for (i = 0; i < num_remind; i++) 
			if (strcmp(daytime_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);
		
		strcpy(reminders[i], daytime_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	fputs("\nMonth/day Time Reminder\n", stdout);
	for (int k = 0; k < num_remind; k++)
		printf("%s\n", reminders[k]);

	return 0;
}


