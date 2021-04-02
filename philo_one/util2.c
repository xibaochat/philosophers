#include "philo_one.h"

long unsigned   get_actual_time(void)
{
    struct timeval actual;

    gettimeofday(&actual, NULL);
    return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

long unsigned   get_time_diff(long unsigned a, long unsigned b)
{
    return (a - b);
}

long unsigned   get_timestamp(long unsigned start_time)
{
    return (get_time_diff(get_actual_time(), start_time));
}

int				ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
