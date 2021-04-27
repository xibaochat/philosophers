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

#include "philo_two.h"

void	*job(void *arg)
{
	t_phi			*phi;

	phi = (t_phi *)arg;
	while (1 && !phi->simu->has_death)
	{
		eat(phi);
		if (phi->simu->has_death || (phi->simu->has_option
				&& phi->actual_eat_time >= phi->simu->nb_times_eat))
		{
			phi->simu->is_died = 1;
			break ;
		}
		if (!phi->simu->has_death)
			p_sleep(phi);
		if (!phi->simu->has_death)
			p_thinking(phi);
		usleep(10);
	}
	return (NULL);
}
