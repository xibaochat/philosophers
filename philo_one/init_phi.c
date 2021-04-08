#include "philo_one.h"

static int	get_next_fork_nb(int nb, int i)
{
	if (i + 1 >= nb)
		return (0);
	return (i + 1);
}

pthread_mutex_t	*init_mutex_fork(int nb)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb);
	if (!fork)
		return (NULL);
	while (i < nb)
		pthread_mutex_init(&fork[i++], NULL);
	return (fork);
}

void	init_phi_fork(int nb, pthread_mutex_t *f, t_phi *node)
{
	int				next_id;

	next_id = get_next_fork_nb(nb, node->phi_id);
	node->left_fork = &(f[next_id]);
	node->right_fork = &(f[node->phi_id]);
}

t_phi	*create_node_list(pthread_mutex_t *f, int nb, char **av, t_simu *simu)
{
	int				i;
	t_phi			*prev;
	t_phi			*head;
	t_phi			*current_node;

	i = 0;
	current_node = NULL;
	while (i < nb)
	{
		current_node = (t_phi *)malloc(sizeof(t_phi));
		init_phi_fork(nb, f, current_node);
		current_node->simu = simu; //init_simu_thread(av);
		current_node->phi_id = i;
		current_node->actual_eat_time = 0;
		current_node->last_meal = 0;
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
