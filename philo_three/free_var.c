#include "philo_three.h"

void	close_sem(t_phi *head)
{
	sem_close(head->simu->fork);
	sem_close(head->simu->display);
	while (head)
	{
		sem_close(head->eating);
		sem_unlink(head->name);
		head = head->next;
	}
	sem_unlink("fork");
	sem_unlink("display");
}

void	ft_free_var(t_phi *head)
{
	t_phi	*tmp;

	close_sem(head);
	if (head->simu->pid)
	{
		free(head->simu->pid);
		head->simu->pid = NULL;
	}
	if (head->simu)
	{
		free(head->simu);
		head->simu = NULL;
	}
	while (head)
	{
		tmp = head->next;
		free(head->name);
		head->name = NULL;
		head->next = NULL;
		free(head);
		head = tmp;
	}
}
