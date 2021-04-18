#include "philo_two.h"

void	eat(t_phi *p)
{
	sem_wait(p->simu->fork);
	if (p->simu->has_death)
	{
		sem_post(p->simu->fork);
		return ;
	}
	printf_message(p, TAKE_FORK);
	sem_wait(p->simu->fork);
	printf_message(p, TAKE_FORK);
	if (!p->simu->has_death)
	{
		sem_wait(p->eating);
		printf_message(p, "is eating");
		p->last_meal = get_actual_time();
		wait_for(p->simu->time_spend_eat);
		sem_post(p->eating);
		p->actual_eat_time++;
	}
	sem_post(p->simu->fork);
	sem_post(p->simu->fork);
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
    long unsigned start;

    start = get_actual_time();
    while (get_actual_time() - start < time)
        usleep(10);
}
