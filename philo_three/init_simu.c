/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_var_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:07 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 16:39:08 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		init_fork_display(t_simu *simu)
{
	sem_unlink("fork");
	sem_unlink("display");
	simu->fork = sem_open("fork", O_CREAT, S_IRWXU, simu->nb_p);
	simu->display = sem_open("display", O_CREAT, S_IRWXU, 1);
	if (simu->fork == SEM_FAILED)
	{
		sem_unlink("fork");
		return (1);
	}
	if (simu->display == SEM_FAILED)
	{
		sem_unlink("display");
		return (1);
	}
	return (0);
}

void	init_simulation_info(t_simu *simu, char **av)
{
	simu->die_time = (unsigned long)(ft_atoi(av[2]));
	simu->time_spend_eat = ft_atoi(av[3]);
	simu->time_spend_sleep = ft_atoi(av[4]);
	simu->finish_meal = 0;
	simu->is_died = 0;
	if (av[5])
	{
		simu->has_option = 1;
		simu->nb_times_eat = ft_atoi(av[5]);
	}
	else
	{
		simu->has_option = 0;
		simu->nb_times_eat = -1;
	}
	simu->has_death = 0;
}

t_simu	*init_simu(char **av)
{
	t_simu			*simu;

	simu = (t_simu *)malloc(sizeof(t_simu));
	if (!simu)
		return (NULL);
	memset(simu, 0, sizeof(t_simu));
	simu->nb_p = ft_atoi(av[1]);
	init_simulation_info(simu, av);
	if (init_fork_display(simu))
	{
		printf("Failed in sem initialization\n");
		return (NULL);
	}
	simu->pid = (pid_t *)malloc(sizeof(pid_t) * simu->nb_p);
	memset(simu->pid, 0, sizeof(pid_t) * simu->nb_p);
	return (simu);
}
