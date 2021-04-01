#include "philo_one.h"

static int get_next_fork_nb(int nb, int i)
{
	if (i + 1 >= nb)
		return (0);
	return (i + 1);
}

void init_phi_fork(int nb, t_fork *fork_info, int i, t_phi *node)
{

	int next_id;
	next_id = get_next_fork_nb(nb, i);
	node->left_fork = &(fork_info[next_id]);
	node->right_fork = &(fork_info[i]);
	printf("in the func init_phi_fork:L:%d R:%d\n", node->left_fork->id, node->right_fork->id);
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
