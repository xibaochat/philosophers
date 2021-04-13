#include "philo_two.h"

void	init_phi_node_data(int i, int nb, t_phi *node, t_simu *simu)
{
		node->simu = simu; //init_simu_thread(av);
		node->phi_id = i;
		node->actual_eat_time = 0;
		node->last_meal = get_actual_time();
		node->next = NULL;
}

t_phi	*init_phi_node(char **av, t_simu *simu)
{
	int				i;
	t_phi			*prev;
	t_phi			*head;
	t_phi			*current_node;

	i = 0;
	current_node = NULL;
	while (i < simu->nb_p)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		memset(current_node, 0, sizeof(current_node));
		init_phi_node_data(i, simu->nb_p, current_node, simu);
		if (i == 0)
		{
			head = current_node;
			prev = head;
		}
		else
		{
			prev->next = current_node;
			prev = current_node;
		}
		current_node->head = head;
		i++;
	}
	return (head);
}
