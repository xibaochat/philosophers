#include "philo_one.h"

void	init_stimulation_info(t_stimu *sti, char **av)
{
	sti->die_time = ft_atoi(av[2]);
	sti->time_spend_eat = ft_atoi(av[3]);
	sti->time_spend_sleep = ft_atoi(av[4]);
	if (av[5])
		sti->nb_times_eat = ft_atoi(av[5]);
	else
		sti->nb_times_eat = 0;
	sti->has_death = 0;
}

t_stimu	*init_stimu_thread(char **av)
{
	unsigned long	start_time;
	t_stimu			*phi_stimu;

	phi_stimu = (t_stimu *)malloc(sizeof(t_stimu));
	phi_stimu->start_time = get_actual_time();
	init_stimulation_info(phi_stimu, av);
	return (phi_stimu);
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
	t_fork	*fork_info;
	t_phi	*head;
	t_stimu	*phi_stimu;
	int		v;

	v = valid_input(ac, av);
	if (v)
		return (0);
	nb = ft_atoi(av[1]);
	fork_info = init_fork(nb);
	phi_stimu = init_stimu_thread(av);
	head = create_node_list(fork_info, nb, av, phi_stimu);
	ft_create_thread(head);
	tmp = head;
	while (tmp)
	{
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(fork_info[i].mutex));
		i++;
	}
	write(0, "ici2\n", 5);
	/* ft_free_var(head, fork_info); */
	/* free(phi_stimu); */
	return (0);
}
