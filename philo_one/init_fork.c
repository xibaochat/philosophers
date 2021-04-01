#include "philo_one.h"

void init_phi_fork(int nb, t_fork *fork_info, int i, t_phi *node)
{

	if (i == nb - 1)
		node->left_fork = &(fork_info[0]);
	else
		node->left_fork = &(fork_info[i + 1]);
	node->right_fork = &(fork_info[i]);
	printf("%d %d\n", node->left_fork->id, node->right_fork->id);
}

t_fork* init_fork(int nb)
{
	int i;
	t_fork *fork;

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
