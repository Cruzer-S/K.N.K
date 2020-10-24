#include <stdio.h>
#include <stdbool.h>

#define SSIZE(T)	(sizeof((T)) / sizeof((T[0])))
#define ABS(X)		((X) < 0 ? -(X) : (X))

struct flight_time {
	int departure_time;
	int arrival_time;
} const flight_time_set[] = {
	{ 8  * 60 +  0, 10 * 60 + 16 }, {  9 * 60 + 43, 11 * 60 + 52 },
	{ 11 * 60 +  0, 13 * 60 + 31 }, { 12 * 60 + 47, 15 * 60 +  0 },
	{ 14 * 60 +  0, 16 * 60 +  8 }, { 15 * 60 + 45, 17 * 60 + 55 },
	{ 19 * 60 +  0, 21 * 60 + 20 }, { 21 * 60 + 45, 23 * 60 + 58 }
};

struct time {
	int hours;
	int minutes;
	bool isAM;
};

int get_time(void)
{
	int hours, minutes;

	scanf("%d:%d", &hours, &minutes);

	return hours * 60 + minutes;
}

struct time split_time(int minutes)
{	
	struct time ret;

	ret.hours = minutes / 60;
	ret.minutes = minutes % 60;

	if (ret.hours < 12)	ret.isAM = true;
	else				ret.isAM = false;

	if (ret.hours > 12) ret.hours %= 12;

	return ret;
}

void show_flight_time(struct flight_time ftime)
{
	struct time dep_hm, arr_hm;

	dep_hm = split_time(ftime.departure_time), arr_hm = split_time(ftime.arrival_time);

	printf("Closest departure time is %d:%02d %s, arriving at %d:%02d p.m. \n",
			dep_hm.hours, dep_hm.minutes, (dep_hm.isAM) ? "a.m." : "p.m.",
			arr_hm.hours, arr_hm.minutes, (arr_hm.isAM) ? "a.m." : "p.m."
	);
}

int main(void)
{
	int depart, position, relative;

	fputs("Enter a 24-hour time: ", stdout);
	depart = get_time();

	relative = ABS(flight_time_set[position = 0].departure_time - depart);

	for (int k = 1; k < SSIZE(flight_time_set); k++)
		if (ABS(flight_time_set[k].departure_time - depart) < relative)
			relative = ABS(flight_time_set[position = k].departure_time - depart);
	
	show_flight_time(flight_time_set[position]);

	return 0;
}
