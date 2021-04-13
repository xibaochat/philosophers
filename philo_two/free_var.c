# include "philo_two.h"

void	close_sem(t_phi *head)
{
	sem_close(head->simu->fork);
	sem_close(head->simu->display);
	sem_close(head->simu->death);
}

void	ft_free_var(t_phi *head)
{
	t_phi	*tmp;

	close_sem(head);
	if (head->simu)
	{
		free(head->simu);
		head->simu = NULL;
	}
	while (head)
	{
		tmp = head->next;
		head->next = NULL;
		free(head);
		head = tmp;
	}
}
