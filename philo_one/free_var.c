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

void	destroy_mutex(t_phi *head)
{
	int	i;

	i = 0;
	while (i < head->simu->nb_p)
	{
		pthread_mutex_destroy(head->simu->fork + i);
		i++;
	}
	pthread_mutex_destroy(&head->simu->display);
}

void	ft_free_var(t_phi *head)
{
	t_phi	*tmp;

	if (head->simu->has_death && !head->simu->is_died)
		printf("All meals are finished\n");
	if (head->simu)
	{
		if (head->simu->fork)
		{
			free(head->simu->fork);
			head->simu->fork = NULL;
		}
		free(head->simu);
		head->simu = NULL;
	}
	while (head)
	{
		tmp = head->next;
		pthread_mutex_destroy(&head->eat_lock);
		head->next = NULL;
		free(head);
		head = tmp;
	}
}
