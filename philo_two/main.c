#include "philo_two.h"

int	monitoring_threads(t_phi *phi)
{
	pthread_t	monitor;
	if (pthread_create(&monitor, NULL, &monitoring, phi))
		return (1);
	if (pthread_join(monitor, NULL))
		return (1);
	return (0);
}

int	create_philosophers_threads(t_phi   *phi)
{
	int		i;
	t_phi	*tmp;

	tmp = phi;
	phi->simu->start_time = get_actual_time();
	i = -1;
	while (phi && ++i < phi->simu->nb_p)
	{
		if (!(i % 2))
			if (pthread_create(&(phi->thread), NULL, &job, phi))
				return (1);
		usleep(70);
		phi = phi->next;
	}
	i = -1;
	phi = tmp;
	while (phi && ++i < phi->simu->nb_p)
	{
		if (i % 2)
			if (pthread_create(&(phi->thread), NULL, &job, phi))
				return (1);
		usleep(70);
		phi = phi->next;
	}
	return (0);
}

int	terminate_philosopher_threads(t_phi *phi)
{
	int	i;

	i = -1;
	while (phi && ++i < phi->simu->nb_p)
	{
//		printf("xibao\n");
		if (pthread_detach(phi->thread))
			return (1);
		phi = phi->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		err_input;
	t_phi	*phi;
	t_simu	*simu;

	err_input = valid_input(ac, av);
	if (err_input)
		return (1);
	simu = init_simu(av);
	if (!simu)
		return (1);
	phi = init_phi_node(av, simu);
	if (!phi)
		return (1);
//	printf("maobe000\n");
	if (create_philosophers_threads(phi))
		return (err_create_thread(phi, P_THREAD_ERR));
//	printf("maobe111\n");
	if (monitoring_threads(phi))
		return (err_create_thread(phi, MONITOR_THREAD_ERR));
//	printf("maobe222\n");
	if (terminate_philosopher_threads(phi))
	{
		return (err_terminate_thread(phi));
	}
//	printf("maobe333\n");
	ft_free_var(phi);
	return (0);
}
