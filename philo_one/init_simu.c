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

#include "philo_one.h"

void	init_simulation_info(t_simu *simu, char **av)
{
	simu->die_time = (unsigned long)(ft_atoi(av[2]));
	simu->time_spend_eat = ft_atoi(av[3]);
	simu->time_spend_sleep = ft_atoi(av[4]);
	pthread_mutex_init(&(simu->display), NULL);
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
	simu->nb_p = ft_atoi(av[1]);
	init_simulation_info(simu, av);
	return (simu);
}
