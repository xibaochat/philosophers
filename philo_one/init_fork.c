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

static int		get_next_fork_nb(int nb, int i)
{
	if (i + 1 >= nb)
		return (0);
	return (i + 1);
}

pthread_mutex_t	*init_mutex_fork(int nb)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb);
	if (!fork)
		return (NULL);
	while (i < nb)
		pthread_mutex_init(&fork[i++], NULL);
	return (fork);
}

void			init_phi_fork(int nb, pthread_mutex_t *f, t_phi *node)
{
	int				next_id;

	next_id = get_next_fork_nb(nb, node->phi_id);
	node->right_fork = &(f[next_id]);
	node->left_fork = &(f[node->phi_id]);
}
