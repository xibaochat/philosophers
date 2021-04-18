# include "philo_one.h"

void	destroy_mutex(t_phi *head)
{
	int	i;

	i = 0;
	while (i < head->simu->nb_p)
	{
		pthread_mutex_destroy(head->simu->fork + i);
		i++;
	}
	pthread_mutex_destroy(&head->simu->display);
}

void	ft_free_var(t_phi *head)
{
	t_phi	*tmp;

	if (head->simu)
	{
		if (head->simu->fork)
		{
			free(head->simu->fork);
			head->simu->fork = NULL;
		}
		free(head->simu);
		head->simu = NULL;
	}
	while (head)
	{
		tmp = head->next;
		pthread_mutex_destroy(&head->eat_lock);
		head->next = NULL;
		free(head);
		head = tmp;
	}
}
