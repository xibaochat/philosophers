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

void	*monitoring(void *arg)
{
	t_phi			*phi;
	unsigned long	t;

	phi = (t_phi *)arg;
	while (1 && phi)
	{
		if (phi->simu->is_died)
			break ;
		t = get_timestamp(phi->last_meal);
		if (t > phi->simu->die_time)
		{
			sem_wait(phi->eating);
			phi->simu->has_death = 1;
			phi->simu->is_died = 1;
			sem_wait(phi->simu->display);
			printf("%ld %d is died\n",\
			get_timestamp(phi->simu->start_time), phi->phi_id + 1);
			sem_post(phi->eating);
			exit(0);
		}
		usleep(1000);
	}
	return (NULL);
}
