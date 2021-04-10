#include "philo_one.h"

void	take_forks(t_phi *phi_i, pthread_mutex_t  *fst_fork, pthread_mutex_t *scd_fork)
{
	pthread_mutex_lock(fst_fork);
	printf("%p %p\n",fst_fork, scd_fork);
	printf_message(phi_i, "has taken a fork");
	pthread_mutex_lock(scd_fork);
	printf_message(phi_i, "has taken a fork");
}

void	p_eat(t_phi *phi_i, pthread_mutex_t  *fst_fork, pthread_mutex_t *scd_fork)
{
	printf_message(phi_i, "eating");
	phi_i->last_meal = get_timestamp(phi_i->simu->start_time);
	usleep(phi_i->simu->time_spend_eat);
	phi_i->actual_eat_time++;
	pthread_mutex_unlock(fst_fork);
	pthread_mutex_unlock(scd_fork);
}

void	p_sleep(t_phi *phi_i)
{
	printf_message(phi_i, "sleeping");
	usleep(phi_i->simu->time_spend_sleep);
}

void	p_thinking(t_phi *phi_i)
{
	printf_message(phi_i, "thinking");
}

void	*routine(void *arg)
{
	t_phi					*phi_i;
	pthread_mutex_t			*fst_fork;
	pthread_mutex_t			*scd_fork;
	int						i;

	i = 0;
	phi_i = (t_phi *)arg;
	fst_fork = get_fst_fork(phi_i);
	scd_fork = get_scd_fork(phi_i);
	printf("%d %p %p\n", phi_i->phi_id, phi_i->left_fork, phi_i->right_fork);
	while (!phi_i->simu->has_death)// && (phi_i->simu->nb_times_eat == -1 || i < phi_i->simu->nb_times_eat))
	{
		printf("boid0\n");
		take_forks(phi_i, fst_fork, scd_fork);
		printf("boid0\n");
		p_eat(phi_i, fst_fork, scd_fork);
		printf("boid1\n");
		p_sleep(phi_i);
		printf("boid2\n");
		p_thinking(phi_i);
		printf("boid3\n");
	}
}
