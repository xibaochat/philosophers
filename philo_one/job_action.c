#include "philo_one.h"

void	take_forks(int i, t_phi *p, pthread_mutex_t *fst, pthread_mutex_t *scd)
{
		pthread_mutex_lock(fst);
		pthread_mutex_lock(scd);
		pthread_mutex_lock(&p->simu->display);
		if (continue_job(i, p))
		{
			printf_message(p, TAKE_FORK);
			printf_message(p, TAKE_FORK);
		}
		pthread_mutex_unlock(&p->simu->display);
}

void	p_eat(t_phi *p, pthread_mutex_t *fst, pthread_mutex_t *scd)
{
	pthread_mutex_lock(&p->simu->display);
	printf_message(p, "eating");
	p->last_meal = get_actual_time();
	pthread_mutex_unlock(&p->simu->display);
//	usleep(p->simu->time_spend_eat * 1000);
	wait_for(p->simu->time_spend_eat);
	p->actual_eat_time++;
	pthread_mutex_unlock(fst);
	pthread_mutex_unlock(scd);
}

void	p_sleep(t_phi *p)
{
	pthread_mutex_lock(&p->simu->display);
	printf_message(p, "sleeping");
	pthread_mutex_unlock(&p->simu->display);
//	usleep(p->simu->time_spend_sleep * 1000);
	wait_for(p->simu->time_spend_sleep);
}

void	p_thinking(t_phi *p)
{
	pthread_mutex_lock(&p->simu->display);
	printf_message(p, "thinking");
	pthread_mutex_unlock(&p->simu->display);
}

void	wait_for(long unsigned time)
{
    long unsigned start;

    start = get_actual_time();
    while (get_actual_time() - start < time)
        usleep(100);
}
