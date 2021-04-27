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

void	lock_and_display_time(t_phi *phi)
{
	phi->simu->has_death = 1;
	phi->simu->is_died = 1;
	pthread_mutex_lock(&phi->eat_lock);
	pthread_mutex_lock(&phi->simu->display);
	printf("%ld %d died\n", \
		get_timestamp(phi->simu->start_time), phi->phi_id + 1);
	pthread_mutex_unlock(&phi->eat_lock);
	pthread_mutex_unlock(&phi->simu->display);
}

void	*monitoring(void *arg)
{
	t_phi			*phi;
	unsigned long	t;

	phi = (t_phi *)arg;
	while (phi && !phi->simu->has_death)
	{
		if (phi->simu->is_died)
			break ;
		t = get_timestamp(phi->last_meal);
		if (t > phi->simu->die_time)
		{
			lock_and_display_time(phi);
			break ;
		}
		if (!phi->next)
			phi = phi->head;
		else
			phi = phi->next;
		usleep(1000);
	}
	return (NULL);
}
