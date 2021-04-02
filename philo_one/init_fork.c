#include "philo_one.h"

t_fork	*init_fork(int nb)
{
	int		i;
	t_fork	*fork;

	i = 0;
	fork = (t_fork *)malloc(sizeof(t_fork) * nb);
	while (i < nb)
	{
		fork[i].id = i;
		fork[i].in_use = 0;
		pthread_mutex_init(&fork[i].mutex, NULL);
		i++;
	}
	return (fork);
}
