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

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	get_start_index(char *str)
{
	int		i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	return (i);
}

int			ft_atoi(const char *s)
{
	int		sign;
	int		res;
	int		i;
	char	*str;

	str = (char *)s;
	sign = 1;
	res = 0;
	i = get_start_index(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;
	size_t	lens;

	i = -1;
	lens = 0;
	while (str[++i])
		lens++;
	return (lens);
}
