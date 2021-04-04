#include "philo_one.h"

void	eat(t_phi *phi_i, t_fork  *current, t_fork  *next)
{
	unsigned long	s_t;
	unsigned long	t1;

	s_t = phi_i->simu->start_time;
	pthread_mutex_lock(&(current->mutex));
	printf("in_ms:%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);
	pthread_mutex_lock(&(next->mutex));
	printf("in_ms:%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);
	if (!phi_i->simu->has_death)
	{
		if ((phi_i->actual_eat_time
			&& get_timestamp(phi_i->last_meal) > phi_i->simu->die_time)
			|| (!phi_i->actual_eat_time
				&& get_timestamp(s_t) > phi_i->simu->die_time))
		{
			pthread_mutex_unlock(&(current->mutex));
			pthread_mutex_unlock(&(next->mutex));
			phi_i->simu->has_death = 1;
			return ;
		}
		printf("in_ms:%ld %d is eating\n", get_timestamp(s_t), phi_i->phi_id + 1);
		phi_i->last_meal = get_actual_time();
		usleep(phi_i->simu->time_spend_eat);
	}
	pthread_mutex_unlock(&(current->mutex));
	pthread_mutex_unlock(&(next->mutex));
	phi_i->actual_eat_time++;

}

void	*job(void *arg)
{
	t_phi			*phi_i;
	t_fork			*next;
	t_fork			*current;
	unsigned long	s_t;

	phi_i = (t_phi *)arg;
	if (phi_i->phi_id % 2)
	{
		next = phi_i->left_fork;
		current = phi_i->right_fork;
	}
	else
	{
		next = phi_i->right_fork;
		current = phi_i->left_fork;
	}
	s_t = phi_i->simu->start_time;
	while (1 && !phi_i->simu->has_death)
	{
		eat(phi_i, current, next);
		if ((phi_i->simu->nb_times_eat
			&& phi_i->actual_eat_time >= phi_i->simu->nb_times_eat)
			|| phi_i->simu->has_death)
		{
			printf("in_ms:%ld %d is dead\n", get_timestamp(s_t), phi_i->phi_id + 1);
			break;
		}
		printf("in_ms:%ld %d is sleeping\n", get_timestamp(s_t), phi_i->phi_id + 1);
		usleep(phi_i->simu->time_spend_sleep);
		printf("in_ms:%ld %d is thinking\n", get_timestamp(s_t), phi_i->phi_id + 1);
	}
}
