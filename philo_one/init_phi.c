#include "philo_one.h"

static int	get_next_fork_nb(int nb, int i)
{
	if (i + 1 >= nb)
		return (0);
	return (i + 1);
}

void	init_phi_fork(int nb, t_fork *fork_info, int i, t_phi *node)
{
	int	next_id;

	next_id = get_next_fork_nb(nb, i);
	node->left_fork = &(fork_info[next_id]);
	node->right_fork = &(fork_info[i]);
}

t_phi	*create_node_list(t_fork *fork_info, int nb, char **av, t_simu *simu)
{
	int		i;
	t_phi	*prev;
	t_phi	*head;
	t_phi	*current_node;

	i = 0;
	current_node = NULL;
	while (i < nb)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		current_node->simu = simu; //init_simu_thread(av);
		current_node->phi_id = i;
		current_node->actual_eat_time = 0;
		current_node->last_meal = 0;
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
		current_node->head = head;
		i++;
	}
	return (head);
}
