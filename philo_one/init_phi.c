#include "philo_one.h"

t_phi* create_node_list(t_fork *fork_info, int nb)
{
	int i;
	t_phi *prev;
	t_phi *head;
	t_phi *current_node;

	i = 0;
	current_node = NULL;
	while (i < nb)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		current_node->phi_id = i;
		init_phi_fork(nb, fork_info, i, current_node);
		current_node->next = NULL;
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
		i++;
	}
	return (head);
}
