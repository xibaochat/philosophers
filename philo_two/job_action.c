#include "philo_two.h"

void	eat(t_phi *p)
{
	sem_wait(p->simu->fork);
	//printf("I am in eating000\n");
	if (p->simu->has_death)
	{
		sem_post(p->simu->fork);
		return ;
	}
	printf_message(p, TAKE_FORK);
	//printf("I am in eating111\n");
	sem_wait(p->simu->fork);
	//printf("I am in eating222\n");
	printf_message(p, TAKE_FORK);
	//printf("I am in eating333\n");
	if (!p->simu->has_death)
	{
		//printf("I am in eating444\n");
		sem_wait(p->eating);
		//printf("I am in eating555\n");
		printf_message(p, "is eating");
		//printf("I am in eating666\n");
		p->last_meal = get_actual_time();
		//printf("I am in eating777\n");
		wait_for(p->simu->time_spend_eat);
		//printf("I am in eating888\n");
		sem_post(p->eating);
		//printf("I am in eating999\n");
		p->actual_eat_time++;
	}
	//printf("I am in eating end\n");
	sem_post(p->simu->fork);
	//printf("I am in eating end000\n");
	sem_post(p->simu->fork);
	//printf("I am in eating end111\n");
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
