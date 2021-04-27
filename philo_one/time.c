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

unsigned long	get_actual_time(void)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	return (actual.tv_sec * 1000 + actual.tv_usec / 1000);
}

unsigned long	get_time_diff(unsigned long a, unsigned long b)
{
	return (a - b);
}

unsigned long	get_timestamp(unsigned long start_time)
{
	return (get_time_diff(get_actual_time(), start_time));
}

int				ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
