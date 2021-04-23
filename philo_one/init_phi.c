#include "philo_one.h"

void	init_phi_node_data(int i, int nb, t_phi *node, t_simu *simu)
{
	node->simu = simu;
	node->phi_id = i;
	node->actual_eat_time = 0;
	pthread_mutex_init(&(node->eat_lock), NULL);
	node->last_meal = get_actual_time();
	init_phi_fork(nb, simu->fork, node);
	node->next = NULL;
}

void	conjoin_node(int i, t_phi **current_node, t_phi **head, t_phi **prev)
{
	if (i == 0)
	{
		*head = *current_node;
		*prev = *head;
	}
	else
	{
		(*prev)->next = *current_node;
		*prev = *current_node;
	}
}

t_phi	*init_phi_node(char **av, t_simu *simu)
{
	int				i;
	t_phi			*prev;
	t_phi			*head;
	t_phi			*current_node;

	i = 0;
	current_node = NULL;
	simu->fork = init_mutex_fork(simu->nb_p);
	while (i < simu->nb_p)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		memset(current_node, 0, sizeof(t_phi));
		init_phi_node_data(i, simu->nb_p, current_node, simu);
		conjoin_node(i, &current_node, &head, &prev);
		current_node->head = head;
		i++;
	}
	return (head);
}
