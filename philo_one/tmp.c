#include "philo_one.h"

int	eat(t_phi *phi_i, pthread_mutex_t  *current, pthread_mutex_t *next)
{
	unsigned long	s_t;
	unsigned long	t1;

	s_t = phi_i->simu->start_time;
	if (phi_i->actual_eat_time)
		printf("%ld %d is thinking\n", get_timestamp(s_t), phi_i->phi_id + 1);
	if (someone_died(phi_i))
	{
		pthread_mutex_unlock(current);
		return (0);
	}
	/* --- FIRST FORK --- */
	pthread_mutex_lock(current);
	if (someone_died(phi_i))
	{
		pthread_mutex_unlock(current);
		return (0);
	}
//	printf("%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);

	/* --- SCD FORK --- */
	pthread_mutex_lock(next);
	if (someone_died(phi_i))
	{
		pthread_mutex_unlock(next);
		return (0);
	}
	printf("%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);
	printf("%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);
	// ACUTALLY EATING
	printf("%ld %d is eating\n", get_timestamp(s_t), phi_i->phi_id + 1);
	phi_i->last_meal = get_timestamp(s_t);
	usleep(phi_i->simu->time_spend_eat * 1000);
	pthread_mutex_unlock(current);
	pthread_mutex_unlock(next);
	if (someone_died(phi_i))
		return (0);
	phi_i->actual_eat_time++;
	printf("%ld %d is sleeping\n", get_timestamp(s_t), phi_i->phi_id + 1);
	usleep(phi_i->simu->time_spend_sleep * 1000);
//	printf("%ld finish sleepng\n", get_timestamp(s_t));
	if (someone_died(phi_i))
		return (0);
	return(1);
}

void	*job(void *arg)
{
	t_phi			*phi_i;
	pthread_mutex_t			*next;
	pthread_mutex_t			*current;
	unsigned long	s_t;
	int				eat_enough_times;

	phi_i = (t_phi *)arg;
	eat_enough_times = 0;
	current = get_current_fork(phi_i);
	next = get_next_fork(phi_i);
	s_t = phi_i->simu->start_time;
	while (1)
	{
		eat_enough_times = meals_times_reach_max(phi_i);
		if (eat_enough_times)
			break;
		if (someone_died(phi_i))
			break;
		if (!eat(phi_i, current, next))
			break;
	}
}
