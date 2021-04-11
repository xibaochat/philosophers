#include "philo_one.h"

void	init_simulation_info(t_simu *simu, char **av)
{
	simu->die_time = (unsigned long)(ft_atoi(av[2]));
	simu->time_spend_eat = ft_atoi(av[3]);
	simu->time_spend_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&(simu->display), NULL);
	pthread_mutex_init(&(simu->dead_lock), NULL);
	if (av[5])
	{
		simu->has_option = 1;
		simu->nb_times_eat = ft_atoi(av[5]);
	}
	else
	{
		simu->has_option	= 0;
		simu->nb_times_eat = -1;
	}
	simu->has_death = 0;
}

t_simu	*init_simu(char **av)
{
	int				nb_p;
	unsigned long	start_time;
	t_simu			*simu;

	simu = (t_simu *)malloc(sizeof(t_simu));
	simu->nb_p = ft_atoi(av[1]);
	init_simulation_info(simu, av);
	return (simu);
}
