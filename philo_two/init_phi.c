#include "philo_two.h"

int	init_phi_sem(int i, t_phi *phi)
{
	char	*phi_n;

	phi_n = ft_itoa(i);
	if (phi_n)
	{
		phi->name = ft_strjoin("eat_phi_", ft_itoa(i));
		free(phi_n);
		sem_unlink(phi->name);
		phi->eating = sem_open(phi->name, O_CREAT | O_EXCL, S_IRWXU, 1);
		if (phi->eating == SEM_FAILED)
		{
			sem_unlink(phi->name);
			return (1);
		}
		return (0);
	}
}

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
		if (init_phi_sem(i, current_node))
			return (NULL);
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
