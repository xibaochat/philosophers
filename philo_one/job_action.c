#include "philo_one.h"

void	p_eat(t_phi *p, pthread_mutex_t *fst, pthread_mutex_t *scd)
{
	pthread_mutex_lock(fst);
	pthread_mutex_lock(scd);
	if (p->simu->has_death)
	{
		pthread_mutex_unlock(fst);
		pthread_mutex_unlock(scd);
		return ;
	}
	printf_message(p, TAKE_FORK);
	printf_message(p, TAKE_FORK);
	pthread_mutex_lock(&p->eat_lock);
	if (!p->simu->has_death)
	{
		printf_message(p, "is eating");
		p->last_meal = get_actual_time();
		wait_for(p->simu->time_spend_eat);
		p->actual_eat_time++;
	}
	pthread_mutex_unlock(fst);
	pthread_mutex_unlock(scd);
	pthread_mutex_unlock(&p->eat_lock);
}

void	p_sleep(t_phi *p)
{
	printf_message(p, "is sleeping");
	wait_for(p->simu->time_spend_sleep);
}

void	p_thinking(t_phi *p)
{
	printf_message(p, "is thinking");
}

void	wait_for(long unsigned time)
{
	long unsigned	start;

	start = get_actual_time();
	while (get_actual_time() - start < time)
		usleep(10);
}
