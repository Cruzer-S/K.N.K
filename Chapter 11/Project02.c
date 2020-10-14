#include <stdio.h>

void find_closest_flight(int desired_time,
						 int *departure_time,
						 int *arrival_time);

int main(void)
{
	int hour, minute, desired_time;
	int departure, arrival;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	// printf("hour: %d\tminute: %d\n", hour, minute);
	desired_time = hour * 60 + minute;

	find_closest_flight(desired_time, &departure, &arrival);

	printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s \n",
			(departure / 60) > 12 ? (departure / 60) % 12: (departure / 60), departure % 60, (departure / 60) >= 12 ? "p.m." : "a.m.",
			(arrival / 60) > 12 ? (arrival / 60) % 12 : (arrival / 60), arrival % 60, (arrival / 60) >= 12 ? "p.m." : "a.m.");

	return 0;
}

void find_closest_flight(int desired_time,
						 int *departure_time,
						 int *arrival_time)
{
	const int departure_time_table[8] = {
		( 8 * 60) +  0,
		( 9 * 60) + 43,
		(11 * 60) + 19,
		(12 * 60) + 47,
		(14 * 60) +  0,
		(15 * 60) + 45,
		(19 * 60) +  0,
		(21 * 60) + 45
	}, arrival_time_table[8]    = {
		(10 * 60) + 16,
		(11 * 60) + 52,
		(13 * 60) + 31,
		(15 * 60) +  0,
		(16 * 60) +  8,
		(17 * 60) + 55,
		(21 * 60) + 20,
		(23 * 60) + 58
	};

	for (int i = 1; i < 8; i++) {
		if (desired_time < departure_time_table[i]) {
			if ( (desired_time - departure_time_table[i - 1]) < (departure_time_table[i] - desired_time) ) { 
				*departure_time = departure_time_table[i - 1];
				*arrival_time = arrival_time_table[i - 1];
			} else {
				*departure_time = departure_time_table[i];
				*arrival_time = arrival_time_table[i];
			}
			break;
		}
	}
}
