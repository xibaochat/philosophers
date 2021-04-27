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

int		err_create_thread(t_phi *p, char *s)
{
	printf("%s", s);
	ft_free_var(p);
	return (1);
}

int		err_terminate_thread(t_phi *p)
{
	printf("pthread join for philosopher is failed\n");
	ft_free_var(p);
	return (1);
}

void	printf_message(t_phi *p, char *s)
{
	unsigned long	t;

	if (p->simu->has_death && !p->simu->is_died)
		return ;
	t = p->simu->start_time;
	pthread_mutex_lock(&p->simu->display);
	if (p->simu->has_death)
	{
		pthread_mutex_unlock(&p->simu->display);
		return ;
	}
	printf("%ld %d %s\n", get_timestamp(t), p->phi_id + 1, s);
	pthread_mutex_unlock(&p->simu->display);
}
