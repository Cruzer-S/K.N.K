#include <stdio.h>
#include <stdlib.h>

#define FILENAME "flights.dat"

#define ERROR_HANDLING(MSG, ...) {				\
	fprintf(stderr, MSG "\n", ## __VA_ARGS__);	\
	exit(EXIT_FAILURE);							\
}

#define AMPM(HOUR) ((HOUR) < 12 ? "a.m." : "p.m.")
#define TO12(HOUR) ((HOUR) > 12 ? HOUR - 12 : HOUR)
#define ABS(X)	   ((X < 0) ? -X : X)
#define FOR(BASE, INIT, COND, INCR)						\
		for((BASE), INIT;								\
			(BASE), COND;								\
			(BASE), INCR)

struct time {
	int hour;
	int minute;
};

struct flight_time {
	struct time depart;
	struct time arrive;
};

struct time    read_time(FILE *);
struct flight_time read_flight_time(FILE *);

int time_gap(struct time, struct time);
void show_time(struct time );

int main(void)
{
	struct time desire;
	FILE *fp;

	fp = fopen(FILENAME, "r");
	if (fp == NULL)
		ERROR_HANDLING("failed to open file %s", FILENAME);

	printf("Enter a 24-hour time: ");
	desire = read_time(stdin);

	for (struct flight_time 
		 prev = read_flight_time(fp),
		 cur  = read_flight_time(fp);
		 /* No condition */ ;
		 prev = cur,
		 cur  = read_flight_time(fp))
	{
		if (time_gap(desire, prev.depart)
		<=  time_gap(desire, cur.depart)) 
		{
			printf("Closest departure time is ");
			show_time(prev.depart);
			printf(", arriving at ");
			show_time(prev.arrive);
			printf("\n");
			break;
		}
	}
	
	fclose(fp);

	return 0;
}

void show_time(struct time t)
{
	printf("%d:%.2d %s", TO12(t.hour), t.minute, AMPM(t.hour));
}

int time_gap(struct time t1, struct time t2)
{
	int ret = 0;

	ret = ((t1.hour * 60) + t1.minute) 
		- ((t2.hour * 60) + t2.minute);

	return ABS(ret);
}

struct time read_time(FILE *fp)
{
	struct time t;

	fscanf(fp, "%d:%d", &t.hour, &t.minute);

	if (t.hour   < 0 || t.hour   > 23
	||  t.minute < 0 || t.minute > 59)
		ERROR_HANDLING("invalid form; failed to extract time");

	return t;
}

struct flight_time read_flight_time(FILE *fp)
{
	struct flight_time t;

	t.depart = read_time(fp);
	t.arrive = read_time(fp);

	return t;
}
