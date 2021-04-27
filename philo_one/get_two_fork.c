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

pthread_mutex_t	*get_fst_fork(t_phi *phi_i)
{
	if (phi_i->phi_id % 2)
		return (phi_i->right_fork);
	return (phi_i->left_fork);
}

pthread_mutex_t	*get_scd_fork(t_phi *phi_i)
{
	if (phi_i->phi_id % 2)
		return (phi_i->left_fork);
	return (phi_i->right_fork);
}
