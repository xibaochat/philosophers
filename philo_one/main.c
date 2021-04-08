#include "philo_one.h"

void	init_simulation_info(t_simu *sti, char **av)
{
	sti->die_time = (unsigned long)(ft_atoi(av[2]));
	sti->time_spend_eat = ft_atoi(av[3]);
	sti->time_spend_sleep = ft_atoi(av[4]);
	if (av[5])
		sti->nb_times_eat = ft_atoi(av[5]);
	else
		sti->nb_times_eat = -1;
	sti->has_death = 0;
}

t_simu	*init_simu_thread(char **av)
{
	unsigned long	start_time;
	t_simu			*phi_simu;

	phi_simu = (t_simu *)malloc(sizeof(t_simu));
	phi_simu->start_time = get_actual_time();
	init_simulation_info(phi_simu, av);
	return (phi_simu);
}

void	ft_create_thread(t_phi *phi)
{
	while (phi)
	{
		pthread_create(&phi->thread, NULL, &job, phi);
		phi = phi->next;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		nb;
	t_phi	*tmp;
	t_phi	*head;
	t_simu	*phi_simu;
	int		v;
	pthread_mutex_t *fork;

	v = valid_input(ac, av);
	if (v)
		return (0);
	nb = ft_atoi(av[1]);
	phi_simu = init_simu_thread(av);
	fork = init_mutex_fork(nb);
	head = create_node_list(fork, nb, av, phi_simu);
	ft_create_thread(head);
	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	/* write(0, "ici2\n", 5); */
	/* ft_free_var(head, fork_info); */
	/* free(phi_simu); */
	return (0);
}
