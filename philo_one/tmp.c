#include "philo_one.h"

/*
** Check if too much time has passed between the last meal and
** the philo's next one
*/
int died_before_next_meal(t_phi *phi_i, unsigned long   s_t)
{
	return (phi_i->actual_eat_time &&
			(get_timestamp(phi_i->last_meal) > phi_i->simu->die_time));
}

/*
** Check if too much time has passed between the beginning of the
** simulation and the philo's first meal
*/
int died_before_first_meal(t_phi *phi_i, unsigned long   s_t)
{
	/* printf("[%d] %ld | %ld\n\n", phi_i->phi_id + 1, get_timestamp(s_t), phi_i->simu->die_time); */
	return (!phi_i->actual_eat_time && (get_timestamp(s_t) > phi_i->simu->die_time));
}

int someone_died(t_phi *phi_i)
{
	return (phi_i->simu->has_death);
}

/*
** Check if current philosopher have already eaten maximum allowed time
*/
int have_eaten_min_times(t_phi *phi_i)
{
	return (phi_i->simu->nb_times_eat &&
			phi_i->actual_eat_time >= phi_i->simu->nb_times_eat);
}

int	eat(t_phi *phi_i, t_fork  *current, t_fork  *next)
{
	unsigned long	s_t;
	unsigned long	t1;

	s_t = phi_i->simu->start_time;
	if (phi_i->actual_eat_time)
		printf("%ld %d is thinking\n", get_timestamp(s_t), phi_i->phi_id + 1);

	/* --- FIRST FORK --- */
	pthread_mutex_lock(&(current->mutex));
	if (someone_died(phi_i))
		return (0);
	if (died_before_first_meal(phi_i, s_t) || died_before_next_meal(phi_i, s_t))
	{
		if (!someone_died(phi_i))
			printf("FIRST %ld %d is dead\n", get_timestamp(s_t), phi_i->phi_id + 1);
		phi_i->simu->has_death = 1;
		/* printf("ALREADY DEAD\n"); */
		pthread_mutex_unlock(&(current->mutex));
		return (0);
	}
	printf("%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);

	/* --- SCD FORK --- */
	pthread_mutex_lock(&(next->mutex));
	if (someone_died(phi_i))
		return (0);
	if (died_before_first_meal(phi_i, s_t) || died_before_next_meal(phi_i, s_t))
	{
		if (!someone_died(phi_i))
			printf("SCD %ld %d is dead\n", get_timestamp(s_t), phi_i->phi_id + 1);
		phi_i->simu->has_death = 1;
		/* printf("ALREADY DEAD\n"); */
		pthread_mutex_unlock(&(current->mutex));
		pthread_mutex_unlock(&(next->mutex));
		return (0);
	}
	printf("%ld %d has taken a fork\n", get_timestamp(s_t), phi_i->phi_id + 1);

	// ACUTALLY EATING
	printf("%ld %d is eating\n", get_timestamp(s_t), phi_i->phi_id + 1);
	phi_i->last_meal = get_actual_time();
	/* usleep((useconds_t)(phi_i->simu->time_spend_eat) * 1000); */
	usleep(phi_i->simu->time_spend_eat * 1000);
	/* printf("%ld %d is DONE eating\n", get_timestamp(s_t), phi_i->phi_id + 1); */

	printf("%ld %d is sleeping\n", get_timestamp(s_t), phi_i->phi_id + 1);
	pthread_mutex_unlock(&(current->mutex));
	pthread_mutex_unlock(&(next->mutex));
	phi_i->actual_eat_time++;

	/* usleep((useconds_t)(phi_i->simu->time_spend_sleep) * 1000); */
	usleep(phi_i->simu->time_spend_sleep * 1000);
	return(1);
}

int all_philo_ate_min_meals(t_phi *phi_i)
{
	t_phi *link;

	link = phi_i->head;
	while (link)
	{
		if (link->actual_eat_time < link->simu->nb_times_eat)
			return (0);
		link = link->next;
	}
	return (1);
}

void	*job(void *arg)
{
	t_phi			*phi_i;
	t_fork			*next;
	t_fork			*current;
	unsigned long	s_t;

	/* printf("HERE\n"); */
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
	while (!someone_died(phi_i) && !all_philo_ate_min_meals(phi_i))
	{
		if (!eat(phi_i, current, next))
			break;
		if (someone_died(phi_i))
			break;
		if (all_philo_ate_min_meals(phi_i))
		{
			/* printf("%ld %d: all philo eat all their meals\n", */
			/* 	   get_timestamp(s_t), phi_i->phi_id + 1); */
			break;
		}
	}
}
