#include "philo_two.h"

void	take_forks(int i, t_phi *p)
{
		sem_wait(p->simu->fork);
		sem_wait(p->simu->fork);
		sem_wait(p->simu->display);
		if (continue_job(i, p))
		{
			printf_message(p, TAKE_FORK);
			printf_message(p, TAKE_FORK);
		}
		sem_post(p->simu->display);
}

void	p_eat(t_phi *p)
{
	sem_wait(p->simu->display);
	printf_message(p, "is eating");
	p->last_meal = get_actual_time();
	sem_post(p->simu->display);
	wait_for(p->simu->time_spend_eat);
	p->actual_eat_time++;
	sem_post(p->simu->fork);
	sem_post(p->simu->fork);
}

void	p_sleep(t_phi *p)
{
	sem_wait(p->simu->display);
	printf_message(p, "is sleeping");
	sem_post(p->simu->display);
	wait_for(p->simu->time_spend_sleep);
}

void	p_thinking(t_phi *p)
{
	sem_wait(p->simu->display);
	printf_message(p, "is thinking");
	sem_post(p->simu->display);
}

void	wait_for(long unsigned time)
{
    long unsigned start;

    start = get_actual_time();
    while (get_actual_time() - start < time)
        usleep(10);
}
